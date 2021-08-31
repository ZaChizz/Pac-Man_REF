#include "hpp/Point.h"

Point::Point(int x, int y): IPoint(), x(x), y(y) {
    if ( x < 0 || y < 0 ) {
        throw PointException("Coord X and Y shoud be >= 0.");
    }
}

Point::Point(const Point& point) {
    this->x = point.x;
    this->y = point.y;
}

Point::~Point() {}

int Point::getX() {
    return this->x;
}

int Point::getY() {
    return this->y;
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

void Point::increaseX() {
    this->x += 1;
}

void Point::increaseY() {
    this->y += 1;
}

void Point::decreaseX() {
    this->x -= 1;
}

void Point::decreaseY() {
    this->y -= 1;
}

bool Point::operator==(const Point& other) const {
    return this->x == other.x && this->y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return !((*this) == other);
}

double Point::distance(const Point& other) const {
    return hypot(this->x - other.x, this->y - other.y);
}
