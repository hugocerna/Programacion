// Mostrando el uso de la función strncpy()

#include <stdio.h>
#include <string.h>

char destino[] = "..........................";
char fuente[] = "Hola mundo! Estás ahi?";

int main( void )
{
	size_t n;
	while (1)
	{
		puts("");
		printf(" Ingrese el número de caracteres a copiar (1-26): ");
		scanf("%zu", &n);
		if (n > 0 && n < 27)
			break;
	}
	printf(" destino antes de strncpy = %s\n", destino);
	strncpy(destino, fuente, n);
	printf(" destino después de strncpy = %s\n\n", destino);
	return 0;
}
