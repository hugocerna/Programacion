// Mostrando la generación aleatoria de una cadena de letras MAYÚSCULAS y sus estadísticas

#include <stdio.h>
#include <stdlib.h> // en algunos compiladores NO es necesario incluirla para poder emplear la función rand()

#define LonMax 100

// Variable globales
char cad_letras[27]; // para almacenar la cadena de letras MAYÚSCULAS
char cad_aleatoria[LonMax + 1];
int i, j; // para almacenar índices

// Prototipo de la funciones 
void generar_cadena_letras (); 
void generar_cadena_aleatoria (int lon);
void mostrar_cadena ();
void mostrar_estadisticas ();
int ingresar_longitud ();

int main() 
{
	int longitud;
	generar_cadena_letras ();
	longitud = ingresar_longitud ();
	generar_cadena_aleatoria (longitud);
	mostrar_cadena ();
	mostrar_estadisticas ();
}

/* Función que genera la cadena de letras MAYÚSCULAS */
void generar_cadena_letras ()
{
	for( i = 0 ; i <= 25 ; i++)
		cad_letras[i] = i + 65;
	cad_letras[i] = '\0'; // asignando a cad_letras[26] el caracter nulo
}

int ingresar_longitud () 
{
	int N; 
	printf("\n Ingrese la longitud (<= %d) de la cadena aleatorio a generar: ", LonMax); 
	scanf("%d",&N);
	return N;	
}

/* Funcion que genera la cadena aleatoria de tamaño lon */
void generar_cadena_aleatoria (int lon)
{
	for( i = 0 ; i < lon; i++)
	// Asignando aleatoriamente a cad_aleatoria[i] un valor entero del intervalo [65,90] 
		cad_aleatoria[i] = rand()%26 + 65;
	cad_aleatoria[i] = '\0'; // asignando a cad_aleatoria[lon] el caracter nulo 
}

void mostrar_cadena ()
{
	printf("\n Cadena generada aleatoriamente: ");
	i = 0;
	while (cad_aleatoria[i] != '\0')
	// mostrando el valor de a[i] y luego asignando a i el valor de i+1
		printf("%c", cad_aleatoria[i++]);
	printf("\n");
}

/* Funcion que muestra las veces que aparece cada letra en la cadena aleatoria generada */
void mostrar_estadisticas ()
{
	int cont, sum = 0;
	printf("\n Estadísticas de la cadena aleatoria generada:%c", 10);
	for( i = 0 ; i < 26 ; i++ )
	{
		cont = 0;
		j = 0;
		while (cad_aleatoria[j] != '\0')
			if(cad_letras[i] == cad_aleatoria[j++]) cont++;
		printf(" La letra %c aparece %i veces%c", cad_letras[i], cont, 10);
		sum += cont; // sum = sum + cont
	}
	printf("\n Total de letras generas aleatoriamente: %d%c%c", sum, 10, 10);
}
