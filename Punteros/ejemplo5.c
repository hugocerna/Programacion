// Demonstrando el paso de un arreglo de punteros a una funci\'on 
 
#include <stdio.h>
#define Cadena 10

// Declarando prototipo de funciones 
void imprimir_cadenas(char *p[], int N);
void imprimir_direcciones(char *p[], int N);

void main()
{
	// Declarando e inicializando un arreglo de punteros a caracter
	char *mensaje[Cadena] = {"one", "two", "three"};
	
	imprimir_cadenas(mensaje, Cadena);
	imprimir_direcciones(mensaje, Cadena);
}

void imprimir_cadenas(char *p[], int N)
{
	int cont; // variable contadora local
	printf("\n========================= Imprimiendo cadenas ");
	printf("===========================\n\n");		
	for (cont = 0; cont < N; cont++)
		printf(" %s\n", p[cont]);
	printf("===============================================");
	printf("==========================\n\n");		
}

void imprimir_direcciones(char *p[], int N)
{
	int cont; // variable contadora local
	printf("================== Imprimiendo arreglo de punteros ");
	printf("======================\n");		
	for (cont = 0; cont < N; cont++)
		printf("\n mensaje[%d]:\t%p", cont, p[cont]); 
	printf("\n===============================================");
	printf("==========================\n\n");
}
