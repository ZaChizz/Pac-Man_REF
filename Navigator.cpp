#include "hpp/Navigator.h"

Navigator::Navigator(IMoover4Navigator* moover): INavigator() {
    try {
        this->compass = new Compass();    
    } catch(const CompassException& e) {
        throw NavigatorException("Compass class didn't made. Check the Compass class constructor.");
    }
    this->moover = moover;
}

Navigator::~Navigator() {
    delete(this->compass);
}

char Navigator::getWay() {
    return this->way;
}

char Navigator::navigate() {
    this->checkDirections();
    this->chooseDirection();
    return this->way;
}

void Navigator::checkDirections() {
    this->countDirections = 0;

    if ( this->moover->checkDirection(this->compass->getForward()) ) {
        this->directions[this->countDirections] = this->compass->getForward();
        this->countDirections += 1;
    }

    if ( this->moover->checkDirection(this->compass->getRight()) ) {
        this->directions[this->countDirections] = this->compass->getRight();
        this->countDirections += 1;
    }

    if ( this->moover->checkDirection(this->compass->getLeft()) ) {
        this->directions[this->countDirections] = this->compass->getLeft();
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
        this->way = this->compass->getBackward();
    }

    this->compass->calibrate(this->way);
}
