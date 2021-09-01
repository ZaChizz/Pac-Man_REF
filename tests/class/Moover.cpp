#include "../../hpp/Moover.h"
#include "../../hpp/Layout.h"
#include "../../hpp/Unit.h"

TEST_CASE("Moover POSITIVE test") {
    SECTION("Constructor() check Throws") {
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

    SECTION("moove() check Throws") {
        FILE* in;
        in = fopen("tests/source/positive/map.in", "r");
        Layout* l = new Layout(in);
        Unit* u = new Unit('$');
        Moover* m = new Moover(l, u);

        CHECK_NOTHROW(m->moove('s'));
        CHECK_NOTHROW(m->moove('w'));
        CHECK_NOTHROW(m->moove('d'));
        CHECK_NOTHROW(m->moove('a'));

        delete(l);
        delete(u);
        delete(m);
    }

    SECTION("moove() [with a tail] check Throws") {
        FILE* in;
        in = fopen("tests/source/positive/map.in", "r");
        Layout* l = new Layout(in);
        Unit* u = new Unit('$');
        Moover* m = new Moover(l, u);

        CHECK_NOTHROW(m->moove('s','%'));
        CHECK_NOTHROW(m->moove('w','%'));
        CHECK_NOTHROW(m->moove('d','%'));
        CHECK_NOTHROW(m->moove('a','%'));

        delete(l);
        delete(u);
        delete(m);        
    }

    SECTION("checkDirection() check Throws") {
        FILE* in;
        in = fopen("tests/source/positive/map.in", "r");
        Layout* l = new Layout(in);
        Unit* u = new Unit('$');
        Moover* m = new Moover(l, u);

        CHECK_NOTHROW(m->checkDirection('w'));
        CHECK_NOTHROW(m->checkDirection('s'));
        CHECK_NOTHROW(m->checkDirection('a'));
        CHECK_NOTHROW(m->checkDirection('d'));

        delete(l);
        delete(u);
        delete(m);

    }

    SECTION("nextPoint() check Throws") {
        FILE* in;
        in = fopen("tests/source/positive/map.in", "r");
        Layout* l = new Layout(in);
        Unit* u = new Unit('$');
        Moover* m = new Moover(l, u);

        CHECK_NOTHROW(m->nextPoint('w'));
        CHECK_NOTHROW(m->nextPoint('s'));
        CHECK_NOTHROW(m->nextPoint('a'));
        CHECK_NOTHROW(m->nextPoint('d'));

        delete(l);
        delete(u);
        delete(m);
    }

    SECTION("nextPoint() check unit coord") {
        FILE* in;
        in = fopen("tests/source/positive/map.in", "r");
        Layout* l = new Layout(in);
        Unit* u = new Unit('$');
        Moover* m = new Moover(l, u);
        m->nextPoint('w');

        REQUIRE( u->getCoord()->getX() == -1 );

        m->nextPoint('s');

        REQUIRE( u->getCoord()->getX() == 0 );

        m->nextPoint('a');

        REQUIRE( u->getCoord()->getY() == -1 );

        m->nextPoint('d');

        REQUIRE( u->getCoord()->getY() == 0 );                        

        delete(l);
        delete(u);
        delete(m);
    }
}
