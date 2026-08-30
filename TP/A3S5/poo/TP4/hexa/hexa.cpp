//TP4 : hexa
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include "hexa.h"
using namespace std;

Hexa::Hexa()
{

}

Hexa::~Hexa()
{

}

void Hexa::dec_to_bin()
{	
	while(nombre != 0 && nombre != 1)		// convertion en binaire
	{
		int temp = nombre % 2;
		binary.push_front(temp);			// utilisation de list
		nombre /= 2;
	}
	binary.push_front(nombre);

	while(binary.size() % 4 != 0)			// assure d'avoir un multiple de 4 comme taille de list
		binary.push_front(0);
}

void Hexa::bin_to_hexa()
{
	vector<int> c;
	int tab[4] = { 8, 4, 2, 1 };
	while(binary.size() != 0)
	{
		int res=0;
		list<int>::iterator it=binary.begin();	// utilisation d'un iterator
		for(int i=0; i<4; i++)					// converti le binaire en hexadecimal
		{
			if(*it == 1)
			{
				res += tab[i];
			}
			it++;
			binary.pop_front();
		}
		c.push_back(res);
	}
	hexadecimal.resize(c.size());
	transform(c.begin(), c.end(), hexadecimal.begin(), int_to_char2);		// utilisation d'un algorithm
}

char Hexa::int_to_char2(int con)		// coordone avec l'utilisation de l'algo transform
{
	switch(con)
	{
		case 0 : return '0';
			break;
		case 1 : return '1';
			break;
		case 2 : return '2';
			break;
		case 3 : return '3';
			break;
		case 4 : return '4';
			break; 
		case 5 : return '5';
			break; 
		case 6 : return '6';
			break; 
		case 7 : return '7';
			break; 
		case 8 : return '8';
			break; 
		case 9 : return '9';
			break; 
		case 10 : return 'a';
			break; 
		case 11 : return 'b';
			break; 
		case 12 : return 'c';
			break; 
		case 13 : return 'd';
			break; 
		case 14 : return 'e';
			break; 
		case 15 : return 'f';
			break;
	}
}


vector<char> Hexa::operator()(int nombre)		// utilisation d'un foncteur
{
	hexadecimal.clear();
	setNombre(nombre);
	dec_to_bin();
	bin_to_hexa();
	return getHexadecimal();
}