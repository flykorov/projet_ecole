#include <stdio.h>

int main()
{
	int  iVar;
	int *p_iVar = NULL;
	double dDouble;
	double *p_dDouble = NULL;
	char cChar;
	char *p_cChar = NULL;
	printf("The Value of &iVar is %p and p_iVar %p\n", &iVar, p_iVar);
	p_iVar = &iVar;
	printf("The Value of &iVar is %p and p_iVar %p\n", &iVar, p_iVar);
	printf("The Value of &iVar is %p and p_iVar %p\n", &dDouble, p_dDouble);
	p_dDouble = &dDouble;
	printf("The Value of &iVar is %p and p_iVar %p\n", &dDouble, p_dDouble);
	printf("The Value of &iVar is %p and p_iVar %p\n", &cChar, p_cChar);
	p_cChar = &cChar;
	printf("The Value of &iVar is %p and p_iVar %p\n", &cChar, p_cChar);
	return 0;
}	
