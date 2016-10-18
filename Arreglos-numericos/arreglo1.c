#include <stdio.h>
#define Max 15 // definiendo la constante Max

// definiendo variables globales
int arreglo[Max];
int Lon; // longitud del arreglo a ingresar

// prototipos de funciones
void ingresar_longitud(void);
void ingresar_arreglo(void);
void mostrar_arreglo(void);
void mostrar_arreglo_invertido(void);

void main ()
{
	ingresar_longitud();
	ingresar_arreglo();
	mostrar_arreglo();
	mostrar_arreglo_invertido();
}

void ingresar_longitud(void)
{
	printf("\n Ingrese la longitud del arreglo (<= 15): ");
	scanf("%d",&Lon);
}
	
void ingresar_arreglo(void)
{
	int i;
	for (i = 0; i < Lon; i++)
	{
		printf(" Ingrese el elemento %d del arreglo: ",i);
		scanf("%d",&arreglo[i]);
	}	
}

void mostrar_arreglo(void)
{
	int i;
	printf("\n Elementos del arreglo:");
	for (i = 0; i < Lon; i++)
		printf("\n Elemento %d del arreglo: %d", i, arreglo[i]);
	printf("\n");
}

void mostrar_arreglo_invertido(void)
{
	int i;
	printf("\n Elementos en sentido invertido del arreglo:");
	for (i = Lon-1; i >= 0; i--)
		printf("\n Elemento %d del arreglo: %d", i, arreglo[i]);
	printf("\n");
}
