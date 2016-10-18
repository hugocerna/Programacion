#include<stdio.h>

int suma(int n); // Prototipo de la función suma
int entrada(void); // Prototipo de la función entrada
int potencia(int n); // Prototipo de la función potencia

void main()
	{
	int n,i; // i y n son VARIABLES GLOBALES
	n = entrada();
	for ( i = 1 ; i <= n ; i++ )
		printf("S(%d) = %d\n",i,suma(i));
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

int potencia(int n) // cabecera de la definición de la función primo
	{
	int i = 1; // la variable 'i' es una VARIABLE LOCAL
	int p = 1; // variable donde almacenaremos n*n*...*n (n veces) 
	for ( ; i <= n ; i++)
		p = p*n;
	return p; // retorna p = n*n*...*n (n veces)
	}	
	
int suma(int n) // cabecera de la definición de la función primo
	{
	if (n%2 == 1) // en caso n sea impar
	{
		if (n == 1) 
			return 1; // retornamos S = 1 y la funci\'on suma acaba
		else
			return suma(n-1) + potencia(n);
	}
	else // en caso n sea par
		return suma(n-1) - potencia(n); 
	}
