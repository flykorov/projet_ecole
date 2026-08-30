#include <stdio.h>

unsigned long long int FIBONACCI_ITER(unsigned long long int n)
{
	unsigned long long int i, Fn1, Fn2, Fn;
	if(n == 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}
	Fn1 = 1;
	Fn2 = 0;
	for(i=2; i<=n; i++)
	{
		Fn = Fn1 + Fn2;
		Fn2 = Fn1;
		Fn1 = Fn;
	}
	return Fn;
}

int main(int argc, char** argv)
{
	unsigned long long int n;
	while(scanf("%llu", &n) != EOF)
	{
		printf("FIBONACCI(%llu) = %llu\n", n , FIBONACCI_ITER(n));
	}
	return 0;
}
//la valeur limite de n est 3010
