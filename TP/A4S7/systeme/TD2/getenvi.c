#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	char *ptr;

	ptr = getenv("PATH");
	printf("PATH = %s\n", ptr);
}
