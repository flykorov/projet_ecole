// TP 3 systeme
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <cmath>
#include <fstream>
#include "struct.h"
using namespace std;

list<int> convert_dec_to_bin(int dec)
{
	int i;
	list<int> bin;
	list<int>::const_iterator cit;
	while(dec != 0 && dec != 1)					// convertion de decimal en binaire
	{
		int temp = dec % 2;
		bin.push_front(temp);
		dec /= 2;
	}
	bin.push_front(dec);
	// cout << bin.size() << endl;
	if(bin.size() < 16)							// verifie la taille de la list
		while(bin.size() < 16)					// ajoute des elements si > 16					
			bin.push_front(0);
	else if(bin.size() > 16)
		while(bin.size() > 16)					// enleve des elements si < 16
			bin.pop_front();

	// cout << bin.size() << endl;
	// for(cit=bin.begin(); cit!=bin.end(); cit++)
	// {
	// 	cout << *cit << " ";
	// }
	// cout << endl;
	return bin;
}

void divide_list(list<int>& div, vector<int>& page, vector<int>& offset)
{
	int i;
	for(i=0; i<8; i++)
	{
		page.push_back(div.front());		// prend les 8 premiers element pour faire la page
		div.pop_front();
	}

	// for(i=0; i<8; i++)
	// 	cout << page[i] << " ";
	// cout << endl;

	for(i=0; i<8; i++)
	{
		offset.push_back(div.front());		// prend les 8 derniers element pour faire l'offset
		div.pop_front();
	}

	// for(i=0; i<8; i++)
	// 	cout << offset[i] << " ";
	// cout << endl;
}

int convert_bin_to_dec(vector<int> bin)
{
	int i, res=0;
	for(i=0; i<8; i++)
	{
		res = res + bin[i] * pow(2, 8-i-1); 		// convertion binaire to decimal avec les puissance
	}
	// cout << res << endl;
	return res;
}

int bite_signe(int page, frame &f)
{
	unsigned int LENGTH = 1;
	ifstream fic("simuleDisque.bin", ios::binary);
	if(!fic.is_open())
	{
		cout << "erreur ouverture fichier bin\n";
		exit(1);
	}
	fic.seekg(page, ios::beg);					// ce positionne au bon endroit
	char a;
	int i, v;
	for(i=0; i<256; i++)						// lit tout la page de 256 bit
	{
		fic.read(&a, 1);
		v = (int)a;
		f.page.push_back(v);
	}
	// cout << v << endl;
	fic.close();
	return f.page[0];							// return le bit signe
}

bool verif_page(vector<adresse_logique> &add, adresse_logique &al, memoire &m, int &res)
{
	int k, j;
	bool verif;
	for(k=0; k<add.size(); k++)
	{
		verif = true;
		for(j=0; j<8; j++)
		{
			if(add[k].page[j] != al.page[j])		// verifie si la page est identique
			{
				verif = false;
			}
		}
		if(verif)									// si oui
		{
			add[k].offset = al.offset;				// affecte les differentes variable a modifie
			// cout << k << endl;
			res = k;								// return le numero de frame au pages identiques
			m.physique = k*256 + convert_bin_to_dec(al.offset);
			return true;		
		}
	}
	return false;
}


// partie 2
void ecrire_correct(vector<adresse_logique> &add ,vector<frame> &fra, vector<memoire> &mem)		// commentaire voir ce du TLB (partie 3)
{
	ifstream lec("addresses.txt");
	ofstream ecr("solution.txt");

	int i, l=0, d=0;
	for(i=0; i<1000; i++)
	{
		int a, k;
		lec >> a;

		frame f;
		adresse_logique al;
		memoire m;
		m.virtuelle = a;
		list<int> bin = convert_dec_to_bin(a);
		divide_list(bin, al.page, al.offset);
		if(verif_page(add, al, m, k))
		{
			d++;
			m.valeur = bite_signe(m.virtuelle, f);
			int j;
			for(j=0; j<256; j++)
				fra[k].page[j] = f.page[j];
		}else
		{
			l++;
			add.push_back(al);
			m.physique = (i-d)*256 + convert_bin_to_dec(al.offset);
			m.valeur = bite_signe(m.virtuelle, f);
			fra.push_back(f);
		}

		
		mem.push_back(m);
		
		ecr << "virtual address: "<< m.virtuelle <<" physical address: " << m.physique << " value: " << m.valeur /*<< " " << faux */<< endl;
	}
	cout << "page deja existante : " << (float)d/10 << " %" << endl << "nb page fault : " << (float)l/10 << " %" << endl;

	lec.close();
	ecr.close();
}

int least_recently_used_is_a_page(vector<TLB> &t, adresse_logique al)
{
	vector<TLB>::iterator it;
	bool verif;
	int i, j;
	for(i=0; i<t.size(); i++)
	{
		verif = true;
		for(j=0; j<8; j++)
		{
			if(t[i].page[j] != al.page[j])				// verifie si la page est dans le TLB
				verif = false;
		}
		if(verif)										// si oui
		{
			int res = t[i].lru;							// return le numero de frame

			// effectue le swap
			t.push_back(t[i]);							// affecte au TLB la derniere page utilise
			for(it=t.begin(); it!=t.end(); it++)
			{
				if(it->lru == t[i].lru)					// supprime la page venant d'etre utilise au centre du TLB
				{
					t.erase(it);
					return res;
				}
			}

			return res;
		}
	}
	return -1;
}

void least_recently_used_change_frame(vector<TLB> &t, adresse_logique al, int num)
{
	if(t.size() == 16)				// si il y a 16 bit page suprimme la premiere pour faire de la place dans le TLB
		t.erase(t.begin());
	TLB temp;
	for(int i=0; i<8; i++)
	{
		temp.page.push_back(al.page[i]);
	}
	temp.lru = num;
	t.push_back(temp);				// affecte la nouvelle bit page a la fin du TLB
}

// partie 3
void ecrire_TLB(vector<adresse_logique> &add ,vector<frame> &fra, vector<memoire> &mem, vector<TLB> &tlb)
{
	ifstream lec("addresses.txt");
	ofstream ecr("sol_TLB.txt");

	int i, l=0, d=0, nb_page_fault=0;
	for(i=0; i<1000; i++)
	{
		int a, k;
		lec >> a;

		frame f;
		adresse_logique al;
		memoire m;
		m.virtuelle = a;
		list<int> bin = convert_dec_to_bin(a);						// converti la memoire virtuelle en binaire
		divide_list(bin, al.page, al.offset);						// separe le chiffre binaire en 2, 8 bit gauche = page, 8 bit droit = offset  
		int res = least_recently_used_is_a_page(tlb, al);
		if(res == -1)
		{
			bool verif = verif_page(add, al, m, k);					// k numero de frame
			if(verif)
			{
				d++;												// compteur de page charge grace au frame
				m.valeur = bite_signe(m.virtuelle, f);				// valeur du bit signe + chargement de la page dans la frame (les 256 bits)
				int j;
				for(j=0; j<256; j++)
					fra[k].page[j] = f.page[j];						// change la page charge a la bonne frame
				least_recently_used_change_frame(tlb, al, k);		// change le TLB

			}else
			{
				add.push_back(al);
				m.physique = (i-d-l)*256 + convert_bin_to_dec(al.offset);		// adresse physique i pour le enieme chiffre pris, d pour le nombre de page deja charge grace a la frame, l pour le nombre de page charge grace au TLB
				m.valeur = bite_signe(m.virtuelle, f);							// valeur du bit signe + chargement de la page dans la frame (les 256 bits)
				fra.push_back(f);
				least_recently_used_change_frame(tlb, al, i-d-l);	// change le TLB
				nb_page_fault++;									// compteur de page_fault
			}
		}else
		{
			l++;													// compteur de page charge grace au TLB
			m.physique = (res)*256 + convert_bin_to_dec(al.offset);
			m.valeur = bite_signe(m.virtuelle, f);					// valeur du bit signe + chargement de la page dans la frame (les 256 bits)
			int j;
			for(j=0; j<256; j++)
				fra[res].page[j] = f.page[j];						// change la page charge a la bonne frame
		}
		
		mem.push_back(m);
		
		ecr << "Virtuelle : " << m.virtuelle << "\tPhysique : " << m.physique << "\tValeur dec : " << m.valeur << "\t Valeur bin : ";
		list<int> turlututu = convert_dec_to_bin(m.valeur);
		while(turlututu.empty() == 0)
		{
			ecr << turlututu.front();
			turlututu.pop_front();
			//chapeau pointu
		}
		ecr << endl;
		// ecr << "virtual address: "<< m.virtuelle <<" physical address: " << m.physique << " value: " << m.valeur /*<< " " << faux */<< endl;		// ecrit dans le fichier
	}
	cout << "nb page fault : " << (float)nb_page_fault/10 << " %" << endl;								// affiche le nombre de page fault
	cout << "page deja existante : " << (float)d/10 << " %" << endl << "page sauvee : " << (float)l/10 << " %" << endl;		// affiche le nombre de page charge grace au frame et au TLB

	lec.close();
	ecr.close();
}