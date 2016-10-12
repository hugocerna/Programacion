/* Pasando un arreglo a una función */

#include <stdio.h>
#define MAX 10

int arreglo[MAX], cont;
int mayor(int num_arreglo[], int lon);

int main()
{
	/* Ingresando el arreglo de enteros desde el teclado. */
	printf("\n Ingresando los elementos del arreglo:\n");
	for (cont = 0; cont < MAX; cont++)
	{
		printf(" areglo[%d]: ", cont);
		scanf("%d", &arreglo[cont]);
	}

	/* Llamando a la función y mostrando el valor de retorno. */
	printf("\n Mayor elemento : %d\n\n", mayor(arreglo, MAX) );
	return 0;
}

/* Esta función retorna el elemento mayor de un arreglo de enteros */
int mayor(int* num_arreglo, int lon)
{
	int max = *(num_arreglo+0);
	for ( cont = 1; cont < lon; cont++)
	{
		if (*(num_arreglo + cont)> max)
			max = *(num_arreglo+cont);
	}
	return max;
}
