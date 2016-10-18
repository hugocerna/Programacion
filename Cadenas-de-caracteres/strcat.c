// Mostrando el uso de la función strcat()

#include <stdio.h>
#include <string.h>

char str1[27] = "a";
char str2[2];

void main( void )
{
	int n;
	/* Colocando un caracter nulo al final de str2[]. */
	str2[1] = '\0';
	puts("");
	for (n = 98 ; n < 123 ; n++)
	{
		str2[0] = n;
		strcat(str1, str2);
		puts(str1);
	}
	puts("");
}
