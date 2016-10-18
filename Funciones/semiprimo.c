#include<stdio.h>

int primo(int n); // Prototipo de la función primo
void semiprimo(int n); // Prototipo de la función semiprimo
int entrada(void); // Prototipo de la función entrada

void main()
	{
	int n;
	n = entrada();
	semiprimo(n);
	}

int entrada(void) // cabecera de la definición de la función entrada
	{
	int ok = 0, n;
	do
	{
		printf("Ingrese un entero positivo: "); 
		scanf("%d",&n);
		if (n > 0) ok = 1; // como n es positivo, hacemos ok = 1 para salir del bucle
		else printf("Valor de entrada incorrecto!\n"); 
	}
	while (ok == 0);
	return n;
	}
	
int primo(int n) // cabecera de la definición de la función primo
	{
	int d=2; // la variable 'd' es una VARIABLE LOCAL 
	for ( ; d < n ; d++)
		if (n%d == 0) return 0; // esto ocurre cuando hay un divisor propio de n
	return 1; // retorna 1 cuando n es primo y 0 caso contrario
	}

void semiprimo(int n) // cabecera de la definición de la función gemelo
	{
	int a,b; // a estas variables las iremos asignando todos los posibles divisores de n
	int pri;
	int ok = 0; 
	for( a = 2 ; a < n ; a++ )
		{
		for( b = a ; b < n ; b++ )
			{
			pri = primo(a)*primo(b); // pri = 1 si y solo si a y b son primos 
			if ( (pri == 1) && (n == a*b) ) // esto es verdad si y solo si n es semiprimo
				{
				ok = 1;
				printf("Es semiprimo: %d = %d*%d.\n",n,a,b);
				}
			}
		}
	if(ok == 0) // si ok permanece igual a cero, entonces es porque NO ha encontrado dos primos a y b cuyo producto sea n 
		printf("No es semiprimo.\n");
	}
