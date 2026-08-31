#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("echo Voici le nombre de variable dans mon environement : ");
	system("printenv | wc -l");
	system("echo Voici le statut de retour de la commande précédente : ");
	system("echo $?");

	return 0;
}
