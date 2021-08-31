#ifndef IPOINT_H
#define IPOINT_H

class IPoint {
	public:
		IPoint();
		virtual ~IPoint();

		virtual int getX()=0;
		virtual int getY()=0;
		virtual void setX(int x)=0;
		virtual void setY(int y)=0;
		virtual void increaseX()=0;
		virtual void increaseY()=0;
		virtual void decreaseX()=0;
		virtual void decreaseY()=0;

};

#endif
