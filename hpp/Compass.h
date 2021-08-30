#ifndef COMPASS_H
#define COMPASS_H

#include "../exceptions/CompassException.cpp"

class Compass {
    private:
        char forward;
        char backward;
        char left;
        char right;
        void goBack(char* forward, char* backward);
        void goBack();
        void goTwist(char side);
    public:
        Compass();
        ~Compass();

        char getForward();
        char getBackward();
        char getLeft();
        char getRight();

        void calibrate(char way);
};

#endif
