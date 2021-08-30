#include <iostream>
#include <cstdio>
#include "../../hpp/Layout.h"
#include "../../hpp/Point.h"

TEST_CASE("Layout POSITIVE test") {
    SECTION("Constructor()") {
        FILE* in;
        in = fopen("tests/source/map.in", "r");
        Layout* l;

        CHECK_NOTHROW(l = new Layout(in));

        delete(l);        
    }

    SECTION("getLabel() Check map") {

        FILE* in;
        in = fopen("tests/source/map.in", "r");

        Layout* l = new Layout(in);
        Point* a = new Point(0,0);
        Point* b = new Point(1,1);
        Point* c = new Point(2,2);
        Point* d = new Point(3,3);
        Point* e = new Point(4,4);
        Point* f = new Point(5,5);
        Point* g = new Point(6,6);
        Point* h = new Point(9, 40);

        REQUIRE( l->getLabel(a) == '*' );
        REQUIRE( l->getLabel(b) == '[' );
        REQUIRE( l->getLabel(c) == ']' );
        REQUIRE( l->getLabel(d) == '*' );
        REQUIRE( l->getLabel(e) == '*' );
        REQUIRE( l->getLabel(f) == ']' );
        REQUIRE( l->getLabel(g) == '*' );
        REQUIRE( l->getLabel(h) == '\n' );

        delete(l);
        delete(a);
        delete(b);
        delete(c);
        delete(d);
        delete(e);
        delete(f);
        delete(g);
        delete(h);
    }
}
