// Mostrando el uso de la función strncat()

#include <stdio.h>
#include <string.h>

char str2[] = "abcdefghijklmnopqrstuvwxyz";
int n;

void main( void )
{
	char str1[28];
	puts("");
	for (n = 1 ; n < 27 ; n++)
	{
		strcpy (str1, " ");
		strncat (str1, str2, n);
		puts(str1);
	}
	puts("");
}
