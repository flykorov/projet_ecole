#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h> 
#include <time.h>
#include "code_ProjetProg.h"
#define curseur(x,y) printf("\033[%d;%dH", (x), (y))

int L, C;

void ncurses_initialiser()
{
  initscr();	        /* Demarre le mode ncurses */
  cbreak();	        /* Pour les saisies clavier (desac. mise en buffer) */
  noecho();             /* Desactive l'affichage des caracteres saisis */
  keypad(stdscr, TRUE);	/* Active les touches specifiques */
  refresh();            /* Met a jour l'affichage */
  curs_set(FALSE);      /* Masque le curseur */
}

void ncurses_souris() 
{
  if(!mousemask(ALL_MOUSE_EVENTS, NULL)) 
  {
    endwin();
    fprintf(stderr, "Erreur lors de l'initialisation de la souris.\n");
    exit(EXIT_FAILURE);
  }

  if(has_mouse() != TRUE) 
  {
    endwin();
    fprintf(stderr, "Aucune souris n'est détectée.\n");
    exit(EXIT_FAILURE);
  }
}

int click_souris()
{
  MEVENT event ;
  int ch;

  while((ch = getch()) != KEY_F(1)) 
  {
    switch(ch) 
    {
      case KEY_F(2): /*Pour quitter le jeu*/
	return 1;
      case KEY_MOUSE:
        if(getmouse(&event) == OK) 
	{
	  C = event.x;
	  L = event.y;
	  if(event.bstate & BUTTON1_CLICKED)
	  {
	    if (L < 51 && C < 132) /*Vous pouvez changer ici et mettre les dimensions de votre plateau de jeu*/
	    {
	    return 0;
	    }
	  }
	}
    }
  }
  return 0;
}

int CHOIX_MODE() // Fonction permettant de choisir le mode de jeu
{
	clear();
	int mode;
	printw("                          _________________ \n");
	printw("                         |                 |\n");
	printw("                         |  Jeu du Taquin  |\n");
	printw("                         |_________________|\n");
	printw("                          _________________ \n");
	printw("                         |                 |\n");
	printw("                         |   Mode de Jeu   |\n");
	printw("                         |_________________|\n");
	printw("                                                         \n");
	printw("             _________________         _________________ \n");
	printw("            |                 |       |                 |\n");
	printw("            |                 |       |                 |\n");
	printw("            |      Image      |       |    Chiffres     |\n");
	printw("            |                 |       |                 |\n");
	printw("            |_________________|       |_________________|\n");
	do
	{
		click_souris();
		if(L > 10 && L < 16 && C > 13 && C < 31)
		{
			mode = 1;
		}
		if(L > 10 && L < 16 && C > 39 && C < 57)
		{
			mode = 2;
		}
	}
	while(mode != 1 && mode != 2);
	return mode;	
}		

int CHOIX_DIF() // Fonction permettant de choisir la difficulté du jeu
{
	clear();
	int dif;
	printw("                          _________________ \n");
	printw("                         |                 |\n");
	printw("                         |  Jeu du Taquin  |\n");
	printw("                         |_________________|\n");
	printw("                          _________________ \n");
	printw("                         |                 |\n");
	printw("                         |   Difficulté    |\n");
	printw("                         |_________________|\n");
	printw("                                                         \n");
	printw("             _________________         _________________ \n");
	printw("            |                 |       |                 |\n");
	printw("            |                 |       |                 |\n");
	printw("            |     Facile      |       |    Difficile    |\n");
	printw("            |                 |       |                 |\n");
	printw("            |_________________|       |_________________|\n");
	do
	{
		click_souris();
		if(L > 10 && L < 16 && C > 13 && C < 31)
		{
			dif = 1;
		}	
		if(L > 10 && L < 16 && C > 39 && C < 57)
		{
			dif = 2;	
		}
	}
	while(dif != 1 && dif != 2);
	return dif;
}

int REJOUER() // Fonction permettant à l'utilisateur de rejouer ou non
{
	clear();
	int choix;
	printw("                          _________________ \n");
	printw("                         |                 |\n");
	printw("                         |  Jeu du Taquin  |\n");
	printw("                         |_________________|\n");
	printw("                      _________________________ \n");
	printw("                     |                         |\n");
	printw("                     |  Voulez-vous rejouer ?  |\n");
	printw("                     |_________________________|\n");
	printw("                                                         \n");
	printw("             _________________         _________________ \n");
	printw("            |                 |       |                 |\n");
	printw("            |                 |       |                 |\n");
	printw("            |       Oui       |       |       Non       |\n");
	printw("            |                 |       |                 |\n");
	printw("            |_________________|       |_________________|\n");
	do
	{
		click_souris();
		if(L > 10 && L < 16 && C > 13 && C < 31)
		{
			choix = 1;
		}
		if(L > 10 && L < 16 && C > 39 && C < 57)
		{
			choix = 0;
		}
	}
	while(choix != 1 && choix != 0);
	return choix;	
}

int AUREVOIR() // Fonction qui fait s'afficher l'écran quand l'utilisateur ne veut pas rejouer, le jeu s'éteint après 2 secondes sur cet écran
{
	clear();
	printw("                          _________________ \n");
	printw("                         |                 |\n");
	printw("                         |  Jeu du Taquin  |\n");
	printw("                         |_________________|\n");
	printw("                         ___________________ \n");
	printw("                        |                   |\n");
	printw("                        |Merci d'avoir joué!|\n");
	printw("                        |___________________|\n");
	refresh();
	sleep(2);
}

void MUSIQUE()
{
	system("play -q Etude_Op.25_No.1.wav repeat 100 &");
}		
       	 
int** INI_TAB_BI()
{
	int i;
	int** MAT;
	MAT = malloc(3 * sizeof(int));
	for(i=0; i<3; i++)
	{
		*(MAT+i) = malloc(3 * sizeof(int));	
	}
	return MAT;
}

void CHARG_MAT_ORDER(int** ORDER_TAB)
{
	int i, j;
	int v = 1;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			ORDER_TAB[i][j] = v;
			v++;	
		}
	}
}

void CHARG_MAT_NUM(int** NUM_IN_GAME)
{
	int i, j, k, l, a, t;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			NUM_IN_GAME[i][j] = 0;	
		}
	}
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
		
			
			do
			{
				t = 1;
				a = rand() % 9;
				a = a + 1;
				for(k = 0; k < 3; k++)
				{
					for(l = 0; l < 3; l++)
					{
						
						if(NUM_IN_GAME[k][l] == a)
						{
							t = 0;
						}
					}
				}
			}
			while(t == 0);
			NUM_IN_GAME[i][j] = a;
		}
	}			
}

void AFFICH_MAT_ORDER(int** ORDER_TAB)
{
	int i, j;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d ", ORDER_TAB[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}	

void AFFICH_MAT_NUM(int** NUM_IN_GAME)
{
	int i, j;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d ", NUM_IN_GAME[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}	

void LIB_MAT_ORDER(int** ORDER_TAB)
{
	int i;
	for(i = 0; i < 3; i++)
	{
		free(ORDER_TAB[i]);
		ORDER_TAB[i] = NULL;
	}
	free(ORDER_TAB);
	ORDER_TAB = NULL;	
}

void LIB_MAT_NUM(int** NUM_IN_GAME)
{
	int i;
	for(i = 0; i < 3; i++)
	{
		free(NUM_IN_GAME[i]);
		NUM_IN_GAME[i] = NULL;
	}
	free(NUM_IN_GAME);
	NUM_IN_GAME = NULL;	
}

int AFFICHE_CHIFFRE_MODE(int** NUM_IN_GAME) // Fonction permettant d'afficher les nombres sous forme de 8 cases
{
	int i, j, k, p, n;
	i = 0;
	for(k = 0; k < 3; k++)
	{
		for(j = 0; j < 3; j++)
		{
			switch(NUM_IN_GAME[i][j])	
			{
				case 1:
				printw(" 1111  ");
				break;	
				case 2:
				printw("  2222 ");
				break;
				case 3:
				printw("  3333 ");
				break;
				case 4:
				printw(" 44  44");
				break;
				case 5:
				printw(" 555555");
				break;
				case 6:
				printw("  6666 ");
				break;
				case 7:
				printw(" 777777");
				break;
				case 8:
				printw("  8888 ");
				break;
				case 9:
				printw("       ");
				break;
			}				
		}
		printw("\n");	
		for(j = 0; j < 3; j++)
		{
			switch(NUM_IN_GAME[i][j])
			{
				case 1:
				printw("   11  ");
				break;
				case 2:
				printw(" 22  22");
				break;
				case 3:
				printw(" 33  33");
				break;
				case 4:
				printw(" 44  44");
				break;
				case 5:
				printw(" 55    ");
				break;
				case 6:
				printw(" 66    ");
				break;
				case 7:
				printw("    77 ");
				break;
				case 8:
				printw(" 88  88");
				break;
				case 9:
				printw("       ");
				break;
			}			
		}
		printw("\n");	
		for(j = 0; j < 3; j++)
		{
			switch(NUM_IN_GAME[i][j])
			{
				case 1:
				printw("   11  ");
				break;
				case 2:
				printw("    22 ");
				break;
				case 3:
				printw("    333");
				break;
				case 4:
				printw(" 444444");
				break;
				case 5:
				printw(" 55555 ");
				break;
				case 6:
				printw(" 66666 ");
				break;
				case 7:
				printw("   77  ");
				break;
				case 8:
				printw("  8888 ");
				break;
				case 9:
				printw("       ");
				break;
			}					
		}
		printw("\n");	
		for(j = 0; j < 3; j++)
		{
			switch(NUM_IN_GAME[i][j])
			{
				case 1:
				printw("   11  ");
				break;
				case 2:
				printw("   22  ");
				break;
				case 3:
				printw(" 33  33");
				break;
				case 4:
				printw("     44");
				break;
				case 5:
				printw("     55");
				break;
				case 6:
				printw(" 66  66");
				break;
				case 7:
				printw("  77   ");
				break;
				case 8:
				printw(" 88  88");
				break;
				case 9:
				printw("       ");
				break;
			}				
		}
		printw("\n");	
		for(j = 0; j < 3; j++)
		{
			switch(NUM_IN_GAME[i][j])
			{
				case 1:
				printw(" 111111");
				break;
				case 2:
				printw(" 222222");
				break;
				case 3:
				printw("  3333 ");
				break;
				case 4:
				printw("     44");
				break;
				case 5:
				printw(" 55555 ");
				break;
				case 6:
				printw("  6666 ");
				break;
				case 7:
				printw(" 77    ");
				break;
				case 8:
				printw("  8888 ");
				break;
				case 9:
				printw("       ");
				break;
			}				
		}
		i++;
		printw("\n");
	}
}

int AFFICHE_IMAGE_MODE(int** NUM_IN_GAME) // Fonction permettant d'afficher l'image sous forme de 8 cases
{
        int i, j, k, p, n;
        i = 0;
	for(k = 0; k < 3; k++)
        {
                for(j = 0; j < 3; j++)
                {
                        switch(NUM_IN_GAME[i][j])
                        {
                                case 1:
                                printw("    1##-------##-------##-------##-  ");
                                break;
				 case 2:
                                printw("------##-------##-------##-------##--");
                                break;
                                case 3:
                                printw("-----##-------##-------##-------##1  ");
                                break;
                                case 4:
                                printw("   1                                1");
                                break;
                                case 5:
                                printw("  :  .-'   ..---! - !---..   `-.  :  ");
                                break;
                                case 6:
                                printw("1                                1   ");
                                break;
                                case 7:
                                printw("   1        `'   .    `.   :        1");
                                break;
                                case 8:
                                printw("  1                               1  ");
                                break;
                                case 9:
                                printw("                                     ");
                                break;
                        }
                }
                printw("\n");
		for(j = 0; j < 3; j++) 
                {
                        switch(NUM_IN_GAME[i][j])
                        {
                                case 1:
                                printw(" ------------------------------------");
                                break;
				 case 2:
                                printw("-------------------------------------");
                                break;
                                case 3:
                                printw("------------------------------------ ");
                                break;
                                case 4:
                                printw("   1  +-------------------------+   1");
                                break;
                                case 5:
                                printw(" .  :   .-'     !   !     `-.   :  . ");
                                break;
                                case 6:
                                printw("1   +-------------------------+  1   ");
                                break;
                                case 7:
                                printw("   1         .     '   ..  '        1");
                                break;
                                case 8:
                                printw("  1                               1  ");
                                break;
                                case 9:
                                printw("                                     ");
                                break;
                        }
                }
                printw("\n");
		for(j = 0; j < 3; j++) 
                {
                        switch(NUM_IN_GAME[i][j])
                        {
                                case 1:
                                printw("  ===================================");
                                break;
				 case 2:
                                printw("=====================================");
                                break;
                                case 3:
                                printw("===================================  ");
                                break;
                                case 4:
                                printw("   1  1 ----------------------- 1   1");
                                break;
                                case 5:
                                printw(" . .  .'    .----`-'----.    `.  . . ");
                                break;
                                case 6:
                                printw("1   1 ----------------------- 1  1   ");
                                break;
                                case 7:
                                printw("   1        ` '  ^        :'        1");
                                break;
                                case 8:
                                printw("  1                               1  ");
                                break;
                                case 9:
                                printw("                                     ");
                                break;
                        }
                }
                printw("\n");
		for(j = 0; j < 3; j++) 
                {
                        switch(NUM_IN_GAME[i][j])
                        {
                                case 1:
                                printw("    1!!1 ' ` 1!!1 ' ` 1!!1 ' ` 1!!1 '");
                                break;
				 case 2:
                                printw(" ` 1!!1 ' ` 1!!1 ' ` 1!!1 ' ` 1!!1 ' ");
                                break;
                                case 3:
                                printw("` 1!!1 ' ` 1!!1 ' ` 1!!1 ' ` 1!!1    ");
                                break;
                                case 4:
                                printw("   1  1 ..   .  .  .   .  .  .  1   1");
                                break;
                                case 5:
                                printw(" .. .'   .-'             `-.   `. .. ");
                                break;
                                case 6:
                                printw("1   1 .  .  .   .  .  . . ..  1  1   ");
                                break;
                                case 7:
                                printw("   1        ..  .   ` .   :         1");
                                break;
                                case 8:
                                printw("  1                               1  ");
                                break;
                                case 9:
                                printw("                                     ");
                                break;
                        }
                }
                printw("\n");
		for(j = 0; j < 3; j++) 
                {
                        switch(NUM_IN_GAME[i][j])
                        {
                                case 1:
                                printw("   :1  1     1  1     1  1     1  1  ");
                                break;
				 case 2:
                                printw("   1  1     1  1     1  1     1  1   ");
                                break;
                                case 3:
                                printw("  1  1     1  1     1  1     1  1:   ");
                                break;
                                case 4:
                                printw("   1  1  . .  . .  .  .   . . . 1   1");
                                break;
                                case 5:
                                printw("   :   .'                   `.   :   ");
                                break;
                                case 6:
                                printw("1   1 . . .. .  .  . .  .     1  1   ");
                                break;
                                case 7:
                                printw("   1        ..  .   ` .   :         1");
                                break;
                                case 8:
                                printw("  1                               1  ");
                                break;
                                case 9:
                                printw("                                     ");
                                break;
                        }
                }
                printw("\n");
		for(j = 0; j < 3; j++) 
                {
                        switch(NUM_IN_GAME[i][j])
                        {
                                case 1:
                                printw("   +---------------------------------");
                                break;
				case 2:
                                printw("-------------------------------------");
                                break;
                                case 3:
                                printw("---------------------------------+   ");
                                break;
                                case 4:
                                printw("   1  1 .  . ..  .  .   .    .  1   1");
                                break;
                                case 5:
                                printw("  :   '                       `   :  ");
                                break;
                                case 6:
                                printw("1   1  . .  .  . . .     . .  1  1   ");
                                break;
                                case 7:
                                printw("   1          :  !!   !  .'         1"); 
                                break;
                                case 8:
                                printw("  1                               1  ");
                                break;
                                case 9:
                                printw("                                     ");
                                break;
                        }
                }
                printw("\n");
		for(j = 0; j < 3; j++) 
                {
                        switch(NUM_IN_GAME[i][j])
                        {
                                case 1:
                                printw("   1                                 ");
                                break;
				 case 2:
                                printw("                                     ");
                                break;
                                case 3:
                                printw("                                 1   ");
                                break;
                                case 4:
                                printw("   1  1  .      . . . .   . ... 1   1");
                                break;
                                case 5:
                                printw(" :   '                         `   : ");
                                break;
                                case 6:
                                printw("1   1 .. . . .       . .  .   1  1   ");
                                break;
                                case 7:
                                printw("   1          ------------          1");
                                break;
                                case 8:
                                printw("  1                               1  ");
                                break;
                                case 9:
                                printw("                                     ");
                                break;
                        }
                }
                printw("\n");
		for(j = 0; j < 3; j++) 
                {
                        switch(NUM_IN_GAME[i][j])
                        {
                                case 1:
                                printw("=====================================");
                                break;
			   	 case 2:
                                printw("=====================================");
                                break;
                                case 3:
                                printw("=====================================");
                                break;
                                case 4:
                                printw("   1  1 .  . .      .  . . . .. 1   1");
                                break;
                                case 5:
                                printw(".' .'                           `. `.");
                                break;
                                case 6:
                                printw("1   1 ..  .   .   .    .  .   1  1   ");
                                break;
                                case 7:
                                printw("   1         /            |         1");
                                break;
                                case 8:
                                printw("  1                               1  ");
                                break;
                                case 9:
                                printw("                                     ");
                                break;
                        }
                }
                printw("\n");
		for(j = 0; j < 3; j++) 
                {
                        switch(NUM_IN_GAME[i][j])
                        {
                                case 1:
                                printw("|  U       U       U       U       U ");
                                break;
				case 2:
                                printw("      U       U       U       U      ");
                                break;
                                case 3:
                                printw(" U       U       U       U       U  /");
                                break;
                                case 4:
                                printw("   1  1 ======================= 1    ");
                                break;
                                case 5:
                                printw(":  '                             `  :");
                                break;
                                case 6:
                                printw("    1 ======================= 1  1   ");
                                break;
                                case 7:
                                printw("   1        ================        1");
                                break;
                                case 8:
                                printw("  1                               1  ");
                                break;
                                case 9:
                                printw("                                     ");
                                break;
                        }
                }
                printw("\n");
		for(j = 0; j < 3; j++) 
                {
                        switch(NUM_IN_GAME[i][j])
                        {
                                case 1:
                                printw(" ------------------------------------");
                                break;
				 case 2:
                                printw("-------------------------------------");
                                break;
                                case 3:
                                printw("------------------------------------ ");
                                break;
                                case 4:
                                printw("   1  +-------------------------+    ");
                                break;
                                case 5:
                                printw("' :                               : `");
                                break;
                                case 6:
                                printw("    +-------------------------+  1   ");
                                break;
                                case 7:
                                printw("  ===========1            1=========="); 
                                break;
                                case 8:
                                printw("  1                               1  ");
                                break;
                                case 9:
                                printw("                                     ");
                                break;
                        }
                }
                printw("\n");
		for(j = 0; j < 3; j++) 
                {
                        switch(NUM_IN_GAME[i][j])
                        {
                                case 1:
                                printw("   1U  U  U  U  U  U  U  U  U  U  U  ");
                                break;
				 case 2:
                                printw("U  U  U  U  U  U  U  U  U  U  U  U  U");
                                break;
                                case 3:
                                printw("  U  U  U  U  U  U  U  U  U  U  U1   ");
                                break;
                                case 4:
                                printw("   1                                !");
                                break;
                                case 5:
                                printw("  !                               !  ");
                                break;
                                case 6:
                                printw("!                                1   ");
                                break;
                                case 7:
                                printw("   1         1            1         1");
                                break;
                                case 8:
                                printw("  1                               1  ");
                                break;
                                case 9:
                                printw("                                     ");
                                break;
                        }
                }
                printw("\n");
		for(j = 0; j < 3; j++) 
                {
                        switch(NUM_IN_GAME[i][j])
                        {
                                case 1:
                                printw("   1 ..   .    .  .   . .   . .   . .");
                                break;
				 case 2:
                                printw("    .    .  .  .    .  .  . . .  .  .");
                                break;
                                case 3:
                                printw("  . .  .   . .   .  . .  .  .  . 1   ");
                                break;
                                case 4:
                                printw("   1                                1");
                                break;
                                case 5:
                                printw("  1                               1  ");
                                break;
                                case 6:
                                printw("1                                1   ");
                                break;
                                case 7:
                                printw("   1         1            1         1");
                                break;
                                case 8:
                                printw("  1                               1  ");
                                break;
                                case 9:
                                printw("                                     ");
                                break;
                        }
                }
                printw("\n");
		for(j = 0; j < 3; j++) 
                {
                        switch(NUM_IN_GAME[i][j])
                        {
                                case 1:
                                printw("   ::::::::::::::::::::::::::::::::::");
                                break;
				case 2:
                                printw(":::::::::::::::::::::::::::::::::::::");
                                break;
                                case 3:
                                printw("::::::::::::::::::::::::::::::::::   ");
                                break;
                                case 4:
                                printw(" ====================================");
                                break;
                                case 5:
                                printw("=====                           =====");
                                break;
                                case 6:
                                printw("==================================== ");
                                break;
                                case 7:
                                printw("  /---------/--------------|--------|");
                                break;
                                case 8:
                                printw("---|                             /---");
                                break;
                                case 9:
                                printw("                                     ");
                                break;
                        }
                }
                printw("\n");
		for(j = 0; j < 3; j++) 
                {
                        switch(NUM_IN_GAME[i][j])
                        {
                                case 1:
                                printw("   ----------------------------------");
                                break;
				case 2:
                                printw("---------------   -   ---------------");
                                break;
                                case 3:
                                printw("----------------------------------   ");
                                break;
                                case 4:
                                printw("   1                                1");
                                break;
                                case 5:
                                printw("  1                               1  ");
                                break;
                                case 6:
                                printw("1                                1   ");
                                break;
                                case 7:
                                printw("  1         1              1        1");
                                break;
                                case 8:
                                printw("1  1                             1  1");
                                break;
                                case 9:
                                printw("                                     ");
                                break;
                        }
                }
                printw("\n");
		for(j = 0; j < 3; j++) 
                {
                        switch(NUM_IN_GAME[i][j])
                        {
                                case 1:
                                printw("   1                                1");
                                break;
				 case 2:
                                printw("  .^.....      `:   :'      .....^.  ");
                                break;
                                case 3:
                                printw("1                                1   ");
                                break;
                                case 4:
                                printw("   1---------------------------------");
                                break;
                                case 5:
                                printw("--1                               1--");
                                break;
                                case 6:
                                printw("---------------------------------1   ");
                                break;
                                case 7:
                                printw("  -----------------------------------");
                                break;
                                case 8:
                                printw("-------------------------------------");
                                break;
                                case 9:
                                printw("                                     ");
                                break;
                        }
                }
		i++;
                printw("\n");
      }
}


	
int CHIFFRE_MODE_FAC(int** ORDER_TAB, int** NUM_IN_GAME) // Fait fonctionner le mode chiffre en difficulté facile
{
	int g, i, j, n;
	do
	{
		n = 0;
		clear();
		AFFICHE_CHIFFRE_MODE(NUM_IN_GAME);
		click_souris();
		if(L > 0 && L < 6 && C > 1 && C < 8) //NUM_IN_GAME[0][0]
		{
			if(NUM_IN_GAME[1][0] == 9 || NUM_IN_GAME[0][1] == 9 || NUM_IN_GAME[1][1] == 9)
			{
				if(NUM_IN_GAME[1][0] == 9)
				{
					g = NUM_IN_GAME[0][0];
					NUM_IN_GAME[0][0] = 9;
					NUM_IN_GAME[1][0] = g;
				}
				if(NUM_IN_GAME[0][1] == 9)
				{
					g = NUM_IN_GAME[0][0];
					NUM_IN_GAME[0][0] = 9;
					NUM_IN_GAME[0][1] = g;
				}
				if(NUM_IN_GAME[1][1] == 9)
				{
					g = NUM_IN_GAME[0][0];
					NUM_IN_GAME[0][0] = 9;
					NUM_IN_GAME[1][1] = g;
				}
			}
		}
		if(L > 0 && L < 6 && C > 8 && C < 15)  //NUM_IN_GAME[0][1]
		{
			if(NUM_IN_GAME[0][0] == 9 || NUM_IN_GAME[1][0] == 9 || NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[1][2] == 9 || NUM_IN_GAME[0][2] == 9)
			{
				if(NUM_IN_GAME[0][0] == 9)
				{
					g = NUM_IN_GAME[0][1];
					NUM_IN_GAME[0][1] = 9;
					NUM_IN_GAME[0][0] = g;
				}
				if(NUM_IN_GAME[1][0] == 9)
				{
					g = NUM_IN_GAME[0][1];
					NUM_IN_GAME[0][1] = 9;
					NUM_IN_GAME[1][0] = g;
				}
				if(NUM_IN_GAME[1][1] == 9)
				{
					g = NUM_IN_GAME[0][1];
					NUM_IN_GAME[0][1] = 9;
					NUM_IN_GAME[1][1] = g;
				}
				if(NUM_IN_GAME[1][2] == 9)
				{
					g = NUM_IN_GAME[0][1];
					NUM_IN_GAME[0][1] = 9;
					NUM_IN_GAME[1][2] = g;
				}
				if(NUM_IN_GAME[0][2] == 9)
				{
					g = NUM_IN_GAME[0][1];
					NUM_IN_GAME[0][1] = 9;
					NUM_IN_GAME[0][2] = g;
				}
			}
		}
		if(L > 0 && L < 6 && C > 15 && C < 22)  //NUM_IN_GAME[0][2]
		{
			if(NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[0][1] == 9 || NUM_IN_GAME[1][2] == 9)
			{
				if(NUM_IN_GAME[1][2] == 9)
				{
					g = NUM_IN_GAME[0][2];
					NUM_IN_GAME[0][2] = 9;
					NUM_IN_GAME[1][2] = g;
				}
				if(NUM_IN_GAME[0][1] == 9)
				{
					g = NUM_IN_GAME[0][2];
					NUM_IN_GAME[0][2] = 9;
					NUM_IN_GAME[0][1] = g;
				}
				if(NUM_IN_GAME[1][1] == 9)
				{
					g = NUM_IN_GAME[0][2];
					NUM_IN_GAME[0][2] = 9;
					NUM_IN_GAME[1][1] = g;
				}
			}
		}
		if(L > 5 && L < 11 && C > 1 && C < 8)  //NUM_IN_GAME[1][0]
		{
			if(NUM_IN_GAME[0][0] == 9 || NUM_IN_GAME[0][1] == 9 || NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[2][0] == 9 || NUM_IN_GAME[2][1] == 9)
			{
				if(NUM_IN_GAME[0][0] == 9)
				{
					g = NUM_IN_GAME[1][0];
					NUM_IN_GAME[1][0] = 9;
					NUM_IN_GAME[0][0] = g;
				}
				if(NUM_IN_GAME[0][1] == 9)
				{
					g = NUM_IN_GAME[1][0];
					NUM_IN_GAME[1][0] = 9;
					NUM_IN_GAME[0][1] = g;
				}
				if(NUM_IN_GAME[1][1] == 9)
				{
					g = NUM_IN_GAME[1][0];
					NUM_IN_GAME[1][0] = 9;
					NUM_IN_GAME[1][1] = g;
				}
				if(NUM_IN_GAME[2][0] == 9)
				{
					g = NUM_IN_GAME[1][0];
					NUM_IN_GAME[1][0] = 9;
					NUM_IN_GAME[2][0] = g;
				}
				if(NUM_IN_GAME[2][1] == 9)
				{
					g = NUM_IN_GAME[1][0];
					NUM_IN_GAME[1][0] = 9;
					NUM_IN_GAME[2][1] = g;
				}
			}
		}
		if(L > 5 && L < 11 && C > 8 && C < 15)  //NUM_IN_GAME[1][1]
		{
			if(NUM_IN_GAME[1][1] != 9)
			{
				if(NUM_IN_GAME[0][0] == 9)
				{
					g = NUM_IN_GAME[1][1];
					NUM_IN_GAME[1][1] = 9;
					NUM_IN_GAME[0][0] = g;
				}
				if(NUM_IN_GAME[0][1] == 9)
				{
					g = NUM_IN_GAME[1][1];
					NUM_IN_GAME[1][1] = 9;
					NUM_IN_GAME[0][1] = g;
				}
				if(NUM_IN_GAME[0][2] == 9)
				{
					g = NUM_IN_GAME[1][1];
					NUM_IN_GAME[1][1] = 9;
					NUM_IN_GAME[0][2] = g;
				}
				if(NUM_IN_GAME[2][0] == 9)
				{
					g = NUM_IN_GAME[1][1];
					NUM_IN_GAME[1][1] = 9;
					NUM_IN_GAME[2][0] = g;
				}
				if(NUM_IN_GAME[2][1] == 9)
				{
					g = NUM_IN_GAME[1][1];
					NUM_IN_GAME[1][1] = 9;
					NUM_IN_GAME[2][1] = g;
				}
				if(NUM_IN_GAME[2][2] == 9)
				{
					g = NUM_IN_GAME[1][1];
					NUM_IN_GAME[1][1] = 9;
					NUM_IN_GAME[2][2] = g;
				}
				if(NUM_IN_GAME[1][0] == 9)
				{
					g = NUM_IN_GAME[1][1];
					NUM_IN_GAME[1][1] = 9;
					NUM_IN_GAME[1][0] = g;
				}
				if(NUM_IN_GAME[1][2] == 9)
				{
					g = NUM_IN_GAME[1][1];
					NUM_IN_GAME[1][1] = 9;
					NUM_IN_GAME[1][2] = g;
				}
			}
		}
		if(L > 5 && L < 11 && C > 15 && C < 22)  //NUM_IN_GAME[1][2]
		{
			if(NUM_IN_GAME[0][2] == 9 || NUM_IN_GAME[0][1] == 9 || NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[2][2] == 9 || NUM_IN_GAME[2][1] == 9)
			{
				if(NUM_IN_GAME[0][2] == 9)
				{
					g = NUM_IN_GAME[1][2];
					NUM_IN_GAME[1][2] = 9;
					NUM_IN_GAME[0][2] = g;
				}
				if(NUM_IN_GAME[0][1] == 9)
				{
					g = NUM_IN_GAME[1][2];
					NUM_IN_GAME[1][2] = 9;
					NUM_IN_GAME[0][1] = g;
				}
				if(NUM_IN_GAME[1][1] == 9)
				{
					g = NUM_IN_GAME[1][2];
					NUM_IN_GAME[1][2] = 9;
					NUM_IN_GAME[1][1] = g;
				}
				if(NUM_IN_GAME[2][2] == 9)
				{
					g = NUM_IN_GAME[1][2];
					NUM_IN_GAME[1][2] = 9;
					NUM_IN_GAME[2][2] = g;
				}
				if(NUM_IN_GAME[2][1] == 9)
				{
					g = NUM_IN_GAME[1][2];
					NUM_IN_GAME[1][2] = 9;
					NUM_IN_GAME[2][1] = g;
				}
			}
		}
		if(L > 10 && L < 16 && C > 1 && C < 8)  //NUM_IN_GAME[2][0]
		{
			if(NUM_IN_GAME[1][0] == 9 || NUM_IN_GAME[2][1] == 9 || NUM_IN_GAME[1][1] == 9)
			{
				if(NUM_IN_GAME[1][0] == 9)
				{
					g = NUM_IN_GAME[2][0];
					NUM_IN_GAME[2][0] = 9;
					NUM_IN_GAME[1][0] = g;
				}
				if(NUM_IN_GAME[2][1] == 9)
				{
					g = NUM_IN_GAME[2][0];
					NUM_IN_GAME[2][0] = 9;
					NUM_IN_GAME[2][1] = g;
				}
				if(NUM_IN_GAME[1][1] == 9)
				{
					g = NUM_IN_GAME[2][0];
					NUM_IN_GAME[2][0] = 9;
					NUM_IN_GAME[1][1] = g;
				}
			}
		}
		if(L > 10 && L < 16 && C > 8 && C < 15)  //NUM_IN_GAME[2][1]
		{
			if(NUM_IN_GAME[1][2] == 9 || NUM_IN_GAME[1][0] == 9 || NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[2][2] == 9 || NUM_IN_GAME[2][0] == 9)
			{
				if(NUM_IN_GAME[1][2] == 9)
				{
					g = NUM_IN_GAME[2][1];
					NUM_IN_GAME[2][1] = 9;
					NUM_IN_GAME[1][2] = g;
				}
				if(NUM_IN_GAME[1][0] == 9)
				{
					g = NUM_IN_GAME[2][1];
					NUM_IN_GAME[2][1] = 9;
					NUM_IN_GAME[1][0] = g;
				}
				if(NUM_IN_GAME[1][1] == 9)
				{
					g = NUM_IN_GAME[2][1];
					NUM_IN_GAME[2][1] = 9;
					NUM_IN_GAME[1][1] = g;
				}
				if(NUM_IN_GAME[2][2] == 9)
				{
					g = NUM_IN_GAME[2][1];
					NUM_IN_GAME[2][1] = 9;
					NUM_IN_GAME[2][2] = g;
				}
				if(NUM_IN_GAME[2][0] == 9)
				{
					g = NUM_IN_GAME[2][1];
					NUM_IN_GAME[2][1] = 9;
					NUM_IN_GAME[2][0] = g;
				}
			}
		}
		if(L > 10 && L < 16 && C > 15 && C < 22)  //NUM_IN_GAME[2][2]
		{
			if(NUM_IN_GAME[1][2] == 9 || NUM_IN_GAME[2][1] == 9 || NUM_IN_GAME[1][1] == 9)
			{
				if(NUM_IN_GAME[1][2] == 9)
				{
					g = NUM_IN_GAME[2][2];
					NUM_IN_GAME[2][2] = 9;
					NUM_IN_GAME[1][2] = g;
				}
				if(NUM_IN_GAME[2][1] == 9)
				{
					g = NUM_IN_GAME[2][2];
					NUM_IN_GAME[2][2] = 9;
					NUM_IN_GAME[2][1] = g;
				}
				if(NUM_IN_GAME[1][1] == 9)
				{
					g = NUM_IN_GAME[2][2];
					NUM_IN_GAME[2][2] = 9;
					NUM_IN_GAME[1][1] = g;
				}
			}
		}
		for(i=0; i<3; i++)
		{
			for(j=0; j<3; j++)
			{
				if(ORDER_TAB[i][j] == NUM_IN_GAME[i][j])
				{
					n++;
				}
			}
		}			
	}
	while(n != 9);
	clear();
	AFFICHE_CHIFFRE_MODE(NUM_IN_GAME);
	refresh();
	sleep(2);
}	
				
int CHIFFRE_MODE_DIF(int** ORDER_TAB, int** NUM_IN_GAME) // Fait fonctionner le mode chiffre en difficulté difficile
{
	int g, i, j, n;
	do
	{
		n = 0;
		clear();
		AFFICHE_CHIFFRE_MODE(NUM_IN_GAME);
		click_souris();
		if(L > 0 && L < 6 && C > 1 && C < 8) //NUM_IN_GAME[0][0]
		{
			if(NUM_IN_GAME[1][0] == 9 || NUM_IN_GAME[0][1] == 9)
			{
				if(NUM_IN_GAME[1][0] == 9)
				{
					g = NUM_IN_GAME[0][0];
					NUM_IN_GAME[0][0] = 9;
					NUM_IN_GAME[1][0] = g;
				}
				if(NUM_IN_GAME[0][1] == 9)
				{
					g = NUM_IN_GAME[0][0];
					NUM_IN_GAME[0][0] = 9;
					NUM_IN_GAME[0][1] = g;
				}
			}
		}
		if(L > 0 && L < 6 && C > 8 && C < 15)  //NUM_IN_GAME[0][1]
		{
			if(NUM_IN_GAME[0][0] == 9 || NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[0][2] == 9)
			{
				if(NUM_IN_GAME[0][0] == 9)
				{
					g = NUM_IN_GAME[0][1];
					NUM_IN_GAME[0][1] = 9;
					NUM_IN_GAME[0][0] = g;
				}
				if(NUM_IN_GAME[1][1] == 9)
				{
					g = NUM_IN_GAME[0][1];
					NUM_IN_GAME[0][1] = 9;
					NUM_IN_GAME[1][1] = g;
				}
				if(NUM_IN_GAME[0][2] == 9)
				{
					g = NUM_IN_GAME[0][1];
					NUM_IN_GAME[0][1] = 9;
					NUM_IN_GAME[0][2] = g;
				}
			}
		}
		if(L > 0 && L < 6 && C > 15 && C < 22)  //NUM_IN_GAME[0][2]
		{
			if(NUM_IN_GAME[0][1] == 9 || NUM_IN_GAME[1][2] == 9)
			{
				if(NUM_IN_GAME[1][2] == 9)
				{
					g = NUM_IN_GAME[0][2];
					NUM_IN_GAME[0][2] = 9;
					NUM_IN_GAME[1][2] = g;
				}
				if(NUM_IN_GAME[0][1] == 9)
				{
					g = NUM_IN_GAME[0][2];
					NUM_IN_GAME[0][2] = 9;
					NUM_IN_GAME[0][1] = g;
				}
			}
		}
		if(L > 5 && L < 11 && C > 1 && C < 8)  //NUM_IN_GAME[1][0]
		{
			if(NUM_IN_GAME[0][0] == 9 || NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[2][0] == 9)
			{
				if(NUM_IN_GAME[0][0] == 9)
				{
					g = NUM_IN_GAME[1][0];
					NUM_IN_GAME[1][0] = 9;
					NUM_IN_GAME[0][0] = g;
				}
				if(NUM_IN_GAME[1][1] == 9)
				{
					g = NUM_IN_GAME[1][0];
					NUM_IN_GAME[1][0] = 9;
					NUM_IN_GAME[1][1] = g;
				}
				if(NUM_IN_GAME[2][0] == 9)
				{
					g = NUM_IN_GAME[1][0];
					NUM_IN_GAME[1][0] = 9;
					NUM_IN_GAME[2][0] = g;
				}
			}
		}
		if(L > 5 && L < 11 && C > 8 && C < 15)  //NUM_IN_GAME[1][1]
		{
			if(NUM_IN_GAME[0][1] == 9 || NUM_IN_GAME[2][1] == 9 || NUM_IN_GAME[1][0] == 9 || NUM_IN_GAME[1][2] == 9)
			{
				if(NUM_IN_GAME[0][1] == 9)
				{
					g = NUM_IN_GAME[1][1];
					NUM_IN_GAME[1][1] = 9;
					NUM_IN_GAME[0][1] = g;
				}
				if(NUM_IN_GAME[2][1] == 9)
				{
					g = NUM_IN_GAME[1][1];
					NUM_IN_GAME[1][1] = 9;
					NUM_IN_GAME[2][1] = g;
				}
				if(NUM_IN_GAME[1][0] == 9)
				{
					g = NUM_IN_GAME[1][1];
					NUM_IN_GAME[1][1] = 9;
					NUM_IN_GAME[1][0] = g;
				}
				if(NUM_IN_GAME[1][2] == 9)
				{
					g = NUM_IN_GAME[1][1];
					NUM_IN_GAME[1][1] = 9;
					NUM_IN_GAME[1][2] = g;
				}
			}
		}
		if(L > 5 && L < 11 && C > 15 && C < 22)  //NUM_IN_GAME[1][2]
		{
			if(NUM_IN_GAME[0][2] == 9 || NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[2][2] == 9)
			{
				if(NUM_IN_GAME[0][2] == 9)
				{
					g = NUM_IN_GAME[1][2];
					NUM_IN_GAME[1][2] = 9;
					NUM_IN_GAME[0][2] = g;
				}
				if(NUM_IN_GAME[1][1] == 9)
				{
					g = NUM_IN_GAME[1][2];
					NUM_IN_GAME[1][2] = 9;
					NUM_IN_GAME[1][1] = g;
				}
				if(NUM_IN_GAME[2][2] == 9)
				{
					g = NUM_IN_GAME[1][2];
					NUM_IN_GAME[1][2] = 9;
					NUM_IN_GAME[2][2] = g;
				}
			}
		}
		if(L > 10 && L < 16 && C > 1 && C < 8)  //NUM_IN_GAME[2][0]
		{
			if(NUM_IN_GAME[1][0] == 9 || NUM_IN_GAME[2][1] == 9)
			{
				if(NUM_IN_GAME[1][0] == 9)
				{
					g = NUM_IN_GAME[2][0];
					NUM_IN_GAME[2][0] = 9;
					NUM_IN_GAME[1][0] = g;
				}
				if(NUM_IN_GAME[2][1] == 9)
				{
					g = NUM_IN_GAME[2][0];
					NUM_IN_GAME[2][0] = 9;
					NUM_IN_GAME[2][1] = g;
				}
			}
		}
		if(L > 10 && L < 16 && C > 8 && C < 15)  //NUM_IN_GAME[2][1]
		{
			if(NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[2][2] == 9 || NUM_IN_GAME[2][0] == 9)
			{
				if(NUM_IN_GAME[1][1] == 9)
				{
					g = NUM_IN_GAME[2][1];
					NUM_IN_GAME[2][1] = 9;
					NUM_IN_GAME[1][1] = g;
				}
				if(NUM_IN_GAME[2][2] == 9)
				{
					g = NUM_IN_GAME[2][1];
					NUM_IN_GAME[2][1] = 9;
					NUM_IN_GAME[2][2] = g;
				}
				if(NUM_IN_GAME[2][0] == 9)
				{
					g = NUM_IN_GAME[2][1];
					NUM_IN_GAME[2][1] = 9;
					NUM_IN_GAME[2][0] = g;
				}
			}
		}
		if(L > 10 && L < 16 && C > 15 && C < 22)  //NUM_IN_GAME[2][2]
		{
			if(NUM_IN_GAME[1][2] == 9 || NUM_IN_GAME[2][1] == 9)
			{
				if(NUM_IN_GAME[1][2] == 9)
				{
					g = NUM_IN_GAME[2][2];
					NUM_IN_GAME[2][2] = 9;
					NUM_IN_GAME[1][2] = g;
				}
				if(NUM_IN_GAME[2][1] == 9)
				{
					g = NUM_IN_GAME[2][2];
					NUM_IN_GAME[2][2] = 9;
					NUM_IN_GAME[2][1] = g;
				}
			}
		}
		for(i=0; i<3; i++)
		{
			for(j=0; j<3; j++)
			{
				if(ORDER_TAB[i][j] == NUM_IN_GAME[i][j])
				{
					n++;
				}
			}
		}			
	}
	while(n != 9);
	clear();
	AFFICHE_CHIFFRE_MODE(NUM_IN_GAME);
	refresh();
	sleep(2);
}				

int IMAGE_MODE_FAC(int** ORDER_TAB, int** NUM_IN_GAME) // Fait fonctionner le mode image en difficulté facile
{
        int g, i, j, n;
        do
        {
                n = 0;
                clear();
                AFFICHE_IMAGE_MODE(NUM_IN_GAME);
                click_souris();
                if(L > 0 && L < 16 && C > 0 && C < 39) //NUM_IN_GAME[0][0]
                {
                        if(NUM_IN_GAME[1][0] == 9 || NUM_IN_GAME[0][1] == 9 || NUM_IN_GAME[1][1] == 9)
                        {
                                if(NUM_IN_GAME[1][0] == 9)
                                {
                                        g = NUM_IN_GAME[0][0];
                                        NUM_IN_GAME[0][0] = 9;
                                        NUM_IN_GAME[1][0] = g;
                                }
                                if(NUM_IN_GAME[0][1] == 9)
                                {
                                        g = NUM_IN_GAME[0][0];
                                        NUM_IN_GAME[0][0] = 9;
                                        NUM_IN_GAME[0][1] = g;
                                }
                                if(NUM_IN_GAME[1][1] == 9)
                                {
                                        g = NUM_IN_GAME[0][0];
                                        NUM_IN_GAME[0][0] = 9;
                                        NUM_IN_GAME[1][1] = g;
                                }
                        }
                }
		if(L > 0 && L < 16 && C > 38 && C < 76)  //NUM_IN_GAME[0][1]
                {
                        if(NUM_IN_GAME[0][0] == 9 || NUM_IN_GAME[1][0] == 9 || NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[1][2] == 9 || NUM_IN_GAME[0][2] == 9)
                        {
                                if(NUM_IN_GAME[0][0] == 9)
                                {
                                        g = NUM_IN_GAME[0][1];
                                        NUM_IN_GAME[0][1] = 9;
                                        NUM_IN_GAME[0][0] = g;
                                }
                                if(NUM_IN_GAME[1][0] == 9)
                                {
                                        g = NUM_IN_GAME[0][1];
                                        NUM_IN_GAME[0][1] = 9;
                                        NUM_IN_GAME[1][0] = g;
                                }
                                if(NUM_IN_GAME[1][1] == 9)
                                {
                                        g = NUM_IN_GAME[0][1];
                                        NUM_IN_GAME[0][1] = 9;
                                        NUM_IN_GAME[1][1] = g;
                                }
                                if(NUM_IN_GAME[1][2] == 9)
                                {
                                        g = NUM_IN_GAME[0][1];
                                        NUM_IN_GAME[0][1] = 9;
                                        NUM_IN_GAME[1][2] = g;
                                }
                                if(NUM_IN_GAME[0][2] == 9)
                                {
                                        g = NUM_IN_GAME[0][1];
                                        NUM_IN_GAME[0][1] = 9;
                                        NUM_IN_GAME[0][2] = g;
                                }
                        }
                }
		if(L > 0 && L < 16 && C > 75 && C < 114)  //NUM_IN_GAME[0][2]
                {
                        if(NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[0][1] == 9 || NUM_IN_GAME[1][2] == 9)
                        {
                                if(NUM_IN_GAME[1][2] == 9)
                                {
                                        g = NUM_IN_GAME[0][2];
                                        NUM_IN_GAME[0][2] = 9;
                                        NUM_IN_GAME[1][2] = g;
                                }
                                if(NUM_IN_GAME[0][1] == 9)
                                {
                                        g = NUM_IN_GAME[0][2];
                                        NUM_IN_GAME[0][2] = 9;
                                        NUM_IN_GAME[0][1] = g;
                                }
                                if(NUM_IN_GAME[1][1] == 9)
                                {
                                        g = NUM_IN_GAME[0][2];
                                        NUM_IN_GAME[0][2] = 9;
                                        NUM_IN_GAME[1][1] = g;
                                }
                        }
                }
		if(L > 15 && L < 31 && C > 0 && C < 39)  //NUM_IN_GAME[1][0]
                {
                        if(NUM_IN_GAME[0][0] == 9 || NUM_IN_GAME[0][1] == 9 || NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[2][0] == 9 || NUM_IN_GAME[2][1] == 9)
                        {
                                if(NUM_IN_GAME[0][0] == 9)
                                {
                                        g = NUM_IN_GAME[1][0];
                                        NUM_IN_GAME[1][0] = 9;
                                        NUM_IN_GAME[0][0] = g;
                                }
                                if(NUM_IN_GAME[0][1] == 9)
                                {
                                        g = NUM_IN_GAME[1][0];
                                        NUM_IN_GAME[1][0] = 9;
                                        NUM_IN_GAME[0][1] = g;
                                }
                                if(NUM_IN_GAME[1][1] == 9)
                                {
                                        g = NUM_IN_GAME[1][0];
                                        NUM_IN_GAME[1][0] = 9;
                                        NUM_IN_GAME[1][1] = g;
                                }
                                if(NUM_IN_GAME[2][0] == 9)
                                {
                                        g = NUM_IN_GAME[1][0];
                                        NUM_IN_GAME[1][0] = 9;
                                        NUM_IN_GAME[2][0] = g;
                                }
                                if(NUM_IN_GAME[2][1] == 9)
                                {
                                        g = NUM_IN_GAME[1][0];
                                        NUM_IN_GAME[1][0] = 9;
                                        NUM_IN_GAME[2][1] = g;
                                }
                        }
                }
		if(L > 15 && L < 31 && C > 38 && C < 76)  //NUM_IN_GAME[1][1]
                {
                        if(NUM_IN_GAME[1][1] != 9)
                        {
                                if(NUM_IN_GAME[0][0] == 9)
                                {
                                        g = NUM_IN_GAME[1][1];
                                        NUM_IN_GAME[1][1] = 9;
                                        NUM_IN_GAME[0][0] = g;
                                }
                                if(NUM_IN_GAME[0][1] == 9)
                                {
                                        g = NUM_IN_GAME[1][1];
                                        NUM_IN_GAME[1][1] = 9;
                                        NUM_IN_GAME[0][1] = g;
                                }
                                if(NUM_IN_GAME[0][2] == 9)
                                {
                                        g = NUM_IN_GAME[1][1];
                                        NUM_IN_GAME[1][1] = 9;
                                        NUM_IN_GAME[0][2] = g;
                                }
                                if(NUM_IN_GAME[2][0] == 9)
                                {
                                        g = NUM_IN_GAME[1][1];
                                        NUM_IN_GAME[1][1] = 9;
                                        NUM_IN_GAME[2][0] = g;
                                }
                                if(NUM_IN_GAME[2][1] == 9)
                                {
                                        g = NUM_IN_GAME[1][1];
                                        NUM_IN_GAME[1][1] = 9;
                                        NUM_IN_GAME[2][1] = g;
                                }
                                if(NUM_IN_GAME[2][2] == 9)
                                {
                                        g = NUM_IN_GAME[1][1];
                                        NUM_IN_GAME[1][1] = 9;
                                        NUM_IN_GAME[2][2] = g;
                                }
                                if(NUM_IN_GAME[1][0] == 9)
                                {
                                        g = NUM_IN_GAME[1][1];
                                        NUM_IN_GAME[1][1] = 9;
                                        NUM_IN_GAME[1][0] = g;
                                }
				if(NUM_IN_GAME[1][2] == 9)
                                {
                                        g = NUM_IN_GAME[1][1];
                                        NUM_IN_GAME[1][1] = 9;
                                        NUM_IN_GAME[1][2] = g;
                                }
                        }
                }
		if(L > 15 && L < 31 && C > 75 && C < 114)  //NUM_IN_GAME[1][2]
                {
                        if(NUM_IN_GAME[0][2] == 9 || NUM_IN_GAME[0][1] == 9 || NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[2][2] == 9 || NUM_IN_GAME[2][1] == 9)
                        {
                                if(NUM_IN_GAME[0][2] == 9)
                                {
                                        g = NUM_IN_GAME[1][2];
                                        NUM_IN_GAME[1][2] = 9;
                                        NUM_IN_GAME[0][2] = g;
                                }
                                if(NUM_IN_GAME[0][1] == 9)
                                {
                                        g = NUM_IN_GAME[1][2];
                                        NUM_IN_GAME[1][2] = 9;
                                        NUM_IN_GAME[0][1] = g;
                                }
                                if(NUM_IN_GAME[1][1] == 9)
                                {
                                        g = NUM_IN_GAME[1][2];
                                        NUM_IN_GAME[1][2] = 9;
                                        NUM_IN_GAME[1][1] = g;
                                }
                                if(NUM_IN_GAME[2][2] == 9)
                                {
                                        g = NUM_IN_GAME[1][2];
                                        NUM_IN_GAME[1][2] = 9;
                                        NUM_IN_GAME[2][2] = g;
                                }
                                if(NUM_IN_GAME[2][1] == 9)
                                {
                                        g = NUM_IN_GAME[1][2];
                                        NUM_IN_GAME[1][2] = 9;
                                        NUM_IN_GAME[2][1] = g;
                                }
                        }
                }
		if(L > 30 && L < 46 && C > 0 && C < 39)  //NUM_IN_GAME[2][0]
                {
                        if(NUM_IN_GAME[1][0] == 9 || NUM_IN_GAME[2][1] == 9 || NUM_IN_GAME[1][1] == 9)
                        {
                                if(NUM_IN_GAME[1][0] == 9)
                                {
                                        g = NUM_IN_GAME[2][0];
                                        NUM_IN_GAME[2][0] = 9;
                                        NUM_IN_GAME[1][0] = g;
                                }
                                if(NUM_IN_GAME[2][1] == 9)
                                {
                                        g = NUM_IN_GAME[2][0];
                                        NUM_IN_GAME[2][0] = 9;
                                        NUM_IN_GAME[2][1] = g;
                                }
                                if(NUM_IN_GAME[1][1] == 9)
                                {
                                        g = NUM_IN_GAME[2][0];
                                        NUM_IN_GAME[2][0] = 9;
                                        NUM_IN_GAME[1][1] = g;
                                }
                        }
                }
		if(L > 30 && L < 46 && C > 38 && C < 76)  //NUM_IN_GAME[2][1]
                {
                        if(NUM_IN_GAME[1][2] == 9 || NUM_IN_GAME[1][0] == 9 || NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[2][2] == 9 || NUM_IN_GAME[2][0] == 9)
                        {
                                if(NUM_IN_GAME[1][2] == 9)
                                {
                                        g = NUM_IN_GAME[2][1];
                                        NUM_IN_GAME[2][1] = 9;
                                        NUM_IN_GAME[1][2] = g;
                                }
                                if(NUM_IN_GAME[1][0] == 9)
                                {
                                        g = NUM_IN_GAME[2][1];
                                        NUM_IN_GAME[2][1] = 9;
                                        NUM_IN_GAME[1][0] = g;
                                }
                                if(NUM_IN_GAME[1][1] == 9)
                                {
                                        g = NUM_IN_GAME[2][1];
                                        NUM_IN_GAME[2][1] = 9;
                                        NUM_IN_GAME[1][1] = g;
                                }
                                if(NUM_IN_GAME[2][2] == 9)
                                {
                                        g = NUM_IN_GAME[2][1];
                                        NUM_IN_GAME[2][1] = 9;
                                        NUM_IN_GAME[2][2] = g;
                                }
                                if(NUM_IN_GAME[2][0] == 9)
                                {
                                        g = NUM_IN_GAME[2][1];
                                        NUM_IN_GAME[2][1] = 9;
                                        NUM_IN_GAME[2][0] = g;
                                }
                        }
                }
		if(L > 30 && L < 46 && C > 75 && C < 114)  //NUM_IN_GAME[2][2]
                {
                        if(NUM_IN_GAME[1][2] == 9 || NUM_IN_GAME[2][1] == 9 || NUM_IN_GAME[1][1] == 9)
                        {
                                if(NUM_IN_GAME[1][2] == 9)
                                {
                                        g = NUM_IN_GAME[2][2];
                                        NUM_IN_GAME[2][2] = 9;
                                        NUM_IN_GAME[1][2] = g;
                                }
                                if(NUM_IN_GAME[2][1] == 9)
                                {
                                        g = NUM_IN_GAME[2][2];
                                        NUM_IN_GAME[2][2] = 9;
                                        NUM_IN_GAME[2][1] = g;
                                }
                                if(NUM_IN_GAME[1][1] == 9)
                                {
                                        g = NUM_IN_GAME[2][2];
                                        NUM_IN_GAME[2][2] = 9;
                                        NUM_IN_GAME[1][1] = g;
                                }
                        }
                }
                for(i = 0; i < 3; i++)
                {
                        for(j = 0; j < 3; j++)
                        {
                                if(ORDER_TAB[i][j] == NUM_IN_GAME[i][j])
                                {
                                        n++;
                                }
                        }
                }
        }
        while(n != 9);
        clear();
        AFFICHE_IMAGE_MODE(NUM_IN_GAME);
        refresh();
        sleep(2);
}

int IMAGE_MODE_DIF(int** ORDER_TAB, int** NUM_IN_GAME) // Fait fonctionner le mode chiffre en difficulté difficile
{
        int g, i, j, n;
        do
        {
                n = 0;
                clear();
                AFFICHE_IMAGE_MODE(NUM_IN_GAME);
                click_souris();
                if(L > 0 && L < 16 && C > 0 && C < 39) //NUM_IN_GAME[0][0]
                {
                        if(NUM_IN_GAME[1][0] == 9 || NUM_IN_GAME[0][1] == 9)
                        {
                                if(NUM_IN_GAME[1][0] == 9)
                                {
                                        g = NUM_IN_GAME[0][0];
                                        NUM_IN_GAME[0][0] = 9;
                                        NUM_IN_GAME[1][0] = g;
                                }
                                if(NUM_IN_GAME[0][1] == 9)
                                {
                                        g = NUM_IN_GAME[0][0];
                                        NUM_IN_GAME[0][0] = 9;
                                        NUM_IN_GAME[0][1] = g;
                                }
                        }
                }
		if(L > 0 && L < 16 && C > 38 && C < 76)  //NUM_IN_GAME[0][1]
                {
                        if(NUM_IN_GAME[0][0] == 9 || NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[0][2] == 9)
                        {
                                if(NUM_IN_GAME[0][0] == 9)
                                {
                                        g = NUM_IN_GAME[0][1];
                                        NUM_IN_GAME[0][1] = 9;
                                        NUM_IN_GAME[0][0] = g;
                                }
                                if(NUM_IN_GAME[1][1] == 9)
                                {
                                        g = NUM_IN_GAME[0][1];
                                        NUM_IN_GAME[0][1] = 9;
                                        NUM_IN_GAME[1][1] = g;
                                }
                                if(NUM_IN_GAME[0][2] == 9)
                                {
                                        g = NUM_IN_GAME[0][1];
                                        NUM_IN_GAME[0][1] = 9;
                                        NUM_IN_GAME[0][2] = g;
                                }
                        }
                }
                if(L > 0 && L < 16 && C > 75 && C < 114)  //NUM_IN_GAME[0][2]
                {
                        if(NUM_IN_GAME[0][1] == 9 || NUM_IN_GAME[1][2] == 9)
                        {
                                if(NUM_IN_GAME[1][2] == 9)
                                {
                                        g = NUM_IN_GAME[0][2];
                                        NUM_IN_GAME[0][2] = 9;
                                        NUM_IN_GAME[1][2] = g;
                                }
                                if(NUM_IN_GAME[0][1] == 9)
                                {
                                        g = NUM_IN_GAME[0][2];
                                        NUM_IN_GAME[0][2] = 9;
                                        NUM_IN_GAME[0][1] = g;
                                }
                        }
                }
		if(L > 15 && L < 31 && C > 0 && C < 39)  //NUM_IN_GAME[1][0]
                {
                        if(NUM_IN_GAME[0][0] == 9 || NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[2][0] == 9)
                        {
                                if(NUM_IN_GAME[0][0] == 9)
                                {
                                        g = NUM_IN_GAME[1][0];
                                        NUM_IN_GAME[1][0] = 9;
                                        NUM_IN_GAME[0][0] = g;
                                }
                                if(NUM_IN_GAME[1][1] == 9)
                                {
                                        g = NUM_IN_GAME[1][0];
                                        NUM_IN_GAME[1][0] = 9;
                                        NUM_IN_GAME[1][1] = g;
                                }
                                if(NUM_IN_GAME[2][0] == 9)
                                {
                                        g = NUM_IN_GAME[1][0];
                                        NUM_IN_GAME[1][0] = 9;
                                        NUM_IN_GAME[2][0] = g;
                                }
                        }
                }
		if(L > 15 && L < 31 && C > 38 && C < 76)  //NUM_IN_GAME[1][1]
                {
                        if(NUM_IN_GAME[0][1] == 9 || NUM_IN_GAME[2][1] == 9 || NUM_IN_GAME[1][0] == 9 || NUM_IN_GAME[1][2] == 9)
                        {
                                if(NUM_IN_GAME[0][1] == 9)
                                {
                                        g = NUM_IN_GAME[1][1];
                                        NUM_IN_GAME[1][1] = 9;
                                        NUM_IN_GAME[0][1] = g;
                                }
                                if(NUM_IN_GAME[2][1] == 9)
                                {
                                        g = NUM_IN_GAME[1][1];
                                        NUM_IN_GAME[1][1] = 9;
                                        NUM_IN_GAME[2][1] = g;
                                }
                                if(NUM_IN_GAME[1][0] == 9)
                                {
                                        g = NUM_IN_GAME[1][1];
                                        NUM_IN_GAME[1][1] = 9;
                                        NUM_IN_GAME[1][0] = g;
                                }
                                if(NUM_IN_GAME[1][2] == 9)
                                {
                                        g = NUM_IN_GAME[1][1];
                                        NUM_IN_GAME[1][1] = 9;
                                        NUM_IN_GAME[1][2] = g;
                                }
                        }
                }
		if(L > 15 && L < 31 && C > 75 && C < 114)  //NUM_IN_GAME[1][2]
                {
                        if(NUM_IN_GAME[0][2] == 9 || NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[2][2] == 9)
                        {
                                if(NUM_IN_GAME[0][2] == 9)
                                {
                                        g = NUM_IN_GAME[1][2];
                                        NUM_IN_GAME[1][2] = 9;
                                        NUM_IN_GAME[0][2] = g;
                                }
                                if(NUM_IN_GAME[1][1] == 9)
                                {
                                        g = NUM_IN_GAME[1][2];
                                        NUM_IN_GAME[1][2] = 9;
                                        NUM_IN_GAME[1][1] = g;
                                }
                                if(NUM_IN_GAME[2][2] == 9)
                                {
                                        g = NUM_IN_GAME[1][2];
                                        NUM_IN_GAME[1][2] = 9;
                                        NUM_IN_GAME[2][2] = g;
                                }
                        }
                }
                if(L > 30 && L < 46 && C > 0 && C < 39)  //NUM_IN_GAME[2][0]
                {
                        if(NUM_IN_GAME[1][0] == 9 || NUM_IN_GAME[2][1] == 9)
                        {
                                if(NUM_IN_GAME[1][0] == 9)
                                {
                                        g = NUM_IN_GAME[2][0];
                                        NUM_IN_GAME[2][0] = 9;
                                        NUM_IN_GAME[1][0] = g;
                                }
                                if(NUM_IN_GAME[2][1] == 9)
                                {
                                        g = NUM_IN_GAME[2][0];
                                        NUM_IN_GAME[2][0] = 9;
                                        NUM_IN_GAME[2][1] = g;
                                }
                        }
                }
		if(L > 30 && L < 46 && C > 38 && C < 76)  //NUM_IN_GAME[2][1]
                {
                        if(NUM_IN_GAME[1][1] == 9 || NUM_IN_GAME[2][2] == 9 || NUM_IN_GAME[2][0] == 9)
                        {
                                if(NUM_IN_GAME[1][1] == 9)
                                {
                                        g = NUM_IN_GAME[2][1];
                                        NUM_IN_GAME[2][1] = 9;
                                        NUM_IN_GAME[1][1] = g;
                                }
                                if(NUM_IN_GAME[2][2] == 9)
                                {
                                        g = NUM_IN_GAME[2][1];
                                        NUM_IN_GAME[2][1] = 9;
                                        NUM_IN_GAME[2][2] = g;
                                }
                                if(NUM_IN_GAME[2][0] == 9)
                                {
                                        g = NUM_IN_GAME[2][1];
                                        NUM_IN_GAME[2][1] = 9;
                                        NUM_IN_GAME[2][0] = g;
                                }
                        }
                }
                if(L > 30 && L < 46 && C > 75 && C < 114)  //NUM_IN_GAME[2][2]
                {
                        if(NUM_IN_GAME[1][2] == 9 || NUM_IN_GAME[2][1] == 9)
                        {
                                if(NUM_IN_GAME[1][2] == 9)
                                {
                                        g = NUM_IN_GAME[2][2];
                                        NUM_IN_GAME[2][2] = 9;
                                        NUM_IN_GAME[1][2] = g;
                                }
                                if(NUM_IN_GAME[2][1] == 9)
                                {
                                        g = NUM_IN_GAME[2][2];
                                        NUM_IN_GAME[2][2] = 9;
                                        NUM_IN_GAME[2][1] = g;
                                }
                        }
                }
		for(i=0; i<3; i++)
                {
                        for(j=0; j<3; j++)
                        {
                                if(ORDER_TAB[i][j] == NUM_IN_GAME[i][j])
                                {
                                        n++;
                                }
                        }
                }
        }
        while(n != 9);
        clear();
        AFFICHE_IMAGE_MODE(NUM_IN_GAME);
        refresh();
        sleep(2);
}
