#include <iostream>
#include <cmath>
using namespace std;

void test_f5()
{
	int i, j, k;
	unsigned long long int res=0, somme=0;
	for(i=0; i<100; i++)
		for(j=0; j<i*i; j++)
			res = res + j;
	cout << res << endl;
	for(i=0; i<100; i++)
		for(j=0; j<i*i; j++)
			for(k=0; k<j; k++)
				somme++;
	cout << somme << endl;
}

void test_petit_f5()
{
	int i, j;
	unsigned long long int res=0, somme=0;
	for(i=0; i<10000; i++)
		res = res + i*i;
	cout << res << endl;
	// for(i=0; i<100; i++)
	// 	for(j=0; j<i*i; j++)
	// 		somme++;
	// cout << somme << endl;
}

void recur()
{
	int i, n, res=0;
	cin >> n;
	for(i=n-1; i>=0; i--)
		res = res + pow(2, i);
	cout << res << endl;
}

void f4()
{
	int i, res=0;
	for(i=0; i<1000;i++)
	{
		res+=i;
	}
	cout << res << endl;
}

int main()
{
	f4();
	return 0;
}