#include <iostream>
#include <string>
#include <new>
#include "employes.h"
using namespace std;

Employes::Employes()
{
	compteurConcept = 1;
	compteurProg = 1;
	concepteur = NULL;
	programmeur = NULL;
}

Employes::~Employes()
{
	if(compteurConcept == 1)	// En fonction du compteur on libere une case ou tout le tableau de classe
	{
		delete concepteur;
		if(compteurProg == 1)
			delete programmeur;
		else
			delete[] programmeur;
	}else
	{
		delete[] concepteur;
		if(compteurProg == 1)
			delete programmeur;
		else
			delete[] programmeur;
	}
}

void Employes::ajouterProgrammeur(Programmeur& pro)
{
	programmeur = &pro;
}

void Employes::ajouterConcepteur(Concepteur& con)
{
	concepteur = &con;
}

void Employes::afficherConcepteur()
{
	cout << "\n\nAffichage des " << compteurConcept << " concepteur\n";
	int i;
	for(i=0; i<compteurConcept; i++)
	{
		cout << i+1 << " :\n";
		cout << concepteur[i].getPrenom() << " " << concepteur[i].getNom() << endl;
		cout << concepteur[i].getAnneeExp() << " annee d'experience\n";
		Specialite spe = concepteur[i].getSpe();	// recupere la classe specialite pour pouvoir l'afficher
		cout << "Specialite : " << spe.getSpe() << endl;
		cout << "Niveau de Specialite : " << spe.getLevelSpe() << endl;
	
	}
	cout << endl;
}
	
void Employes::afficherProgrammeur()
{
	cout << "\n\nAffichage des " << compteurProg << " programmeur\n";
	int i;
	for(i=0; i<compteurProg; i++)
	{
		cout << i+1 << " :\n";
		cout << programmeur[i].getPrenom() << " " << programmeur[i].getNom() << endl;
		if(programmeur[i].getChar())
			cout << "senior\n";
		else
			cout << "junior\n";
	}
	cout << endl;
}

void Employes::afficher()
{
	cout << "\n\n\nAffichage des Employees\n";
	afficherConcepteur();
	afficherProgrammeur();
}

int Employes::getCompteurConc()
{
	return compteurConcept;
}

int Employes::getCompteurProg()
{
	return compteurProg;
}

void Employes::setCompteurConc(int com)
{
	compteurConcept = com;
}

void Employes::setCompteurProg(int com)
{
	compteurProg = com;
}

void Employes::changer_concepteur(int i, int exp, string p, string n, string name_spe, int lvl)
{
	concepteur[i].setName(p, n);
	concepteur[i].setExp(exp);
	Specialite spe = concepteur[i].getSpe();
	spe.setSpe(name_spe);
	spe.setLevelSpe(lvl);
}

void Employes::changer_programmeur(int i, string p, string n, bool senior)
{
	programmeur[i].setName(p, n);
	programmeur[i].setChar(senior);
}