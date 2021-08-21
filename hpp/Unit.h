#ifndef UNIT_H
#define UNIT_H

#include "Point.h"

class Unit {
    private:
        Point* coord;
        char label;
    public:
        Unit(char label);
        ~Unit();
        char getLabel();
        Point* getCoord();
        void setStartPoint(int x, int y);
};

#endif