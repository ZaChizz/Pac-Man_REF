#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
#include "../exceptions/PointException.cpp"
#include "../interfaces/IPoint.h"

class Point: public IPoint {
    private:
        int x;
        int y;

    public:
        Point(int x=0, int y=0);
        Point(const Point& point);
        ~Point();

        int getX();
        int getY();

        void setX(int x);
        void setY(int y);

        void increaseX();
        void increaseY();
        void decreaseX();
        void decreaseY();
};

#endif // POINT_H
