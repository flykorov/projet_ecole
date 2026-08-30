int lire_lettre()
{
	int chiffre, l;
	FILE* fic = fopen("compression_carte.txt", "r");
	chiffre = fgetc(fic);
	l = fgetc(fic);
	chiffre = chiffre * 10 + l;
	fclose(fic);
	return chiffre;
}

int lire_fic()
{
	int chiffre;
	FILE* fic = fopen("compression_carte.txt", "r");
	chiffre = fgetc(fic);
	fclose(fic);
	return chiffre;
}

void creer_arbre_decom(struct arbre* mec, int* tab, int i)
{
	mec = malloc(sizeof(struct arbre));
	if(tab[i] == 1)
	{
		creer_arbre_decom(mec, tab, i++);
	}else
	{
		lettre = malloc(sizeof(struct lettre));
		lettre->num = 
	}
}

int* tab_dec(int nb_char)
{
	int i, k, n;
	FILE* fic = fopen("compression_carte.txt", "r");
	fscanf(scrib, "%d\n", &k);
	int tab[nb_char*3];
	for(i=0; i<nb_char*3; i++)
	{
		k = fgetc(fic);
		if(k == 1)
		{
			tab[i] = k;
		}else
		{
			tab[i] = k;
			k = fgetc(fic);
			n = fgetc(fic);
			k = k*10+n;
			i++
			tab[i] = k;
		}
	}
	fclose(fic);
	return tab;
}

void decompresser_carte(int nb_char)
{
	struct init_comp* pourquoi = malloc(sizeof(struct init_comp));
	pourquoi->debut = NULL;
	struct compression* comp = malloc(sizeof(struct comp));
	comp->lettre = NULL;
	comp->debut = NULL;
	comp->suivant = NULL;
	int chiffre;
	int tab[nb_char*3] = tab_dec(nb_char);
	FILE* fic = fopen("compression_carte.txt", "r");
	fscanf(scrib, "%d\n", &comp->occ);
	for(i=0; i<nb_char*3; i++)
	{

	}
}

int i=0, j, min, ville_min, nb_marque=0;
	// int nb_arete = nb_ville-1;
	// int tab[nb_ville] = {0};
	// struct cartographie* carto = lacrimatica->debut;
	// struct poids_min* camarchepas = ouaient->debut;
	// while(i<nb_arete)
	// {
	// 	if(camarchepas->marque == 0)
	// 	{
	// 		min = carto->distance[0];
	// 		ville_min = 0;
	// 		for(j=1; j<carto->nb_con; j++)
	// 		{
	// 			if(min > carto->distance[j])
	// 			{
	// 				min = carto->distance[j];
	// 				ville_min = carto->connexion[j];
	// 			}
	// 		}
	// 		camarchepas->nb_con++;
	// 		camarchepas->connexion = (int*)realloc(camarchepas->connexion, camarchepas->nb_con * sizeof(int));
	// 		camarchepas->distance = (float*)realloc(camarchepas->distance, camarchepas->nb_con * sizeof(float));
	// 		camarchepas->connexion[camarchepas->nb_con-1] = min;
	// 		camarchepas->distance[camarchepas->nb_con-1] = ville_min;
	// 		camarchepas->marque++;
	// 		ville_min = camarchepas->id;
	// 		while(camarchepas->id != ville_min)
	// 			camarchepas = camarchepas->suivant;
	// 		camarchepas->nb_con++;
	// 		camarchepas->connexion = (int*)realloc(camarchepas->connexion, camarchepas->nb_con * sizeof(int));
	// 		camarchepas->distance = (float*)realloc(camarchepas->distance, camarchepas->nb_con * sizeof(float));
	// 		camarchepas->connexion[camarchepas->nb_con-1] = min;
	// 		camarchepas->distance[camarchepas->nb_con-1] = ville_min;
	// 		camarchepas->marque++;
	// 		i++;
	// 		camarchepas = ouaient->debut;
	// 	}else
	// 	{
	// 		camarchepas = camarchepas->suivant;
	// 	}
	// }
	
	
// while(encore == true)
			// {
			// 	encore = false;
			// 	for(u=0; u<nb_ville; u++)
			// 	{
			// 		if(adg[tab_un[k]][u] == 1)
			// 		{
			// 			etat = true;
			// 			for(v=0; v<m; v++)
			// 				if(tab_un[v] == u)
			// 					etat = false;
			// 			if(etat)
			// 			{
			// 				tab_un[m] = u;
			// 				m++;
			// 				encore = true;
			// 			}
			// 		}
			// 		if(adg[tab_deux[l]][u] == 1)
			// 		{
			// 			etat = true;
			// 			for(v=0; v<n; v++)
			// 				if(tab_deux[v] == u)
			// 					etat = false;
			// 			if(etat)
			// 			{
			// 				tab_deux[n] = u;
			// 				n++;
			// 				encore = true;
			// 			}
			// 		}
			// 	}
			// 	k++;
			// 	l++;
			// }
