#include <stdio.h>

int main()
{
	int var = 4;
	int *p_var= NULL;
	p_var = &var;
	printf("var = %d, (*p_var) = %d", var, (*p_var));
	var++;
	printf("var = %d, (*p_var) = %d", var, (*p_var));
	return 0;
	//var = 4, (*p_var) = 4var = 5, (*p_var) = 5
	/*Je vois que la valeur de la variable et du pointeur on augmenter de 1 juste en incrémentant la variable de 1*/
}	
