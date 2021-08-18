#include "hpp/Layout.h"

Layout::Layout(FILE *in): in(in) {
    for ( int row = 0; row < ROWS; row++ ) {
        for ( int col = 0; col < COLS; col++ ) {
            fscanf(in, "%c", &this->matrix[row][col]);
        }
    }

    this->matrixSize = ROWS * COLS;
}

Layout::~Layout() {
    fclose(this->in);
}

void Layout::setPoint(char label, Point* coord) {
    this->matrix[coord->getX()][coord->getY()] = label;
}

char Layout::getLabel(Point* coord) {
    return this->matrix[coord->getX()][coord->getY()]; 
}

void Layout::render() {
    copy ( &(**this->matrix), &(**this->matrix) + this->matrixSize, std::ostream_iterator<char>(std::cout));
}


std::ostream& operator<<(std::ostream& out, Layout& layout) {
    for ( int row = 0; row < ROWS; row++ ) {
        for ( int col = 0; col < COLS; col++ ) {
            out << layout.matrix[row][col];
        }
    }

    return out;
}
