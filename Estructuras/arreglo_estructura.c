/* Demonstrando arreglos de estructuras que contienen arreglos. */

#include <stdio.h>

/* Declarando una estructura que contiene arreglos */
struct entrada {
char nombre[20];
char apellido[20];
char telefono[10];
};

/* Declarando un arreglo de estructuras. */
struct entrada lista[3];

void main( void )
{
	/* Bucle para ingresar datos de 3 personas. */
	int i = 0;
	for (; i < 3; i++)
	{
		printf("\nIngreso del registro lista[%d]",i);
		printf("\nIngrese el primer nombre: ");
		scanf("%s", lista[i].nombre);
		printf("Ingrese el apellido paterno: ");
		scanf("%s", lista[i].apellido);
		printf("Ingrese el numero telefonico en el formato 123-4567: ");
		scanf("%s", lista[i].telefono);
	}
	
	/* Buble para mostrar los datos. */
	for (i = 0; i < 3; i++)
	{
		printf("\nNombre: %s %s", lista[i].nombre, lista[i].apellido);
		printf("\tNumero telefonico: %s", lista[i].telefono);
	}
	printf("\n\n");
	
	/* Imprimiendo direcciones de memoria. */
	printf("============ Imprimiendo las direcciones");
	printf(" de memoria ==============\n\n");		
	printf("\t\tnombre\t\tapellido\ttelefono");
	printf("\n=====================================");
	printf("=============================");	
	for (i = 0; i < 3; i++)
		printf("\nlista[%d]:\t%p\t%p\t%p", i, &(lista[i].nombre[0]), 
		&(lista[i].apellido[0]), &(lista[i].telefono[0]));
	printf("\n=====================================");
	printf("=============================\n\n");
}
