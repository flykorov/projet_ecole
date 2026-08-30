#ifndef POINT_H
#define POINT_H 

class Point
{
public:
	Point();
	Point(int x, int y) : xx(x), yy(y) {}

	int getX() { return xx; }
	int getY() { return yy; }

	void setX(int x) { xx = x; }
	void setY(int y) { yy = y; }

	float distance(Point & p);

	void affiche();

private:
	double xx;
	double yy;	
};

#endif