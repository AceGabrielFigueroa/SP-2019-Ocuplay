#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H
#include "checkerboard.h"

class Quadrilateral : public CheckerBoard
{
Quadrilateral(); // Default constructor
Quadrilateral(int width, int height, int columns, int rows, bool randomSquare = false);

~Quadrilateral(); // Destructor

void Draw();
void Fill(int row, int col, int wid, int hgt);
int  xValue(int x1, int y1, int x2, int y2, int y);
void FillLine(int xleft, int xright, int wid, int row, int col, bool outer);
};

#endif // QUADRILATERAL_H
