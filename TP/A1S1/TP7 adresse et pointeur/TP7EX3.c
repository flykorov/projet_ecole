#include <stdio.h>

int main()
{
	int var = 7;
	int tmp;
	int *p_var = &var;
	printf("var = %d, (*p_var) = %d\n", var, (*p_var));
	tmp = (*p_var) + 5;
	printf("var = %d, (*p_var) = %d, tmp = %d\n", var, (*p_var), tmp);
	(*p_var) = tmp;
	printf("var = %d, (*p_var) = %d, tmp = %d\n", var, (*p_var), tmp);
	return 0;
	/*var = 7, (*p_var) = 7
	var = 7, (*p_var) = 7, tmp = 12
	var = 12, (*p_var) = 12, tmp = 12*/
	/*Le pointeur à pris une la variable de tmp et cela à aussi changer la valeur de var*/
}	
