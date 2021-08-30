#include "../../hpp/Unit.h"

TEST_CASE("Unit POSITIVE test") {
    SECTION("Constructor") {
        Unit* a;
        CHECK_NOTHROW(a = new Unit('a'));
        delete(a);
    }
}
