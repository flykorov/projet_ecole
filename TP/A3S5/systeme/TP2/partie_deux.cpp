// TP2 : multithreading
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <thread>
#include <semaphore.h>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
using namespace std;


// g++ -std=c++11 x.cpp –lpthread
sem_t nb_th;

sem_t liste;

sem_t au;
sem_t ar;
sem_t fe;
sem_t bo;
sem_t di;
sem_t me;

sem_t res;

ofstream fichier("info.txt");

void coupe_de_vin(int* result, int* ressource)
{
	int u, v;
	bool verif=false;
	time_t tmm;
	char* dt;
	sem_wait(&nb_th);					// vérifie si il y a 6 thread max
	do
	{
		sem_getvalue(&ar, &u);			// verifie la disponibilite de la ressource
		if(u==0)
		{
			cout << "coupe de vin attend argent\n";			
		}
		sem_getvalue(&au, &v);			// meme chose
		if(v==0)
		{
			cout << "coupe de vin attend or\n";
		}
	}while(u==0 || v==0);
	sem_wait(&ar);						// prend la ressource
	ressource[0]--;
	if(ressource[0] == 0)
	{
		cout << "coupe de vin possede argent\n";
		sem_wait(&au);						// prende la deuxieme ressource
		ressource[1]--;
		if(ressource[1] == 0)
		{
			cout << "coupe de vin possede or\n";
			cout << "coupe de vin en creation\n";
			verif = true;
			tmm = time(0);				// capture la date
			dt = ctime(&tmm);
			fichier << "thread n°" << this_thread::get_id() << " cree coupe de vin a " << dt << endl;		// affiche dans le fichier
			this_thread::sleep_for(chrono::milliseconds(200));
			sem_wait(&res);
			result[0]++;
			sem_post(&res);
		}
		ressource[1]++;
		sem_post(&au);						// libere les ressource
	}
	ressource[0]++;
	sem_post(&ar);
	tmm = time(0);
	dt = ctime(&tmm);
	if(verif)
		fichier << "thread n°" << this_thread::get_id() << " detruit coupe de vin a " << dt << endl;
	sem_post(&nb_th);					// libère le thread
}

void porte(int* result, int* ressource)
{
	int u, v;
	bool verif=false;
	time_t tmm;
	char* dt;
	sem_wait(&nb_th);
	do
	{
		sem_getvalue(&au, &u);			// verifie la disponibilite de la ressource
		if(u==0)
		{
			cout << "porte attend or\n";			
		}
		sem_getvalue(&bo, &v);			// meme chose
		if(v==0)
		{
			cout << "porte attend bois\n";
		}
	}while(u==0 || v==0);
	sem_wait(&au);
	ressource[1]--;
	if(ressource[1] == 0)
	{
		cout << "porte possede or\n";
		sem_wait(&bo);
		ressource[2]--;
		if(ressource[2] == 0)
		{
			verif=true;
			cout << "porte possede bois\n";
			cout << "porte en creation\n";
			tmm = time(0);
			dt = ctime(&tmm);
			fichier << "thread n°" << this_thread::get_id() << " cree porte a " << dt << endl;
			this_thread::sleep_for(chrono::milliseconds(200));
			sem_wait(&res);
			result[1]++;
			sem_post(&res);
		}
		ressource[2]++;
		sem_post(&bo);
	}
	ressource[1]++;
	sem_post(&au);
	tmm = time(0);
	dt = ctime(&tmm);
	if(verif)
		fichier << "thread n°" << this_thread::get_id() << " detruit porte a " << dt << endl;
	sem_post(&nb_th);
}

void table(int* result, int* ressource)
{
	int u, v;
	bool verif=false;
	time_t tmm;
	char* dt;
	sem_wait(&nb_th);
	do
	{
		sem_getvalue(&bo, &u);			// verifie la disponibilite de la ressource
		if(u==0)
		{
			cout << "table attend bois\n";			
		}
		sem_getvalue(&me, &v);			// meme chose
		if(v==0)
		{
			cout << "table attend metal\n";
		}
	}while(u==0 || v==0);
	sem_wait(&bo);
	ressource[2]--;
	if(ressource[2] == 0)
	{
		cout << "table possede bois\n";
		sem_wait(&me);
		ressource[3]--;
		if(ressource[3] == 0)
		{
			verif=true;
			cout << "table possede metal\n";
			cout << "table en creation\n";
			tmm = time(0);
			dt = ctime(&tmm);
			fichier << "thread n°" << this_thread::get_id() << " cree table a " << dt << endl;
			this_thread::sleep_for(chrono::milliseconds(200));
			sem_wait(&res);
			result[2]++;
			sem_post(&res);
		}
		ressource[3]++;
		sem_post(&me);
	}
	ressource[2]++;
	sem_post(&bo);
	tmm = time(0);
	dt = ctime(&tmm);
	if(verif)
		fichier << "thread n°" << this_thread::get_id() << " detruit table a " << dt << endl;
	sem_post(&nb_th);
}

void bague(int* result, int* ressource)
{
	int u, v;
	time_t tmm;
	char* dt;
	bool verif=false;
	sem_wait(&nb_th);
	do
	{
		sem_getvalue(&me, &u);			// verifie la disponibilite de la ressource
		if(u==0)
		{
			cout << "bague attend metal\n";			
		}
		sem_getvalue(&di, &v);			// meme chose
		if(v==0)
		{
			cout << "bague attend diamant\n";
		}
	}while(u==0 || v==0);
	sem_wait(&me);
	ressource[3]--;
	if(ressource[3]==0)
	{
		cout << "bague possede metal\n";
		sem_wait(&di);
		ressource[4]--;
		if(ressource[4] == 0)
		{
			verif=true;
			cout << "bague possede diamant\n";
			cout << "bague en creation\n";
			tmm = time(0);
			dt = ctime(&tmm);
			fichier << "thread n°" << this_thread::get_id() << " cree bague a " << dt << endl;
			this_thread::sleep_for(chrono::milliseconds(200));
			sem_wait(&res);
			result[3]++;
			sem_post(&res);
		}
		ressource[4]++;
		sem_post(&di);
	}
	ressource[3]++;
	sem_post(&me);
	tmm = time(0);
	dt = ctime(&tmm);
	if(verif)
		fichier << "thread n°" << this_thread::get_id() << " detruit bague a " << dt << endl;
	sem_post(&nb_th);
}

void chandelier(int* result, int* ressource)
{
	int u, v;
	bool verif=false;
	time_t tmm;
	char* dt;
	sem_wait(&nb_th);
	do
	{
		sem_getvalue(&di, &u);			// verifie la disponibilite de la ressource
		if(u==0)
		{
			cout << "chandelier attend diamant\n";			
		}
		sem_getvalue(&fe, &v);			// meme chose
		if(v==0)
		{
			cout << "chandelier attend fer\n";
		}
	}while(u==0 || v==0);
	sem_wait(&di);
	ressource[4]--;
	if(ressource[4] == 0)
	{
		cout << "chandelier possede diamant\n";
		sem_wait(&fe);
		ressource[5]--;
		if(ressource[5] == 0)
		{
			verif=true;
			cout << "chandelier possede fer\n";
			cout << "chandelier en creation\n";
			tmm = time(0);
			dt = ctime(&tmm);
			fichier << "thread n°" << this_thread::get_id() << " cree chandelier a " << dt << endl;
			this_thread::sleep_for(chrono::milliseconds(200));
			sem_wait(&res);
			result[4]++;
			sem_post(&res);
		}
		ressource[5]++;
		sem_post(&fe);
	}
	ressource[4]++;
	sem_post(&di);
	tmm = time(0);
	dt = ctime(&tmm);
	if(verif)
		fichier << "thread n°" << this_thread::get_id() << " detruit chandelier a " << dt << endl;
	sem_post(&nb_th);
}

void epee(int* result, int* ressource)
{
	int u, v;
	time_t tmm;
	char* dt;
	bool verif=false;
	sem_wait(&nb_th);
	do
	{
		sem_getvalue(&fe, &u);			// verifie la disponibilite de la ressource
		if(u==0)
		{
			cout << "epee attend fer\n";			
		}
		sem_getvalue(&ar, &v);			// meme chose
		if(v==0)
		{
			cout << "epee attend argent\n";
		}
	}while(u==0 || v==0);
	sem_wait(&fe);
	ressource[5]--;
	if(ressource[5] == 0)
	{
		cout << "epee possede fer\n";
		sem_wait(&ar);
		ressource[0]--;
		if(ressource[0] == 0)
		{
			verif=true;
			cout << "epee possede argent\n";
			cout << "epee en creation\n";
			tmm = time(0);
			dt = ctime(&tmm);
			fichier << "thread n°" << this_thread::get_id() << " cree epee a " << dt << endl;
			this_thread::sleep_for(chrono::milliseconds(200));
			sem_wait(&res);
			result[5]++;
			sem_post(&res);
		}
		ressource[0]++;
		sem_post(&ar);	
	}
	ressource[5]++;
	sem_post(&fe);
	tmm = time(0);
	dt = ctime(&tmm);
	if(verif)
		fichier << "thread n°" << this_thread::get_id() << " detruit epee a " << dt << endl;
	sem_post(&nb_th);
}

void init_sem()
{
	if(sem_init(&res, 0, 1) != 0)
		cout << "raté res\n";

	if(sem_init(&liste, 0, 1) != 0)
		cout << "raté res\n";

	if(sem_init(&nb_th, 0, 6) != 0)
		cout << "raté nb_th\n";

	if(sem_init(&au, 0, 1) != 0)
		cout << "raté co\n";
	if(sem_init(&ar, 0, 1) != 0)
		cout << "raté ch\n";
	if(sem_init(&bo, 0, 1) != 0)
		cout << "raté ep\n";
	if(sem_init(&me, 0, 1) != 0)
		cout << "raté po\n";
	if(sem_init(&di, 0, 1) != 0)
		cout << "raté ta\n";
	if(sem_init(&fe, 0, 1) != 0)
		cout << "raté ba\n";
}

void destroy_sem()
{
	sem_destroy(&nb_th);
	sem_destroy(&bo);
	sem_destroy(&fe);
	sem_destroy(&au);
	sem_destroy(&bo);
	sem_destroy(&me);
	sem_destroy(&di);
	sem_destroy(&res);
}


int main()
{
	chrono::system_clock::time_point start = chrono::system_clock::now();
	string nom[6] {"nb_coupe", "nb_porte", "nb_table", "nb_bague", "nb_chandelier", "nb_epee"};		// nom des elements
	int* result = new int[6];				// nombre d'element
	int* ressource = new int[6];			// nombre de ressource
	int i, j=0, q=0;
	for(i=0; i<6; i++)
	{
		result[i] = 0;
		ressource[i] = 1;
	}

	init_sem();		// initialise les semaphores
	
	while(result[0] < 100 || result[1] < 100 || result[2] < 100 || result[3] < 100 || result[4] < 100 || result[5] < 100)	// verifie le nombre d'objets
	{
		sem_getvalue(&nb_th, &q);		// verifie le nombre de thread actif
		if(q>0)
		{	
			if(j%6==0)			// reparti plus equitablement les threads
			{
				thread coupe(coupe_de_vin, result, ressource);
				if(coupe.joinable())
					coupe.detach();
			}
			if(j%6==1)
			{
				thread tabl(table, result, ressource);
				if(tabl.joinable())
					tabl.detach();
			}
			if(j%6==2)
			{
				thread bag(bague, result, ressource);
				if(bag.joinable())
					bag.detach();
			}
			if(j%6==3)
			{
				thread epe(epee, result, ressource);
				if(epe.joinable())
					epe.detach();
			}
			if(j%6==4)
			{
				thread chand(chandelier, result, ressource);
				if(chand.joinable())
					chand.detach();
			}
			if(j%6==5)
			{
				thread port(porte, result, ressource);
				if(port.joinable())
					port.detach();
			}	

			j++;
		}
		
			
		// for(i=0; i<6; i++)
		// {
		// 	sem_wait(&res);
		// 	cout << nom[i] << " " << result[i] << endl;
		// 	sem_post(&res);
		// }
	}

	this_thread::sleep_for(chrono::seconds(3));			// affiche les resultats separement du reste du programme

	for(i=0; i<6; i++)
	{
		sem_wait(&res);
		cout << nom[i] << " " << result[i] << endl;
		sem_post(&res);
	}

	delete[] result; 
	delete[] ressource;
	destroy_sem();
	chrono::duration<double> nanosec = chrono::system_clock::now() - start;
	cout << " Duree : " << nanosec.count() << " s\n";
	fichier.close();
	return 0;
}