// Mostrando el uso de la función strcpy()

#include <stdio.h>
#include <string.h>
char origen[] = "La cadena de origen.";

int main( void )
{
	char destino[80];
	printf("\n origen: %s", origen);
	/* Copiar a destino está correcto porque destino apunta a
	 * 80 bytes de espacio reservado. */
	strcpy(destino, origen);
	printf("\n destino: %s\n\n", destino);
		
	return 0;
}
