#include "../../hpp/Moover.h"
#include "../../hpp/Layout.h"
#include "../../hpp/Unit.h"

TEST_CASE("Moover POSITIVE test") {
    SECTION("Constructor()") {
        FILE* in;
        in = fopen("tests/source/positive/map.in", "r");
        Layout* l = new Layout(in);
        Unit* u = new Unit('$');
        Moover* m;

        CHECK_NOTHROW(m = new Moover(l, u));
        delete(l);
        delete(u);
        delete(m);
    }

    SECTION("moove()") {

    }

    SECTION("moove() with a tail") {
        
    }

    SECTION("checkDirection()") {

    }

    SECTION("nextPoint()") {
        
    }
}
