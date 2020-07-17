#include "arcpp/arcpp.hpp"
#include "catch.hpp"

SCENARIO("archives can be opened safely", "[archive]") {
	using arcpp::archive;
	using Catch::Contains, Catch::CaseSensitive;

	std::string ext = GENERATE(".zip", ".7z", ".iso", ".rar", ".tar");
	UNSCOPED_INFO("using extension " + ext);

	GIVEN("an archive") {
		archive ar;

		WHEN("trying to open an archive that exists") {
			THEN("it does not throw") {
				ar.open("../test/test" + ext);
				ar.open("../test/test" + ext);
				ar.open("../test/test" + ext);
			}
		}

		ar.open("../test/test" + ext);

		WHEN("trying to open an archive that does not exist") {
			THEN("it errors") {
				REQUIRE_THROWS_WITH(
					ar.open("DOES-NOT-EXIST"),
					Contains("failed to open", CaseSensitive::No));
			}
		}
	}
}