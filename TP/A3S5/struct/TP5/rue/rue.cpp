//TP5
//Victor Bouvier d'Acher
//Arezki Mohamed Meriane

#include <iostream>
#include <list>
#include <iterator>
#include "rue.h"
using namespace std;

int main()
{
	list<int> rue;
	rue.push_back(401);
	rue.push_back(402);
	rue.push_back(403);
	rue.push_back(405);
	rue.push_back(406);
	int choix=-1;
	bool continuer=true;
	do
	{
		affichage();
		cin >> choix;
		switch(choix)
		{
			case 0:
				affichage_rue(rue);
				break;
			case 1:
				rue = ajouter_maison(rue);
				break;
			case 2:
				rue = supprimer_maison(rue);
				break;
			case 3:
				rechercher_maison(rue);
				break;
			case 4:
				continuer = false;
				break;
		}
	}while(continuer);
	return 0;
}