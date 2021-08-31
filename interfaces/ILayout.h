#ifndef ILAYOUT_H
#define ILAYOUT_H

#include "IPoint.h"

class ILayout {
    public:
        ILayout();
        virtual ~ILayout();

        virtual void setPoint(char label, IPoint* coord)=0;
        virtual char getLabel(IPoint* coord)=0;

        virtual void render()=0;
};

#endif //ILAYOUT_H
