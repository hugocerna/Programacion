/* fichero ordenaPal.c */
/* Este programa pide diez palabras y las ordena por orden alfabético */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void) 
{
	char **cadena; /* declaración de puntero a matriz de caracteres*/
	int i, j;
	char temp[20]; /* declaración del array auxiliar */
	char *aux; /* decalaracion de puntero a carácter, auxiliar */
	printf("%s%s\n", "Este programa ordena diez palabras ",
	"introducidas por teclado.");
	printf("Introduce las diez palabras:\n");
	cadena = malloc(10*sizeof(char*));
	for (i = 0; i < 10; i++) 
	{
		printf("Palabra %d: ", i+1);
		scanf("%s", temp);
		cadena[i] = malloc((strlen(temp) + 1)*sizeof(char));
		strcpy(cadena[i], temp);
	}

	/* Ordenando las palabras alfabéticamente */
	for (i = 0; i < 9; i++) 
	{
		for(j = i + 1; j < 10; j++) 
		{
			if ((strcmp(cadena[i], cadena[j])) > 0) 
			{
				aux = cadena[i];
				cadena[i] = cadena[j];
				cadena[j] = aux;
			}
		}
	}
	
	/* Imprimiendo las palabras alfabéticamente */	
	printf("\nLa cadena ordenada es:\n");
	for (i = 0; i < 10; i++)
		printf("%s\n", cadena[i]);
}
