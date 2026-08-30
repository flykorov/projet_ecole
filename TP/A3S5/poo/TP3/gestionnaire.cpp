// TP3
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <typeinfo>
#include "gestionnaire.h"
using namespace std;

Gestionnaire::Gestionnaire()
{

}

Gestionnaire::~Gestionnaire()
{
	deleteConcepteur();
	deleteDesigner();
}

void Gestionnaire::ajouterConcepteur(Concepteur* con)
{
	unsigned long int i;
	bool verif = true;
	for(i=0; i<gestion.size(); i++)
		if(*gestion[i] == *con)
			verif = false;
	if(verif)
		gestion.push_back(con);
}

void Gestionnaire::ajouterDesigner(Designer* des)
{
	unsigned long int i;
	bool verif = true;
	for(i=0; i<gestion.size(); i++)
	{
		if(*gestion[i] == *des)
		{
			verif = false;
		}
	}
	if(verif)
		gestion.push_back(des);
}

void Gestionnaire::deleteConcepteur()
{
	if(gestion.empty() == 1)
		return;
	vector<Programmeur*>::iterator it;
	for(it=gestion.begin(); it!=gestion.end(); it++)
	{
		Concepteur* temp = dynamic_cast<Concepteur*>(*it);
		// const type_info& t = typeid(temp);
		// cout << t.name() << endl;
		if(temp != nullptr)
		{
			delete temp;
			gestion.erase(it);
			// cout << "not null\n";
			if(gestion.empty() == 1)
				return;
			else
				it--;
		}
	}
}

void Gestionnaire::deleteDesigner()
{
	if(gestion.empty() == 1)	// verifie si le vecteur est vide ou non
		return;
	vector<Programmeur*>::iterator it;
	for(it=gestion.begin(); it!=gestion.end(); it++)		// parcours tout le vecteur
	{
		Designer* temp = dynamic_cast<Designer*>(*it);		// prend le type Designer
		// const type_info& t = typeid(temp);
		// cout << t.name() << endl;
		if(temp != nullptr)		// verifie si il existe
		{	
			delete temp;			// le desaloue
			gestion.erase(it);		// le supprime du vecteur 
			// cout << "not null\n";
			if(gestion.empty() == 1)	// verifie si le vecteur est vide
				return;
			else
				it--;					// revient en arriere pour pouvoir supprimer les suivants
		}
	}
}

void Gestionnaire::afficherConcepteur(int nbPro)
{
	unsigned long int i;
	for(i=0; i<gestion.size(); i++)
	{
		Concepteur* temp = dynamic_cast<Concepteur*>(gestion[i]);
		if(temp != nullptr)
		{
			if(temp->getProjet() == nbPro)		// si le concepteur a le meme projet l'affiche
			{
				gestion[i]->affiche();
				gestion[i]->calculSalaire();
				cout << endl;
			}
		}
	}
}

void Gestionnaire::afficherDesigner(string ty)
{
	unsigned long int i;
	for(i=0; i<gestion.size(); i++)
	{
		Designer* temp = dynamic_cast<Designer*>(gestion[i]);
		if(temp != nullptr)
		{
			if(temp->getType() == ty)			// si le designer a le meme type l'affiche
			{
				gestion[i]->affiche();
				gestion[i]->calculSalaire();
				cout << endl;
			}
		}
	}
}
