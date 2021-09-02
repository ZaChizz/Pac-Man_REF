#include "hpp/Moover.h"

Moover::Moover(ILayout4Moover* layout, IUnit* unit): IMoover4Navigator(), IMoover() {
    this->layout = layout;
    this->unit = unit;
    this->buffer.push('*');
    this->start();
}

Moover::~Moover() {}

void Moover::start() {
    if ( this->checkBoard() && this->checkTrail() ) {
        this->layout->setPoint(this->unit->getLabel(), this->unit->getCoord());
    } else {
        throw MooverException("Can't start(). Check the DEFAULT_COORD in config file.");
    }
}

void Moover::moove(char direction) {
    this->nextPoint(direction);
    if ( this->checkBoard() && this->checkTrail() ) {
        this->buffer.push(this->layout->getLabel(this->unit->getCoord()));
        this->layout->setPoint(this->unit->getLabel(), this->unit->getCoord());
        this->rollBack(direction);
        this->layout->setPoint(this->buffer.front(), this->unit->getCoord());
        this->nextPoint(direction);
        this->buffer.pop();
    } else {
        this->rollBack(direction);
    }
}

void Moover::moove(char direction, char tail) {
    this->nextPoint(direction);
    if ( this->checkBoard() && this->checkTrail() ) {
        this->layout->setPoint(this->unit->getLabel(), this->unit->getCoord());
        this->rollBack(direction);
        this->layout->setPoint(tail, this->unit->getCoord());
        this->nextPoint(direction);
    } else {
        this->rollBack(direction);
    }
}

bool Moover::checkDirection(char direction) {
    this->nextPoint(direction);
    if ( this->checkBoard() && this->checkTrail() ) {
        this->rollBack(direction);
        return true;        
    } else {
        this->rollBack(direction);
        return false;
    }
}

void Moover::nextPoint(char direction) {
    if ( direction == 'w' ) {
        this->unit->getCoord()->decreaseX();
    }
    if ( direction == 's' ) {
        this->unit->getCoord()->increaseX();
    }
    if ( direction == 'a' ) {
        this->unit->getCoord()->decreaseY();
    }
    if ( direction == 'd' ) {
        this->unit->getCoord()->increaseY();
    }
}

void Moover::rollBack(char direction) {
    if ( direction == 'w' ) {
        this->unit->getCoord()->increaseX();
    }
    if ( direction == 's' ) {
        this->unit->getCoord()->decreaseX();
    }
    if ( direction == 'a' ) {
        this->unit->getCoord()->increaseY();
    }
    if ( direction == 'd' ) {
        this->unit->getCoord()->decreaseY();
    }
}

bool Moover::checkBoard() {
    if ( this->unit->getCoord()->getX() >= 0 ) {
        if ( this->unit->getCoord()->getX() <= ROWS - 1 ) {
            if ( this->unit->getCoord()->getY() >= 0 ) {
                if ( this->unit->getCoord()->getY() <= COLS - 2 ) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool Moover::checkTrail() {
    if ( '.' == this->layout->getLabel(this->unit->getCoord()) ) {
        return true;
    }
    if ( '*' == this->layout->getLabel(this->unit->getCoord()) ) {
        return true;
    }

    return false;
}
