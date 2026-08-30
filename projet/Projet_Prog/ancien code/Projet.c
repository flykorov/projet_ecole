#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define curseur(x,y) printf("\033[%d;%dH", (x), (y))

int main(int argc, char ** argv)
{
	int system(const char *command); char difficulte[10]; int mode;
	system("clear"); /* Permet de ''nettoyer'' l'interface du terminal */
	system("cat menu.txt");
	curseur(9, 21);
	scanf("%d", &mode);
	if (mode == 1) /* Mode avec Image */
	{
		curseur(9, 50);
		scanf("%s", difficulte);
		curseur(11, 1);
		if (strlen(difficulte) == 6) /* Difficulté Facile */
		{
			printf("C'est la difficulté facile du mode image\n");
		}
		if (strlen(difficulte) == 9) /* Difficulté Difficile */
		{
			printf("C'est la difficulté difficile du mode image\n");
		}
	}
	if (mode == 2) /* Mode avec Chiffres */
        {
		 curseur(9, 50);
                scanf("%s", difficulte);
                curseur(11, 1);
                if (strlen(difficulte) == 6) /* Difficulté Facile */
                {
                        printf("C'est la difficulté facile du mode chiffres\n");
                }
                if (strlen(difficulte) == 9) /* Difficulté Difficile */
                {
                        printf("C'est la difficulté difficile du mode chiffres\n");
                }
        }
	return 0;
}

