#include <stdio.h>

int main()
{
	int* p_var;
	p_var = NULL;
	(*p_var) = 10;
	return 0;
	//Erreur de segmentation (core dumped)
	//un message d'erreur s'affiche
}	
