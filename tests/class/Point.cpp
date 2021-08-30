#include "../../hpp/Point.h"

TEST_CASE("Point POSITIVE test") {
    SECTION("Constructor") {

        Point* a = new Point();
        REQUIRE( a->getX() == 0 );
        REQUIRE( a->getY() == 0 );

        delete(a);
    }

    SECTION("Constructor with paramters") {

        Point* a = new Point(1,20);
        REQUIRE( a->getX() == 1 );
        REQUIRE( a->getY() == 20 );

        delete(a);
    }
}
