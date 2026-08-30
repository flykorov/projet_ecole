#ifndef DATA_H
#define DATA_H

using namespace std;

class Data
{
public:
	Data() : xx(0), yy(0) {}

	int getX() { return xx; }
	int getY() { return yy; }

	void setX(int x) { xx = x; }
	void setY(int y) { yy = y; }
	
	virtual double calculerAire() = 0;
	virtual double calculerPerimetre() = 0;

private:
	int xx;
	int yy;

};

#endif