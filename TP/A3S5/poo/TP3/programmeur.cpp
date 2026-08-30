// TP3
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <string>
#include "programmeur.h"
using namespace std;

Programmeur::Programmeur()
{
	num_ass_social = 0;
	nom = "Not Define";
	prenom = "Not Define";
	age = 0;
	salaire = 0;
	ancien = 0;
}

Programmeur::Programmeur(int soc, int a, string n, string p, int an, double s)
{
	num_ass_social = soc;
	nom = n;
	prenom = p;
	age = a;
	salaire = s;
	ancien = an;
}

Programmeur::Programmeur(const Programmeur& pro)
{
	num_ass_social = pro.getSocial();
	nom = pro.getNom();
	prenom = pro.getPrenom();
	age = pro.getAge();
	salaire = pro.getSalaire();
	ancien = pro.getAncien();
}

Programmeur::~Programmeur()
{

}

void Programmeur::setSocial(int soc){ num_ass_social = soc; }
void Programmeur::setNom(string n) { nom = n; }
void Programmeur::setPrenom(string p){ prenom = p; }
void Programmeur::setAge(int a){ age = a; }
void Programmeur::setSalaire(double s){ salaire = s; }
void Programmeur::setAncien(int a){ ancien = a; }

int Programmeur::getSocial() const { return num_ass_social; }
string Programmeur::getNom() const { return nom; }
string Programmeur::getPrenom() const { return prenom; }
int Programmeur::getAge() const { return age; }
double Programmeur::getSalaire() const { return salaire; }
int Programmeur::getAncien() const { return ancien; }

void Programmeur::affiche() const
{
	cout << getPrenom() << " " << getNom() << endl;
	cout << "Age : " << getAge() << endl;
	cout << "Salaire : " << getSalaire() << endl;
	cout << "Ancienete : " << getAncien() << endl;
	cout << "Numero d'assurance social : " << getSocial() << endl;
}
double Programmeur::calculSalaire()
{
	return salaire;
}

Programmeur& Programmeur::operator=(const Programmeur& add)
{
	if(this == &add)
		return *this;

	num_ass_social = add.getSocial();
	nom = add.getNom();
	prenom = add.getPrenom();
	age = add.getAge();
	salaire = add.getSalaire();
	ancien = add.getAncien();

	return *this;
}

bool Programmeur::operator==(const Programmeur& comp)
{
	if(this == &comp)
		return true;
	if(num_ass_social == comp.getSocial())
		return true;
	else
		return false;
}
