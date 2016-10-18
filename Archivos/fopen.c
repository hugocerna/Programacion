/* Mostrando el uso de fopen() y fclose(). */
#include <stdio.h>

#define LON_nombre 40
#define LON_modo 4

// prototipos de funciones
void ingresar_nombre (char * p_car);
void ingresar_modo (char * p_car);

int main()
{
	FILE * p_archivo;
	char nombre_archivo[LON_nombre], modo[LON_modo];
	
	// ingresamos el nombre del archivo y el modo en que será abierto
	ingresar_nombre(nombre_archivo);
	ingresar_modo(modo);
		
	// Ahora, intentamos abrir el archivo
	p_archivo = fopen (nombre_archivo, modo);
	if (p_archivo == NULL)
	{
		fprintf (stdout,"\n Error al abrir el archivo %s en modo %s.\n", nombre_archivo, modo);
		return -1;
	}	
	fprintf (stdout,"\n Se abrió con éxito el archivo %s en modo %s.\n", nombre_archivo, modo);
	fprintf (stdout," Cerrando el archivo que se abrió.\n\n");
	fclose (p_archivo);
	return 0;
}

void ingresar_nombre (char * p_car)
{
	char car;
	int i = 0;
	printf(" Ingrese el nombre del archivo: ");
	car = fgetc(stdin); // stdin: STanDar INput
	while ( (car != '\n') && (i < LON_nombre-1) )
	{
		*(p_car + i) = car;
		car = fgetc(stdin);
		i += 1;
	}
	*(p_car + i) = '\0';
}

void ingresar_modo (char * p_car)
{
	char car;
	int i = 0;
	printf(" Ingrese el modo en que será abierto el archivo: ");
	car = fgetc(stdin); // stdin: STanDar INput
	while ( (car != '\n') && (i < LON_modo-1) )
	{
		*(p_car + i) = car;
		car = fgetc(stdin);
		i += 1;
	}
	*(p_car + i) = '\0';
}
