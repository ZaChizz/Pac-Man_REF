#include "../../hpp/Navigator.h"
#include "../../hpp/Moover.h"

TEST_CASE("Navigator POSITIVE test") {
    SECTION("Constructor") {

        Navigator* a = new Navigator();
        REQUIRE( a->getX() == 0 );
        REQUIRE( a->getY() == 0 );

        delete(a);
    }
}
