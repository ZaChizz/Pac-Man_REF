#ifndef LAYOUT_H
#define LAYOUT_H

#include "../config.h"
#include <iostream>
#include <iterator>
#include <cstdio>
#include "Point.h"

#include "../exceptions/LayoutException.cpp"
#include "../interfaces/ILayout.h"
#include "../interfaces/ILayout4Moover.h"

class Layout: public ILayout4Moover, ILayout {
    private:
        FILE* in;
        int matrixSize;
        char matrix[ROWS][COLS];

    public:
        Layout(FILE* in);
        ~Layout();

        void setPoint(char label, IPoint* coord);
        char getLabel(IPoint* coord);

        void render();

};

#endif
