//********** M\'etodo de Ordenamiento R\'apido (invertido) *************
 
#include <stdio.h>
#include <stdlib.h> // necesario para evocar las funciones malloc y free

int cont; // variable contadora
int aux; // variable auxiliar
int i;
float pivote;
int min;
int max;

// Declarando prototipo de funciones 
void generar_arreglo(int *ptr, int N);
void ordenar_arreglo(int *ptr, int N);
	void intercambiar(int *ptr1, int *ptr2);
	void min_arreglo(int *ptr, int N);
	void max_arreglo(int *ptr, int N);
	int K_arreglo(int *ptr, int N);
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
	free(arreglo);
}

void generar_arreglo(int *ptr, int N)
{
	srand(1);
	for(cont = 0; cont < N; cont++)
		*(ptr + cont) = rand()%800 - 400;
}

void min_arreglo(int *ptr, int N)
{
	min = *ptr;
	for(cont = 1; cont < N; cont++)
	{
		aux = *(ptr + cont);
		if(aux < min)
			min = aux;
	} 
}

void max_arreglo(int *ptr, int N)
{
	max = *ptr;
	for(cont = 1; cont < N; cont++)
	{
		aux = *(ptr + cont);
		if(max < aux)
			max = aux;
	} 
}

// retornando la cantidad de elementos mayores o iguales a pivo 
int K_arreglo(int *ptr, int N)
{
	int K = 0;
	for(cont = 0; cont < N; cont++)
	{
		if(*(ptr + cont) >= pivote)
			K++;
	} 
	return K;
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
	int K; // variable contadora local
	min_arreglo(ptr, N);
	max_arreglo(ptr, N);
	if(min < max)
	{
		if(N == 2)
			if (*ptr < *(ptr + 1))
				intercambiar(ptr, ptr + 1);
		if(N > 2)
		{
			pivote = ((float)(min + max)) / 2;
			K = K_arreglo(ptr, N);
			for(cont = 0; cont < K; cont++)
			{
				if (*(ptr + cont) < pivote)
				{
					for(i = 1; ;i++)
					{
						if(*(ptr + cont + i) >= pivote)
						{
							intercambiar(ptr + cont, ptr + cont + i);
							break; // saliendo del bucle for m\'as pr\'oximo
						}
					}
				}
			}
			ordenar_arreglo(ptr, K);
			ordenar_arreglo(ptr + K, N - K);
		}
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
