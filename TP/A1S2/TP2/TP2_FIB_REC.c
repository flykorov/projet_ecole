#include <stdio.h>

unsigned long long int FIBONACCI_REC(unsigned long long int n)
{
	if(n == 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}
	return FIBONACCI_REC(n-1) + FIBONACCI_REC(n-2);
}

int main(int argc, char** argv)
{
	unsigned long long int n;
	while(scanf("%llu", &n) != EOF)
	{
		printf("FIBONACCI(%llu) = %llu\n", n, FIBONACCI_REC(n));
	}
	return 0;
}
// la valeur limite de n est 47
