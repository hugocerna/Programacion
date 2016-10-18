/* Demonstrando un puntero a estructura. */

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

/* Declarando un puntero a tipo de dato entrada */
struct entrada *p_entrada;

void main( void )
{
	/* Inicializando el puntero al primer elemento del arreglo lista */
	p_entrada = lista;
	
	/* Bucle para mostrar los datos 
	   utilizando la aritmetica de punteros. */
	int cont;
	for (cont = 0; cont < 4; cont++)
	{
		printf("\nNombre: %s ", p_entrada -> nombre); 
		printf("%s", p_entrada -> apellido);
		printf("\tDeuda: %.2Lf", p_entrada -> deuda);
		p_entrada++;
	}
	printf("\n\n");
	
	/* Imprimiendo direcciones de memoria de lista. */
	printf("======= Imprimiendo las direcciones");
	printf(" de memoria de lista ==========\n\n");		
	printf("\t\tnombre\t\tapellido\ttelefono");
	printf("\n=====================================");
	printf("=============================");	
	/* Inicializando el puntero al primer elemento del arreglo lista */
	p_entrada = lista;
	for (cont = 0; cont < 4; cont++)
	{
		printf("\nlista[%d]:\t%p\t%p\t%p", cont, &p_entrada->nombre, 
		&p_entrada->apellido, &p_entrada->deuda);
		p_entrada++;
	}
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
	/* Inicializando el puntero al primer elemento del arreglo lista */
	p_entrada = lista;
	for (cont = 0; cont < 4; cont++)
	{
		printf("\nlista[%d]:\t%p\t%p", cont, p_entrada->nombre, 
		p_entrada->apellido);
		p_entrada++;
	}
	printf("\n=====================================");
	printf("=============================\n\n");
}
