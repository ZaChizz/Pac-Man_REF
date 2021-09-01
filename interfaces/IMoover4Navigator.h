#ifndef IMOOVER_4_NAVIGATOR_H
#define IMOOVER_4_NAVIGATOR_H

class IMoover4Navigator {
    public:
        IMoover4Navigator();
        ~IMoover4Navigator();

        virtual bool checkDirection(char direction)=0;
};

#endif