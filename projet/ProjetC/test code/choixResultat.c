#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


#define clear() printf("\033[H\033[J") 
#define curseur(x,y) printf("\033[%d;%dH", (x), (y))


int playerResultat(int z, int resultat[z])
{
	int i, a, res, b;
	a = 26;
	for(i=0 ; i<z; i++)
	{
		curseur(44, a);
		scanf("%d", &res);
		curseur(46, a);
		switch(res)
		{
			case 1:
			printf("🐸");
			break;
			case 2:
			printf("🐤");
			break;
			case 3:
			printf("🐎");
			break;
			case 4:
			printf("🐍");
			break;
			case 5:
			printf("🐪");
			break;
			case 6:
			printf("🐘");
			break;
			case 7:
			printf("🐷");
			break;
			case 8:
			printf("🐑");
			break;
			case 9:
			printf("🐕");
			break;
			case 10:
			printf("🐔");
			break;
			case 11:
			printf("🦆");
			break;
			case 12:
			printf("🐒");
			break;
			case 13:
			printf("🧯");
			break;
			case 14:
			printf("📸");
			break;
			case 15:
			printf("☎");
			break;
			case 16:
			printf("📺");
			break;
			case 17:
			printf("📻");
			break;
			case 18:
			printf("🔨");
			break;
			case 19:
			printf("⏰");
			break;
			case 20:
			printf("🚽");
			break;
			case 21:
			printf("🚿");
			break;
			case 22:
			printf("🎥");
			break;
			case 23:
			printf("📱");
			break;
			case 24:
			printf("💿");
			break;
			case 25:
			printf("⚽");
			break;
			case 26:
			printf("🏀");
			break;
			case 27:
			printf("🎱");
			break;
			case 28:
			printf("🏓");
			break;
			case 29:
			printf("🏹");
			break;
			case 30:
			printf("⛳");
			break;
			case 31:
			printf("🥊");
			break;
			case 32:
			printf("⛸");
			break;
			case 33:
			printf("🏋️‍♂️");
			break;
			case 34:
			printf("🏊‍");
			break;
			case 35:
			printf("🏇");
			break;
			case 36:
			printf("🎳");
			break;
			case 37:
			printf("🚙");
			break;
			case 38:
			printf("🏎");
			break;
			case 39:
			printf("🚔");
			break;
			case 40:
			printf("🚑");
			break;
			case 41:
			printf("🏍");
			break;
			case 42:
			printf("🛹");
			break;
			case 43:
			printf("🚍");
			break;
			case 44:
			printf("🚊");
			break;
			case 45:
			printf("🚁");
			break;
			case 46:
			printf("🛬");
			break;
			case 47:
			printf("🚀");
			break;
			case 48:
			printf("⛴");
			break;
			default:
			printf("Error");
		}		
		resultat[i] = res;
		a = a + 8;
	}
	curseur(56,0);
}

int main()
{
	int g;
	int z = 10;
	int resultat[10];
	system("cat maquettedif.txt");
	playerResultat(z, resultat);
	for(g=0; g<10; g++)  
	{  
		printf("%d  ", resultat[g]);  
	}
	printf("\n");
}	
			
