/* Método de paso por referencia, mediante punteros */

#include <stdio.h>

/* Una variable, o parámetro puntero se declara poniendo el asterisco (*) 
 * antes del nombre de la variable. 
 * Las variables p, r y q son punteros a distintos tipos. */
 
char* p; // variable puntero a char
int * r; // variable puntero a int
double* q; // variable puntero a double 

void intercambio (int* a, int* b); 

// &x retorna la dirección en memoria de x 
// *p retorna la el valor almacenado en la dirección de memoria p 

int main (void)
{
	int i = 3; int j = 50;
	printf("\n i = %d y j = %d\n", i, j);
	intercambio( &i, &j );
	printf(" i = %d y j = %d\n\n", i, j);
	return 3;	
}

void intercambio (int* a, int* b) // cabecera de funcion 
{ 
	int aux = *a;
	*a = *b; 
	*b = aux; 
}
