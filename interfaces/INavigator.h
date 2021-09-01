#ifndef INAVIGATOR_H
#define INAVIGATOR_H

class INavigator {
	public:
		INavigator();
		~INavigator();

		virtual char getWay()=0;
        virtual char navigate()=0;
};

#endif