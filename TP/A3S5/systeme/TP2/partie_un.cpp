// TP2 : multithreading
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>
#include <new>
using namespace std;

// g++ -std=c++11 x.cpp –lpthread

// tout les objets ne sont pas crée

void coupe_de_vin(int* tab, int* result)
{
	// while(tab[0] == 0)
	// {
	// 	cout << "Thread coupe de vin attend argent\n";
	// 	this_thread::sleep_for(chrono::milliseconds(10));
	// }
	if(tab[0] > 0)	// verifie si la ressource est disponible
	{
		tab[0]--;
		cout << "Thread coupe de vin possede argent\n";
		while(tab[1] == 0)		// attend la ressource suivante
		{
			cout << "Thread coupe de vin attend or\n";
			this_thread::sleep_for(chrono::milliseconds(10));

		}
		if(tab[1] > 0)			// verifie la disponibilite de la deuxieme ressource
		{
			tab[1]--;
			cout << "Thread coupe de vin possede or\n";
			this_thread::sleep_for(chrono::milliseconds(200));
			tab[0]++;
			tab[1]++;
			result[0]++;
			cout << "coupe de vin cree\n";
		}
	}
}

void porte(int* tab, int* result)
{
	// while(tab[1] == 0)
	// {
	// 	cout << "Thread porte attend or\n";
	// 	this_thread::sleep_for(chrono::milliseconds(10));
	// }
	if(tab[1] > 0)
	{
		tab[1]--;
		cout << "Thread porte possede or\n";
		while(tab[2] == 0)
		{
			cout << "Thread porte attend bois\n";
			this_thread::sleep_for(chrono::milliseconds(10));

		}
		if(tab[2] > 0)
		{
			tab[2]--;
			cout << "Thread porte possede bois\n";
			this_thread::sleep_for(chrono::milliseconds(200));
			tab[1]++;
			tab[2]++;
			result[1]++;
			cout << "porte cree\n";
		}
	}
}

void table(int* tab, int* result)
{
	// while(tab[2] == 0)
	// {
	// 	cout << "Thread table attend bois\n";
	// 	this_thread::sleep_for(chrono::milliseconds(10));
	// }
	if(tab[2] > 0)
	{
		tab[2]--;
		cout << "Thread table possede bois\n";
		while(tab[3] == 0)
		{
			cout << "Thread table attend metal\n";
			this_thread::sleep_for(chrono::milliseconds(10));

		}
		if(tab[3] > 0)
		{
			tab[3]--;
			cout << "Thread table possede metal\n";
			this_thread::sleep_for(chrono::milliseconds(200));
			tab[3]++;
			tab[2]++;
			result[2]++;
			cout << "table cree\n";
		}
	}
}

void bague(int* tab, int* result)
{
	// while(tab[3] == 0)
	// {
	// 	cout << "Thread bague attend metal\n";
	// 	this_thread::sleep_for(chrono::milliseconds(10));
	// }
	if(tab[3] > 0)
	{
		tab[3]--;
		cout << "Thread bague possede metal\n";
		while(tab[4] == 0)
		{
			cout << "Thread bague attend diamant\n";
			this_thread::sleep_for(chrono::milliseconds(10));

		}
		if(tab[4] > 0)
		{
			tab[4]--;
			cout << "Thread bague possede diamant\n";
			this_thread::sleep_for(chrono::milliseconds(200));
			tab[4]++;
			tab[3]++;
			result[3]++;
			cout << "bague cree\n";
		}
	}
}

void chandelier(int* tab, int* result)
{
	// while(tab[5] == 0)
	// {
	// 	cout << "Thread chandelier attend diamant\n";
	// 	this_thread::sleep_for(chrono::milliseconds(10));
	// }
	if(tab[4] > 0)
	{
		tab[4]--;
		cout << "Thread chandelier possede diamant\n";
		while(tab[5] == 0)
		{
			cout << "Thread chandelier attend fer\n";
			this_thread::sleep_for(chrono::milliseconds(10));

		}
		if(tab[5] > 0)
		{
			tab[5]--;
			cout << "Thread chandelier possede fer\n";
			this_thread::sleep_for(chrono::milliseconds(200));
			tab[5]++;
			tab[4]++;
			result[4]++;
			cout << "chandelier cree\n";
		}
	}
}

void epee(int* tab, int* result)
{
	if(tab[5] > 0)
	{
		tab[5]--;
		cout << "Thread epee possede fer\n";
		while(tab[0] == 0)
		{
			cout << "Thread epee attend argent\n";
			this_thread::sleep_for(chrono::milliseconds(10));

		}
		if(tab[0] > 0)
		{
			tab[0]--;
			cout << "Thread epee possede argent\n";
			this_thread::sleep_for(chrono::milliseconds(200));
			tab[0]++;
			tab[5]++;
			result[5]++;
			cout << "epee cree\n";
		}
	}
}

// 0 = argent
// 1 = or
// 2 = bois
// 3 = metal
// 4 = diamant
// 5 = fer

int main()
{
	string nom[6] {"nb_coupe", "nb_porte", "nb_table", "nb_bague", "nb_chandelier", "nb_epee"};
	int* tab = new int[6];
	int* result = new int[6];
	int i;
	for(i=0; i<6; i++)
	{
		tab[i] = 1;
		result[i] = 0;
	}
	
	thread coupe(coupe_de_vin, tab, result);		// lance les threads
	thread epe(epee, tab, result);
	thread tabl(table, tab, result);
	thread chand(chandelier, tab, result);
	thread bag(bague, tab, result);
	thread port(porte, tab, result);

	coupe.join();
	epe.join();
	tabl.join();
	chand.join();
	bag.join();
	port.join();

	for(i=0; i<6; i++)
		cout << nom[i] << " " << result[i] << endl;
	// delete element;
	delete[] tab;
	delete[] result;
	// free(materiaux);

	return 0;
}