// Mostrando el uso de las función strlen() 

#include <stdio.h>
#include <string.h> // necesario para utilizar strlen

#define LonMax 40
int i; // para almacenar índices 
char cad1[LonMax + 1]; 
char cad2[LonMax + 1];

void main()
{
	int ch, Lon1, Lon2, diferencia;
	
	// ingresando cad1
	printf("\n");  
	printf(" Ingrese una cadena de caracteres (de no más de %d caracteres) cad1: ", LonMax);
	ch = getchar(); 
	i = 0;
	while (ch != '\n')
	{
		cad1[i++] = ch;
		ch = getchar();
	}
	cad1[i] = '\0';

	// ingresando cad2
	printf("\n");  
	printf(" Ingrese una cadena de caracteres (de no más de %d caracteres) cad2: ", LonMax);
	ch = getchar(); 
	i = 0;
	while (ch != '\n')
	{
		cad2[i++] = ch;
		ch = getchar();
	}
	cad2[i] = '\0';

	printf("\n");
	printf(" Usted ingresó cad1: %s\n", cad1);
	printf(" Usted ingresó cad2: %s\n\n", cad2);
	
	Lon1 = strlen(cad1);
	Lon2 = strlen(cad2);
	printf(" La longitud de la cadena cad1 es %d.\n", Lon1);
	printf(" La longitud de la cadena cad2 es %d.\n\n", Lon2);
	
	diferencia = Lon1 - Lon2;
	printf(" diferencia = %d\n", diferencia);
	if (diferencia < 0)
		printf(" cad2 es más grande que cad1.\n\n");
	else if (diferencia > 0)
		printf(" cad2 es más pequeña que cad1.\n\n");
	else 
		printf(" cad1 y cad2 son del mismo tamaño.\n\n");	
}
