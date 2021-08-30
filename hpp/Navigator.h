#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <time.h>
#include <windows.h>
#include "Compass.h"
#include "Moover.h"
#include "../exceptions/NavigatorException.cpp"

class Navigator {
    public:
        Navigator(Moover* unitMoover);
        ~Navigator();
        char getWay();
        char navigate();
        void checkDirections();
        void chooseDirection();
    private:
        Compass* unitCompass;
        Moover* unitMoover;
        char way;
        char directions[4];
        int countDirections;
};

#endif
