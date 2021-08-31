#ifndef ICOMPASS_H
#define ICOMPASS_H

class ICompass {
	public:
		ICompass();
		~ICompass();

		virtual char getForward()=0;
        virtual char getBackward()=0;
        virtual char getLeft()=0;
        virtual char getRight()=0;

        virtual void calibrate(char way)=0;
};

#endif
