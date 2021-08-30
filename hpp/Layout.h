#include "../config.h"

#ifndef LAYOUT_H
#define LAYOUT_H

#ifndef ROWS
#define ROWS 10
#endif

#ifndef COLS
#define COLS 11
#endif

#include <iostream>
#include <iterator>
#include <cstdio>
#include "Point.h"

#include "../exeptions/LayoutException.cpp"

class Layout {
    private:
        FILE* in;
        int matrixSize;
        char matrix[ROWS][COLS];

    public:
        Layout(FILE* in);
        ~Layout();

        void setPoint(char label, Point* coord);
        char getLabel(Point* coord);

        void render();

};

#endif
