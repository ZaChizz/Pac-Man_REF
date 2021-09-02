#ifndef MOOVER_H
#define MOOVER_H

#include "../config.h"
#include <queue>
#include "../interfaces/ILayout4Moover.h"
#include "../interfaces/IUnit.h"
#include "../interfaces/IMoover.h"
#include "../interfaces/IMoover4Navigator.h"
#include "../exceptions/MooverException.cpp"

class Moover: public IMoover4Navigator, IMoover {
    private:
        ILayout4Moover* layout;
        IUnit* unit;
        std::queue<char> buffer;
        void start();
        void rollBack(char direction);
        bool checkBoard();
        bool checkTrail();

    public:
        Moover(ILayout4Moover* layout, IUnit* unit);
        ~Moover();

        void moove(char direction);
        void moove(char direction, char tail);
        bool checkDirection(char direction);
        void nextPoint(char direction);
};

#endif
