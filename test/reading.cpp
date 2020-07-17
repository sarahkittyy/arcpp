#include <string>
#include <vector>

#include "arcpp/arcpp.hpp"
#include "catch.hpp"

SCENARIO("archives can be read", "[archive]") {
	using arcpp::archive, arcpp::entry;
	using Catch::Contains, Catch::CaseSensitive, Catch::UnorderedEquals;

	std::string ext = GENERATE(".zip", ".7z", ".iso", ".rar", ".tar");
	UNSCOPED_INFO("using extension " + ext);

	archive ar;
	ar.open("../test/test" + ext);

	GIVEN("a file iterator") {
		auto iter = ar.files();

		WHEN("the files are iterated through") {
			std::vector<std::string> paths;
			const std::vector<std::string> target({ "folder/",
													"file1.txt",
													"folder/file2.txt" });
			const std::vector<std::string> target_alt({ "folder",
														"file1.txt",
														"folder/file2.txt" });
			const std::vector<std::string> target_iso({ "folder",
														"file1.txt",
														"folder/file2.txt",
														"." });

			for (; !iter.done(); iter.next()) {
				paths.push_back(iter.get().path_name());
			}

			THEN("they match the files actually in the archive") {
				REQUIRE_THAT(paths,
							 UnorderedEquals(target) ||
								 UnorderedEquals(target_alt) ||
								 UnorderedEquals(target_iso));
			}
		}

		WHEN("reading content from an entry") {
			for (; !iter.done(); iter.next()) {
				if (iter.get().path_name() == "file1.txt") {
					break;
				}
			}
			REQUIRE(iter.get().type() == entry::FILE);

			THEN("it matches the content in the file") {
				std::string file1_content = "the contents of file1.txt";
				REQUIRE_THAT(iter.get().contents(), Contains(file1_content));
			}
		}
	}
}