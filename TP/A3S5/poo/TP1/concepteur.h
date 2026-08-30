#ifndef CONCEPTEUR_H
#define CONCEPTEUR_H

#include "specialite.h"
using namespace std;

class Concepteur
{
public:
	Concepteur();
	Concepteur(string p, string n, int exp, string spe, int lvl);
	~Concepteur();

	string getPrenom();
	string getNom();
	int getAnneeExp();
	Specialite getSpe();

	void setName(string p, string n);
	void setExp(int exp);
	void setSpe(string spe, int lvl);
	void setSpecialite(Specialite spe);

	Concepteur* ajout(Concepteur* concepteur, int compteurConcept);

private:
	string prenom = "not define";
	string nom = "not define";
	int annee_d_experience = 0;
	Specialite specialite;

};

#endif