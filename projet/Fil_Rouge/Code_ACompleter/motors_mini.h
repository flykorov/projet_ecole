#ifndef __motors_mini
#define __motors_mini

extern int enablePin;              //GPIO4, broche enable du moteur 1
extern int m1;                     //GPIO17, entree 1 du moteur 1
extern int m2;                     //GPIO22, entree 2 du moteur 1
extern int enablePin2;            //GPIO24, broche enable du moteur 2
extern int m3;                     //GPIO23, entree 1 du moteur 2
extern int m4;                    //GPIO25, entree 2 du moteur 2

extern int led_g;			        //GPIO16, led gauche
extern int led_d;			        //GPIO12 , led droite

void moteurs(char BOUTONS[12]);
#endif 
