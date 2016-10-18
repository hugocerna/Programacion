//******** M\'etodo de Ordenamiento de Burbuja (invertido) *************
 
#include <stdio.h>
#include <stdlib.h> // necesario para evocar las funciones malloc y free

int cont; // variable contadora
int aux; // variable auxiliar
int i;

// Declarando prototipo de funciones 
void generar_arreglo(int *ptr, int N);
void ordenar_arreglo(int *ptr, int N);
	void intercambiar(int *ptr1, int *ptr2);
void imprimir_arreglo(int *ptr, int N);

void main()
{
	int N; // en N almacenar\'e la longitud del arreglo a generar
	
	//********** Ingresando logintud del arreglo a generar *************
	printf("\n============================ Ingreso de Datos ");
	printf("=============================\n");
	// Asignando memoria din\'amica
	int OK = 0; // declarando e inicializando variable validadora
	int *arreglo; // declarando un puntero a un arreglo de punteros
	do
	{
		printf("\n Ingrese el numero de registros de la lista: "); 
		scanf("%d%*c",&N);
		arreglo = (int*)malloc( N*sizeof(int) );
		if (arreglo != NULL) 
			// en caso en que el compilador ha separado la
			// memoria exitosamente, asignamos OK=1 para salir del bucle 
			OK = 1;
		else printf("\n Mensaje: No hay suficiente memoria.\n");
	}
	while (OK == 0);	
	printf("=============================================");
	printf("==============================\n\n");	
	//******************************************************************
	
	generar_arreglo(arreglo, N);
	imprimir_arreglo(arreglo, N);
	ordenar_arreglo(arreglo, N);
	imprimir_arreglo(arreglo, N);
	free(arreglo); // liberando memoria reservada por malloc
}

void generar_arreglo(int *ptr, int N)
{
	srand(1);
	for(cont = 0; cont < N; cont++)
		*(ptr + cont) = rand()%800 - 400;
}

// intercambiando los contenidos a los que apuntan ptr1 y ptr2
void intercambiar(int *ptr1, int *ptr2)
{
	aux = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = aux;
}

void ordenar_arreglo(int *ptr, int N)
{
	if(N >= 2)
	{
		for(cont = 0; cont < N - 1; cont++)
			if (*(ptr + cont) < *(ptr + cont + 1))
				intercambiar(ptr + cont, ptr + cont + 1);
		ordenar_arreglo(ptr, N - 1);
	}
}

void imprimir_arreglo(int *ptr, int N)
{
	printf("========================== Imprimiendo arreglo ");
	printf("============================\n\n");
	for(cont = 0; cont < N; cont++)
		printf(" arreglo[%d] = %d\n", cont, *(ptr + cont));
	printf("=============================================");
	printf("==============================\n\n");	
}
