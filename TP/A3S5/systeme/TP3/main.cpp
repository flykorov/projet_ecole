// TP 3 systeme
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <vector>
#include <list>
#include "fonction.h"
using namespace std;

int main()
{
	frame f;
	vector<TLB> tlb;
	vector<adresse_logique> add;
	vector<frame> fra;
	vector<memoire> mem;
	
	cout << "Partie II : \n";
	ecrire_correct(add, fra, mem);

	vector<adresse_logique> add2;
	vector<frame> fra2;
	vector<memoire> mem2;

	cout << endl << "Partie III : \n";
	ecrire_TLB(add2, fra2, mem2, tlb);

	// 	24.4
	// TLB 5.5 %
}