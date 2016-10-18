#include<stdio.h>

int primo(int n); // Prototipo de la función primo
int golbach(int n); // Prototipo de la función golbach

void main()
	{
	int n = 4;
	for ( ; n <= 100 ; n = n + 2 )
		golbach(n);
	}
	
int primo(int n) // cabecera de la definición de la función primo
	{
	int d=2; // la variable 'd' es una VARIABLE LOCAL 
	for ( ; d < n ; d++)
		if (n%d == 0) return 0; // esto ocurre cuando hay un divisor propio de n
	return 1; // retorna 1 cuando n es primo y 0 caso contrario
	}

int golbach(int n) // cabecera de la definición de la función golbach
	{
	int a,b; // a estas variables las iremos asignando todas las posibles a,b cuya suma sea n
	int pri;
	int ok = 0; 
	for( a = 2 ; a < n ; a++ )
		{
		for( b = a ; b < n ; b++ )
			{
			pri = primo(a)*primo(b); // pri = 1 si y solo si a y b son primos 
			if ( (pri == 1) && (n == a + b) ) // esto es verdad si y solo si n es semiprimo
				{
				printf("%d = %d + %d.\n",n,a,b);
				return 0;
				}
			}
		}
	}
