#include<stdio.h>

int primo(int n); // Prototipo de la función primo
int gemelo(int n); // Prototipo de la función gemelo
int entrada(void); // Prototipo de la función entrada

void main()
	{
	int n;
	int k = 2; // inicializamos con k = 2 porque es el primo m\'as peque\~no 
	int cont = 0; // cont ser\'a nuestra variable que ir\'a contando las duplas de primos gemelos
	n = entrada();
	printf("Lista de las %d primeras duplas de primos gemelos: ",n);
	do
	{
		if (gemelo(k) == 1) // en caso (k,k+2) sea una dupla de primos gemelos
		{
			printf("(%d,%d) ",k,k+2);
			cont++; // cont = cont + 1
		}
		k++; // k = k + 1				
	}
	while(cont < n); //cuando haya contado n duplas sale del bucle 
	printf("\n");
	}

int entrada(void) // cabecera de la definición de la función entrada
	{
	int ok = 0, n;
	do
	{
		printf("Ingrese un numero entero mayor que uno: "); 
		scanf("%d",&n);
		if (n > 1) ok = 1; // como n es mayor que uno, hacemos ok = 1 para salir del bucle
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

int gemelo(int n) // cabecera de la definición de la función gemelo
	{
	if ( primo(n)*primo(n+2) == 1) // esto ocurre si y solo si (n,n+2) es una dupla de primos gemelos 
		return 1; // retorna 1 cuando (n,n+2) es una dupla de primos gemelos
	else
		return 0; // caso contrario, retorna 0	
	}
