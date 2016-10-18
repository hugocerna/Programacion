#include <stdio.h>
#include <stdlib.h> 

#define tamanho_max 1000 

/* Prototipo de la funciones */
void generar_cadena_de_letras(char a[]);
int ingresar_tamanho(void); 
void generar_cadena_aleatoria(char a[], int tam);
void mostrar_cadena(char a[], int tam);
void mostrar_estadisticas(char cad_letras[], char cad_aleatoria[], int tam);

int main() 
{
	int tamanho;
	char cad_letras[27];
	char cad_aleatoria[tamanho_max + 1];
	generar_cadena_de_letras(cad_letras);
	tamanho = ingresar_tamanho();
	generar_cadena_aleatoria(cad_aleatoria, tamanho);
	mostrar_cadena(cad_aleatoria, tamanho);
	mostrar_estadisticas(cad_letras, cad_aleatoria, tamanho);
}

/* Funcion que genera la cadena de letras */
void generar_cadena_de_letras(char a[])
{
	int i = 65;
	for( ; i <= 90 ; i++)
	{
		a[i - 64] = i;
	} 
}

/* Funcion que genera la cadena aleatoria de tamanho tam */
void generar_cadena_aleatoria(char a[], int tam)
{
	srand(time(NULL));
	int i = 1;
	for(; i <= tam; i++)
	{
		a[i] = rand()%26 + 65;
	} 
}

/* Funcion que imprime la cadena a[] de tamanho tam */
void mostrar_cadena(char a[], int tam)
{
	int i = 1;
	for(; i <= tam; i++)
	{
		printf("%c ",a[i]);
	}
	printf("\n");
}

/* Funcion de entra del tamanho de una cadena */
int ingresar_tamanho(void) 
{
	int ok = 0; 
	int N; // variable donde almacenar\'e lo que voy a retornar
	do
	{
		printf("Ingrese el tamanho del arreglo aleatorio a genrar: "); 
		scanf("%d",&N);
		if (N <= tamanho_max) ok = 1; // en caso que N sea menor o igual a tamanho_max, asignamos ok = 1 para salir del bucle
		else printf("El tamnho no puede ser mayor que 1000!\n");
	}
	while (ok == 0);
	return N;	
}

/* Funcion que muestra las veces que aparece cada letra en la cadena aleatoria generada */
void mostrar_estadisticas(char cad_letras[], char cad_aleatoria[], int tam)
{
	int i, j, cont;
	printf("Estadisticas de la cadena aleatoria generada%c", 10);
	for( i = 1 ; i <= 26 ; i++ )
	{
		cont = 0;
		for( j = 1 ; j <= tam ; j++ )
			if( cad_letras[i] == cad_aleatoria[j] ) cont++;
		printf("La letra %c aparece %i veces%c", 64+i, cont, 10);
	} 
}
