//TP4 : hexa
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include "hexa.h"
using namespace std;

int main()
{
	
	Hexa h;

	ifstream lec("input.txt");
	ofstream ecr("solution.txt");
	if(!lec.is_open() || !ecr.is_open())
	{
		cout << "erreur fichier\n";
		return 1;
	}
	for(int j=0; j<1000; j++)			// converti les 1000 valeur
	{
		int a;
		lec >> a;
		vector<char> c;
		c = h(a);						// convertion du chiffre en hexa

		for(unsigned long int i=0; i<c.size(); i++)			// ecrit le chiffre dans le fichier et sur le terminal
		{
			ecr << c[i];
			cout << c[i];
		}
		ecr << endl;
		cout << endl;
		// c.clear();
	}
	

	return 0;
}