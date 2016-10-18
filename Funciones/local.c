/* Ilustrando el alcance de una variable global. */

#include <stdio.h>

void imprimir_valor(void);

int main( void )
{
	int x = 999; // variable local
	printf(" %d\n", x);
	imprimir_valor();
	return 0;
}

void imprimir_valor(void)
{
	printf(" %d\n”", x);
}
