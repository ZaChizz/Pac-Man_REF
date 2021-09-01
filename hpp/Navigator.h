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
        Navigator(IMoover* moover);
        ~Navigator();
        char getWay();
        char navigate();
    private:
        ICompass* compass;
        IMoover* moover;
        char way;
        char directions[4];
        int countDirections;
        void checkDirections();
        void chooseDirection();
};

#endif
