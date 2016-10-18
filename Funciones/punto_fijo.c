#include<stdio.h>

void banach(float x1); // Prototipo de la función primo
float entrada(void); // Prototipo de la función entrada

int main()
	{
	float x; // x es una VARIABLE GLOBAL
	x = entrada();	
	banach(x);
	}

float entrada(void) // cabecera de la definición de la función entrada
{
	int ok = 0; 
	float x1; // variable donde almacenar\'e lo que voy a retornar
	do
	{
		printf("Ingrese un numero entre 0 y 1: "); 
		scanf("%f",&x1);
		if ( (0 <= x1) && (x1 <= 1) ) ok = 1; // en caso que x1 viva en [0,1] asignamos ok = 1 para salir del bucle
		else printf("Valor de entrada incorrecto!\n"); // ok sigue valiendo 0
	}
	while (ok == 0);
	return x1;
	}
	
void banach(float x1) // cabecera de la definición de la función banach
	{
	int i = 2; // la variable 'i' es una VARIABLE LOCAL
	float x = x1;  
	printf("Primeros 40 t\'erminos de la secuencia:\n"); 
	printf("x(1) = %f\n",x);
	for ( ; i <= 40 ; i++)
	{
		x = 1/(1+x*x); // x_(i+1) = f(x_i)
		printf("x(%d) = %f\n",i,x);
	}
	printf("Valor aproximado de p = %f\n",x);	
	}
