#include <iostream>
#include <cstdio>
#include "../../hpp/Layout.h"
#include "../../hpp/Point.h"

TEST_CASE("Layout POSITIVE test") {
    SECTION("Constructor() check Throws") {
        FILE* in;
        in = fopen("tests/source/positive/map.in", "r");
        Layout* l;

        CHECK_NOTHROW(l = new Layout(in));

        delete(l);        
    }

    SECTION("getLabel() check Throws") {
        FILE* in;
        in = fopen("tests/source/positive/map.in", "r");
        Layout* l = new Layout(in);
        Point* a = new Point(0,0);

        CHECK_NOTHROW(l->getLabel(a));

        delete(l);
        delete(a);
    }

    SECTION("setPoint() check Throws") {
        FILE* in;
        in = fopen("tests/source/positive/map.in", "r");
        Layout* l = new Layout(in);
        Point* a = new Point(0,0);

        CHECK_NOTHROW(l->setPoint('%', a));

        delete(l);
        delete(a);
    }

    SECTION("getLabel() check Point") {
        FILE* in;
        in = fopen("tests/source/positive/map.in", "r");
        Layout* l = new Layout(in);
        Point* a = new Point(0,0);
        l->setPoint('%', a);

        REQUIRE( l->getLabel(a) == '%' );

        delete(l);
        delete(a);
    }   

    SECTION("getLabel() Check map") {

        FILE* in;
        in = fopen("tests/source/positive/map.in", "r");

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

    SECTION("getLabel() Check end line in the map") {

        FILE* in;
        in = fopen("tests/source/positive/map.in", "r");

        Layout* l = new Layout(in);
        Point* a = new Point(0,40);
        Point* b = new Point(1,40);
        Point* c = new Point(2,40);
        Point* d = new Point(3,40);
        Point* e = new Point(4,40);
        Point* f = new Point(5,40);
        Point* g = new Point(6,40);
        Point* h = new Point(7,40);
        Point* i = new Point(8,40);
        Point* j = new Point(9,40);

        REQUIRE( l->getLabel(a) == '\n' );
        REQUIRE( l->getLabel(b) == '\n' );
        REQUIRE( l->getLabel(c) == '\n' );
        REQUIRE( l->getLabel(d) == '\n' );
        REQUIRE( l->getLabel(e) == '\n' );
        REQUIRE( l->getLabel(f) == '\n' );
        REQUIRE( l->getLabel(g) == '\n' );
        REQUIRE( l->getLabel(h) == '\n' );
        REQUIRE( l->getLabel(i) == '\n' );
        REQUIRE( l->getLabel(j) == '\n' );

        delete(l);
        delete(a);
        delete(b);
        delete(c);
        delete(d);
        delete(e);
        delete(f);
        delete(g);
        delete(h);
        delete(i);
        delete(j);
    }

    SECTION("render() check Throws") {
        FILE* in;
        in = fopen("tests/source/positive/map.in", "r");
        Layout* l = new Layout(in);

        CHECK_NOTHROW(l->render());

        delete(l);
    }


}

TEST_CASE("Layout NEGATIVE test") {
    SECTION("Constructor()") {
        FILE* in;
        in = fopen("tests/source/negative/map.in", "r");

        CHECK_THROWS(new Layout(in));       
    }
}
