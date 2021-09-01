#include "../../hpp/Navigator.h"
#include "../../hpp/Moover.h"

TEST_CASE("Navigator POSITIVE test") {
    SECTION("Constructor()") {

        FILE* in;
        in = fopen("tests/source/positive/map.in", "r");
        Layout* l = new Layout(in);
        Unit* u = new Unit('$');
        Moover* m = new Moover(l, u);
        Navigator* n;

        CHECK_NOTHROW(n = new Navigator(m));

        delete(l);
        delete(u);
        delete(m);
        delete(n);
    }
}
