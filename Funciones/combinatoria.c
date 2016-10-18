#include<stdio.h>

int universo(void); // Prototipo de la función universo
int muestra(int n); // Prototipo de la función muestra
int combinatoria(int n, int k); // Prototipo de la función combinatoria

int main()
	{
	int n,k; // VARIABLES GLOBALES
	n = universo();	
	k = muestra(n);
	printf("El n\'umero de combinaciones de %d elemento(s) de %d elemento(s) dado(s) es %d\n",k,n,combinatoria(n,k));	
	}

int universo(void) // cabecera de la definición universo
	{
	int ok = 0; 
	int n; // variable donde almacenar\'e lo que voy a retornar
	do
	{
		printf("Ingrese un entero positivo: "); 
		scanf("%d",&n);
		if ( n > 0 ) ok = 1; // en caso que n sea positivo asignamos ok = 1 para salir del bucle
		else printf("Valor de entrada incorrecto!\n"); // ok sigue valiendo 0
	}
	while (ok == 0);
	return n;
	}

int muestra(int n) // cabecera de la definición de la funci\'on muestra
	{
	int ok = 0; 
	int k; // variable donde almacenar\'e lo que voy a retornar
	do
	{
		printf("Ingrese un entero positivo menor o igual a %d: ",n); 
		scanf("%d",&k);
		if ( (0 < k) && (k <= n) ) ok = 1; // en caso que k sea positivo y menor o igual a n asignamos ok = 1 para salir del bucle
		else printf("Valor de entrada incorrecto!\n"); // ok sigue valiendo 0
	}
	while (ok == 0);
	return k;
	}
		
int combinatoria(int n, int k) // cabecera de la definición de la función combinatoria
	{
	if (k == 1)	
		return n;
	else
		if (n == k)
			return 1;
		else
			return combinatoria(n-1,k-1) + combinatoria(n-1,k);
	}
