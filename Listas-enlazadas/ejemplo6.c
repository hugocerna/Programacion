// Demonstrando el ingreso de una lista de cadenas desde el teclado,
// el ordenamiento alfab\'etico de ellos y el mostrarlos en pantalla 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

// Declarando el arreglo auxiliar buffer
char buffer[MAX]; 

// Prototipo de funciones 
int ingresar_lista(char *puntero[], int N);
void ordenar_lista(char *puntero[], int N);
void imprimir_lista(char *puntero[], int N);
void imprimir_direcciones(char *puntero[], int N); 

void main(void) 
{
	int N, registros;
	
	//***************** Ingresando lista de nombres ********************
	printf("\n=========================== Ingreso de Datos ");
	printf("============================\n");
	// Asignando memoria din\'amica
	int OK = 0; // declarando e inicializando variable validadora
	char **lista; // declarando un puntero a un arreglo de punteros
	do
	{
		printf("\n Ingrese el numero de registros de la lista: "); 
		scanf("%d%*c",&N);
		lista = (char**)malloc( N*sizeof(char *) );
		if (lista != NULL) 
			// en caso en que el compilador ha separado la
			// memoria exitosamente, asignamos OK=1 para salir del bucle 
			OK = 1;
		else printf("\n Mensaje: No hay suficiente memoria.\n");
	}
	while (OK == 0);	
	registros = ingresar_lista(lista, N);
	//******************************************************************

	imprimir_direcciones(lista, registros);// antes del ordenamiento	
	ordenar_lista(lista, registros);
	imprimir_lista(lista, registros);
	imprimir_direcciones(lista, registros);// despu\'es del ordenamiento
	
	// Liberando memoria din\'amica
	free(lista);
}

int ingresar_lista(char *puntero[], int N)
{
	int cont = 0; // Declarando e inicializando variable contadora local
	int ok = 1; // Declarando e inicializando variable validadora local
	printf("\n");
	do
	{
		printf(" Ingrese lista[%d]: ", cont);
		scanf("%[^\n]%*c", buffer);
		puntero[cont] = 
			(char *)malloc( (strlen(buffer) + 1) * sizeof(char) );
		if (puntero[cont] != NULL) 
			// en caso en que el compilador ha separado la
			// memoria exitosamente hacemos a puntero[cont]
			// apuntar a buffer 
			strcpy(puntero[cont++], buffer);
		else 
		{
			printf("\n Mensaje: No hay suficiente memoria.\n");
			if (strlen(buffer) == 1)
				// No hay memoria ni para ingresar un caracter.
				// Entonces, hacemos ok = 0 para salir del bucle
				ok = 0; 
		}
	}
	while ((cont < N) && (ok == 1));
	printf("=================================================");
	printf("========================\n\n");
	return cont; // retornando la cantidad de nombres ingresados
}

// Ordenando la lista de nombres alfab\'eticamente 
void ordenar_lista(char *puntero[], int N)
{
	int cont, k; // Declarando variables contadoras locales
	char * aux; // Declarando un puntero a caracter auxiliar
	for (cont = 0; cont < N; cont++) 
	{
		for(k = cont + 1; k < N; k++) 
		{
			if ((strcmp(puntero[cont], puntero[k])) > 0) 
			{
				aux = puntero[cont];
				puntero[cont] = puntero[k];
				puntero[k] = aux;
			}
		}
	}
}
	
// Imprimiendo la lista de nombres  
void imprimir_lista(char *puntero[], int N)
{
	printf("=========================== Lista de nombres ");
	printf("============================\n\n");
	int cont; // Declarando variable contadora local
	for (cont = 0; cont < N; cont++)
		printf(" %s\n", puntero[cont]);
	printf("=================================================");
	printf("========================\n\n");
}

// Imprimiendo la lista de punteros
void imprimir_direcciones(char *puntero[], int N)
{
	int cont; // variable contadora local
	printf("================== Imprimiendo arreglo de punteros ");
	printf("======================\n");		
	for (cont = 0; cont < N; cont++)
		printf("\n lista[%d]:\t%p", cont, puntero[cont]); 
	printf("\n=================================================");
	printf("========================\n\n");
}
