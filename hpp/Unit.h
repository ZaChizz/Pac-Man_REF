#ifndef UNIT_H
#define UNIT_H

#include "../exceptions/UnitException.cpp"
#include "../interfaces/IUnit.h"
#include "Point.h"

class Unit: public IUnit {
    private:
        IPoint* coord;
        char label;
    public:
        Unit(char label, int x = 0, int y = 0);
        ~Unit();
        char getLabel();
        IPoint* getCoord();
        void setStartPoint(int x, int y);
};

#endif
