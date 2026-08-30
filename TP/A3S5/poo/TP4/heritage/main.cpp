#include <iostream>
#include <vector>
#include <cmath>
#include "cercle.h"
#include "rectangle.h"
#include "dataset.h"
using namespace std;

int main()
{
	Point* p1 = new Point(2, 4);	// cree des points
	Point* p2 = new Point(6, 4);
	Point* p3 = new Point(2, 9); 
	Point* p4 = new Point(6, 9);
	Point* p5 = new Point(2, 4);
	Point* p6 = new Point(6, 9);
	Dataset* d = new Dataset();		// cree le dataset
	Rectangle* rect = new Rectangle(p1, p3, p2, p4, 10, true);	// cree le rectangle
	Cercle* c = new Cercle(p5, 10, 2, false);	// cree le cercle

	d->ajouterData(rect);	// l'ajoute a dataset
	d->ajouterData(c);
	d->printData();			// affiche les rectangle et cercle

	delete p1;	// supprime les point 
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
	delete d;	// supprime le dataset
	return 0;
}