#ifndef CERCLE_H
#define CERCLE_H

#include "point.h"
#include "print.h"
#include "data.h"

class Cercle : public Print, public Data
{
public:
	Cercle(Point* c, float r, int e, bool re);/* : centre(c), rayon(r) {}*/
	~Cercle();

	double calculerAire();
	double calculerPerimetre();

	void affiche();

private:
	Point* centre;
	double rayon;
	
};

#endif