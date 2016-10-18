#include <stdio.h>

// Definiendo constantes y variables globales
#define LonMax 1000 
int arreglo[LonMax]; // para almacenar el arreglo de enteros a ingresar
int sigma[LonMax]; // arreglo de indices permutados
int temp[LonMax]; // arreglo de indices temporales
int N; // longitud del arreglo a ingresar
int cont; // variable contadora

// Prototipo de la funciones 
void ingresar_longitud( void ); 
void ingresar_arreglo( void );
void mostrar_arreglos( void );
void permutar_arreglo( void );
void permutar_indices( int val , int n );
int factorial( int k );

void main() 
{
	ingresar_longitud(); 
	ingresar_arreglo();

	permutar_arreglo();
	mostrar_arreglos();

	permutar_arreglo();
	mostrar_arreglos();

	printf("\n");
}

void ingresar_longitud(void)
{
	printf("\n Ingresar la longitud del arreglo a introducir: ");
	scanf("%d", &N);
}

void ingresar_arreglo( void )
{
	int i;
	for ( i = 0 ; i < N ; i++ )
	{
		printf(" arreglo[%d]: ", i);
		scanf("%d", &arreglo[i]);
	}
}

void mostrar_arreglos( void )
{
	int i;
	printf("\n Arreglo ingresado: ");
	for ( i = 0 ; i < N ; i++ )
		printf( "\t%d", arreglo[i] );
	printf("\n Arreglo permutado: ");
	for ( i = 0 ; i < N ; i++ )
		printf( "\t%d", arreglo[ sigma[i] ] );
	printf("\n");
}

void permutar_arreglo( void )
{
	int i, M; // M va almacenar un valor entero de [0,N!-1]
	for ( i = 0 ; i < N ; i++ )
		temp[i] = i; // inicializando el arreglo temporal de índices
	cont = 0; // inicializando a cero la variable contadora
	M = rand() % ( factorial(N) ); // sorteando un entero en [0, N!-1]
	permutar_indices( M , N );
}

void permutar_indices( int val , int n )
{
	if (n == 1)
		sigma[cont] = temp[0];
	else
	{
		int k, i;
		i = val / factorial(n-1);
		sigma[cont++] = temp[i];
		for ( k = 0 ; k < n ; k++ )
		{
			if (k < i)
				temp[k] = temp[k];
			else
				if (k + 1 < n)
					temp[k] = temp[k + 1];
		}
		permutar_indices( val % factorial(n-1) , n-1 );
	}
}

int factorial( int k )
{
	if (k == 1)
		return 1;
	else
		return k * factorial(k-1); 
}
