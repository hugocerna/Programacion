#include <stdio.h>

int x = 2, y = 5;

void intercambio (int * ptr1, int * ptr2);

void main ()
{
	printf("\n x = %d, y = %d\n", x, y);
	intercambio (&x, &y);
	printf(" x = %d, y = %d\n\n", x, y);
}

void intercambio (int * ptr1, int * ptr2)
{
	int aux = *ptr1;
	*ptr1 = *ptr2; // x = 5
	*ptr2 = aux; // y = 2
}
