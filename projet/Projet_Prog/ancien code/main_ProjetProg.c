#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include "code_ProjetProg.h"
#define curseur(x,y) printf("\033[%d;%dH", (x), (y))

int main()
{
	srand(time(NULL));
	MODE_DIF();
	int** ORDER_TAB;
	int** NUM_IN_GAME;
	ORDER_TAB = INI_TAB_BI();
	NUM_IN_GAME = INI_TAB_BI();
	CHARG_MAT_ORDER(ORDER_TAB);
	CHARG_MAT_NUM(NUM_IN_GAME);
	AFFICH_MAT_ORDER(ORDER_TAB);
	AFFICH_MAT_NUM(NUM_IN_GAME);
	LIB_MAT_ORDER(ORDER_TAB);
	LIB_MAT_NUM(NUM_IN_GAME);
	return 0;
}
