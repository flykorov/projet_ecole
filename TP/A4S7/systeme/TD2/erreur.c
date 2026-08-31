#include <stdio.h>

extern char** environ;

int main(void)
{
	int nro_var = 0;
	for (nro_var=0; environ[nro_var]!= NULL; nro_var++)
	{
		char* a = environ[nro_var];
		// printf("%s\n", a);
	}

	// nro_var--;
	printf("Le nombre de variable du systeme est %d\n", nro_var);
	return 0;
}
