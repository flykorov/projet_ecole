#include <stdio.h>

int rocketTest(int oldAlt, int newAlt)
{
	printf("old altitude : %d, new altitude : %d\n", oldAlt, newAlt);
	if(newAlt >= oldAlt)
	{
		return 1;
	}
	else
	{
		printf("Falling\n");
		return 0;
	}
}

int runLoop(int speed)
{
	int actAlt, oldAlt, newAlt, altitude, b;
	int a = 0;
	for( altitude=0; altitude<=300000; altitude=altitude+speed)
	{
	oldAlt = a;
	newAlt = altitude;
	a = altitude;
	printf("Actual altitude : %d,", altitude);
	b = rocketTest(oldAlt, newAlt);
	if(b == 0)
	{
		printf("Boom\n");
		break;
	}	
	}
}	

int main()
{
	int speed;
	printf("Saisir une vitesse :");
	scanf("%d", &speed);
	runLoop(speed);
}	

