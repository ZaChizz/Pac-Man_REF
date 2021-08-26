#ifndef COMPASS_H
#define COMPASS_H

#include <string>

class CompassException
{
private:
    std::string m_error;
 
public:
    CompassException(std::string error): m_error(error) {
    }
 
     const char* getError() { 
        return m_error.c_str(); 
    }
};

class Compass {
    private:
        char forward;
        char backward;
        char left;
        char right;
        void goBack(char* forward, char* backward);
    public:
        Compass();
        ~Compass();

        char getForward();
        char getBackward();
        char getLeft();
        char getRight();

        void goBack();
        void goTwist(char side);
        void calibrate(char way);
};

#endif
