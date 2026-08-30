#include <iostream>
#include <string>
#include "concepteur.h"
using namespace std;

Concepteur::Concepteur()
{
	prenom = "not define";
	nom = "not define";
	annee_d_experience = 0;
}

Concepteur::Concepteur(string p, string n, int exp, string spe, int lvl)
{
	prenom = p;
	nom = n;
	annee_d_experience = exp;
	specialite.setSpe(spe);
	specialite.setLevelSpe(lvl);
}

Concepteur::~Concepteur()
{

}

string Concepteur::getPrenom()
{
	return prenom;
}

string Concepteur::getNom()
{
	return nom;
}

int Concepteur::getAnneeExp()
{
	return annee_d_experience;
}

Specialite Concepteur::getSpe()
{
	return specialite;
}

void Concepteur::setName(string p, string n)
{
	prenom = p;
	nom = n;
}

void Concepteur::setExp(int exp)
{
	annee_d_experience = exp;
}

void Concepteur::setSpe(string spe, int lvl)
{
	specialite.setLevelSpe(lvl);
	specialite.setSpe(spe);
}

void Concepteur::setSpecialite(Specialite spe)
{
	specialite = spe;
}

Concepteur* Concepteur::ajout(Concepteur* concepteur, int compteurConcept)
{
	int i;
	Concepteur* con = new Concepteur[compteurConcept+1];
	for(i=0; i<compteurConcept; i++)
	{
		con[i] = concepteur[i];	// Copie l'ancien tableau dans le nouveau
	}
	if(compteurConcept == 1)	// delete l'ancien tableau
		delete concepteur;
	else
		delete[] concepteur;
	concepteur = con;			// Met a jour le tableau de classe
	return concepteur;
}