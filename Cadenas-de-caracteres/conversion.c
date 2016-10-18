/* Mostrando el uso de las funciones de conversion de caracter: 
   tolower() y toupper(). */

#include <ctype.h> //  necesario para utilizar tolower y toupper
#include <stdio.h>
#define LonMax 40

char buffer[LonMax + 1];
int ch, i;

int main( void )
{
	// Ingresando una línea de texto
	puts("");
	printf(" Ingrese una cadena de caracteres (de no más de %d caracteres) cad1: ", LonMax);
	ch = getchar(); 
	i = 0;
	while (ch != '\n')
	{
		buffer[i++] = ch;
		ch = getchar();
	}
	buffer[i] = '\0';
	
	// Mostrando el texto ingresado en minúscula
	puts("");
	printf(" Texto en minúscula: ");
	i = 0; 
	while (buffer[i] != '\0')
		printf("%c", tolower (buffer[i++]) );
	puts("");
	
	// Mostrando el texto ingresado en mayúscula
	puts("");
	printf(" Texto en mayúscula: ");
	i = 0; 
	while (buffer[i] != '\0')
		printf("%c", toupper (buffer[i++]) );
	puts("\n");
}
