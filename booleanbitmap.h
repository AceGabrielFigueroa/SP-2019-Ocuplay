#pragma once

class BooleanBitMap {

public:
    BooleanBitMap();  // default constructor
    ~BooleanBitMap(); // destructor
    BooleanBitMap( BooleanBitMap* chb1, BooleanBitMap* chb2, bool exOR); // replaced boolean xor for bool xor for 3rd parameter

    int irand(int n); //
    int irand(int lo, int hi); //

    bool getAt(int row, int col); // changed function return type from boolean to char *****

    double drand(int n); //

    void setAt(int row, int col, bool value); // changed boolean data type in 3rd parameter to bool data type
    void construct(int width, int height); // Sets size of boolean bit map
    void copy(BooleanBitMap* fromBM, BooleanBitMap* toBM, int fromX, int fromY, int toX, int toY, int wid, int hgt); //
    void copy(BooleanBitMap* fromBM, int fromX, int fromY, int toX, int toY, int wid, int hgt); //
    void rotateCounter(BooleanBitMap* fromBM, int fromX, int fromY, int toX, int toY, int size); //
    void flipVert(BooleanBitMap* fromBM, int fromX, int fromY, int toX, int toY, int wid, int hgt); //
    void flipHoriz(BooleanBitMap* fromBM, int fromX, int fromY, int toX, int toY, int wid, int hgt); //
    void show(); //

private:

protected:
    bool *m_board; //
    int m_widthPixels; //
    int m_heightPixels; //

};

