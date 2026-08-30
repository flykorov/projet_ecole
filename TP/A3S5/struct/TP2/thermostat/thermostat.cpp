#include <iostream>
#include "thermostat.h"
using namespace std;

Thermostat::Thermostat()
{
	mode = 'A';
	zone = 0;
	temperature_manuel = 10;
	int i;
	for(i=0; i<3; i++)
	{
		temperature[i] = 10;
	}
}

Thermostat::~Thermostat()
{
	
}

void Thermostat::afficher_option()		// affiche les choix
{
	cout << "Options\n";
	cout << " 0- Arreter le thermostat\n";
	cout << " 1- Definir le mode\n";
	cout << " 2- Ajuster la temperature\n";
	cout << " 3- Afficher le thermostat\n";
	cout << " -- Votre choix? ";
}

char Thermostat::get_mode()
{
	return mode;
}

int Thermostat::get_zone()
{
	return zone;
}

int* Thermostat::get_temperature()
{
	return temperature;
}

int Thermostat::get_temperature_manuel()
{
	return temperature_manuel;
}

void Thermostat::set_mode(char _mode)
{
	mode = _mode;
}

void Thermostat::set_zone(int _zone)
{
	zone = _zone;
}

void Thermostat::set_temperature(int* _temperature)
{
	*temperature = *_temperature;
}

void Thermostat::set_temperature_manuel(int _temperature_manuel)
{
	temperature_manuel = _temperature_manuel;
}

void Thermostat::afficher_thermostat()		// affiche le thermostat
{
	cout << "--------------------------------------------\n";
	int i;
	cout << "- THERMOSTAT                               -\n";
	cout << "- Mode : ";
	if(mode == 'M')		// verifie le mode choisi
	{
		cout << "MANUEL                            -\n";
		cout << "-   Temperature : " << temperature_manuel << "                       -\n";
	}
	else
	{
		cout << "AUTOMATIQUE                       -\n";
		for(i=0; i<3; i++)
		{
		cout << "- Zone : " << i << "                                 -\n";
		cout << "-   Temperature : " << temperature[i] << "                       -\n";
		}
	}
	cout << "--------------------------------------------\n";
}

std::ostream& operator<<(std::ostream& os, Thermostat const & t)	// affiche le thermostat en surcharge
{
	os << "--------------------------------------------\n";
	int i;
	os << "- THERMOSTAT                               -\n";
	os << "- Mode : ";
	if(t.mode == 'M')
	{
		os << "MANUEL                            -\n";
		os << "-   Temperature : " << t.temperature_manuel << "                       -\n";
	}
	else
	{
		os << "AUTOMATIQUE                       -\n";
		for(i=0; i<3; i++)
		{
		os << "- Zone : " << i << "                                 -\n";
		os << "-   Temperature : " << t.temperature[i] << "                       -\n";
		}
	}
	os << "--------------------------------------------\n";
	return os;
}

void Thermostat::ajuster_temperature()		// ajuste la temperature
{
	if(mode == 'A')		// verifiee le mode choisi
	{
		cout << "Mode actuel : AUTOMATIQUE\n";
		do
		{
			if(zone != 0 && zone != 1 && zone != 2)
				cout << "\nZone invalide\n\n";

			cout << "  Definir la zone (0), (1) ou (2) : ";
			cin >> zone;
		}while(zone != 0 && zone != 1 && zone != 2);	// verifie la valeur entree
		do
		{
			if(temperature[zone] < 10 || temperature[zone] > 20)
				cout << "\ntemperature invalide\n\n";

			cout << "  Definir la nouvelle temperature (10-20) : ";
			cin >> temperature[zone];
		}while(temperature[zone] < 10 || temperature[zone] > 20);
	}else
	{
		cout << "Mode actuel : MANUEL\n";
		do
		{
			if(temperature_manuel < 10 || temperature_manuel > 20)
				cout << "\ntemperature invalide\n\n";

			cout << "  Definir la nouvelle temperature (10-20) : ";
			cin >> temperature_manuel;
		}while(temperature_manuel < 10 || temperature_manuel > 20);
	}
}

void Thermostat::definir_mode()  	// change le mode
{
	if(mode == 'A')
		cout << "Mode actuel : AUTOMATIQUE\n";
	else
		cout << "Mode actuel : MANUEL\n";

	do
	{
		if(mode != 'A' && mode != 'M')
		{
			cout << "Mode invalide\n";
		}
		cout << "  Definir le nouveau mode (M) ou (A) : ";
		cin >> mode;
	}while(mode != 'A' && mode != 'M');		// verifie les valeurs entree

}

bool Thermostat::choix(Thermostat thermometre)		// fonction obsolete
{
	bool continuer = true;
	thermometre.afficher_option();
	int choix;
	cin >> choix;
	switch(choix)
	{
		case 0:
		cout << "ARRET DU THERMOSTAT\n";
		continuer = false;
		break;
		case 1:
		thermometre.definir_mode();
		break;
		case 2:
		thermometre.ajuster_temperature();
		break;
		case 3:
		thermometre.afficher_thermostat();
		break;
		default:
		cout << "erreur lors de la prise de la valeur\n";
	}
	return continuer;
}

