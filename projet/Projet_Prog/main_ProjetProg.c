#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include "code_ProjetProg.h"
#define curseur(x,y) printf("\033[%d;%dH", (x), (y))

int L, C;

int main()
{
	srand(time(NULL));
	ncurses_initialiser();
	ncurses_souris();
	scrollok(stdscr, TRUE);
	int choix;
	int mode;
	int dif;
	int** ORDER_TAB;
	int** NUM_IN_GAME;
	ORDER_TAB = INI_TAB_BI();
	NUM_IN_GAME = INI_TAB_BI();
	CHARG_MAT_ORDER(ORDER_TAB);
	MUSIQUE();
	do
  	{
		CHARG_MAT_NUM(NUM_IN_GAME);
    		mode = CHOIX_MODE();
    		dif = CHOIX_DIF();
    		clear();
    		if(mode == 1 && dif == 1)
		{
			IMAGE_MODE_FAC(ORDER_TAB, NUM_IN_GAME);
		}
		if(mode == 1 && dif == 2)
		{	
			IMAGE_MODE_DIF(ORDER_TAB, NUM_IN_GAME);
		}
		if(mode == 2 && dif == 1)
		{
			CHIFFRE_MODE_FAC(ORDER_TAB, NUM_IN_GAME);
		}
		if(mode == 2 && dif == 2)
		{
			CHIFFRE_MODE_DIF(ORDER_TAB, NUM_IN_GAME);
		}
		choix = REJOUER();	
  	}
	while(choix == 1);
  	AUREVOIR();
	endwin();
	LIB_MAT_ORDER(ORDER_TAB);
	LIB_MAT_NUM(NUM_IN_GAME);
	system("killall play");
	return 0;
}
