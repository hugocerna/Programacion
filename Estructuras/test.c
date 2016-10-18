/* Demonstrando el paso de una estructura a una funcion. */

#include <stdio.h>
#include <stdlib.h> // necesario para usar malloc y free

/* Declarando un prototipo de estructura */
struct entrada {
float nombre[20];
char apellido[20];
long double deuda;
};

/* Declarando prototipo de funcion */
void ingresar_lista(struct entrada *p_entrada, int N);
void imprimir_lista(struct entrada *p_entrada, int N);
void imprimir_direcciones_memoria(struct entrada *p_entrada, int N);

int cont; // variable contadora

void main( void )
{
	/* Declarando e inicializando un arreglo de estructuras. */
	printf("sizeof(struct entrada) = %lu\n", sizeof(struct entrada));

	int ok = 0, N;
	struct entrada *lista;
	if (lista == NULL)
		printf("lista = NULL\n");
	printf("Direccion de lista: %p\n", &lista);
	printf("Contenido de lista: %p\n", lista);
	do
	{
		printf("Ingrese el numero de registros de la lista: "); 
		scanf("%d",&N);
		printf("N = %d\n", N);
		lista = (struct entrada *)malloc( N*sizeof(struct entrada) );
		if (lista != NULL) 
			ok = 1; /* en caso en que el compilador ha separado la
			memoria exitosamente, asignamos ok=1 para salir del bucle */
		else printf("No hay suficiente memoria para tal tamanho.\n");
	}
	while (ok == 0);
	
	if (lista == NULL)
		printf("lista = NULL\n");
	printf("Direccion de lista: %p\n", &lista);
	printf("Contenido de lista: %p\n", lista);
	printf("Direccion de lista[0].nombre[0]: %p\n", lista -> nombre);
	//lista -> nombre = lista -> nombre + 1;
	printf("Direccion de lista[0].nombre[1]: %p\n", lista -> nombre + 1);
	

/*	
	ingresar_lista(lista, N);
	imprimir_lista(lista, N);
	imprimir_direcciones_memoria(lista, N);
	
	printf("sizeof(float) = %lu\n", sizeof(float));
	printf("sizeof(double) = %lu\n", sizeof(double));
	printf("sizeof(long float) = %lu\n\n", sizeof(long double)); 
}

void ingresar_lista(struct entrada *p_entrada, int N)
{
	//struct entrada *p_entrada = lista; 
	for (cont = 0; cont < N; cont++)
	{
		printf("\nIngreso del registro lista[%d]",cont);
		printf("\nIngrese el primer nombre: ");
		scanf("%s", p_entrada->nombre);
		printf("Ingrese el apellido paterno: ");
		scanf("%s", p_entrada->apellido);
		printf("Ingrese la deuda: ");
		scanf("%Lf", &p_entrada->deuda);
		p_entrada++;
	}
	printf("\n\n");
}

void imprimir_lista(struct entrada *p_entrada, int N)
{
	/* Bucle para mostrar los datos 
	   utilizando la aritmetica de punteros. 
	//p_entrada = lista;
	for (cont = 0; cont < N; cont++)
	{
		printf("\nNombre: %s ", p_entrada -> nombre); 
		printf("%s", p_entrada -> apellido);
		printf("\tDeuda: %.2Lf", p_entrada -> deuda);
		p_entrada++;
	}
	printf("\n\n");
}

void imprimir_direcciones_memoria(struct entrada *p_entrada, int N)
{
	/* Imprimiendo direcciones de memoria de lista. 
	printf("======= Imprimiendo las direcciones");
	printf(" de memoria de lista ==========\n\n");		
	printf("\t\tnombre\t\tapellido\ttelefono");
	printf("\n=====================================");
	printf("=============================");	
	// p_entrada = lista;
	for (cont = 0; cont < N; cont++)
	{
		printf("\nlista[%d]:\t%p\t%p\t%p", cont, p_entrada->nombre, 
		p_entrada->apellido, &p_entrada->deuda);
		p_entrada++;
	}
	printf("\n=====================================");
	printf("=============================\n\n");
	*/
}
