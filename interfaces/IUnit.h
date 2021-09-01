#ifndef IUNIT_H
#define IUNIT_H

class IPoint;

class IUnit {
    public:
        IUnit();
        virtual ~IUnit();

        virtual char getLabel()=0;
        virtual IPoint* getCoord()=0;
};

#endif //IUNIT_H
