//TP2
//Victor Bouvier d'Acher

#include <iostream>
#include <cstring>
#include <unistd.h>
#include "thermostat.h"
using namespace std;

template <class T>
void afficher(T obj)	//fonction template
{
	cout << obj << endl;
}

int main()
{

// partie Thermostat

	Thermostat thermometre;
	bool continuer = true;
	while(continuer)	// pour le thermostat
	{
		// continuer = thermometre.choix(thermometre);
		thermometre.afficher_option();	// 4 choix possible
		int choix;
		cin >> choix;
		switch(choix)	//affectation du choix
		{
			case 0:		// sort du while;
			cout << "ARRET DU THERMOSTAT\n";
			continuer = false;
			break;
			case 1:		// change le mode
			thermometre.definir_mode();
			break;
			case 2:		// ajuste la temperature
			thermometre.ajuster_temperature();
			break;
			case 3:		// affiche le thermostat
			thermometre.afficher_thermostat();
			break;
			default:
			cout << "erreur lors de la prise de la valeur\n";
		}
	}

	sleep(1);

// partie Template

	system("clear");
	cout << "AFFICHER INT : ";
	afficher<int>(100);

	cout << "AFFICHER FLOAT : ";
	afficher<float>(82.12);

	cout << "AFFICHER ";
	afficher<string>("THERMOSTAT:");

	afficher<Thermostat>(thermometre);

	return 0;
}