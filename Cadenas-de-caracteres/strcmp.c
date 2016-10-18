// Mostrando el uso de las función strcmp()

#include <stdio.h>
#include <string.h> // necesario para utilizar strcmp

#define LonMax 40
int i; // para almacenar índices 
char cad1[LonMax + 1];
char cad2[LonMax + 1];

void main()
{
	int ch, diferencia;
	
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

	diferencia = strcmp (cad1, cad2);
	printf("\n");		
	printf(" diferencia = %d\n", diferencia);
	if (diferencia < 0)
		printf(" cad2 está después de cad1.\n\n");
	else if (diferencia > 0)
		printf(" cad2 está antes de cad1.\n\n");
	else 
		printf(" cad1 y cad2 son iguales.\n\n");	
}
