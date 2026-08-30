#include <iostream>
#include <atomic>
#include <mutex>
#include <thread>
using namespace std;


void bonjour(int nb, int* a, int b)
{
	int i;
	for(i=0; i<nb; i++)
	{
		cout << "bijour\n" << *a << endl;
		*a = *a - 1;
	}
}

void aurevoir(int nb, int* a, int b)
{
	int i;
	for(i=0; i<nb; i++)
	{
		cout << "auvoir\n" << *a << endl;
		*a = *a - 1;
	}
}

void pourquoi(int nb)
{
	int i;
	for(i=0; i<nb; i++)
	{
		cout << "pouquoi\n";
	}
}

int main()
{
	int b = 6;
	int* a = &b;
	thread th1(bonjour, 3, a, b);
	thread th2(aurevoir, 3, a, b);
	// thread th3(pourquoi, 3);


	// th3.join();
	th2.join();
	th1.join();

	return 0;
}