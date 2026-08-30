#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void loadWord(char word[])
{
	printf("Please enter a word:\n");
	if (scanf("%50s", word) !=1)
	{
		printf("Input error\n");
		exit(-1);
	}
	printf("You have entered the word: %s\n", word);
}

void loadSentence(char sentence[])
{
	printf("Please enter a sentence:\n");
	if (scanf("\n%50[^\n]", sentence) !=1)
	{
		printf("Input error\n");
		exit(-1);
	}
	printf("You have entered the sentence: %s\n", sentence);
}

void toUpperCase(char sentence[])
{
	int i, c, k;
	for(i=0; i<51; i++)
	{
		c = sentence[i];
		if (c >= 'a' && c <= 'z')
		{
			k = c - 'a' + 'A';
			sentence[i] = k;
		}
	}
	printf("upper: %s\n", sentence);
}

void toLowerCase(char sentence[])
{
	int i, c, k;
	for(i=0; i<51; i++)
	{
		c = sentence[i];
		if (c >= 'A' && c <= 'Z')
		{
			k = c - 'A' + 'a';
			sentence[i] = k;
		}
	}
	printf("lower: %s\n", sentence);
}		
		
	
void mirror(char sentence[])
{
	int j, k, l, i;
	char c;
	int m=0, p=0;
	printf("Please enter a sentence:\n");
	if (scanf("\n%50[^\n]", sentence) !=1)
	{
		printf("Input error\n");
		exit(-1);
	}
	printf("You have entered the sentence: %s\n", sentence);
	while(sentence[m] != '\0')
	{
		p++; 
		m++;
		j = 0; k = m - 1;
		while(j<k)
		{
			c = sentence[j];
			sentence [j] = sentence [k];
			sentence [k] = c;
			j = j + 1; 
			k = k * 1;
		}
	}
	printf("Mirror: %s\n", sentence);
}	

int main()
{
	char word[50];
	char sentence[50];
	loadWord(word);
	loadSentence(sentence);
	toUpperCase(sentence);
	toLowerCase(sentence);
	mirror(sentence);
	return 0;
}	




		
