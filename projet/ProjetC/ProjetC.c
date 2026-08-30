#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>

#define clear() printf("\033[H\033[J") 
#define curseur(x,y) printf("\033[%d;%dH", (x), (y))

//Choix du niveau de difficulté
int chooseDificulty(int *z)
{
	int d, a;
	do
	{
		printf("Choisisser votre niveau de difficulté (1 = facile, 2 = moyen, 3 = difficile)\n");
		if(scanf("%d", &d) == 1)
		{
			switch(d)						//Choix du niveau et affichage de la maquette selon le niveau
			{
				case 1:
				system("cat maquettefac.txt");
				a = 1;						//Pour sortir de la boucle
				*z = 3;
				break;
				case 2:
				system("cat maquettemoy.txt");
				a = 1;
				*z = 5;
				break;
				case 3:
				system("cat maquettedif.txt");
				a = 1;
				*z = 10;
				break;
				default:
				printf("Erreur lors du choix de difficulté, veuillez recommencer\n");
				a = 0;						//Pour recommencer la boucle
			}	
		}
		else
		{
			printf("Input error\n");
			return -1;	
		}		
	}while(a == 0);	
}

//Ecoute des différents sons
int playSound(int z, int order[])
{
	int i, a;
	for(i=0; i<z; i++)
	{
		a = rand() % 48;
		a = a + 1;
		switch(a)						//Lancement des différents sons
		{
			case 1:
			system("play -q grenouille.wav &");
			order[i] = a;
			break;
			case 2:
			system("play -q poussin.wav &");
			order[i] = a;
			break;
			case 3:
			system("play -q cheval.wav &");
			order[i] = a;
			break;
			case 4:
			system("play -q serpent.wav &");
			order[i] = a;
			break;
			case 5:
			system("play -q chameau.wav &");
			order[i] = a;
			break;
			case 6:
			system("play -q elephant.wav &");
			order[i] = a;
			break;
			case 7:
			system("play -q cochon.wav &");
			order[i] = a;
			break;
			case 8:
			system("play -q mouton.wav &");
			order[i] = a;
			break;
			case 9:
			system("play -q chien.wav &");
			order[i] = a;
			break;
			case 10:
			system("play -q poule.wav &");
			order[i] = a;
			break;
			case 11:
			system("play -q canard.wav &");
			order[i] = a;
			break;
			case 12:
			system("play -q singe.wav &");
			order[i] = a;
			break;
			case 13:
			system("play -q extincteur.wav &");
			order[i] = a;
			break;
			case 14:
			system("play -q photo.wav &");
			order[i] = a;
			break;
			case 15:
			system("play -q 'telephone cadran.wav' &");
			order[i] = a;
			break;
			case 16:
			system("play -q television.wav &");
			order[i] = a;
			break;
			case 17:
			system("play -q radio.wav &");
			order[i] = a;
			break;
			case 18:
			system("play -q marteau.wav &");
			order[i] = a;
			break;
			case 19:
			system("play -q chronometre.wav &");
			order[i] = a;
			break;
			case 20:
			system("play -q 'chasse deau.wav' &");
			order[i] = a;
			break;
			case 21:
			system("play -q douche.wav &");
			order[i] = a;
			break;
			case 22:
			system("play -q camera.wav &");
			order[i] = a;
			break;
			case 23:
			system("play -q 'telephone message.wav' &");
			order[i] = a;
			break;
			case 24:
			system("play -q disque.wav &");
			order[i] = a;
			break;
			case 25:
			system("play -q ballonfoot.wav &");
			order[i] = a;
			break;
			case 26:
			system("play -q basket.wav &");
			order[i] = a;
			break;
			case 27:
			system("play -q billard.wav &");
			order[i] = a;
			break;
			case 28:
			system("play -q 'tennis de table.wav' &");
			order[i] = a;
			break;
			case 29:
			system("play -q arc.wav &");
			order[i] = a;
			break;
			case 30:
			system("play -q golf.wav &");
			order[i] = a;
			break;
			case 31:
			system("play -q boxe.wav &");
			order[i] = a;
			break;
			case 32:
			system("play -q patinage.wav &");
			order[i] = a;
			break;
			case 33:
			system("play -q halterophilie.wav &");
			order[i] = a;
			break;
			case 34:
			system("play -q natation.wav &");
			order[i] = a;
			break;
			case 35:
			system("play -q 'trot de cheval.wav' &");
			order[i] = a;
			break;
			case 36:
			system("play -q bowling.wav &");
			order[i] = a;
			break;
			case 37:
			system("play -q voiture.wav &");
			order[i] = a;
			break;
			case 38:
			system("play -q vroumvroum.wav &");
			order[i] = a;
			break;
			case 39:
			system("play -q police.wav &");
			order[i] = a;
			break;
			case 40:
			system("play -q ambulance.wav &");
			order[i] = a;
			break;
			case 41:
			system("play -q moto.wav &");
			order[i] = a;
			break;
			case 42:
			system("play -q skate.wav &");
			order[i] = a;
			break;
			case 43:
			system("play -q bus.wav &");
			order[i] = a;
			break;
			case 44:
			system("play -q train.wav &");
			order[i] = a;
			break;
			case 45:
			system("play -q helicoptere.wav &");
			order[i] = a;
			break;
			case 46:
			system("play -q avion.wav &");
			order[i] = a;
			break;
			case 47:
			system("play -q fusée.wav &");
			order[i] = a;
			break;
			case 48:
			system("play -q grosbateau.wav &");
			order[i] = a;
			break;
			default:
			printf("Error");
		}
		sleep(7);
	}
}

//Choix de l'ordre par le joueur
int playerResultat(int z, int resultat[z])
{
	int i, a, res, b;
	a = 26;
	curseur(41 - z, 3);
	printf("Veuillez saisir les sons mémoriser.");
	for(i=0 ; i<z; i++)
	{
		curseur(44 - z, a);
		scanf("%d", &res);
		curseur(46 - z, a);
		switch(res)		//Affichage des différents émojis
		{
			case 1:
			printf("🐸");
			break;
			case 2:
			printf("🐤");
			break;
			case 3:
			printf("🐎");
			break;
			case 4:
			printf("🐍");
			break;
			case 5:
			printf("🐪");
			break;
			case 6:
			printf("🐘");
			break;
			case 7:
			printf("🐷");
			break;
			case 8:
			printf("🐑");
			break;
			case 9:
			printf("🐕");
			break;
			case 10:
			printf("🐔");
			break;
			case 11:
			printf("🦆");
			break;
			case 12:
			printf("🐒");
			break;
			case 13:
			printf("🧯");
			break;
			case 14:
			printf("📸");
			break;
			case 15:
			printf("☎");
			break;
			case 16:
			printf("📺");
			break;
			case 17:
			printf("📻");
			break;
			case 18:
			printf("🔨");
			break;
			case 19:
			printf("⏰");
			break;
			case 20:
			printf("🚽");
			break;
			case 21:
			printf("🚿");
			break;
			case 22:
			printf("🎥");
			break;
			case 23:
			printf("📱");
			break;
			case 24:
			printf("💿");
			break;
			case 25:
			printf("⚽");
			break;
			case 26:
			printf("🏀");
			break;
			case 27:
			printf("🎱");
			break;
			case 28:
			printf("🏓");
			break;
			case 29:
			printf("🏹");
			break;
			case 30:
			printf("⛳");
			break;
			case 31:
			printf("🥊");
			break;
			case 32:
			printf("⛸");
			break;
			case 33:
			printf("🏋️‍♂️");
			break;
			case 34:
			printf("🏊‍");
			break;
			case 35:
			printf("🏇");
			break;
			case 36:
			printf("🎳");
			break;
			case 37:
			printf("🚙");
			break;
			case 38:
			printf("🏎");
			break;
			case 39:
			printf("🚔");
			break;
			case 40:
			printf("🚑");
			break;
			case 41:
			printf("🏍");
			break;
			case 42:
			printf("🛹");
			break;
			case 43:
			printf("🚍");
			break;
			case 44:
			printf("🚊");
			break;
			case 45:
			printf("🚁");
			break;
			case 46:
			printf("🛬");
			break;
			case 47:
			printf("🚀");
			break;
			case 48:
			printf("⛴");
			break;
			default:
			printf(" ");
		}		
		resultat[i] = res;		//Affecter la valeur choisir à la valeur du tableau correspondant
		a = a + 8;			//Pour réajuster le curseur
	}
}

//Changement de l'ordre si le joueur le souhaite
int changeNumber(int z, int resultat[])
{
	int i, a, b, c, e;
	int d = 0;
	do
	{	
		if(d == 1)			//Redemander au joueur si il veux changer une valeur
		{
			curseur(41 - z, 3);
			printf("Voulez-vous changer un autre de vos choix (0 pour non, 1 pour oui)");
			curseur(42 - z, 3);
			scanf("%d", &d);
			curseur(40 - z, 3);
			printf("                                                   ");
		}else				//Demander pour la première fois au joueur si il veux changer une valeur
		{
			curseur(41 - z, 3);
			printf("Voulez-vous changer vos choix (0 pour non, 1 pour oui)");
			curseur(42 - z, 3);
			scanf("%d", &d);
		}	
		if(d == 1)			//Demander lequel il veux changer
		{
			curseur(41 - z, 3);
			printf("                                                                         ");
			curseur(41 - z, 3);
			printf("Lequel voulez-vous changer?");
			curseur(42 - z, 3);
			printf("  ");
			curseur(42 - z, 3);
			scanf("%d", &c);
			if(z == 3)		//Redirection selon le niveau de difficulté
			{
				switch(c)	//Changement de la valeur à la case demander
				{
					case 1:
					curseur(44 - z, 26);
					printf("  ");
					curseur(44 - z, 26);
					scanf("%d", &e);
					resultat[0] = e;	//Affecter la valeur changer à l'endrois correspondant dans le tableau
					b = 1;			//Valeur utilisé pour redemander au joueur si il veut changer une autre valeur
					break;
					case 2:
					curseur(44 - z, 34);
					printf("  ");
					curseur(44 - z, 34);
					scanf("%d", &e);
					resultat[1] = e;
					b = 1;
					break;
					case 3:
					curseur(44 - z, 42);
					printf("  ");
					curseur(44 - z, 42);
					scanf("%d", &e);
					resultat[2] = e;
					b = 1;
					break;
					default:
					curseur(41 - z, 3);
					printf("                                      ");
					curseur(40 - z, 3);
					printf("Erreur lors de la prise du nombre");
					e = 0;			//Eviter que le programme affiche des émojis non voulu
					b = 1;			//Relancer la boucle
				}
			}
			if(z == 5)		//Redirection selon le niveau de difficulté
			{
				switch(c)	//Changement de la valeur à la case demander
				{
					case 1:
					curseur(44 - z, 26);
					printf("  ");
					curseur(44 - z, 26);
					scanf("%d", &e);
					resultat[0] = e;
					b = 1;
					break;
					case 2:
					curseur(44 - z, 34);
					printf("  ");
					curseur(44 - z, 34);
					scanf("%d", &e);
					resultat[1] = e;
					b = 1;
					break;
					case 3:
					curseur(44 - z, 42);
					printf("  ");
					curseur(44 - z, 42);
					scanf("%d", &e);
					resultat[2] = e;
					b = 1;
					break;
					case 4:
					curseur(44 - z, 50);
					printf("  ");
					curseur(44 - z, 50);
					scanf("%d", &e);
					resultat[3] = e;
					b = 1;
					break;
					case 5:
					curseur(44 - z, 58);
					printf("  ");
					curseur(44 - z, 58);
					scanf("%d", &e);
					resultat[4] = e;
					b = 1;
					break;
					default:
					curseur(41 - z, 3);
					printf("                                      ");
					curseur(40 - z, 3);
					printf("Erreur lors de la prise du nombre");
					e = 0;
					b = 1;
				}
			}
			if(z == 10)		//Redirection selon le niveau de difficulté
			{			
				switch(c)	//Changement de la valeur à la case demander
				{
					case 1:
					curseur(44 - z, 26);
					printf("  ");
					curseur(44 - z, 26);
					scanf("%d", &e);
					resultat[0] = e;
					b = 1;
					break;
					case 2:
					curseur(44 - z, 34);
					printf("  ");
					curseur(44 - z, 34);
					scanf("%d", &e);
					resultat[1] = e;
					b = 1;
					break;
					case 3:
					curseur(44 - z, 42);
					printf("  ");
					curseur(44 - z, 42);
					scanf("%d", &e);
					resultat[2] = e;
					b = 1;
					break;
					case 4:
					curseur(44 - z, 50);
					printf("  ");
					curseur(44 - z, 50);
					scanf("%d", &e);
					resultat[3] = e;
					b = 1;
					break;
					case 5:
					curseur(44 - z, 58);
					printf("  ");
					curseur(44 - z, 58);
					scanf("%d", &e);
					resultat[4] = e;
					b = 1;
					break;
					case 6:
					curseur(44 - z, 66);
					printf("  ");
					curseur(44 - z, 66);
					scanf("%d", &e);
					resultat[5] = e;
					b = 1;
					break;
					case 7:
					curseur(44 - z, 74);
					printf("  ");
					curseur(44 - z, 74);
					scanf("%d", &e);
					resultat[6] = e;
					b = 1;
					break;
					case 8:
					curseur(44 - z, 82);
					printf("  ");
					curseur(44 - z, 82);
					scanf("%d", &e);
					resultat[7] = e;
					b = 1;
					break;
					case 9:
					curseur(44 - z, 90);
					printf("  ");
					curseur(44 - z, 90);
					scanf("%d", &e);
					resultat[8] = e;
					b = 1;
					break;
					case 10:
					curseur(44 - z, 98);
					printf("  ");
					curseur(44 - z, 98);
					scanf("%d", &e);
					resultat[9] = e;
					b = 1;
					break;
					default:
					curseur(41 - z, 3);
					printf("                                      ");
					curseur(40 - z, 3);
					printf("Erreur lors de la prise du nombre");
					e = 0;
					b = 1;
				}
			}	
			switch(c)		//Pour afficher les émojis au bon endroit
			{
				case 1:
				a = 26;
				break;
				case 2:
				a = 34;
				break;
				case 3:
				a = 42;
				break;
				case 4:
				a = 50;
				break;
				case 5:
				a = 58;
				break;
				case 6:
				a = 66;
				break;
				case 7:
				a = 74;
				break;
				case 8:
				a = 82;
				break;
				case 9:
				a = 90;
				break;
				case 10:
				a = 98;
				break;
				default:
				;
			}	
			curseur(46 - z, a);
			switch(e)		//Afficher les émojis
			{
				case 1:
				printf("🐸");
				break;
				case 2:
				printf("🐤");
				break;
				case 3:
				printf("🐎");
				break;
				case 4:
				printf("🐍");
				break;
				case 5:
				printf("🐪");
				break;
				case 6:
				printf("🐘");
				break;
				case 7:
				printf("🐷");
				break;
				case 8:
				printf("🐑");
				break;
				case 9:
				printf("🐕");
				break;
				case 10:
				printf("🐔");
				break;
				case 11:
				printf("🦆");
				break;
				case 12:
				printf("🐒");
				break;
				case 13:
				printf("🧯");
				break;
				case 14:
				printf("📸");
				break;
				case 15:
				printf("☎");
				break;
				case 16:
				printf("📺");
				break;
				case 17:
				printf("📻");
				break;
				case 18:
				printf("🔨");
				break;
				case 19:
				printf("⏰");
				break;
				case 20:
				printf("🚽");
				break;
				case 21:
				printf("🚿");
				break;
				case 22:
				printf("🎥");
				break;
				case 23:
				printf("📱");
				break;
				case 24:
				printf("💿");
				break;
				case 25:
				printf("⚽");
				break;
				case 26:
				printf("🏀");
				break;
				case 27:
				printf("🎱");
				break;
				case 28:
				printf("🏓");
				break;
				case 29:
				printf("🏹");
				break;
				case 30:
				printf("⛳");
				break;
				case 31:
				printf("🥊");
				break;
				case 32:
				printf("⛸");
				break;
				case 33:
				printf("🏋️‍♂️");
				break;
				case 34:
				printf("🏊‍");
				break;
				case 35:
				printf("🏇");
				break;
				case 36:
				printf("🎳");
				break;
				case 37:
				printf("🚙");
				break;
				case 38:
				printf("🏎");
				break;
				case 39:
				printf("🚔");
				break;
				case 40:
				printf("🚑");
				break;
				case 41:
				printf("🏍");
				break;
				case 42:
				printf("🛹");
				break;
				case 43:
				printf("🚍");
				break;
				case 44:
				printf("🚊");
				break;
				case 45:
				printf("🚁");
				break;
				case 46:
				printf("🛬");
				break;
				case 47:
				printf("🚀");
				break;
				case 48:
				printf("⛴");
				break;
				default:
				;
			}
		}else		//Sortir de la boucle
		{
			b = 0;
		}
		curseur(42 - z, 3);
		printf("  ");
	}while(b == 1);
	curseur(41 - z, 3);
	printf("                                                                    ");
	curseur(42 - z, 3);
	printf("        ");
}				
	
//Verification de l'ordre mis par le joueur
int verificationResultat(int z, int order[], int resultat[])
{
	int i;
	int a = 26;
	int b = 0;
	for(i=0; i<z; i++)
	{
		curseur(48 - z, a);
		if(order[i] == resultat[i])		//Vérifier le resultat
		{
			printf("✅");
			b = b + 1;			//Compter le nombre de point obtenu
		}else
		{	
			printf("❌");
		}
		a = a + 8;				//Afficher les émojis au bon endroits
	}
	curseur(48 - z, a - 3);
	printf("Vous avez obtenu : %d/%d", b, z);	
}

//Effacer les textes en trop
void effacer(int z)
{
	int i;
	for(i = 0; i<z; i++)				//Pour les textes qui s'affiche lorsqu'un son ce joue
	{
		curseur(56 - z + i, 0);
		printf("                                                             ");
	}
}			

int main()
{	
	int z, b;
	srand(time(NULL));
	printf("Bonjour et bienvenue au jeu sonore de Arezki et Victor\n");
	do
	{
		chooseDificulty(&z);
		int order[z];
		int resultat[z];
		playSound(z, order);
		effacer(z);
		playerResultat(z, resultat);
		changeNumber(z, resultat);
		verificationResultat(z, order, resultat);
		curseur(52 - z, 3);
		printf("Voulez-vous rejouer? (0 pour non, 1 pour oui)");	//Demander au joueur si il veux rejouer
		curseur(53 - z, 3);
		scanf("%d", &b);
		curseur(56 - z, 0);
	}while(b == 1);						//Recommencer une partie
}
































	
