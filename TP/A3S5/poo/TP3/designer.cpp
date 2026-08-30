// TP3
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <string>
#include "designer.h"
using namespace std;

Designer::Designer() : Programmeur()
{
	type = "Not Define";
	diplome = false;
}

Designer::Designer(int soc, int age, string n, string p, int an, double s, string t, bool d) : Programmeur(soc, age, n, p, an, s)
{
	type = t;
	diplome = d;
}

Designer::Designer(const Designer& des) : Programmeur(des)
{
	type = des.getType();
	diplome = des.getDiplome();
}

Designer::~Designer()
{

}

void Designer::setType(string t){ type = t; }
void Designer::setDiplome(int d){ diplome = d; }

string Designer::getType() const { return type; }
bool Designer::getDiplome() const { return diplome; }

void Designer::affiche() const
{
	cout << "Designer : ";
	Programmeur::affiche();			// utilise la fonction affiche de la classe programmeur
	cout << "Diplome : " << diplome << endl;
	cout << "Type : " << type << endl;

}

double Designer::calculSalaire()
{
	double anc = getAncien() * 5;
	double sal = getSalaire() * (anc/100) + getSalaire();
	cout << "Salaire du designer " << getPrenom() << " " << getNom() << " : " << sal << endl;
	return sal;
}

Designer& Designer::operator=(const Designer& add)
{
	if(this == &add)
		return *this;

	setAge(add.getAge());
	setAncien(add.getAncien());
	setNom(add.getNom());
	setPrenom(add.getPrenom());
	setSalaire(add.getSalaire());
	setSocial(add.getSocial());

	type = add.getType();
	diplome = add.getDiplome();

	return *this;
}

bool Designer::operator==(const Designer& comp)
{
	if(this == &comp)
		return true;
	if(getSocial() == comp.getSocial())
		return true;
	else
		return false;
}