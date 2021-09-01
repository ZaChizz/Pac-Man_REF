#include "../../hpp/Unit.h"
#include "../../config.h"

TEST_CASE("Unit POSITIVE test") {
    SECTION("Constructor()") {
        Unit* a;
        CHECK_NOTHROW(a = new Unit('a'));
        delete(a);
    }

    SECTION("Constructor() with custom start Point") {
        Unit* a;
        CHECK_NOTHROW(a = new Unit('a', (int)PACMAN_DEFAULT_COORD_X, (int)PACMAN_DEFAULT_COORD_Y));
        delete(a);
    }
}
