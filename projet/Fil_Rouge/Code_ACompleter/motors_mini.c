//gcc foo.c -lwiringPi

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "motors_mini.h"

int enablePin = 7;              //GPIO4, broche enable du moteur 1
int m1 = 0;                     //GPIO17, entree 1 du moteur 1
int m2 = 3;                     //GPIO22, entree 2 du moteur 1
int enablePin2 = 5;            //GPIO24, broche enable du moteur 2
int m3 = 4;                     //GPIO23, entree 1 du moteur 2
int m4 = 6;                    //GPIO25, entree 2 du moteur 2

int led_g = 27;			        //GPIO16, led gauche
int led_d = 26;			        //GPIO12 , led droite

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
