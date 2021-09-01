#include "../../hpp/Point.h"

TEST_CASE("Point POSITIVE test") {
    SECTION("Constructor() check Throws") {
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

    SECTION("Check increaseX() and increaseY()") {
        Point* a = new Point();
        CHECK_NOTHROW(a->increaseX());
        CHECK_NOTHROW(a->increaseY());

        REQUIRE( a->getX() == 1 );
        REQUIRE( a->getY() == 1 );

        delete(a);
    }

    SECTION("Check decreaseX() and decreaseY()") {
        Point* a = new Point(1,1);
        CHECK_NOTHROW(a->decreaseX());
        CHECK_NOTHROW(a->decreaseY());

        REQUIRE( a->getX() == 0 );
        REQUIRE( a->getY() == 0 );

        delete(a);
    }     
}
