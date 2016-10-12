/* Demostrando el uso de la diferencia y la comparació de punteros. */

#include <stdio.h>
#define MAX 10

int i_arreglo[MAX] = { 0,1,2,3,4,5,6,7,8,9 };
int * ptr1 = i_arreglo + 2;
int * ptr2 = i_arreglo + 5;

void main( void )
{
	printf("\n El elemento %d está %ld lugares", *ptr2, ptr2 - ptr1);
	printf(" a la derecha del elemento %d.\n\n", *ptr1);

	if (ptr2 > ptr1)
		printf(" El elemento %d está después del elemento %d.\n\n", *ptr2, *ptr1);
}
