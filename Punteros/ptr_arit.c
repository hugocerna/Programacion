/* Demostrando el uso de la artimética de punteros para acceder */
/* a los elementos de una arreglo con la notación de punteros.  */

#include <stdio.h>
#define MAX 10

int i_arreglo[MAX] = { 0,1,2,3,4,5,6,7,8,9 };
int *i_ptr, cont; // declarando un puntero a entero y una variable entera

float f_arreglo[MAX] = { .0, .1, .2, .3, .4, .5, .6, .7, .8, .9 };

void main( void )
{
	i_ptr = i_arreglo; // inicializando puntero
	
	/* Mostrando los elementos del arreglo. */	
	for (cont = 0; cont < MAX; cont++)
		printf(" %d\t%.2f\n", *i_ptr++, *(f_arreglo + cont) );
}
