#ifndef ILAYOUT_4_MOOVER_H
#define ILAYOUT_4_MOOVER_H

#include "IPoint.h"

class ILayout4Moover {
	public:
		ILayout4Moover();
		~ILayout4Moover();

		virtual void setPoint(char label, IPoint* coord)=0;
        virtual char getLabel(IPoint* coord)=0;
};

#endif