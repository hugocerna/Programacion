// Demonstrando el paso de puntero a un 
// arreglo multidimensional a una funcion 
 
#include <stdio.h>
#define Arreglo 3
#define Longitud 5

// Declarando prototipo de funciones 
void imprimir_arreglo_1(int (*ptr)[Longitud]);
void imprimir_arreglo_2(int (*ptr)[Longitud], int n);

void main()
{
	int k; // Declarando variable contadora

	// Inicializando arreglo multidimensional
	int multi[Arreglo][Longitud] = 
		{ 
			{ 1, 2, 3, 4, 5 },
			{ 6, 7, 8, 9, 10  },
			{ 11, 12, 13, 14, 15 } 
		};
	
	// Declarando un puntero a un arreglo de 5 enteros 
	int (*puntero)[Longitud];

	// Haciendo puntero apuntar al primer elemento de multi
	puntero = multi;

	//*************** Imprimiendo de la primera forma ******************
	//
	// En cada iteraci\'on, puntero es incrementado para apuntar al 
	// siguiente elemento, i.e. el sgte arreglo de 5 enteros,
	// de multi. 
	printf("\n================= Imprimiendo arreglo mutidimensional ");
	printf("===================\n");		
	for (k = 0; k < Arreglo; k++)
		imprimir_arreglo_1(puntero++);
	printf("\n===============================================");
	printf("==========================\n\n");		
	//******************************************************************	

	//*************** Imprimiendo de la segunda forma ******************	
	imprimir_arreglo_2(multi, Arreglo);
}

// Esta funci\'on imprime los elementos de un arreglo de 5 enteros
void imprimir_arreglo_1(int (*ptr)[Longitud])
{	
	// Declarando un puntero a entero y una variable contadora local
	int *p, cont; 
	
	// Debemos usar (int *) para hacer p igual a la direcci\'on de ptr
	// porque ptr es un puntero a un arreglo de 5 elementos 
	p = (int *)ptr;
	
	for (cont = 0; cont < Longitud; cont++)
		printf("\n%d", *p++);
}

// Esta funci\'on imprime los elementos de un arreglo de N por 5 enteros	
void imprimir_arreglo_2(int (*ptr)[Longitud], int N)
{
	// Declarando un puntero a entero y una variable contadora local
	int *p, cont; 
	p = (int *)ptr; // Necesario hacer el casting para poder igualar
	printf("\n================= Imprimiendo arreglo mutidimensional ");
	printf("===================\n");		
	for (cont = 0; cont < (N * Longitud); cont++)
		printf("\n%d", *p++);
	printf("\n===============================================");
	printf("==========================\n\n");		
}
