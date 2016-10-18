/* Demonstraci\'on del uso de una estructura simple */

#include <stdio.h>

struct coordenada
{
	int x;
	int y;
} punto;

void main( void )
{
	/* asignando valores a las coordenadas de punto */
	punto.x = 5;
	punto.y = 12;
	printf("\nLas coordenadas son: (%d,%d).\n\n", punto.x, punto.y);
	
 	/* mostrando direcciones de memoria */
	printf("======== Imprimiendo las direcciones");
	printf(" de memoria ========\n\n");	
	printf("\tpunto\t\tpunto.x\t\tpunto.y");
	printf("\n================================");
	printf("========================");
	printf("\n\t%p\t%p\t%p", &punto, &punto.x, &punto.y);
	printf("\n================================");
	printf("========================\n\n"); 	
}
