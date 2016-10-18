// Demonstrando punteros y arreglos multidimensionales. 
 
#include <stdio.h>
#define Arreglo 3
#define Longitud 5

// Declarando arreglo multidimensional y variable contadora
int multi[Arreglo][Longitud], cont; 

// Declarando prototipo de funciones 
void imprimir_direcciones();
void imprimir_cantidad_bytes();

void main()
{	
	imprimir_direcciones();
	imprimir_cantidad_bytes();
}

void imprimir_direcciones()
{
	printf("\n== Imprimiendo las direcciones de");
	printf(" memoria del arreglo multidimensional ==\n\n");		
	printf(" multi\t :\t%p", multi);
	printf("\n multi + 0 :\t%p", multi + 0);
	printf("\n multi + 1 :\t%p", multi + 1);
	printf("\n multi + 2 :\t%p", multi + 2);
	printf("\n\n\t\tPrimer\t\tUltimo");
	for (cont = 0; cont < Arreglo; cont++)
	{
		printf("\n multi[%d]:\t%p\t%p", cont, &multi[cont][0], 
		//printf("\n Arreglo[%d]:\t%p\t%p", cont, multi[cont], 
		&multi[cont][Longitud]);
	}
	printf("\n========================================");
	printf("=================================\n\n");
}

void imprimir_cantidad_bytes()
{ 
	printf("========= Imprimiendo las cantidades de");
	printf(" bytes de cada variable ==========\n");			
	printf("\n sizeof( multi[0][0] ) = %lu", sizeof(multi[0][0]));
	printf("\n sizeof( multi[Arreglo - 1][Longitud - 1] ) = %lu", 
			sizeof(multi[Arreglo - 1][Longitud - 1]));
	printf("\n sizeof( multi[0] ) = %lu", sizeof(multi[0]));		
	printf("\n sizeof( multi[1] ) = %lu", sizeof(multi[1]));			
	printf("\n sizeof( multi[Arreglo - 1] ) = %lu", 
			sizeof(multi[Arreglo - 1]));
	printf("\n sizeof( multi ) = %lu", sizeof(multi));
	printf("\n sizeof( multi + 0 ) = %lu", sizeof(multi + 0));
	printf("\n sizeof( multi + 1 ) = %lu", sizeof(multi + 1));
	printf("\n sizeof( multi + Arreglo - 1 ) = %lu", 
			sizeof(multi + Arreglo - 1));
	printf("\n========================================");
	printf("=================================\n\n");
}
