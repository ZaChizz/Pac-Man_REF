#include "../../hpp/Moover.h"
#include "../../hpp/Layout.h"
#include "../../hpp/Unit.h"

TEST_CASE("Moover POSITIVE test") {
    SECTION("Constructor") {
        FILE* in;
        in = fopen("tests/source/map.in", "r");
        Layout* l = new Layout(in);
        Unit* u = new Unit('$');

        CHECK_NOTHROW(new Moover(l, u));
        delete(l);
        delete(u);
    }
}

