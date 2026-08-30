#include <iostream>
#include <cmath>
#include "cercle.h"
using namespace std;

#define PI 3.14159

Cercle::Cercle(Point* c, float r, int e, bool re) : rayon(r)
{
	centre = new Point(c->getX(), c->getY());	// cree un nouveau point a partir des parametre
	epaisseur =e;
	rempli = re;
}

Cercle::~Cercle()
{
	delete centre;
}

double Cercle::calculerAire()
{
	return PI * pow(rayon, 2); 	// aire cercle : PI * rayon^2
}

double Cercle::calculerPerimetre()
{
	return 2 * PI * rayon;		// perimetre cercle : 2 * PI * rayon
}

void Cercle::affiche()
{
	cout << "rayon : " << rayon << endl;	// affiche le rayon du cercle
	// cout << "centre x : " << centre->getX() << endl;
	// cout << "centre y : " << centre->getY() << endl;
	cout << "point centre :\n"; 		
	centre->affiche();					// affiche le centre du cercle
	cout << "perimetre : " << calculerPerimetre() << endl;		// affiche le perimetre du cercle
	cout << "aire : " << calculerAire() << endl;				// affiche l'aire du cercle
	cout << "epaisseur : " << epaisseur << endl;
	cout << "rempli : " << rempli << endl;
	cout << endl;

}