#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "data.h"
#include "print.h"
#include "point.h"

class Rectangle : public Print, public Data
{
public:
	Rectangle();
	Rectangle(Point* tl, Point* br);
	Rectangle(Point* tl, Point* tr, Point* bl, Point* br, int e, bool r);/* : topLeft(tl), topRight(tr), backLeft(bl), backRight(br) {}*/
	~Rectangle();

	double getLargeur();
	double getLongueur();

	double calculerAire();
	double calculerPerimetre();

	void affiche();

private:
	Point* topLeft;
	Point* topRight;
	Point* backLeft;
	Point* backRight;
	
};

#endif