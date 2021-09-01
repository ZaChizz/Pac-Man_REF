#ifndef IMOOVER_H
#define IMOOVER_H

class IMoover {
    public:
        IMoover();
        ~IMoover();

        virtual void moove(char direction)=0;
        virtual void moove(char direction, char tail)=0;
        virtual bool checkDirection(char direction)=0;
        virtual void nextPoint(char direction)=0;
};

#endif