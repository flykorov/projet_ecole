#include <iostream>
#include <cmath>
#include "rectangle.h"
using namespace std;

Rectangle::Rectangle()
{

}

Rectangle::Rectangle(Point* tl, Point* tr, Point* bl, Point* br, int e, bool r) 
{
	topLeft = new Point(tl->getX(), tl->getY());		// cree de nouveau point a partir des paramatre
	topRight = new Point(tr->getX(), tr->getY());
	backLeft = new Point(bl->getX(), bl->getY());
	backRight = new Point(br->getX(), br->getY());
	rempli = r;
	epaisseur = e;
}
// : topLeft(tl), topRight(tr), backLeft(bl), backRight(br) {}
Rectangle::~Rectangle()
{
	delete topRight;
	delete topLeft;
	delete backRight;
	delete backLeft;
}


Rectangle::Rectangle(Point* tl, Point* br) : topLeft(tl), backRight(br)
{

	backLeft = new Point(backRight->getX(), topLeft->getY());
	// backLeft->setY(topLeft->getY());
	// backLeft->setX(backRight->getX());

	topRight = new Point(topLeft->getX(), backRight->getY());

	// topRight->setX(topLeft->getX());
	// topRight->setY(backRight->getY());
}

double Rectangle::getLongueur()
{
	return abs(topLeft->getX() - backRight->getX());	// valeur absolue de la longueur
}

double Rectangle::getLargeur()
{
	return abs(topLeft->getY() - backRight->getY());
}

double Rectangle::calculerAire()
{
	return getLongueur() * getLargeur();	// aire rectangle : longueur * largeur
}

double Rectangle::calculerPerimetre()
{
	return getLongueur()*2 + getLargeur()*2;	// perimetre rectangle : 2 * longueur + 2 * largeur
}

void Rectangle::affiche()
{
	cout << "point topLeft :\n";		// affiche les 4 points du rectangle
	topLeft->affiche();
	cout << "point backLeft :\n";
	backLeft->affiche(); 
	cout << "point topRight :\n";
	topRight->affiche(); 
	cout << "point backRight :\n";
	backRight->affiche(); 
	cout << "longueur : " << getLongueur() << endl;		// affiche la longueur du rectangle 
	cout << "largeur : " << getLargeur() << endl;		// affiche la largeur du rectangle
	cout << "perimetre : " << calculerPerimetre() << endl;	// affiche le perimetre du rectangle
	cout << "aire : " << calculerAire() << endl;		// affiche l'aire du rectangle
	cout << "epaisseur : " << epaisseur << endl;
	cout << "rempli : " << rempli << endl;
	cout << endl;
}