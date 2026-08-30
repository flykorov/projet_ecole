#include <iostream>
#include <cmath>
#include "point.h"
using namespace std;

Point::Point()
{
	xx = 0;
	yy = 0;
}

float Point::distance(Point & p)
{
	double x = abs(xx - yy);				// calcul la position du x
	double y = abs(p.getX() - p.getY());	// calcul la postion du y

	double res = pow(x, 2) + pow(y, 2);	// effectue le theoreme de pythagore
	res = sqrt(res);					// effectue la racine de pythagore
	return res; 
}

void Point::affiche()
{
	cout << "coordonee de x : " << xx << endl;	// affiche la coordonee x du point
	cout << "coordonee de y : " << yy << endl;	// affiche la coordonee y du point
}