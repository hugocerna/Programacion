// Copiando una cadena en otra
#include <stdio.h>

char origen[] = "La cadena de origen.";
char destino[80];
int i; // para almacenar el índice

void strcop (char des[], char ori[]);

void main( void )
{
	printf("\n origen: %s", origen);
	/* Copiar a destino está correcto porque destino apunta a
	 * 80 bytes de espacio reservado. */
	strcop(destino, origen);
	printf("\n destino: %s\n\n", destino);
}

void strcop (char des[], char ori[])
{
	i = 0;
	while (ori[i] != '\0')
		des[i] = ori[i++];
	des[i] = '\0';
}
