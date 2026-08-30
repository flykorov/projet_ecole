//TP4 : hexa
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#ifndef HEXA_H
#define HEXA_H

#include <vector>
using namespace std; 

class Hexa
{
public:
	Hexa();
	~Hexa();

	void setNombre(int n) { nombre=n; }
	
	int getNombre() { return nombre; }
	vector<char> getHexadecimal() { return hexadecimal; }

	void dec_to_bin();
	void bin_to_hexa();
	void int_to_char(int con);
	static char int_to_char2(int con);

	vector<char> convert_hexa(int nombre);
	vector<char> operator()(int nombre);

private:
	int nombre;
	list<int> binary;
	vector<char> hexadecimal;
	
};

#endif