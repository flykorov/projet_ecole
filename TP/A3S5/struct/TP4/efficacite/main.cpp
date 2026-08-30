// TP4
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane
// 
// Lors du test de V2
// On constate que les puissance de 2 sont plus lente a inserer
// (entre 2*10^-7 et 3*10^-7)
// les autres insertion sont plus rapide et oscille entre 4*10^-8 et 6*10^-8

// le tp a ete fait a 3 puisque arezki est arrive tardivement a l'uqac
// en effet il est arriver le 3 octobre a Chicoutimi

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
using namespace std;

void testTab(int n)
{
	chrono::system_clock::time_point start = chrono::system_clock::now();
	int i;
	int tab[n];
	cout << "testTab - Insertion dans un tablau\n";
	for(i=0; i<n; i++)
		tab[i] = 1;
	chrono::duration<double> sec = chrono::system_clock::now() - start;
	cout << " N : " << n << endl;
	cout << " Duree : " << sec.count() << " s\n";
	cout << " Moyenne : " << sec.count() / n << " s\n\n";
}

void testV1(int n)
{
	chrono::system_clock::time_point start = chrono::system_clock::now();
	int i;
	vector<int> v;
	cout << "testV1 - Insertion dans un vecteur\n";
	for(i=0; i<n; i++)
		v.push_back(1);
	chrono::duration<double> sec = chrono::system_clock::now() - start;
	cout << " N : " << n << endl;
	cout << " Duree : " << sec.count() << " s\n";
	cout << " Moyenne : " << sec.count() / n << " s\n\n";
}

void testV2(int n)
{
	int i, j=0;
	int tab[15] = {0, 1, 2, 4, 7, 8, 9, 15, 16, 17, 25, 64, 78, 79};
	vector<int> v;
	chrono::system_clock::time_point debut = chrono::system_clock::now();
	cout << "testV2 - Insertion dans un vecteur\n";
	for(i=0; i<n; i++)
	{
		if(tab[j] == i)
		{
			j++;
			chrono::system_clock::time_point start = chrono::system_clock::now();
			v.push_back(1);
			chrono::duration<double> sec = chrono::system_clock::now() - start;
			cout << i << " Duree : " << sec.count() << " s\n";
		}else
		{
			v.push_back(1);
		}
	}
	chrono::duration<double> fin = chrono::system_clock::now() - debut;
	cout << "\n N : " << n << endl;
	cout << " Duree : " << fin.count() << " s\n";
	cout << " Moyenne : " << fin.count() / n << " s\n\n";
}

int main()
{
	int n = 100;
	testTab(n);
	testTab(n*100);
	testTab(n*10000);
	cout << endl << endl;
	testV1(n);
	testV1(n*1000);
	testV1(n*100000);
	cout << endl << endl;
	testV2(n*10);
	return 0;
}