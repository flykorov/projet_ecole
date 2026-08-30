#include <iostream>
#include <string>
#include <new>
#include "employes.h"
#include "concepteur.h"
#include "programmeur.h"
#include "specialite.h"
using namespace std;

int main()
{
	int compteurProgrammeur=1, compteurConcepteur=1, i;
	Employes* emp = new Employes();

	Programmeur* pro = new Programmeur("Montacer", "Dridi", false);
	Concepteur* con = new Concepteur("Eric", "Konieczy", 3 , "UX", 4);

	emp->ajouterConcepteur(*con);		// Affecte le tableau de classe Concepteur par reference dans la classe Employees
	emp->afficherConcepteur();

	emp->ajouterProgrammeur(*pro);		// Affecte le tableau de classe Programmeur par reference dans la classe Employees
	emp->afficherProgrammeur();

	emp->afficher();

	pro = pro->ajout(pro, compteurProgrammeur);	// Ajoute une case au tableau de classe Programmeur
	Programmeur* p = new Programmeur("Sylvie", "Zago", false);
	pro[compteurProgrammeur] = *p;				// Affecte le nouveau programmeur a la derniere case du tableau de classe Programmeur
	compteurProgrammeur++;						// Incremente le compteur Programmeur
	delete p;

	pro = pro->ajout(pro, compteurProgrammeur);
	p = new Programmeur("Abdalah", "Gahouti", true);
	pro[compteurProgrammeur] = *p;
	compteurProgrammeur++;
	delete p;


	con = con->ajout(con, compteurConcepteur);	// Ajoute une case au tableau de classe Concepteur
	Concepteur* c = new Concepteur("Amine", "Jaouadi", 1, "Game Design", 1);
	con[compteurConcepteur] = *c;				// Affecte le nouveau programmeur a la derniere case du tableau de classe Concepteur
	compteurConcepteur++;						// Incremente le compteur Concepteur
	delete c;

	con = con->ajout(con, compteurConcepteur);
	c = new Concepteur("Michael", "Francois", 5, "UX", 5);
	con[compteurConcepteur] = *c;
	compteurConcepteur++;
	delete c;

	emp->setCompteurProg(compteurProgrammeur);	// Met a jour le compteur Programmeur dans la classe Employees
	emp->setCompteurConc(compteurConcepteur);	// Met a jour le compteur Concepteur dans la classe Employees
	emp->ajouterProgrammeur(*pro);
	emp->ajouterConcepteur(*con);

	emp->afficher();

	delete emp;
	return 0;
}