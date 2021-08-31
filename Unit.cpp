#include "hpp/Unit.h"
#include "interfaces/IUnit.h"

Unit::Unit(char label): IUnit() {
    this->label = label;
    this->coord = new Point();
}

Unit::~Unit() {
    delete(this->coord);
}

char Unit::getLabel() {
    return this->label;
}

IPoint* Unit::getCoord() {
    return this->coord;
}

void Unit::setStartPoint(int x, int y) {
    this->coord->setX(x);
    this->coord->setY(y);
}
