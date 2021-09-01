#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <time.h>
#include <windows.h>
#include "Compass.h"
#include "../interfaces/IMoover4Navigator.h"
#include "../interfaces/ICompass.h"
#include "../interfaces/INavigator.h"
#include "../exceptions/NavigatorException.cpp"

class Navigator: public INavigator {
    public:
        Navigator(IMoover4Navigator* moover);
        ~Navigator();
        char getWay();
        char navigate();
    private:
        ICompass* compass;
        IMoover4Navigator* moover;
        char way;
        char directions[4];
        int countDirections;
        void checkDirections();
        void chooseDirection();
};

#endif
