#include <stdio.h>

#define LonMax 40
int Alumno[LonMax + 1];
int i;
int Lon, min, max;
float med;
 
void ingresar_arreglo ();
void retornar_estadisticas ();
 
void main ()
{
	ingresar_arreglo ();
	retornar_estadisticas (Alumno);
}

void ingresar_arreglo ()
{
	printf("\n Ingrese la cantidad de alumnos: ");
	scanf("%d",&Lon);
	printf("\n Ingrese las edades de los alumnos:\n");
	for (i = 0 ; i < Lon ; i++)
	{
		printf(" Alumno[%d] = ", i);
		scanf("%d",&Alumno[i]);
	}
}

void retornar_estadisticas (int * ptr)
{
	min = max = *ptr;
	med = 0;
	for (i = 0 ; i < Lon ; i++)
	{	
		if (*ptr < min)
			min = *ptr;
		if (*ptr > max)
			max = *ptr;
		med = med + *ptr;
		ptr++;
	}
	med = med/Lon;
	printf("\n Estadísticas:\n");
	printf(" mínimo = %d\n", min);
	printf(" máximo = %d\n", max);
	printf(" media = %f\n\n", med);
}
