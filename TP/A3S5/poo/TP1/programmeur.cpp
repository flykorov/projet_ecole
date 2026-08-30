#include <iostream>
#include <string>
#include "programmeur.h"
using namespace std;

Programmeur::Programmeur()
{
	characteristique = 0;
	nom = "not define";
	prenom = "not define";	
}

Programmeur::~Programmeur()
{
	
}

string Programmeur::getPrenom()
{
	return prenom;
}

string Programmeur::getNom()
{
	return nom;
}

bool Programmeur::getChar()
{
	return characteristique;
}

void Programmeur::setChar(bool c)
{
	characteristique = c;
}

void Programmeur::setName(string p, string n)
{
	prenom = p;
	nom = n;
}

Programmeur* Programmeur::ajout(Programmeur* programmeur, int compteurProg)
{
	int i;
	compteurProg;
	Programmeur* pro = new Programmeur[compteurProg+1];
	for(i=0; i<compteurProg; i++)
	{
		pro[i] = programmeur[i];	// Copie l'ancien tableau dans le nouveau
	}
	if(compteurProg == 1)			// delete l'ancien tableau
		delete programmeur;
	else
		delete[] programmeur;
	programmeur = pro;				// Met a jour le tableau de classe
	return programmeur;
}