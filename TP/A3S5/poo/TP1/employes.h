#ifndef EMPLOYES_H
#define EMPLOYES_H

#include "concepteur.h"
#include "programmeur.h"
#include "specialite.h"

class Employes
{
public:
	Employes();
	~Employes();

	void ajouterProgrammeur(Programmeur& pro);
	void ajouterConcepteur(Concepteur& con);

	void afficherConcepteur();
	void afficherProgrammeur();

	void afficher();

	int getCompteurConc();
	int getCompteurProg();

	void setCompteurConc(int com);
	void setCompteurProg(int com);

	void changer_concepteur(int i, int exp, string p, string n, string name_spe, int lvl);
	void changer_programmeur(int i, string p, string n, bool senior);

private:
	int compteurConcept = 0;
	int compteurProg = 0;

	Concepteur* concepteur;
	Programmeur* programmeur;

};

#endif