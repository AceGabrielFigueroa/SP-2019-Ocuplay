#include "checkerboard.h"
#include <QDebug>
#include <QTime>


// Must be a multiple 32
static const int MAX_PIXEL_WIDTH = 1024;
static const int MAX_PIXEL_HEIGHT = 1024;

CheckerBoard::CheckerBoard() {

}

CheckerBoard::CheckerBoard(int width, int height, int col, int row, bool randomSquare) {
    qDebug() << '[' << QTime::currentTime().toString() << ']' << "Created CheckerBoard.";

    construct(width, height, col, row);

    m_random = randomSquare;
    draw();
}

// To be implemented
CheckerBoard::CheckerBoard(CheckerBoard* chb1, CheckerBoard* chb2, bool exOr) {

}

CheckerBoard::~CheckerBoard() {

}

// Unfinished, Waiting for ryan
void CheckerBoard::construct(int width, int height, int col, int row) {
    m_column = col;
    m_row = row;

    //BooleanBitMap::construct(width, height);
}

// Unfinished, Waiting for RYAN
void CheckerBoard::fill(int width, int height, int col, int row) {
    bool pixelValue;

    int pixRow = 0;
    int pixCol = 0;

    if(m_random) {
        pixelValue = (rand()) % 2;
    }
    else {
        pixelValue = ((row + col) % 2 == 0);
    }

    // Test Case
    qDebug() << '[' << QTime::currentTime().toString() << ']' << "Fill returned: " << pixelValue;
}

void CheckerBoard::draw() {

}
