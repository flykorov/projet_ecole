#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

void f1(int n)
{
	int i, somme=0;
	for(i=0 ; i<n ; i++)
		somme ++;
}

void f2(int n)
{
	int i, j, somme=0;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			somme++;
}

void f3(int n)
{
	int i, j, somme=0;
	for(i=0; i<n; i++)
		for(j=0; j<n*n; j++)
			somme++;
}

void f4(int n)
{
	int i, j, somme=0;
	for(i=0; i<n; i++)
		for(j=0; j<i; j++)
			somme++;
}

void f5(int n)
{
	int i, j, k, somme=0;
	for(i=0; i<n; i++)
		for(j=0; j<i*i; j++)
			for(k=0; k<j; k++)
				somme++;
}

void f6(int n)
{
	int i, j, k, somme=0;
	for(i=1; i<n; i++)
		for(j=1; j<i*i; j++)
			if(j%i == 0)
				for(k=0; k<j; k++)
					somme++;
}


int main()
{
	chrono::system_clock::time_point start = chrono::system_clock::now();
	int n=1000;
	f6(n);
	chrono::duration<double> sec = chrono::system_clock::now() - start;
    cout << "took " << sec.count() << " seconds\n";
	return 0;
}