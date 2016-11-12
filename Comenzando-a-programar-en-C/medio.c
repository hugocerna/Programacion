#include <stdio.h>

int main ()
{
	float A1, A2, B1, B2, M1, M2;

	printf ("\n Ingrese las coordenadas A: ");
	scanf ("%f %f", &A1,&A2);
	printf (" Ingrese las coordenadas A: ");
	scanf ("%f %f", &B1,&B2);

	M1 = (A1+B1)/2;
	M2 = (A2+B2)/2;
	
	printf ("\n El punto medio es (%f,%f)\n",M1,M2);
}
