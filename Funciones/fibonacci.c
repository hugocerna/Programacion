#include<stdio.h>

int fibo(int n); // Prototipo de la función fibo

void main()
{
	int n = 1; // n es una VARIABLE GLOBAL
	for ( ; n <= 25 ; n++ )
		printf("fibo(%d) = %d\n",n,fibo(n));
}
	
int fibo(int n) // cabecera de la definición de la función fibo
	{ 
	if ( n <= 2 ) 
		return 1; // fibo(1) = fibo (2) = 1
	else
		return fibo(n-1) + fibo(n-2); // fibo(n) = fibo(n-1) + fibo(n-2)
	}
