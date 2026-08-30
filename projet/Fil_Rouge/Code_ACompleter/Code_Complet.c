#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include <lcd.h>
#include <softPwm.h>
#include "motors_mini.h"
#include "but_celebration.h"

int enablePin = 7;              //GPIO4, broche enable du moteur 1
int m1 = 0;                     //GPIO17, entree 1 du moteur 1
int m2 = 3;                     //GPIO22, entree 2 du moteur 1
int enablePin2 = 5;            //GPIO24, broche enable du moteur 2
int m3 = 4;                     //GPIO23, entree 1 du moteur 2
int m4 = 6;                    //GPIO25, entree 2 du moteur 2

int led_g = 27;			        //GPIO16, led gauche
int led_d = 26;			        //GPIO12 , led droite

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

void lcd_but(){
/*
     À remplir 
*/
}

void lcd_victoire(){
/*
     À remplir 
*/
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

void moteurs(char BOUTONS[12])
{
	/*Pour avancer*/
	if ((int)BOUTONS[0] == 1)
	{//printf("yes 2\n");
		//allumage moteur 1 sens positif
		digitalWrite (enablePin, 1);  //active moteur : GPIOC=HIGH
		digitalWrite (m1, 1);         //GPIOA=HIGH
		digitalWrite (m2, 0);         //GPIOB=LOW

		//allumage moteur 2 sens positif
		digitalWrite (enablePin2, 1); //active moteur : GPIOC=HIGH
		digitalWrite (m3, 0);         //GPIOA=HIGH
		digitalWrite (m4, 1);         //GPIOB=LOW

		//pause d'une seconde
		printf ("Avancer ! ");
		printf("\r");
		fflush(stdout);
		sleep (1);
		printf("                                                 ");
		printf("\r");
	}

	/*Pour reculer*/
	if ((int)BOUTONS[2] == 1)
	{
		 /*A remplir*/
	}

	/*Pour tourner à droite*/
	if ((int)BOUTONS[1] == 1)
	{
		//allumage moteur 1 sens positif
        digitalWrite (enablePin, 1);  //active moteur : GPIOC=HIGH
        digitalWrite (m1, 1);         //GPIOA=HIGH
        digitalWrite (m2, 0);         //GPIOB=LOW
        
        //allumage de led droite
	   digitalWrite(led_d,1);

        //pause d'une seconde
        printf ("Tourner à droite ! ");
        printf("\r");
        fflush(stdout);
        sleep (1);
        printf("                                                 ");
        printf("\r");
    }
	/*Pour tourner à gauche*/
	if ((int)BOUTONS[3] == 1)
	{
        /*A remplir*/
    }



	//arret du moteur 1
	digitalWrite (enablePin, 0);

	//arret du moteur 2
	digitalWrite (enablePin2, 0);
	

	//on eteint les led
	digitalWrite(led_g,0);		//led gauche= LOW
	digitalWrite(led_d,0);		//led droite= LOW

	printf ("TANK immobile ! ");
	printf("\r");
	fflush(stdout);
	printf("                                                 ");
	printf("\r");

}

int main (int argc, char ** argv){
	int i, j;
	char BOUTON_PRESSE[8], BOUTONS[12]; 
    
	int nb_goal = 0;		//compteur de but
	int max_goal = 3;
		

	/*A remplir*/ 
    
    /*Ouverture du fichier /dev/input/js0*/

    /*Si la joystick n'est pas connectÃ©e afficher un message et quitter le programme*/

    
    

	if (wiringPiSetup () == -1){
		printf ("error!\n");
		return (1);
	}else{
		//on definit les GPIO en sortie pour le moteur 1
		pinMode (enablePin, OUTPUT);
		pinMode (m1, OUTPUT);
		pinMode (m2, OUTPUT);
		//on definit les GPIO en sortie pour le moteur 2
		pinMode (enablePin2, OUTPUT);
		pinMode (m3, OUTPUT);
		pinMode (m4, OUTPUT);
		//on definit les GPIO en sortie pour le decodeur
		pinMode (A, OUTPUT);
		pinMode (B, OUTPUT);
		pinMode (C, OUTPUT);
		pinMode (D, OUTPUT);
		//on definit les GPIO en sortie pour les led
		pinMode (led_d, OUTPUT);
		pinMode (led_g, OUTPUT);
	}


	//on affiche 0 sur l'afficheur 7 segments via le dÃ©codeur --> A=0,B=0,C=0,D=0 => 0
	digitalWrite(A,0);
	digitalWrite(B,0);
	digitalWrite(C,0);
	digitalWrite(D,0);

	/*
	   Pour un ecran 4 bit, les valeurs de D0 Ã  D3 correspondent aux pin D4 Ã  D7 sur le schÃ©ma electrique 
    */
	//On initialise l'ecran LCD puis on affiche un message
	fd = lcdInit(2,16,4, rs,e,D4,D5,D6,D7,0,0,0,0);// initialise l'ecran LCD	
	

	while (1)
    {  lcdClear(fd);			// permet d'effacer le contenu de l'ecran LCD
	lcdPuts(fd,team); 	// on affiche le nom de l'Ã©quipe

		/*A remplir*/

        /*Ouverture du fichier /dev/input/js0*/

        /*Une boucle qui rÃ©cupÃšre l'Ã©tats des 12 boutons*/
        
        

		if (((int)BOUTONS[0]==1) || ((int)BOUTONS[1]==1) || ((int)BOUTONS[2]==1) || ((int)BOUTONS[3]==1))
        {
			moteurs(BOUTONS);
		}else if ((int)BOUTONS[5]==1)
        {	
    /* A remplir: si l'utilisateur appuie sur le bouton    correspondant à un but
*/			
		}
		
		/*A remplir*/
		/*Fermeture du fichier /dev/input/js0* Ã  rajouter*/
	}
}


