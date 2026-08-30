#include <stdio.h>
#include <stdlib.h>

void AFFICHAGE_BOISSONS()	//╔ ═ ╠ ╩ ╗ ║ ╝ ╚ ╬ ╦ ╣
{
	printf("╔══════════════════╦════╦═════╗\n");
	printf("║BOISSON           ║PRIX║CHOIX║\n");
	printf("╠══════════════════╬════╬═════╣\n");
	printf("║Café court        ║0.70║  0  ║\n");
	printf("║Café long         ║0.80║  1  ║\n");
	printf("║Café au lait      ║0.60║  2  ║\n");
	printf("║Chocolat          ║0.50║  3  ║\n");
	printf("║Lait              ║0.50║  4  ║\n");
	printf("║Thé au citron     ║0.60║  5  ║\n");
	printf("║Thé à la menthe   ║0.90║  6  ║\n");
	printf("║Thé au gingembre  ║1.20║  7  ║\n");
	printf("║Thé au miel       ║1.40║  8  ║\n");
	printf("║Zlatan tea        ║8.75║  9  ║\n");
	printf("╚══════════════════╩════╩═════╝\n");
}

void ACHAT_BOISSON(double MONNAIE_DISPO[], double PRIX_BOISSONS[], int Choix, double Somme)
{
	double d, v, m;
	int i, z, g;
	int w = 0;
	d = PRIX_BOISSONS[Choix];
	v = Somme - d + 0.000000001;
	printf("La monnaie à rendre est de : %.2lf\n", v);
	for(i=9; i>=0; i--)
	{
		do
		{
			v = v - MONNAIE_DISPO[i];
			if(v < 0)
			{
				v = v + MONNAIE_DISPO[i];
				z = 1;	
			}else	
			{
				w = w + 1;
				z = 0;
			}			
		}while(z == 0);
		if(w > 0)
		{
			printf("%d x %.2lf\n", w, MONNAIE_DISPO[i]);
		}
		w = 0;
	}
	printf("Votre Boisson est prête !!!\n");			
}

void REMP_NOMS_BOISSONS(char BOISSONS[10][20], int Choix)
{
	int i;
	printf("Votre ");
	for(i=0; i<20; i++)
	{
		printf("%c", BOISSONS[Choix][i]);
	}
	printf(" est prêt !!!\n");
}

void ACHAT_BOISSON_2(double MONNAIE_DISPO[], int NB_PIECES_DISPO[], double PRIX_BOISSONS[],int Choix, double Somme)
{
	double d, v, f;
	int i, j, k, l, o, z;
	int w = 0;
	int y = 0;
	int TAB[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};		//pour l'affichage du nombre de pièce du même type donné au client
	int RENDRE_MONNAIE_ERREUR[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};	//pour rendre la monnaie au client si erreur il y a
	d = PRIX_BOISSONS[Choix];
	f = Somme + 0.00000001;		//0.00000000001 est ici pour éviter des erreurs dans le calcul
	v = Somme - d + 0.000000001;		//même chose
	for(i=9; i>=0; i--)				//on incrémente l'argent que le client a inséré (avec le tri glouton) 
	{						//donc on peut toujours voir l'erreur avec les petites monnaie (0.01, 0.02, 0.05 etc)	
		do
		{
			f = f - MONNAIE_DISPO[i];
			if(f < 0)			//si la monnaie est inferieur à 0 on le remet au dessus avec le bon montant
			{
				f = f + MONNAIE_DISPO[i];
				z = 1;	
			}else	
			{
				RENDRE_MONNAIE_ERREUR[i] = RENDRE_MONNAIE_ERREUR[i] + 1;		//Tableau pour décrémenter l'argent mis par le client si il y a une erreur
				w = w + 1;		//utilisé pour incrémenter les pièces mise par le client
				z = 0;
			}			
		}while(z == 0);
		if(w > 0)
		{
			NB_PIECES_DISPO[i] = NB_PIECES_DISPO[i] + w;					//incrémentation de l'argent mis par le client
		}
		w = 0;
		
	}
	printf("La monnaie à rendre est de : %.2lf\n", v);
	for(j=9; j>=0; j--)
	{
		do
		{
			
			if(NB_PIECES_DISPO[j] > 0)		//on vérifie si il reste des pièces d'un type dans le distributeur
			{
				v = v - MONNAIE_DISPO[j];
				if(v < 0)			//si la monnaie est inferieur à 0 on le remet au dessus avec le bon montant
				{	
					v = v + MONNAIE_DISPO[j];
					z = 1;	
				}else		
				{
					NB_PIECES_DISPO[j] = NB_PIECES_DISPO[j] - 1;				//décrémentation des pièces dans le distributeur
					RENDRE_MONNAIE_ERREUR[j] = RENDRE_MONNAIE_ERREUR[j] + 1;		//incrémentation pour rendre la monnaie au client en cas d'erreur
					y = y + 1;			//nombre de pièce du même type donné
					z = 0;
				}	
			}else
			{
				z = 1;
			}				
		}while(z == 0);
		TAB[j] = y;
		y = 0;
	}
	if(v < 0.00001)		//vérifier si toute la monnaie à été compter
	{
		for(k=9; k>=0; k--)
		{	
			if(TAB[k] > 0)
			{
				printf("%d x %.2lf\n", TAB[k], MONNAIE_DISPO[k]);		//affichage des pièces rendus
			}
		}
		printf("Votre Boisson est prête !!!\n");
	}else				//afficher erreur et rendre la monnaie du client (la monnaie du client est soustraie du total de pièce du distibuteur mais n'est pas montrer sur le terminal)
	{
		printf("ATTENTION : OPERATION INTERROMPUE !!!\n");
		printf("Le distibuteur ne dispose pas assez de pieces pour vous rendre la monnaie\n");
		for(o=0; o<10; o++)
		{
			while(RENDRE_MONNAIE_ERREUR[o] > 0)		//rendre la monnaie au client a cause de l'erreur(pas afficher sur le terminal)
			{
				RENDRE_MONNAIE_ERREUR[o] = RENDRE_MONNAIE_ERREUR[o] - 1;
				NB_PIECES_DISPO[o]= NB_PIECES_DISPO[o] + 1;
			}
		}		
	}		
	for(l=0; l<10; l++)
	{
		if(NB_PIECES_DISPO[l] == 0)		//affichage des monnaies qui ne sont plus dans le distributeur
		{	
			printf("ATTENTION le distributeur ne délivre plus de pièces de %.2lf\n", MONNAIE_DISPO[l]);
		}
	}	
	printf("\n");
}


void ACHAT_BOISSON_3(double MONNAIE_DISPO[], int NB_PIECES_DISPO[], double PRIX_BOISSONS[],int Choix, double Somme, char BOISSONS[10][20])
{
	double d, v, f, p;
	int i, j, k, l, o, z, u, b, a;
	int w = 0;
	int y = 0;
	int TAB[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int RENDRE_MONNAIE_ERREUR[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	d = PRIX_BOISSONS[Choix];
	f = Somme + 0.00000001;
	v = Somme - d + 0.000000001;
	printf("Quelle est votre pièce ou billet préféré dans la monnaie ? : ");
	do		//choix de la monnaie que l'on préfère
	{
		b = 0;
		if(scanf("%lf", &p) == 1)
		{
			for(u=0; u<10; u++)
			{
				if(MONNAIE_DISPO[u] == p)
				{
					b = 1;
					a = u;
				}
			}	
		}
		if(b == 0)
		{
			printf("Cette pièce ou billet n'est pas conforme, recommencez !!!\n");
		}		
	}while(b == 0);
	for(i=9; i>=0; i--)
	{
		do
		{
			f = f - MONNAIE_DISPO[i];
			if(f < 0)
			{
				f = f + MONNAIE_DISPO[i];
				z = 1;	
			}else	
			{
				RENDRE_MONNAIE_ERREUR[i] = RENDRE_MONNAIE_ERREUR[i] + 1;
				w = w + 1;
				z = 0;
			}			
		}while(z == 0);
		if(w > 0)
		{
			NB_PIECES_DISPO[i] = NB_PIECES_DISPO[i] + w;
		}
		w = 0;
		
	}
	printf("La monnaie à rendre est de : %.2lf\n", v);
	for(j=a; j>=0; j--)
	{
		do
		{
			
			if(NB_PIECES_DISPO[j] > 0)
			{
				v = v - MONNAIE_DISPO[j];
				if(v < 0)
				{	
					v = v + MONNAIE_DISPO[j];
					z = 1;	
				}else		
				{
					NB_PIECES_DISPO[j] = NB_PIECES_DISPO[j] - 1;
					RENDRE_MONNAIE_ERREUR[j] = RENDRE_MONNAIE_ERREUR[j] + 1;
					y = y + 1;
					z = 0;
				}	
			}else
			{
				z = 1;
			}				
		}while(z == 0);
		TAB[j] = y;
		y = 0;
	}
	if(v < 0.00001)
	{
		for(k=a; k>=0; k--)
		{	
			if(TAB[k] > 0)
			{
				printf("%d x %.2lf\n", TAB[k], MONNAIE_DISPO[k]);
			}
		}
		REMP_NOMS_BOISSONS(BOISSONS, Choix);		//affichage de la boisson choisi lors de la transaction
	}else
	{
		printf("ATTENTION : OPERATION INTERROMPUE !!!\n");
		printf("Le distibuteur ne dispose pas assez de pieces pour vous rendre la monnaie\n");
		for(o=0; o<10; o++)
		{
			while(RENDRE_MONNAIE_ERREUR[o] > 0)
			{
				RENDRE_MONNAIE_ERREUR[o] = RENDRE_MONNAIE_ERREUR[o] - 1;
				NB_PIECES_DISPO[o] = NB_PIECES_DISPO[o] + 1;
			}
		}		
	}		
	for(l=0; l<10; l++)
	{
		if(NB_PIECES_DISPO[l] == 0)
		{	
			printf("ATTENTION le distributeur ne délivre plus de pièces de %.2lf\n", MONNAIE_DISPO[l]);
		}
	}	
	printf("\n");
}
	
int main()
{
	int Choix; 
	double Somme, p;
	int h = 0;
	int v, w, q, b, a, u;
	double MONNAIE_DISPO[10] = {0.01, 0.02, 0.05, 0.10, 0.20, 0.50, 1.00, 2.00, 5.00, 10.0};
	double PRIX_BOISSONS[10] = {0.70, 0.80, 0.60, 0.50, 0.50, 0.60, 0.90, 1.20, 1.40, 8.75};
	int NB_PIECES_DISPO[10] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};		//nombre de pièce disponible par type
	char BOISSONS[10][20] = {{'C', 'a', 'f', 'e', ' ', 'c', 'o', 'u', 'r', 't'}, {'C', 'a' , 'f', 'e', ' ', 'l', 'o', 'n', 'g'}, {'C', 'a', 'f', 'e', ' ', 'a', 'u', ' ', 'l', 'a', 'i', 't'}, {'C', 'h', 'o', 'c', 'o', 'l', 'a', 't'}, {'L', 'a', 'i', 't'}, {'T', 'h', 'e', ' ', 'a', 'u', ' ', 'c', 'i', 't', 'r', 'o', 'n'}, {'T', 'h', 'e', ' ', 'a', ' ', 'l', 'a', ' ', 'm', 'e', 'n', 't', 'h', 'e'}, {'T', 'h', 'e', ' ', 'a', 'u', ' ', 'g', 'i', 'n', 'g', 'e', 'm', 'b', 'r', 'e'}, {'T', 'h', 'e', ' ', 'a', 'u', ' ', 'm', 'i', 'e', 'l'}, {'Z', 'l', 'a', 't', 'a', 'n', ' ', 't', 'e', 'a'}};
	AFFICHAGE_BOISSONS();
	do
	{
		printf("Quel est votre choix (taper 10 ou + pour quitter)\n");
		scanf("%d", &Choix);
		if(Choix == 0 || Choix == 1 || Choix == 2 || Choix == 3 || Choix == 4 || Choix == 5 || Choix == 6 || Choix == 7 || Choix == 8 || Choix == 9) //vérification du choix
		{
			h = 1;
			printf("Donner votre montant (inférieur à 20)\n");
			do		//vérification de l'argent incrémenter par le client
			{
				scanf("%lf", &Somme);
				if(Somme > 20)
				{
					printf("Veuillez saisir un montant inférieur à 20€\n");
					v = 1;
				}else
				{
					v = 0;
				}	
				if(Somme < PRIX_BOISSONS[Choix])
				{
					printf("ATTENTION : le montant donné est inférieur au prix indiqué !!!\nVeuillez ressaisir un montant\n");
					w = 1;
				}else
				{
					w = 0;
				}
				if(v != w)
				{
					q = 1;
				}else
				{
					q = 0;
				}			
			}while(q == 1);
			ACHAT_BOISSON_3(MONNAIE_DISPO, NB_PIECES_DISPO, PRIX_BOISSONS, Choix, Somme, BOISSONS);
		}else
		{
			h = 0;
		}	
	}while(h == 1);
	printf("A BIENTOT\n");
}	
