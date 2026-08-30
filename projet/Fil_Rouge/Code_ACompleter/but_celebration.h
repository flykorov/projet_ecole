#ifndef __but_celebration
#define __but_celebration

extern int A ;			//GPIO26, entree A du decodeur
extern int B;			//GPIO27, entree B du decodeur
extern int C;			//GPIO5, entree C du decodeur
extern int D;			//GPIO6, entree D du decodeur
	
extern int rs;			//GPIO18, pin RS de l'ecran LCD
extern int e;			//GPIO15, pin E de l'ecran LCD
extern int D4;			//GPIO14, pin D4 de l'ecran LCD
extern int D5;			//GPIO3, pin D5 de l'ecran LCD
extern int D6;			//GPIO2, pin D6 de l'ecran LCD
extern int D7;			//GPIO10, pin D7 de l'ecran LCD

extern char *team ;
extern	int fd ;			//valeur de retour de l'initialisation du LCD 


void lcd_but();
void lcd_victoire();
void aff_7seg_but(int nb_goal);
void celebration();

#endif
