#include<stdio.h>

float base(void); // Prototipo de la función base
int exponente(void); // Prototipo de la función exponente
float potencia(float b, int n); // Prototipo de la función potencia

int main()
	{
	float b; // VARIABLE GLOBAL
	int n; 
	b = base();	
	n = exponente();
	printf("%f elevado a la %d es igual a %f\n",b,n,potencia(b,n));	
	}

float base(void) // cabecera de la definición base
	{
	int ok = 0; 
	float b; // variable donde almacenar\'e lo que voy a retornar
	do
	{
		printf("Ingrese la base (n\'umero positivo): "); 
		scanf("%f",&b);
		if ( b > 0 ) ok = 1; // en caso que b sea positivo asignamos ok = 1 para salir del bucle
		else printf("Valor de entrada incorrecto!\n"); // ok sigue valiendo 0
	}
	while (ok == 0);
	return b;
	}

int exponente(void) // cabecera de la definición de la funci\'on exponente
	{
	int n; // variable donde almacenar\'e lo que voy a retornar
	printf("Ingrese el exponente (n\'umero entero): "); 
	scanf("%d",&n);
	return n;
	}
	
float potencia(float b, int n) // cabecera de la definición de la función potencia
	{
	float retorno = 1;
	if ( n > 0 )
		retorno = b*potencia(b,n-1);
	if ( n < 0 )
		retorno = potencia(b,n+1)/b;
	return retorno;
	}
