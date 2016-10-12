/* Demonstración de la relación entre dirección de memoria y  
   elementos de arreglos de diferentes tipos de datos. */

#include <stdio.h>

/* Declarando un contador y tres tipos de arreglos. */
int cont;
short arreglo_s[10];
float arreglo_f[10];
double arreglo_d[10];

void main( void )
{
	/* Imprimiendo la cabecera de la tabla */
	printf("\t\tShort\t\tFloat\t\tDouble");
	printf("\n================================");
	printf("========================");
	
	/* Imprimiendo la dirección de cada elemento de los arreglos. */
	for (cont = 0; cont < 10; cont++)
		printf("\n Elemento %d:\t%p\t%p\t%p", cont, &arreglo_s[cont], 
	&arreglo_f[cont], &arreglo_d[cont]);
	printf("\n================================");
	printf("========================\n");
}
