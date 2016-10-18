#include<stdio.h>

// Prototipo de la funciones
int ingresar( void ); 
void pascal( int n ); 
int combinatorio( int n, int k ); 
int condicion( int N, int x, int y ); 

int main()
{
	int n; 
	n = ingresar();	 // por ejemplo n = 5
	pascal(n);
}

int ingresar( void ) 
{
	int p; // variable donde almacenaré lo que voy a retornar
	printf("Ingrese un entero no negativo: "); 
	scanf("%d",&p);
	return p;
}

void pascal(int N)
{
	int x, y; // para almacenar las coordenadas actuales
	int n, k; // para almacenar los valores a tomar el combinatorio
	for ( y = N ; y >= 0 ; y-- )
	{
		n = N - y; // actualizando el valor de n
		k = 0;   // actualizando el valor de k
		printf("\t");
		for ( x = -N ; x <= N ; x++ )
		{
			if (condicion (N,x,y) == 1)
				printf("%d\t", combinatorio (n,k++));
			else
				printf("\t");
		}
		printf("\n\n");
	}
}	
	
int combinatorio(int n, int k) 
{
	if (k == 0)	
		return 1;
	else
		if (n == k)
			return 1;
		else
			return combinatorio(n-1,k-1) + combinatorio(n-1,k);
}

int condicion( int N , int x , int y)
{
	int i = N;
	while ( i >= 0 )
	{
		if ( i == abs(x) + abs(y) )
			return 1;
		i = i - 2;
	}
	return 0;
}
