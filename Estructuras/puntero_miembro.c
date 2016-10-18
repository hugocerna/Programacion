/* Demonstrando estructuras que contienen punteros como miembros. */

#include <stdio.h>

/* Declarando una estructura que contiene punteros */
struct entrada {
	char *nombre;
	char *apellido;
	long double deuda;
};

/* Declarando e inicializando un arreglo de estructuras. */
struct entrada lista[4] =
{	
	{ 	
		"Juan",
		"Perez",
		1000.50
	},
	{ 
		"Maria",
		"Paz",
		9050.00
	},
	{ 
		"Raul", 
		"Vega",
		2800.50
	},
	{ 
		"Paul",
		"Chungas",
		1800.50
	}		
};

void main( void )
{
	
	/* Buble para mostrar los datos. */
	int i;
	for (i = 0; i < 4; i++)
	{
		printf("\nNombre: %s %s", lista[i].nombre, lista[i].apellido);
		printf("\tDeuda: %.2Lf", lista[i].deuda);
	}
	printf("\n\n");
	
	/* Imprimiendo direcciones de memoria de lista. */
	printf("======= Imprimiendo las direcciones");
	printf(" de memoria de lista ==========\n\n");		
	printf("\t\tnombre\t\tapellido\ttelefono");
	printf("\n=====================================");
	printf("=============================");	
	for (i = 0; i < 4; i++)
		printf("\nlista[%d]:\t%p\t%p\t%p", i, &lista[i].nombre, 
		&lista[i].apellido, &lista[i].deuda);
	printf("\n=====================================");
	printf("=============================\n\n");
	printf("sizeof(float) = %lu\n", sizeof(float));
	printf("sizeof(double) = %lu\n", sizeof(double));
	printf("sizeof(long float) = %lu\n\n", sizeof(long double));
	
	/* Imprimiendo direcciones de memoria que almacenan los punteros. */
	printf(" Imprimiendo las direcciones");
	printf(" de memoria que almacenan los punteros \n\n");		
	printf("\t\tnombre\t\tapellido");
	printf("\n=====================================");
	printf("=============================");	
	for (i = 0; i < 4; i++)
		printf("\nlista[%d]:\t%p\t%p", i, lista[i].nombre, 
		lista[i].apellido);
	printf("\n=====================================");
	printf("=============================\n\n");
}
