#include<stdio.h>
int A[100];
int entrada(void); // Prototipo de la función entrada
void entrada_arreglo(int N); // Prototipo de la función entrada_array
int unico(int k, int P); // Prototipo de la función unico
void mostrar(int N); // Prototipo de la función mostrar

void main()
{
	int N = entrada();
	entrada_arreglo(N);
	mostrar(N);
}

int entrada(void) // cabecera de la definición de la función entrada
{
	int ok = 0; 
	int N; // variable donde almacenar\'e lo que voy a retornar
	do
	{
		printf("Ingrese un entero positivo N: "); 
		scanf("%d",&N);
		if (N > 0) ok = 1; // en caso que N sea mayor que cero, asignamos ok = 1 para salir del bucle
		else printf("Valor de entrada incorrecto!\n"); // ok sigue valiendo 0
	}
	while (ok == 0);
	return N;	
}

void entrada_arreglo(int N) // cabecera de la definición de la función entrada
{
	int i=1;
	printf("Ingrese los elementos del arreglo de enteros A:");
	for (; i <= N; i++ )
	{
		printf("\n A[%d] = ",i);
		scanf("%d",&A[i]);
	}
}

int unico(int k, int P)
{
	// la funcion retornar\'a 0 si encuentra que el elemento P ubicado en la posici\'on k de A 
	// se repite en el arreglo (A[1],A[2],...,A[k-1]); caso contrario, retornar\'a 1
	int i=1;
	for (; i < k; i++)
		if(A[i] == P) return 0;
	return 1;  
}

void mostrar(int N)
{
	int i=2;
	printf("Nuevo arreglo: %d ",A[1]);
	for (; i <= N; i++)
		if (unico(i,A[i]) == 1) printf(", %d ",A[i]);
	printf("\n");
}
