#include "hpp/Navigator.h"

Navigator::Navigator(Moover* unitMoover) {
    this->unitCompass = new Compass();
    this->unitMoover = unitMoover;
}

Navigator::~Navigator() {
    delete(this->unitCompass);
}

char Navigator::getWay() {
    return this->way;
}

void Navigator::checkDirections() {
    this->countDirections = 0;

    if ( this->unitMoover->checkDirection(this->unitCompass->getForward()) ) {
        this->directions[this->countDirections] = this->unitCompass->getForward();
        this->countDirections += 1;
    }

    if ( this->unitMoover->checkDirection(this->unitCompass->getRight()) ) {
        this->directions[this->countDirections] = this->unitCompass->getRight();
        this->countDirections += 1;
    }

    if ( this->unitMoover->checkDirection(this->unitCompass->getLeft()) ) {
        this->directions[this->countDirections] = this->unitCompass->getLeft();
        this->countDirections += 1;
    }
}

void Navigator::chooseDirection() {
    if ( this->countDirections > 1 ) {
        srand(time(NULL));
        this->way = this->directions[rand() % this->countDirections];
    } else if ( this->countDirections == 1 ) {
        this->way = directions[0];
    } else {
        this->way = this->unitCompass->getBackward();
    }

    this->unitCompass->calibrate(this->way);
}

char Navigator::navigate() {
    this->checkDirections();
    this->chooseDirection();
    return this->way;
}
