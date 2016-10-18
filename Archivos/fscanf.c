/* Leyendo "datos con formato" usando fscanf(). */
#include <stdio.h>

#define LON_nombre 40

void ingresar_nombre (char * p_car);

int main()
{
	float f1, f2, f3, f4, f5;
	FILE * p_archivo;
	char nombre_archivo[LON_nombre];
	
	ingresar_nombre(nombre_archivo);
	
	if ( (p_archivo = fopen (nombre_archivo, "r")) == NULL )
	{
		fprintf (stderr, "\n Error al abrir el archivo.\n");
		return -1;
	}
	
	fscanf (p_archivo, "%f %f %f %f %f", &f1, &f2, &f3, &f4, &f5);
	printf ("\n Los valores leidos son %f, %f, %f, %f y %f.\n\n", f1, f2, f3, f4, f5);
	fclose (p_archivo);
	return 0;
}

void ingresar_nombre (char * p_car)
{
	char car;
	int i = 0;
	printf("\n Ingrese el nombre del archivo: ");
	car = fgetc(stdin); // stdin: STanDar INput
	while ( (car != '\n') && (i < LON_nombre-1) )
	{
		*(p_car + i) = car;
		car = fgetc(stdin);
		i += 1;
	}
	*(p_car + i) = '\0';
}
