#ifndef MOOVER_H
#define MOOVER_H

#include <queue>

#include "Layout.h"
#include "Unit.h"
#include "Point.h"

class Moover {
    private:
        Layout* layout;
        Unit* unit;
        std::queue<char> buffer;

    public:
        Moover(Layout* layout, Unit* unit);
        ~Moover();

        void start();

        void moove(char direction);
        void moove(char direction, char tail);

        bool checkDirection(char direction);

        void nextPoint(char direction);
        void rollBack(char direction);

        bool checkBoard();
        bool checkTrail();
        
};

#endif
