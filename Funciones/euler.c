#include<stdio.h>
const float pi = 3.14159;

void suma(float epsilon); // Prototipo de la función primo
float entrada(void); // Prototipo de la función entrada

void main()
{
	float epsilon;
	epsilon = entrada();
	suma(epsilon);
}

float entrada(void) // cabecera de la definición de la función entrada
{
	int ok = 0; 
	float epsilon; // variable donde almacenar\'e lo que voy a retornar
	do
	{
		printf("Ingrese el margen de error (n\'umero positivo): "); 
		scanf("%f",&epsilon);
		if (epsilon > 0) ok = 1; // en caso que epsilon sea mayor que cero, asignamos ok = 1 para salir del bucle
		else printf("Valor de entrada incorrecto!\n"); // ok sigue valiendo 0
	}
	while (ok == 0);
	return epsilon;	
}
	
void suma(float epsilon)
	{
	float s = 0; // en la variable 's' almacenaremos las sumas parciales 
	float k = 0; // inicializamos con k = 0 convenientemente 
	float euler = (pi*pi)/6; // asignamos a la variable euler el valor exacto a la cual la serie converge
	float cota = euler - epsilon; // asignamos a la variable cota el n\'umero que espera superar nuestra suma 's'
	do
	{
		k=k+1;
		s = s + 1/(k*k);
		printf("s(%f) = %f\n",k,s);
	}
	while(s <= cota); //cuando nuestra suma 's' supere cota, se sale del bucle 
	printf("A partir de n=%f s(n) se aproxima a s=%f con un margen de error de %f.\n",k,euler,epsilon);
	}
