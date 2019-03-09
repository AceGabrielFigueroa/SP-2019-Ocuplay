#pragma once

class BooleanBitmap
{
public:
	BooleanBitmap();
	//BooleanBitmap(int width, int height);
	~BooleanBitmap();
    BooleanBitmap(BooleanBitmap* chb1, BooleanBitmap* chb2, bool _xor);

    bool GetAt(int row, int col);
    void SetAt(int row, int col, bool value);
	void Construct(int width, int height);
	void Show();
	void Copy(BooleanBitmap* fromBM, BooleanBitmap* toBM, int fromX, int fromY, int toX, int toY, int wid, int hgt);
	void Copy(BooleanBitmap* fromBM, int fromX, int fromY, int toX, int toY, int wid, int hgt);
	void RotateCounter(BooleanBitmap* fromBM, int fromX, int fromY, int toX, int toY, int size);
	void FlipVert(BooleanBitmap* fromBM, int fromX, int fromY, int toX, int toY, int wid, int hgt);
	void FlipHoriz(BooleanBitmap* fromBM, int fromX, int fromY, int toX, int toY, int wid, int hgt);

private:

protected:
    bool *m_board;
	int m_widthPixels;
	int m_heightPixels;
};

