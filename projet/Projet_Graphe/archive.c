void dechiffre_sequence(int** mat, int** tab, char* s1, char* s2, int nb_char, int bin)
{
	FILE* fic = fopen(s1, "r");
	int i=0, j=0, k, l, f, nb_occ, chiffre;
	for(i=0; i<nb_char; i++)
	{
		for(j=0; j<bin; j++)
		{
			mat[i][j] = -1;				//init à -1 pour facilite la lecture et verification
		}
	}
	i=0;
	j=0;
	fscanf(fic, "%d\n", &nb_occ);	// nb_occ = 1172
										// 1 0 48 1 1 1 0 49 1 1 0 50 1 0 52 0 51 1 1 0 54 0 53 1 1 0 57 0 56 0 55 1 0 13 0 1 0 0 32
	while((chiffre = fgetc(fic)) != '\n')		//recreation de la sequence binaire de chaque caractere ASCII
	{

		if(chiffre == 49)
		{
			mat[i][j] = 0;					//mat est le sequence binaire du chiffre
			j++;
		}
		if(chiffre == 48)
		{
			f = fgetc(fic);
			tab[i][0] = f-48;				//tab est le chiffre pour les ASCII
			f = fgetc(fic);
			tab[i][1] = f-48;
			for(l=0; l<bin; l++)
			{
				if(mat[i][l] == 0)
					k=l;
			}
			i++;
			if(i < nb_char)
			{
				for(l=0; l<k; l++)
					mat[i][l] = mat[i-1][l];
				mat[i][k] = 1;
			}
			j=l+1;
		}
	}

	FILE* scrib = fopen(s2, "w");
	i=0;
	j=0;
	int n;
	int compteur;
	int pouce[nb_char];				//tableau servant à connaitre le caractère
	for(i=0; i<nb_char; i++)
		pouce[i] = 1;
	l=0;

	while(l < nb_occ)		//decompression du fichier en l'écrivant dans un nouveau
	{
		// printf("1\n");
		compteur = 0;
		// printf("%d\n", compteur);
		chiffre = fgetc(fic);
		// printf("%d %d\n", l, chiffre);
		for(i=0; i<nb_char; i++)
		{
			if(mat[i][j] == chiffre-48 && pouce[i] == 1)
			{
				pouce[i] = 1;			//si = 1 sequence binaire d'un chiffre corect
				compteur++;
			}else
			{
				pouce[i] = 0;			//si = 0 sequence binaire incorect
			}
		}
		j++;
		if(compteur == 1)
		{
			for(i=0; i<nb_char; i++)
			{
				if(pouce[i] == 1)
				{
					k=i;
					pouce[i] = 0;
				}
			}
			n = tab[k][0]*10 + tab[k][1];
			fputc(n, scrib);
			l++;
			j=0;
			for(i=0; i<nb_char; i++)
			{
				pouce[i] = 1;
			}
		}

	}
	fclose(scrib);
	fclose(fic);
}