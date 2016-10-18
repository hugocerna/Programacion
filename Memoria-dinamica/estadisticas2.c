#include <stdio.h>

#include <stdlib.h>  /* necesario para poder llamar a las funciones
						malloc y free */ 

int i, * puntero; // puntero es un puntero a entero
int lon, min, max;
float med;
 
void ingresar_arreglo ();
void retornar_estadisticas (int * ptr);
 
void main ()
{
	ingresar_arreglo ();
	retornar_estadisticas (puntero);
	free(puntero); // liberando
}

void ingresar_arreglo ()
{
	int ok = 0;
	while (ok == 0)
	{ 
		printf("\n Ingrese la cantidad de alumnos: ");
		scanf("%d",&lon);
		puntero = malloc ( lon * sizeof(int) );
		if (puntero == NULL) 
			printf("\n Mensaje: No hay suficiente espacio en la memoria.\n");
		else
			ok = 1;
	}
	printf("\n Ingrese las edades de los alumnos:\n");
	for (i = 0 ; i < lon ; i++)
	{
		printf(" Alumno[%d] = ", i);
		scanf("%d", puntero + i);
	}
}

void retornar_estadisticas (int * ptr)
{
	med = min = max = *ptr;
	ptr += 1; // ptr = ptr + 1;
	for (i = 1 ; i < lon ; i++)
	{	
		if (*ptr < min)
			min = *ptr;
		if (*ptr > max)
			max = *ptr;
		med = med + *ptr;
		ptr += 1;
	}
	med = med/lon;
	printf("\n Estadísticas:\n");
	printf(" mínimo = %d\n", min);
	printf(" máximo = %d\n", max);
	printf(" media = %f\n\n", med);
}
