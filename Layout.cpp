#include "hpp/Layout.h"

Layout::Layout(FILE *in): ILayout(), ILayout4Moover() {
    this->in = in;
    int countSymbols = 0;
    for ( int row = 0 ; row < ROWS; row++ ) {
        for ( int col = 0; col < COLS; col++ ) {
            if ( fscanf(in, "%c", &this->matrix[row][col]) != EOF ) {
                countSymbols++;    
            }
        }
    }

    this->matrixSize = ROWS * COLS;
    if ( this->matrixSize != countSymbols ) {
        throw LayoutException("In file 'in' dimension are not right. Check ROWS and COLS in config file, and match them to the map from the file.");
    }
}

Layout::~Layout() {
    fclose(this->in);
}

void Layout::setPoint(char label, IPoint* coord) {
    this->matrix[coord->getX()][coord->getY()] = label;
}

char Layout::getLabel(IPoint* coord) {
    return this->matrix[coord->getX()][coord->getY()]; 
}

void Layout::render() {
    copy (&(**this->matrix), &(**this->matrix) + this->matrixSize, std::ostream_iterator<char>(std::cout));
}
