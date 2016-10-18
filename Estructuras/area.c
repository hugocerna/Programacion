/* Demonstrando estructuras que contienen otras estructuras. */

#include <stdio.h>

int delta1, delta2;
long area;
struct coordenada
{
	int x;
	int y;
};

struct rectangulo
{
	struct coordenada esquina1;
	struct coordenada esquina2;
} rectangulo1;

void main( void )
{
	/* Ingresando las coordenadas de esquina1 */
	printf("\nIngrese la abcisa de esquina1: ");
	scanf("%d", &rectangulo1.esquina1.x);
	printf("Ingrese la ordenada de esquina1: ");
	scanf("%d", &rectangulo1.esquina1.y);

	/* Ingresando las coordenadas de esquina2 */
	printf("\nIngrese la abcisa de esquina2: ");
	scanf("%d", &rectangulo1.esquina2.x);
	printf("Ingrese la ordenada de esquina2: ");
	scanf("%d", &rectangulo1.esquina2.y);
	
	/* Calculando y mostrando el \'area */
	delta1 = abs(rectangulo1.esquina1.x - rectangulo1.esquina2.x);
	delta2 = abs(rectangulo1.esquina1.y - rectangulo1.esquina2.y);
	area = delta1*delta2;
	printf("\nEl area es de %ld unidades.\n\n", area);

 	/* mostrando direcciones de memoria */
	printf("======== Imprimiendo las direcciones");
	printf(" de memoria ========\n\n");	
	printf("\n================================");
	printf("========================");
	printf("\n\trectangulo1\t\t\t%p", &rectangulo1);
	printf("\n\trectangulo1.esquina1\t\t%p", &rectangulo1.esquina1);
	printf("\n\trectangulo1.esquina1.x\t\t%p", &rectangulo1.esquina1.x);
	printf("\n\trectangulo1.esquina1.y\t\t%p", &rectangulo1.esquina1.y);
	printf("\n\trectangulo1.esquina2\t\t%p", &rectangulo1.esquina2);
	printf("\n\trectangulo1.esquina2.x\t\t%p", &rectangulo1.esquina2.x);
	printf("\n\trectangulo1.esquina2.y\t\t%p", &rectangulo1.esquina2.y);
	printf("\n================================");
	printf("========================\n\n");  	
}
