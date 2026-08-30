#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include <lcd.h>
#include "motors_mini.h"
#include "but_celebration.h"

	
	
int main (int argc, char ** argv){
	int i, j;
	char BOUTON_PRESSE[8], BOUTONS[12]; 
    
	int nb_goal = 0;		//compteur de but
	int max_goal = 3;
		

	/*A remplir*/ 
    
    /*Ouverture du fichier /dev/input/js0*/

    /*Si la joystick n'est pas connectée afficher un message et quitter le programme*/

    
    

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


	//on affiche 0 sur l'afficheur 7 segments via le décodeur --> A=0,B=0,C=0,D=0 => 0
	digitalWrite(A,0);
	digitalWrite(B,0);
	digitalWrite(C,0);
	digitalWrite(D,0);

	/*
	   Pour un ecran 4 bit, les valeurs de D0 à D3 correspondent aux pin D4 à D7 sur le schéma electrique 
    */
	//On initialise l'ecran LCD puis on affiche un message
	fd = lcdInit(2,16,4, rs,e,D4,D5,D6,D7,0,0,0,0);// initialise l'ecran LCD	
	

	while (1)
	{  
		lcdClear(fd);			// permet d'effacer le contenu de l'ecran LCD
		lcdPuts(fd, "team"); 	// on affiche le nom de l'équipe

		/*A remplir*/

        /*Ouverture du fichier /dev/input/js0*/

        /*Une boucle qui récupère l'états des 12 boutons*/
        
        

		if (((int)BOUTONS[0]==1) || ((int)BOUTONS[1]==1) || ((int)BOUTONS[2]==1) || ((int)BOUTONS[3]==1))
		{
			moteurs(BOUTONS);
		}else if ((int)BOUTONS[5]==1) //bouton du but
		{
       	 	nb_goal++;
       	 	if(nb_goal == max_goal)
       	 	{
      		  		lcd_victoire();
       	 		nb_goal = 0;
       	 	}else
       	 	{
       	 		lcd_but();	
        		}					
		}
			
		/*A remplir*/
		/*Fermeture du fichier /dev/input/js0* à rajouter*/
	}
}
