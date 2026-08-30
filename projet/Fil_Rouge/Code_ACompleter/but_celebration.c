#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include <lcd.h>
#include "motors_mini.h"
#include "but_celebration.h"

int A = 25;			//GPIO26, entree A du decodeur
int B = 2;			//GPIO27, entree B du decodeur
int C = 21;			//GPIO5, entree C du decodeur
int D = 22;			//GPIO6, entree D du decodeur
	
int rs = 1;			//GPIO18, pin RS de l'ecran LCD
int e = 16;			//GPIO15, pin E de l'ecran LCD
int D4 = 15;			//GPIO14, pin D4 de l'ecran LCD
int D5 = 9;			//GPIO3, pin D5 de l'ecran LCD
int D6 = 8;			//GPIO2, pin D6 de l'ecran LCD
int D7 = 12;			//GPIO10, pin D7 de l'ecran LCD

char *team = "Team ESIEA";
int fd = -1;			//valeur de retour de l'initialisation du LCD (-1 si erreur )

void lcd_but()
{
	lcdPuts(fd, "BUUUUT!!!");
}

void lcd_victoire()
{
	lcdPuts(fd, "VICTOIRE!!!");
}


void aff_7seg_but(int nb_goal){
/*
     À remplir */
}


void celebration(){
	
	/*
     À remplir : à vous d'imaginer un enchainement d'actions sur les moteurs afin de réaliser votre animation !
     */
}


