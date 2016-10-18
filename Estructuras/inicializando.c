/* Demonstrando la inicializacion de estructuras. */

#include <stdio.h>

/* Declarando una plantilla de estructura simple */
struct cliente 
{
	char firma[20];
	char contacto[20];
};

/* Declarando unam plantillla estructura compleja */
struct venta 
{
	struct cliente comprador;
	char item[36];
	float cantidad;
};

/* Declarando e inicializando un arreglo de estructuras. */
struct venta lista[5] = 
{	
	{ 	
		{"Gloria", "Juan Perez"},
		"Un galon de leche descremada",
		100.50
	},
	{ 
		{"Cemento Sol", "Maria Rojas"},
		"Una tonelada de cemento",
		9000.00
	},
	{ 
		{"Primor", "Raul Torres"},
		"Una tonelada de aceite vegetal",
		280.50
	},
	{ 
		{"Bayovar", "Juan Jimenez"},
		"Una tonelada de harina de pescado",
		180.50
	}		
};

void main( void )
{		
	/* Buble para mostrar los datos. */
	int i;
	for (i = 0; i < 4; i++)
	{
		printf("\nFirma: %s", lista[i].comprador.firma);
		printf("\nContacto: %s", lista[i].comprador.contacto);
		printf("\nItem: %s\nCantidad: %.2f\n", lista[i].item, lista[i].cantidad);
	}
	printf("\n\n");
	
	/* Imprimiendo direcciones de memoria. */
	printf("============ Imprimiendo las direcciones");
	printf(" de memoria ==============\n\n");		
	printf("\t\tcomprador\titem\t\tcantidad");
	printf("\n=====================================");
	printf("=============================");	
	for (i = 0; i < 4; i++)
		printf("\nlista[%d]:\t%p\t%p\t%p", i, &(lista[i].comprador), 
		&(lista[i].item[0]), &(lista[i].cantidad));
	printf("\n=====================================");
	printf("=============================\n\n");
		printf("sizeof(float) = %lu\n", sizeof(float));
	printf("sizeof(double) = %lu\n", sizeof(double));
	printf("sizeof(long float) = %lu\n\n", sizeof(long double));

}
