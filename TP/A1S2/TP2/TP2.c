#include <stdio.h>
#include <stdlib.h>

float Exponentiation_Iter(float g, int e)
{
	float EXP;
	int i;
	if(e == 0)
	{
		return 1;
	}
	if(e == 1)
	{
		return g;
	}
	EXP = g;
	for(i=2; i<=e; i++)
	{
		EXP = EXP * g;
	}
	return EXP;
}

int main(int argc, char** argv)
{
	float g;
	int e;
	g = atof(argv[1]);
	e = atoi(argv[2]);
	printf("%.2f^%d = %.2f\n", g, e, Exponentiation_Iter(g, e));
	return 0;
}
