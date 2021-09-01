#include "../../hpp/Unit.h"
#include "../../config.h"

TEST_CASE("Unit POSITIVE test") {
    SECTION("Constructor() check Throws") {
        Unit* a;

        CHECK_NOTHROW(a = new Unit('a'));
        
        delete(a);
    }

    SECTION("Constructor() check Throws with custom start Point") {
        Unit* a;
        
        CHECK_NOTHROW(a = new Unit('a', (int)PACMAN_DEFAULT_COORD_X, (int)PACMAN_DEFAULT_COORD_Y));
        
        delete(a);
    }

    SECTION("getLabel() check lable") {
        Unit* a = new Unit('a');
        
        REQUIRE(a->getLabel() == 'a');
        
        delete(a);
    }

    SECTION("getCoord() check Point") {
        Unit* a = new Unit('a');
        
        REQUIRE(a->getCoord()->getX() == 0);
        REQUIRE(a->getCoord()->getY() == 0);
        
        delete(a);
    }
}
