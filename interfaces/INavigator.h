#ifndef INAVIGATOR_H
#define INAVIGATOR_H

class INavigator {
	public:
		INavigator();
		~INavigator();

		virtual char getWay()=0;
        virtual char navigate()=0;
        virtual void checkDirections()=0;
        virtual void chooseDirection()=0;
};

#endif