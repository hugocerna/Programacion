#include <stdio.h>

#define LonMax 40
char cad[LonMax + 1];
char ch;
int i;
 
void ingresar_cadena ();
void retornar_longitud ();
 
void main ()
{
	ingresar_cadena ();
	retornar_longitud ();
}

void ingresar_cadena ()
{
	printf("\n Ingrese una cadena de a lo más %d caracteres : ", LonMax);
	ch = getchar();
	i = 0;
	while (ch != '\n')
	{
		cad[i++] = ch;
		ch = getchar();
	}
	cad[i] = '\0';
}

void retornar_longitud ()
{
	i = 0;
	while (cad[i] != '\0')
		i++;
	printf("\n La longitud de la cadena ingresada es %d.\n\n", i);
 }
