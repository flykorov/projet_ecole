// TP1
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane


#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

int creer_script(int taille, string nom, int histo)
{
	bool inst = false;
	int i, a, b, n;
	ofstream script(nom);
	if(!script)
		return -1;
	script << taille << endl;
	for(i=0; i<taille; i++)
	{
		a = rand() % 5;
		if(i%histo == 0 && i != 0 && n != i)
		{
			n=i;		// evite de mettre plusieurs historique a la suite
			script << "historique\n";
		}
		switch(a)
		{
			case 0: 
				script << "ls";
				b = rand() % 2;
				if(b == 0)
					script << " -l" << endl;
				else
					script << endl;
				break;
			case 1:
				script << "pwd\n";
				break;
			case 2:
				if(!inst)		// si le dernier appelle de dir etait mkdir ne le refait pas
				{
					script << "mkdir test\n";
					inst = true;
				}
				else
					i--;
				break;
			case 3:
				if(inst)		// de meme pour rmdir
				{
					inst = false;
					script << "rmdir test\n";
				}
				else
					i--;
				break;
			case 4:
				script << "cat bou.txt\n";
				break;
		}
	}
	script << "exit\n";
	script.close();
	return 0;
}

int main()
{
	srand(time(NULL));

	creer_script(100, "100.txt", 50);
	creer_script(500, "500.txt", 100);
	creer_script(1000, "1000.txt", 150);

	return 0;
}