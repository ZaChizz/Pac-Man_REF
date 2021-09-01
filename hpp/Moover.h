

#ifndef MOOVER_H
#define MOOVER_H

#include "../config.h"
#include <queue>
#include "../interfaces/ILayout.h"
#include "../interfaces/IUnit.h"
#include "../interfaces/IMoover.h"
#include "../exceptions/MooverException.cpp"

class Moover: public IMoover {
    private:
        ILayout* layout;
        IUnit* unit;
        std::queue<char> buffer;
        void start();

    public:
        Moover(ILayout* layout, IUnit* unit);
        ~Moover();

        void moove(char direction);
        void moove(char direction, char tail);

        bool checkDirection(char direction);

        void nextPoint(char direction);
        void rollBack(char direction);

        bool checkBoard();
        bool checkTrail();
};

#endif
