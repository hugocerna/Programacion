// Concatenando una cadena en otra

#include <stdio.h>

char str1[27] = "a";
char str2[2];
int i, j; // para almacenar índices

void strkat (char cad1[], char cad2[]);

void main( void )
{
	int n;
	/* Colocando un caracter nulo al final de str2[]. */
	str2[1] = '\0';
	puts (""); // escribe la cadena nula y da un salto de línea
	for (n = 98 ; n < 123 ; n++)
	{
		str2[0] = n;
		strkat (str1, str2);
		puts (str1);
	}
	puts ("");
}

void strkat (char cad1[], char cad2[])
{
	i = 0;
	while (cad1[i] != '\0')
		i++;
	j = 0;
	while (cad2[j] != '\0')
		cad1[i++] = cad2[j++];
	cad1[i] = '\0'; 
}
