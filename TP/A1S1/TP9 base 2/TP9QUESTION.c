\\EX 1				PI = 3.141592653589793284626

\* Dans float on conserve 6 décimals		float PI = 3.14159274101257324219
   Dans double on conserve 15 décimals	double PI = 3.14159265358979311600
   Dans long double on conserve 18 décimals	long double PI = 3.14159265358979328470
*\

\\EX2

\* Le code suivant affiche:
dSum = 1.000000
Nothing makes sense anymore ... are we in the matrix?
0.1 = 0.10000000000000000555
1.0 - dSum = 0.00000000000000011102	

ce qui c'est passé ces que dans la boucle for dSum na pas incrémenter 0.1 à chaque retour de boucle mais à incrémenter à la place 0.10000000000000000555

\\EX3

\* La Valeur afficher est "uVal = 4294967284"
   On observe que la valeur de uVal est devenu positif et qu'on à soustrait -12 à la valeur maximal du type à savoir int.
*\

\\EX4

\* long long | 8 octets | (FFFFFFFFFFFFFFFF)16 | (18446744073709551615)10 
   int       | 4 octets | (00000000FFFFFFFF)16 | (4294967295)10
   short     | 2 octets | (000000000000FFFF)16 | (65535)10
   char      | 1 octets | (00000000000000FF)16 | (255)10
*\

\\EX5

\* On observe que chaque type est affecter à sa valeur maximal
*\

\\EX6

\* le programme affiche:
	12 /7 = 1.000000
	12 / 7 = 1.714286
	
	int 		int	|	int		int
	iVal1	/	iVal2	|((double)iVal1) /	iVal2
	12	/	7	|	12.000000 /	7
		=		|		=
		1.000000	|		1.714286
*\

\\EX7

\* On observe Actual altitude = new altitude et que old altitude = n - 1 où n = actual altitude
de plus la valeur incrémenter est toujours la même donc si la valeur entré en entré est positif alors, la valeur de altitude sera toujours positif, pour faire marqué le BOOM il faut entré une valeur négative en entré.
*\



























 






