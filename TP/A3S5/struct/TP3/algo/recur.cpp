//TP3
//Victor Bouvier d'Acher
//Geoffroy Rodriguez
//O(n) = 2^n

#include <iostream>
#include <cmath>
using namespace std;

void factorielle(int n, unsigned long long int* res)
{
	
	if(n > 1)
	{
		factorielle(n-1, res);
	}

	// cout << n << endl;
	*res *= n;
	// for(int i=0; i<n; i++)
	// 	cout << " ";
	// cout << n << endl;

	if(n > 1)
	{
		factorielle(n-1, res);
	}
	
}

int main()
{
	int n;
	unsigned long long int a = 1;
	unsigned long long int* res = &a;
	cin >> n;
	factorielle(n, res);
	// cout << "nb de depart : "<< n << endl;
	cout << "resultat : " << a << endl;
}
