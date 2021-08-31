#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <time.h>
#include <windows.h>
#include "Compass.h"
#include "../interfaces/IMoover.h"
#include "../interfaces/ICompass.h"
#include "../interfaces/INavigator.h"
#include "../exceptions/NavigatorException.cpp"

class Navigator: public INavigator {
    public:
        Navigator(IMoover* unitMoover);
        ~Navigator();
        char getWay();
        char navigate();
        void checkDirections();
        void chooseDirection();
    private:
        ICompass* unitCompass;
        IMoover* unitMoover;
        char way;
        char directions[4];
        int countDirections;
};

#endif
