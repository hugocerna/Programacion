#include<stdio.h>

int primo(int n); // Prototipo de la función primo
int gemelo(int n); // Prototipo de la función gemelo

void main()
	{
	float B = 0; // en B almacenaremos las sumas parciales 
	float k = 2; // inicializamos con k = 2 porque es el primo m\'as peque\~no 
	int cont = 0; // cont ser\'a nuestra variable que ir\'a contando las duplas de primos gemelos
	do
	{
		if (gemelo(k) == 1) // en caso (k,k+2) sea una dupla de primos gemelos
		{
			//puts("presione");getchar();
			B = B + (1/k) + (1/(k+2));
			cont++;
			printf("S(%d) = %f\n",cont,B);
		}
		k++; 	
	}
	while(cont < 2014); //cuando haya contado 20 duplas sale del bucle 
	printf("Valor aproximado de B = %f\n",B);
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
