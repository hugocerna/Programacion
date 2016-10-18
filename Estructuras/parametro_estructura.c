/* Demonstrando el paso de una estructura a una funcion. */

#include <stdio.h>
#include <stdlib.h> // necesario para usar malloc y free

/* Declarando un prototipo de estructura */
struct entrada {
	char nombre[20];
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
	printf("\nImprimiendo la cantidad de bites empleada por variable:");
	printf("\n\nsizeof(char) = %lu", sizeof(char));
	printf("\nsizeof(float) = %lu", sizeof(float));
	printf("\nsizeof(double) = %lu", sizeof(double));
	printf("\nsizeof(long float) = %lu", sizeof(long double)); 
	printf("\nsizeof(struct entrada) = %lu", sizeof(struct entrada));

	/* Reservando memoria invocando a la funcion malloc */
	int ok = 0, N;
	struct entrada *lista; // declarando un puntero a una estructura
	do
	{
		printf("\n\nIngrese el numero de registros de la lista: "); 
		scanf("%d",&N);
		lista = (struct entrada *)malloc( N*sizeof(struct entrada) );
		if (lista != NULL) 
			ok = 1; /* en caso en que el compilador ha separado la
			memoria exitosamente, asignamos ok=1 para salir del bucle */
		else printf("No hay suficiente memoria para tal tamanho.\n");
	}
	while (ok == 0);
	
	/* Empleando la lista creada dinamicamente */	
	ingresar_lista(lista, N);
	imprimir_lista(lista, N);
	imprimir_direcciones_memoria(lista, N);
	free(lista); // Liberando espacio reservado por malloc
}

void ingresar_lista(struct entrada *p_entrada, int N)
{
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
	   utilizando la aritmetica de punteros. */
	printf("================= Imprimiendo lista de deudores ");
	printf("==================\n");		
	for (cont = 0; cont < N; cont++)
	{
		printf("\nNombre: %s ", p_entrada -> nombre); 
		printf("%s", p_entrada -> apellido);
		printf("\tDeuda: %.2Lf", p_entrada -> deuda);
		p_entrada++;
	}
	printf("\n=============================================");
	printf("=====================\n\n");	
}

void imprimir_direcciones_memoria(struct entrada *p_entrada, int N)
{
	/* Imprimiendo direcciones de memoria de lista. */
	printf("======= Imprimiendo las direcciones");
	printf(" de memoria de lista ==========\n\n");		
	printf("\t\tnombre\t\tapellido\ttelefono");
	printf("\n=====================================");
	printf("=============================");	
	for (cont = 0; cont < N; cont++)
	{
		printf("\nlista[%d]:\t%p\t%p\t%p", cont, p_entrada->nombre, 
		p_entrada->apellido, &p_entrada->deuda);
		p_entrada++;
	}
	printf("\n=====================================");
	printf("=============================\n\n");
}
