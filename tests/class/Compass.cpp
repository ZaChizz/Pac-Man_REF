#include "../../hpp/Compass.h"

TEST_CASE("Compass POSITIVE test") {
    SECTION("Constructor") {
        Compass* a;
        
        CHECK_NOTHROW(a = new Compass());
        
        delete(a);
    }
    SECTION("Check direction") {
        Compass* a = new Compass();

        REQUIRE( a->getForward() == 'w' );
        REQUIRE( a->getBackward() == 's' );
        REQUIRE( a->getLeft() == 'a' );
        REQUIRE( a->getRight() == 'd' );

        delete(a);
    }
    SECTION("Check Calibrate()") {
        Compass* a;
        
        a = new Compass();
        CHECK_NOTHROW(a->calibrate(a->getLeft()));
        CHECK_NOTHROW(a->calibrate(a->getRight()));
        CHECK_NOTHROW(a->calibrate(a->getBackward()));
        CHECK_NOTHROW(a->calibrate(a->getForward()));
        
        delete(a);   
    }
}

TEST_CASE("Compass NEGATIVE test") {
    SECTION("Check Calibrate()") {
        Compass* a;
        
        a = new Compass();
        CHECK_THROWS(a->calibrate('g'));
        
        delete(a);   
    }

}
