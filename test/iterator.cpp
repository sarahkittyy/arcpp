#include "arcpp/arcpp.hpp"
#include "catch.hpp"

SCENARIO("iterators") {
	using arcpp::archive;
	using arcpp::iterator;

	std::string ext = GENERATE(".zip", ".7z", ".iso", ".rar", ".tar");
	UNSCOPED_INFO("using extension " + ext);

	GIVEN("an archive iterator") {
		archive ar;
		ar.open("../test/test" + ext);

		iterator i = ar.files();

		WHEN("initialized") {
			THEN("it is not done") {
				REQUIRE(!i.done());
			}
		}

		WHEN("iterating") {
			for (; !i.done(); i.next())
				;
			THEN("it is done afterward") {
				REQUIRE(i.done());
			}
		}

		AND_WHEN("the iterator is reset") {
			i.reset();
			THEN("it is not done") {
				REQUIRE(!i.done());
			}
		}
	}
}