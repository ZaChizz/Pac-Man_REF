#include "hpp/Unit.h"

Unit::Unit(char label): label(label) {
    this->coord = new Point();
}

Unit::~Unit() {
    delete(this->coord);
}

char Unit::getLabel() {
    return this->label;
}

Point* Unit::getCoord() {
    return this->coord;
}

void Unit::setStartPoint(int x, int y) {
    this->coord->setX(x);
    this->coord->setY(y);
}
