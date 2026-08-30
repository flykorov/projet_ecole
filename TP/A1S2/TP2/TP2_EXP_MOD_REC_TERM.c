#include <stdio.h>
#include <stdlib.h>

float Exponetiation_Rec_Term(float g, int e, float acc)
{
	if(e == 0)
	{
		return acc;
	}
	if(e == 1)
	{
		return g*acc;
	}
	return Exponetiation_Rec_Term(g, e-1, g*acc);
}

int main(int argc, char** argv)
{
	float g; 
	int e;
	g = atof(argv[1]);
	e = atoi(argv[2]);
	printf("%.2f^%d = %.2f\n", g, e, Exponetiation_Rec_Term(g, e, 1));
	return 0;
}	
