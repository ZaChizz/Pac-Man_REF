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

class Layout {
    private:
        FILE* in;
        int matrixSize;

    public:
        char matrix[ROWS][COLS];
        Layout(FILE* in);
        ~Layout();

        void setPoint(char label, Point* coord);
        char getLabel(Point* coord);

        void render();

};

std::ostream& operator<<(std::ostream& out, Layout& layout);

#endif
