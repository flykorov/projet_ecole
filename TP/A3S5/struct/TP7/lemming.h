#ifndef LEMMING_H
#define LEMMING_H

#include <iostream>
using namespace std;

class Lemming
{
private:
	int id;
	static int count;
	static int decount;

public:
	Lemming(int taille, int choix)
	{
		if(decount > taille)
		{
			decount = taille;
		}
		switch(choix)
		{
			case 0: id = count++;
			break;
			case 1: id = decount--;
			break;
			case 2: id = rand() % taille;
			break;
		}
	}
	friend ostream &operator<< (ostream&, const Lemming&);
	Lemming& operator=(Lemming& lemming);
	int getId() {return id;}

};

int Lemming::count = 0;
int Lemming::decount = 1000;

ostream &operator<< (ostream& out, const Lemming& lemming)
{
	out << lemming.id;
	return out;
}

Lemming& Lemming::operator=(Lemming& lemming)
{
	int temp = id;
	id = lemming.id;
	lemming.id = temp;
	return *this;
}


#endif