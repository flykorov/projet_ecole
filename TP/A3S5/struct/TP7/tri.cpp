#include <iostream>
#include <chrono>
#include <ctime>
#include <list>
#include <iterator>
#include "lemming.h"
using namespace std;

int* tab_croissant(int taille)
{
	int i;
	int* tab = new int[taille];
	for(i=0; i<taille; i++)
		tab[i] = i;
	return tab;
}

int* tab_decroissant(int taille)
{
	int i;
	int* tab = new int[taille];
	for(i=0; i<taille; i++)
		tab[i] = taille - i;
	return tab;
}

int* tab_rand(int taille)
{
	int i;
	int* tab = new int [taille];
	for(i=0; i<taille; i++)
		tab[i] = rand() % taille;
	return tab;
}

void free_tab(int* tab)
{
	delete[] tab;
}

void afficher(int* tab, int taille)
{
	int i;
	for(i=0; i<taille; i++)
		cout << tab[i] << " ";
	cout << endl;
}

void tri_bulle(int* tab, int taille)
{
	// chrono::system_clock::time_point start = chrono::system_clock::now();
	int i, j;
	for(i=0; i<taille-1; i++)
	{
		for(j=1; j<taille-i; j++)
		{
			if(tab[j-1] > tab[j])
			{
				int temp = tab[j-1];
				tab[j-1] = tab[j];
				tab[j] = temp;
			}
		}
	}
	// chrono::duration<double, nano> nanosec = chrono::system_clock::now() - start;
	// cout << " Tri a bulle\n";
	// cout << " N : " << taille << endl;
	// cout << " Duree : " << nanosec.count() << " ns\n";
}

void tri_selection(int* tab, int taille)
{
	// chrono::system_clock::time_point start = chrono::system_clock::now();
	int i, j;
	for(i=0; i<taille-1; i++)
	{
		int min = i;
		for(j=i+1; j<taille-0; j++)
		{
			if(tab[j] < tab[min])
			{
				min = j;
			}
		}
		int temp = tab[min];
		tab[min] = tab[i];
		tab[i] = temp;
	}

	// chrono::duration<double, nano> nanosec = chrono::system_clock::now() - start;
	// cout << " Tri a bulle\n";
	// cout << " N : " << taille << endl;
	// cout << " Duree : " << nanosec.count() << " ns\n";
}

void tri_insertion(int* tab, int taille)
{
	// chrono::system_clock::time_point start = chrono::system_clock::now();
	int i, j;
	for(i=0; i<taille; i++)
	{
		int temp = tab[i];
		for(j=i; j>0 && tab[j-1]>temp; j--)
		{
			tab[j] = tab[j-1];
		}
		tab[j] = temp;
	}

	// chrono::duration<double, nano> nanosec = chrono::system_clock::now() - start;
	// cout << " Tri a bulle\n";
	// cout << " N : " << taille << endl;
	// cout << " Duree : " << nanosec.count() << " ns\n";
}

void fusionner(int* tab, int n1, int n2)
{
	int* temp = new int[n2+n1];
	int i=0, j1=0, j2=0;
	while(j1<n1 && j2<n2)
		temp[i++] = (tab[j1] <= tab[n1+j2] ? tab[j1++] : tab[n1+j2++]);
	while(j1<n1)
		temp[i++] = tab[j1++];
	while(j2<n2)
		temp[i++] = tab[n1+j2++];
	for(i=0; i<n1+n2; i++)
		tab[i] = temp[i];
	delete[] temp;
}

void trier(int* tab, int taille)
{
	if(taille > 1)
	{
		int n1 = taille/2;
		int n2 = taille - n1;
		trier(tab, n1);
		trier(tab+n1, n2);
		fusionner(tab, n1, n2);
	}
}

void tri_rapide(int* tab, int lo, int hi)
{
	if(lo >= hi)
		return;
	int pivot = tab[hi];
	int i = lo-1;
	int j = hi;
	while(i<j)
	{
		while(tab[++i]<pivot);
		while(j>=0 && tab[j--]>pivot);
		if(i<j)
		{
			int temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
		}
	}
	int temp = tab[i];
	tab[i] = tab[hi];
	tab[hi] = temp;
	tri_rapide(tab, lo, i-1);
	tri_rapide(tab, i+1, hi);
}

void lancer_tri_bulle(int taille)
{
	int* tab1 = tab_croissant(taille);
	chrono::system_clock::time_point start = chrono::system_clock::now();
	
	tri_bulle(tab1, taille);

	chrono::duration<double, nano> nanosec1 = chrono::system_clock::now() - start;
	cout << " Tri bulle\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec1.count() << " ns\n";
	//afficher(tab1, taille);

	int* tab2 = tab_decroissant(taille);
	chrono::system_clock::time_point start2 = chrono::system_clock::now();
	
	tri_bulle(tab2, taille);

	chrono::duration<double, nano> nanosec2 = chrono::system_clock::now() - start2;
	cout << " Tri bulle\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec2.count() << " ns\n";
	//afficher(tab2, taille);

	int* tab3 = tab_rand(taille);
	chrono::system_clock::time_point start3 = chrono::system_clock::now();
	
	tri_bulle(tab3, taille);

	chrono::duration<double, nano> nanosec3 = chrono::system_clock::now() - start3;
	cout << " Tri bulle\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec3.count() << " ns\n";
	//afficher(tab3, taille);

	free_tab(tab1);
	free_tab(tab2);
	free_tab(tab3);
}

void lancer_tri_selection(int taille)
{
	int* tab1 = tab_croissant(taille);
	chrono::system_clock::time_point start = chrono::system_clock::now();
	
	tri_selection(tab1, taille);

	chrono::duration<double, nano> nanosec1 = chrono::system_clock::now() - start;
	cout << " Tri selection\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec1.count() << " ns\n";
	//afficher(tab1, taille);

	int* tab2 = tab_decroissant(taille);
	chrono::system_clock::time_point start2 = chrono::system_clock::now();
	
	tri_selection(tab2, taille);

	chrono::duration<double, nano> nanosec2 = chrono::system_clock::now() - start2;
	cout << " Tri selection\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec2.count() << " ns\n";
	//afficher(tab2, taille);

	int* tab3 = tab_rand(taille);
	chrono::system_clock::time_point start3 = chrono::system_clock::now();
	
	tri_selection(tab3, taille);

	chrono::duration<double, nano> nanosec3 = chrono::system_clock::now() - start3;
	cout << " Tri selection\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec3.count() << " ns\n";
	//afficher(tab3, taille);

	free_tab(tab1);
	free_tab(tab2);
	free_tab(tab3);
}

void lancer_tri_insertion(int taille)
{
	int* tab1 = tab_croissant(taille);
	chrono::system_clock::time_point start = chrono::system_clock::now();
	
	tri_insertion(tab1, taille);

	chrono::duration<double, nano> nanosec1 = chrono::system_clock::now() - start;
	cout << " Tri insertion\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec1.count() << " ns\n";
	//afficher(tab1, taille);

	int* tab2 = tab_decroissant(taille);
	chrono::system_clock::time_point start2 = chrono::system_clock::now();
	
	tri_insertion(tab2, taille);

	chrono::duration<double, nano> nanosec2 = chrono::system_clock::now() - start2;
	cout << " Tri insertion\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec2.count() << " ns\n";
	//afficher(tab2, taille);

	int* tab3 = tab_rand(taille);
	chrono::system_clock::time_point start3 = chrono::system_clock::now();
	
	tri_insertion(tab3, taille);

	chrono::duration<double, nano> nanosec3 = chrono::system_clock::now() - start3;
	cout << " Tri insertion\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec3.count() << " ns\n";
	//afficher(tab3, taille);

	free_tab(tab1);
	free_tab(tab2);
	free_tab(tab3);
}

void lancer_tri_fusion(int taille)
{
	int* tab1 = tab_croissant(taille);
	chrono::system_clock::time_point start = chrono::system_clock::now();
	
	trier(tab1, taille);

	chrono::duration<double, nano> nanosec1 = chrono::system_clock::now() - start;
	cout << " Tri fusion\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec1.count() << " ns\n";
	//afficher(tab1, taille);

	int* tab2 = tab_decroissant(taille);
	chrono::system_clock::time_point start2 = chrono::system_clock::now();
	
	trier(tab2, taille);

	chrono::duration<double, nano> nanosec2 = chrono::system_clock::now() - start2;
	cout << " Tri fusion\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec2.count() << " ns\n";
	//afficher(tab2, taille);

	int* tab3 = tab_rand(taille);
	chrono::system_clock::time_point start3 = chrono::system_clock::now();
	
	trier(tab3, taille);

	chrono::duration<double, nano> nanosec3 = chrono::system_clock::now() - start3;
	cout << " Tri fusion\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec3.count() << " ns\n";
	//afficher(tab3, taille);

	free_tab(tab1);
	free_tab(tab2);
	free_tab(tab3);
}

void lancer_tri_rapide(int taille)
{
	int* tab1 = tab_croissant(taille);
	chrono::system_clock::time_point start = chrono::system_clock::now();
	
	tri_rapide(tab1, 0, taille-1);

	chrono::duration<double, nano> nanosec1 = chrono::system_clock::now() - start;
	cout << " Tri rapide\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec1.count() << " ns\n";
	//afficher(tab1, taille);

	int* tab2 = tab_decroissant(taille);
	chrono::system_clock::time_point start2 = chrono::system_clock::now();
	
	tri_rapide(tab2, 0, taille-1);

	chrono::duration<double, nano> nanosec2 = chrono::system_clock::now() - start2;
	cout << " Tri rapide\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec2.count() << " ns\n";
	//afficher(tab2, taille);

	int* tab3 = tab_rand(taille);
	chrono::system_clock::time_point start3 = chrono::system_clock::now();
	
	tri_rapide(tab3, 0, taille-1);

	chrono::duration<double, nano> nanosec3 = chrono::system_clock::now() - start3;
	cout << " Tri rapide\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec3.count() << " ns\n";
	//afficher(tab3, taille);

	free_tab(tab1);
	free_tab(tab2);
	free_tab(tab3);
}


void defLem(list<Lemming> &lemming, int nb, int choix)
{
	int i;
	for(i=0; i<nb; i++)
	{
		Lemming lem(nb, choix);
		lemming.push_back(lem);
	}
}

void tri_bulle_lemming(list<Lemming> &lemming, int taille)
{
	chrono::system_clock::time_point start = chrono::system_clock::now();
	list<Lemming>::iterator it=lemming.begin(), jt, kt;
	int i, j;
	for(i=0; i<taille-1; i++, it++)
	{
		kt = lemming.begin();
		jt=lemming.begin();
		jt++;
		for(j=1; j<taille-i; j++, jt++)
		{
			if((*kt).getId() > (*jt).getId())
			{
				*kt = *jt;
			}
			kt++;
		}
	}
	chrono::duration<double, nano> nanosec = chrono::system_clock::now() - start;
	cout << " Tri a bulle lemming\n";
	cout << " N : " << taille << endl;
	cout << " Duree : " << nanosec.count() << " ns\n";
}

void afficherLemming(list<Lemming> &lemming)
{
	list<Lemming>::const_iterator cit;
	cout << "LISTE (" << lemming.size() << ") : " ;
	for(cit = lemming.begin(); cit != lemming.end(); cit++)
		cout << *cit << " <- ";
	cout << endl;
}

void lancer_lem(int taille)
{
	list<Lemming> lem1;
	defLem(lem1, taille, 0);
	// afficherLemming(lem1);
	tri_bulle_lemming(lem1, taille);
	// afficherLemming(lem1);

	list<Lemming> lem2;
	defLem(lem2, taille, 1);
	// afficherLemming(lem2);
	tri_bulle_lemming(lem2, taille);
	// afficherLemming(lem2);

	list<Lemming> lem3;
	defLem(lem3, taille, 2);
	// afficherLemming(lem3);
	tri_bulle_lemming(lem3, taille);
	// afficherLemming(lem3);
}

int main()
{
	srand(time(NULL));

	lancer_tri_bulle(5);
	lancer_tri_bulle(10);
	lancer_tri_bulle(15);
	lancer_tri_bulle(20);
	lancer_tri_bulle(25);
	lancer_tri_bulle(30);
	lancer_tri_bulle(50);
	lancer_tri_bulle(100);
	lancer_tri_bulle(1000);

	lancer_tri_selection(5);
	lancer_tri_selection(10);
	lancer_tri_selection(15);
	lancer_tri_selection(20);
	lancer_tri_selection(25);
	lancer_tri_selection(30);
	lancer_tri_selection(50);
	lancer_tri_selection(100);
	lancer_tri_selection(1000);

	lancer_tri_insertion(5);
	lancer_tri_insertion(10);
	lancer_tri_insertion(15);
	lancer_tri_insertion(20);
	lancer_tri_insertion(25);
	lancer_tri_insertion(30);
	lancer_tri_insertion(50);
	lancer_tri_insertion(100);
	lancer_tri_insertion(1000);

	lancer_tri_fusion(5);
	lancer_tri_fusion(10);
	lancer_tri_fusion(15);
	lancer_tri_fusion(20);
	lancer_tri_fusion(25);
	lancer_tri_fusion(30);
	lancer_tri_fusion(50);
	lancer_tri_fusion(100);
	lancer_tri_fusion(1000);

	lancer_tri_rapide(5);
	lancer_tri_rapide(10);
	lancer_tri_rapide(15);
	lancer_tri_rapide(20);
	lancer_tri_rapide(25);
	lancer_tri_rapide(30);
	lancer_tri_rapide(50);
	lancer_tri_rapide(100);
	lancer_tri_rapide(1000);

	lancer_lem(5);
	lancer_lem(10);
	lancer_lem(15);
	lancer_lem(20);
	lancer_lem(25);
	lancer_lem(30);
	lancer_lem(50);
	lancer_lem(100);
	lancer_lem(1000);

}