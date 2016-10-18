#include <stdio.h>
#include <string.h>
#define LonMax 21

int i = 0, contador = 0;
char cadenas[LonMax][LonMax];
char cadena_final[LonMax];
void ingresar_cadena (void);
void combinaciones (char * cadena);

void main()
{
	ingresar_cadena();
	combinaciones( cadenas[i] );
}

void ingresar_cadena ()
{
	printf("\n Ingrese una cadena de no más de 20 caracteres y presione enter: ");
	scanf("%[^\n]%*c", cadenas[i]);
}
	
void combinaciones (char * cadena)
{
	if (strlen(cadena) == 1)
	{
		cadena_final[i] = cadena[0];
		cadena_final[i+1] = '\0'; // ingresando caracter nulo
		printf(" %d\t: %s\n", ++contador,cadena_final);
	}
	else
	{
		i++;
		int lon = strlen(cadena);
		int cont, k, j = i;
		for( cont = 0; cont < lon; cont++ )
		{
			i = j;
			cadena_final[i-1] = cadena[cont];
			for ( k = 0; k < lon-1; k++ )
				cadenas[i][k] = cadena[(cont+1+k)%(lon)];
			combinaciones (cadenas[i]);
		}
	}
}
