#include "hpp/Compass.h"

Compass::Compass() {
    this->forward = 'w';
    this->backward = 's';
    this->left = 'a';
    this->right = 'd';
}

Compass::~Compass() {}

char Compass::getForward() {
    return this->forward;
}

char Compass::getBackward() {
    return this->backward;
}

char Compass::getLeft() {
    return this->left;
}

char Compass::getRight() {
    return this->right;
}

void Compass::goBack() {
    char buffer;

    buffer = this->forward;
    this->forward = this->backward;
    this->backward = buffer;
}

void Compass::goBack(char* forward, char* backward){
    char buffer;

    buffer = *forward;
    *forward = *backward;
    *backward = buffer;
}

void Compass::goTwist(char side) {
    if ( side == 'l' ) {
        goBack(&this->forward, &this->left);
        goBack(&this->backward, &this->right);
    } else if ( side == 'r' ) {
        goBack(&this->forward, &this->right);
        goBack(&this->backward, &this->left);
    } else {
        throw CompassException("Wrong side! Side whoul be 'l' or 'r'.");
    }
}

void Compass::calibrate(char way) {
/*
"""This is a method which calibrate state depend on directions(left, right, backward)

:param way: Direction, defaults to None
:type way: char
:raises [ErrorType]: [ErrorDescription]
:return: void function
:rtype: void
"""
*/
    if ( way == this->backward ) {
        this->goBack();
    }
    if ( way == this->left ) {
        this->goTwist('l');
    }
    if ( way == this->right ) {
        goTwist('r');
    }
}
