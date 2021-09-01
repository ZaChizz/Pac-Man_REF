#include "../../hpp/Point.h"

TEST_CASE("Point POSITIVE test") {
    SECTION("Constructor()") {
        Point* a;
        CHECK_NOTHROW( a = new Point() );
        delete(a);
    }

    SECTION("Check getX() and getY(). Constructor with default paramters.") {

        Point* a = new Point();
        REQUIRE( a->getX() == 0 );
        REQUIRE( a->getY() == 0 );

        delete(a);
    }

    SECTION("Check getX() and getY(). Constructor with custom paramters.") {

        Point* a = new Point(1,20);
        REQUIRE( a->getX() == 1 );
        REQUIRE( a->getY() == 20 );

        delete(a);
    }
}
