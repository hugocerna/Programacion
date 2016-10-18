#include <stdio.h>
#include <stdlib.h>  /* necesario para poder llamar a las funciones
						malloc y free */ 

/* Prototipo de la funciones */
char *generar_cadena_aleatoria();
char *modificar_cadena(char *cad);
void mostrar_cadena(char *cad);

int main() 
{
	char *cadena = generar_cadena_aleatoria();

	/* Mostrando cadena aleatoria generada */
	printf("Cadena aleatoria generada:\n");
	mostrar_cadena(cadena);

	cadena = modificar_cadena(cadena);
	
	/* Mostrando cadena aleatoria modificada */
	printf("Cadena aleatoria modificada:\n");
	mostrar_cadena(cadena);
	
	/* Liberando espacio reservado al llamar la funci\'on "malloc" */
	free(cadena);
}

/* Funcion que genera la cadena aleatoria */
char *generar_cadena_aleatoria()
{
	int ok = 0, N;
	char * puntero;
	do
	{
		printf("Ingrese el tamanho del arreglo aleatorio a generar: "); 
		scanf("%d",&N);
		puntero = malloc( (N+1)*sizeof(char) );
		if (puntero != NULL) 
			ok = 1; /* en caso en que el compilador ha separado la
			memoria exitosamente, asignamos ok=1 para salir del bucle */
		else printf("No hay suficiente memoria para tal tamanho.\n");
	}
	while (ok == 0);
	char *ptr = puntero;
	//srand(time(NULL));
	srand(1);
	int i = 0, k, num;
	for(; i < N; i++)
	{
		k = rand()%63;
		if ( k < 26 )	
			num = k + 65;
		if ( (26 <= k) && (k < 52) )
			num = k + 71;
		if ( (52 <= k) && (k < 62) )
			num = k - 4;
		if (k == 62)
			num = 32;
		*(ptr + i) = num;
	}
	*(ptr + N) = '\0';
	return puntero;
}

/* Funcion que modifica la cadena aleatoria generada */
char *modificar_cadena(char *cad)
{
	char *ptr = cad;
	char caracter = *cad;
	while(caracter != '\0')
	{
		if ( (48 <= caracter) && (caracter <= 57 ) )	
			*ptr = 105 - caracter;
		if ( (65 <= caracter) && (caracter <= 90) )
			*ptr = caracter + 32;
		if ( (97 <= caracter) && (caracter <= 122) )
			*ptr = caracter - 32;
		caracter = *(++ptr);
	}
	return cad;
}

/* Funcion que imprime la cadena de caracteres a[] */
void mostrar_cadena(char *cad)
{
	char caracter = *cad;
	char *ptr = cad;
	printf("INICIO#");
	while( caracter != '\0')
	{
		printf("%c",caracter); 
		caracter = *(++ptr);
	}
	printf("#FIN\n");
}
