#ifndef CHECKERBOARD_H
#define CHECKERBOARD_H

#include "BooleanBitMap.h"

class CheckerBoard : public BooleanBitMap
{
public:
    CheckerBoard();
    CheckerBoard(int width, int height, int col, int row, bool randomSquare = false);

    CheckerBoard(CheckerBoard* chb1, CheckerBoard* chb2, bool exOr = false);

    ~CheckerBoard();

    void construct(int width, int height, int col, int row);
    void fill(int width, int height, int col, int row);

    void draw();

    // Must be a multiple 32
    static const int MAX_PIXEL_WIDTH;
    static const int MAX_PIXEL_HEIGHT;

protected:
    int m_column;
    int m_row;

    bool m_random;
};

#endif // CHECKERBOARD_H
