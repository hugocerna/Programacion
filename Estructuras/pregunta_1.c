#include <stdio.h>
#include <stdlib.h> // para poder emplear rand()

void ingresar_datos ();
void generar_ventas ();
void mostrar ();

typedef struct plantilla_vendedor
{
	char nombre[10];
	char apellido[10];
	float base; // el sueldo base
	float comi; // % de comision
} vendedor;

vendedor vendedores[4];	
float ventas1[4];
float ventas2[4];
	
void main ()
{
	ingresar_datos ();
	generar_ventas ();
	mostrar ();
}

void ingresar_datos ()
{
	int i = 0;
	for ( ; i < 4 ; i += 1)
	{
		printf("\n\n");
		printf(" Datos de vendedores[%d]:\n",i);
		printf(" Nombre: ");
		scanf("%s", vendedores[i].nombre);
		printf(" Apellido: ");
		scanf("%s", vendedores[i].apellido);
		printf(" Sueldo base: ");
		scanf("%f", &vendedores[i].base);
		printf(" Porcentaje de comisión: ");
		scanf("%f", &vendedores[i].comi); // 20% --> 0.2
	}
}

void generar_ventas ()
{
	int i = 0; // ventas en miles de soles
	for ( ; i < 4 ; i += 1)
	{
		ventas1[i] = rand()%10 + 0.1*( rand()%10 );
		ventas2[i] = rand()%10 + 0.1*( rand()%10 );		
	}	
}

void mostrar ()
{
	int i = 0;
	float base, comi1, comi2, promedio;
	for ( ; i < 4 ; i += 1)
	{
		base = vendedores[i].base, 
		comi1 = vendedores[i].comi * ventas1[i],
		comi2 = vendedores[i].comi * ventas2[i],
		promedio = ( ventas1[i] + ventas2[i] ) / 2; 

		printf("\n\n");
		printf(" Record de %s %s:\n", vendedores[i].nombre, vendedores[i].apellido);
		printf(" Sueldo base: %f\n", base);		
		printf(" Mes 1:\n");
		printf(" Comisión: %f\n", comi1);
		printf(" Sueldo total: %f\n", base + comi1);
		printf(" Mes 2:\n");
		printf(" Comisión: %f\n", comi2);
		printf(" Sueldo total: %f\n", base + comi2);
		printf(" Promedio de ventas: %f\n", promedio);
	}
	printf("\n\n");
}

