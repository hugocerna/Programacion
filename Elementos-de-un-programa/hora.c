/* Programa que muestra el uso de los operadores aritméticos */

/* incluyendo la librería estándar de E/S de datos */
#include<stdio.h>

void main(void)
{
	unsigned int horas, minutos, segundos, min_restantes, seg_restantes;
	printf("\n Ingrese la cantidad de segundos ");
	printf("que ha transcurrido durante el día: ");
	scanf("%u", &segundos);
	
	horas = segundos / 3600; // calculando la cantidad de horas
	minutos = segundos / 60; // calculando la cantidad de minutos 
	min_restantes = minutos % 60; // ... de minutos restantes
	seg_restantes = segundos % 60; // ... de segundos restantes
	
	printf(" La hora es ");
	printf("%u h.  %u m.  %u s.\n\n", horas, min_restantes, seg_restantes);
}
