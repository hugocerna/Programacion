#include <stdio.h> 

#define PI 3.14


void main( void )
{
    float radio, diametro, perimetro, area;

	/* ingresando datos */
	printf("\n Ingrese el radio del circulo: ");
	scanf("%f", &radio);

	/* realizando las conversiones */
	diametro = 2*radio;
	perimetro = 2*PI*radio;
	area = PI*radio*radio;

	printf(" diametro = %f \n", diametro);
	printf(" perimetro = %f \n", perimetro);
	printf(" area = %f \n\n", area);
}
