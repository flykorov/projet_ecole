// TP3
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <string>
#include "concepteur.h"
using namespace std;

Concepteur::Concepteur() : Programmeur()
{
	nbProjet = 0;
}

Concepteur::Concepteur(int soc, int age, string n, string p, int an, double s, int pro) : Programmeur(soc, age, n, p, an, s)
{
	nbProjet = pro;
}

Concepteur::Concepteur(const Concepteur& con) : Programmeur(con)
{
	nbProjet = con.getProjet();
}

Concepteur::~Concepteur()
{

}

void Concepteur::setProjet(int p){ nbProjet = p; }

int Concepteur::getProjet() const { return nbProjet; }

void Concepteur::affiche() const
{
	cout << "Concepteur : ";
	Programmeur::affiche();			// appelle la fonction affiche de ka classe programmeur
	cout << "Nombre de projet : " << nbProjet << endl;

}

double Concepteur::calculSalaire()
{
	double anc = getAncien() * 8;
	double temp = anc/100;
	double sal = getSalaire() * temp + getSalaire();
	cout << "Salaire du concepteur " << getPrenom() << " " << getNom() << " : " << sal << endl;
	return sal;
}

Concepteur& Concepteur::operator=(const Concepteur& add)
{
	if(this == &add)
		return *this;

	setAge(add.getAge());
	setAncien(add.getAncien());
	setNom(add.getNom());
	setPrenom(add.getPrenom());
	setSalaire(add.getSalaire());
	setSocial(add.getSocial());

	nbProjet = add.getProjet();

	return *this;
}

bool Concepteur::operator==(const Concepteur& comp)
{
	if(this == &comp)
		return true;
	if(getSocial() == comp.getSocial())			// verifie le numero d'assurance
		return true;
	else
		return false;
}