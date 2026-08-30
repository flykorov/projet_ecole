// TP1 : pointeur
// Victor Bouvier d'Acher

#include <iostream>

using namespace std;

void permuter1(int* t, int posA, int posB)
{
	int temp;
	temp = t[posA];
	t[posA] = t[posB];
	t[posB] = temp;
}

void permuter2(int t[], int posA, int posB)
{
	int temp;
	temp = t[posA];
	t[posA] = t[posB];
	t[posB] = temp;
}

void permuter3(int& posA, int& posB)
{
	int temp = posA;
	posA = posB;
	posB = temp;
}

void permuter4(int* posA, int* posB)
{
	int temp = *posA;
	*posA = *posB;
	*posB = temp;

}

void afficher1(int* t, int posA, int posB)
{
	cout << "AFFICHER #1 :";
	int i;
	for(i=posA; i<=posB; i++)
		cout << " " << t[i] << ",";
	cout << endl;
}

void afficher2(int t[], int posA, int posB)
{
	cout << "AFFICHER #2 :";
	int i;
	for(i=posA; i<=posB; i++)
		cout << " " << t[i] << ",";
	cout << endl;
}

void afficher3(int& posA, int& posB)
{
	cout << "AFFICHER #3 :";
	int i;
	for(i=posA; i<=posB; i++)
	{
		cout << " " << i << ",";
	}
	cout << endl;
}

void afficher4(int* posA, int* posB)
{
	cout << "AFFICHER #4 : ";
	int i=0;
	while(posA+i != posB+1)
	{
		cout << *(posA+i) << ", ";
		i++;
	}
	cout << endl;
}

int* recherche(int* t, int taille, int valeur)
{
	int i;
	int* val = NULL;
	for(i=0; i<taille; i++)
	{
		if(t[i] == valeur)
			val = &t[i];
	}
	
	return val;
}

int main()
{
    int tableau[] = {1, 3, 4, 5, 8, 7, 0, 2, 6, 9};
    permuter1(tableau, 2, 5);
    permuter2(tableau, 3, 6);
    permuter3(tableau[1], tableau[9]);
    permuter4(tableau + 4, tableau + 7);
    afficher1(tableau, 0, 7);
    afficher2(tableau, 2, 8);
    afficher3(*(tableau + 5), tableau[6]);
    afficher4(&tableau[3], &tableau[8]);
    int* valeur = recherche(tableau, 10, 8);
    if(valeur != NULL)
    {
    	cout << "valeur : " << *valeur << endl;
    	*valeur = 10;
    }
    afficher4(tableau, tableau + 9);

    return 0;
}