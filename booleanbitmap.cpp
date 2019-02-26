#include <assert.h>
#include "booleanbitmap.h"


// Default constructor
BooleanBitMap::BooleanBitMap()
{
    this->m_board = nullptr;
    m_widthPixels = 0;
    m_heightPixels = 0;
}

// Destructor
BooleanBitMap::~BooleanBitMap()
{
    if (m_board != nullptr)
        delete[] m_board;

}

// Constructor with three parameters
// Combines two checkerboards
BooleanBitMap::BooleanBitMap(BooleanBitMap* chb1, BooleanBitMap* chb2, bool exOR)
{
    //assert(chb1->m_widthPixels == chb2->m_widthPixels && chb1->m_heightPixels == chb2->m_heightPixels);
    // Replace with a try and catch statement???

    construct(chb1->m_widthPixels, chb1->m_heightPixels);

    for (auto row = 0; row < m_heightPixels; row++) {
        for (auto col = 0; col < m_widthPixels; col++)
        {
            bool pixelValue = chb1->getAt(row, col); // replaced boolean with bool - Ryan

            if (exOR)
                pixelValue ^= chb2->getAt(row, col); // ^ is ExclusiveOr Op
            else
                pixelValue |= chb2->getAt(row, col); // | is Or Op

            // Sets pixel value to [col][row]
            setAt(row, col, pixelValue);
        }
    }
}

// This function is primarily used to set the dimensions of the bitmap object, primarily the width and height protected properties and uses those to construct a width * height board
void BooleanBitMap::construct(int width, int height)
{
    // Delete if theres an existing m_boards
    if(m_board)
        delete[] m_board;

    m_widthPixels = width; //
    m_heightPixels = height; //

    m_board = new bool[m_widthPixels * m_heightPixels]; //

    // DEBUG FOR TESTING CAPACITY
    for(int i = 0; i < height ; i++)
        for(int j = 0; j < width; j++)
            this->setAt(i, j, rand() % 2);
}

// getter function for Boolean bitmap
bool BooleanBitMap::getAt(int row, int col)
{
    // suggestion: build try catch statements to catch if these conditions
    // row >= 0 && row < m_heightPixels;
    // col >= 0 && col < m_widthPixels;

    return m_board[row * m_widthPixels + col];
}

// setter function for Boolean bitmap
void BooleanBitMap::setAt(int row, int col, bool value)
{
    // suggestion: build try catch statements to catch if these conditions
    // row >= 0 && row < m_heightPixels;
    // col >= 0 && col < m_widthPixels;

    m_board[row * m_widthPixels + col] = value;
}

// copy one bitmap to another bitmap
void BooleanBitMap::copy(BooleanBitMap* fromBM, BooleanBitMap* toBM,
    int fromCol, int fromRow, int toCol, int toRow, int wid, int hgt)
{
    // suggestion: build try catch statements to catch for these conditions
    //fromCol + wid <= fromBM->m_widthPixelsBM
    //toCol + wid <= toBM->m_widthPixels
    //fromRow + hgt <= fromBM->m_heightPixels
    //toRow + hgt <= toBM->m_heightPixels
    for (auto col = 0; col < wid; col++)
    {
        int toCol_c = toCol + col;
        int fromCol_c = fromCol + col;
        for (auto row = 0; row < hgt; row++)
            //orig toBM->SetAt(toCol_c, toRow + row, fromBM->GetAt(fromCol_c, fromRow + row));
            toBM->setAt(toRow + row, toCol_c, fromBM->getAt(fromRow + row, fromCol_c));
    }
}


//
void BooleanBitMap::copy(BooleanBitMap* fromBM, int fromCol, int fromRow, int toCol, int toRow, int wid, int hgt)
{
    copy(fromBM, this, fromCol, fromRow, toCol, toRow, wid, hgt);
}


//
void BooleanBitMap::rotateCounter(BooleanBitMap* fromBM, int fromCol, int fromRow, int toCol, int toRow, int size)
{
    {
        // suggestion: build try catch statements to catch for these conditions

        // fromCol + size <= fromBM->m_widthPixels
        // toCol + size <= m_heightPixels
        // fromRow + size <= fromBM->m_heightPixels
        // toRow + size <= m_widthPixels
        for (auto col = 0; col < size; col++)
        {
            int toCol_c = toCol + col;
            int fromCol_c = fromCol + col;
            for (auto row = 0; row < size; row++)
            {
                //char buffer[200];
                int fromRow_r = fromRow + row;
                int toRow_r = toRow + row;
                bool fromVal = fromBM->getAt(fromRow_r, size - 1 - fromCol_c); // changed boolean to bool
                //sprintf_s(buffer, "From (%d, %d)   To (%d, %d)  Value %c\n",
                //	fromRow_r, size - 1 - fromCol_c, toCol_c, toRow_r, fromVal? '*' :'.');
                //OutputDebugStringA(buffer);
                //SetAt(toCol_c, toRow + row, fromBM->GetAt(fromRow + row, size - 1 - (fromRow + row)));
                setAt(toRow_r, toCol_c, fromBM->getAt(fromRow_r, size - 1 - fromCol_c));
            }
        }
    }
}

//Flip on Vertical Axis: Row is the same -- Col changes
//AB   becomes  BA
//CD            DC
void BooleanBitMap::flipVert(BooleanBitMap* fromBM, int fromCol, int fromRow, int toCol, int toRow, int wid, int hgt)
{

    // suggestion: build try catch statements to catch for these conditions

    // fromCol + wid <= fromBM->m_widthPixels
    // toCol + wid <= m_widthPixels
    // fromRow + hgt <= fromBM->m_heightPixels
    // toRow + hgt <= m_heightPixels

    for (auto col = 0; col < wid; col++)
    {
        int fromCol_c = fromCol + col;
        int toCol_c = toCol + (wid - 1 - col);
        for (auto row = 0; row < hgt; row++)
        {
            // suggestion: build try catch statements to catch for these conditions
            // boolean v = fromBM->GetAt(wid - 1 - fromCol_c, fromRow + row);
            // SetAt(toCol_c, toRow + row, v );
            // boolean v = fromBM->GetAt(fromCol_c, fromRow + row);
            // SetAt(toCol_c, toRow + row, v);
            bool v = fromBM->getAt(fromRow + row, fromCol_c);
            setAt(toRow + row, toCol_c, v);
        }
    }
}

/*************************
 Flip on Horizontal Axis: Col is the same -- Row changes
 AB   becomes  CD
/CD            AB
**************************/
void BooleanBitMap::flipHoriz(BooleanBitMap* fromBM,
    int fromCol, int fromRow, int toCol, int toRow, int wid, int hgt)
{
    // suggestion: build try catch statements to catch for these conditions

    // fromCol + wid <= fromBM->m_widthPixels
    // toCol + wid <= m_widthPixels
    // fromRow + hgt <= fromBM->m_heightPixels
    // toRow + hgt <= m_heightPixels
    for (auto col = 0; col < wid; col++)
    {
        int fromCol_c = fromCol + col;
        int toCol_c = toCol + col;
        for (auto row = 0; row < hgt; row++)
        {
            //boolean v = fromBM->GetAt(fromCol_c, hgt - 1 - fromRow - row);
            //SetAt(toCol_c, toRow + row, v );
            bool v = fromBM->getAt(fromRow + row, fromCol_c);
            setAt(toRow + (hgt - 1 - row), toCol_c, v);
        }
    }
}


void BooleanBitMap::show()
{
    /**
    char bufr[200];
//#define Ou OutputDebugStringA
//#define CH(c) sprintf_s(bufr, "%c", c);
//#define NL() CH('\n');

        CH('-');
        //sprintf_s(bufr, "\nRows %d  Cols %2d\n", m_heightPixels, m_widthPixels);
        for (auto row = 0; row < m_heightPixels; row++) {
            for (auto col = 0; col < m_widthPixels; col++) {
                CH(getAt(row, col) ? '*' : '.'); Ou(bufr);
            }
            NL(); Ou(bufr);
        }
        CH('-');
        NL();
        **/
}

// returns real (0.0, n) ie open interval.
//
double  BooleanBitMap::drand(int n)
{
    //return (double)(rand() % n) / (double)n;
    return 0;
}

// returns int 0 to n-1
int BooleanBitMap::irand(int n)
{
    return rand() % n;
}

// returns int lo to hi inlusive both ends [lo, hi]
int BooleanBitMap::irand(int lo, int hi)
{
    //return lo + rand() % (hi - lo + 1);
}
