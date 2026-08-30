#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <vector>
#include <string>
#include "programmeur.h"
#include "designer.h"
#include "concepteur.h"
using namespace std;

class Gestionnaire
{
public:
	Gestionnaire();
	~Gestionnaire();

	void ajouterConcepteur(Concepteur* con);
	void ajouterDesigner(Designer* des);

	void deleteConcepteur();
	void deleteDesigner();

	vector<Programmeur*> getGestion() { return gestion; }

	void afficherConcepteur(int nbPro);
	void afficherDesigner(string ty);

private:
	vector<Programmeur*> gestion;
	
};

#endif