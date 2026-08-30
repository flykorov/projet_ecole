using namespace std;

void affichage()
{
	cout << "-------------------------------------\n\n";
	cout << "(0) Afficher la rue\n";
	cout << "(1) Ajouter une maison\n";
	cout << "(2) Supprimer une maison\n";
	cout << "(3) Rechercher une maison\n";
	cout << "(4) Quitter la rue\n\n";
	cout << "-------------------------------------\n\n";
	cout << "Notre choix : ";
}

void affichage_rue(list<int> rue)
{
	list<int>::iterator it;
	for(it=rue.begin(); it != rue.end(); it++)
		cout << *it << " ";
	cout << endl;
}

list<int> ajouter_maison(list<int> rue)
{
	int i=0, num;
	list<int>::iterator it;
	do
	{
		cout << "quel est le # civique de la maison? (entre 400 et 600) : ";
		cin >> num;
	}while(num<400 || num>600);
	for(it=rue.begin(); it!=rue.end(); it++)
	{
		if(*it == num)
		{
			cout << "maison " << num << " existe deja\n";
			return rue;
		}
		if(*it > num)
		{
			rue.insert(it--, num);
			return rue;
		}	
	}
	rue.push_back(num);
	return rue;
}

list<int> supprimer_maison(list<int> rue)
{
	int num;
	do
	{
		cout << "quel est le # civique de la maison? (entre 400 et 600) : ";
		cin >> num;
	}while(num<400 || num>600);
	int taille = rue.size();
	rue.remove(num);
	if(taille == rue.size())
		cout << "maison " << num << " inexistante\n";
	return rue;
}

void rechercher_maison(list <int> rue)
{
	int choix, num;
	list<int>::iterator it;
	bool aff=false;
	do
	{
		cout << "quel est le # civique de la maison? (entre 400 et 600) : ";
		cin >> num;
	}while(num<400 || num>600);
	for(it=rue.begin(); it!=rue.end(); it++)
	{
		if(*it == num)
			aff = true;
	}
	if(aff)
		cout << "la maison " << num << " existe\n";
	else
		cout << "maison " << num << " inexistante\n";
}
