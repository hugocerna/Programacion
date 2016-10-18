/* Mostrando el uso de fprintf(). */
#include <stdio.h>

#define LON_nombre 40

// prototipos de funciones
void ingresar_nombre (char * p_car);
void limpiar_stdin ();

int main()
{
	FILE * p_archivo;
	float arreglo[5];
	int i;
	char nombre_archivo[LON_nombre];

	fprintf(stdout,"\n Ingrese los elementos del arreglo:\n");
	for (i = 0; i < 5; i++)
	{
		fprintf (stdout," arreglo[%d] = ", i);	
		scanf ("%f", &arreglo[i]);
	}
	
	limpiar_stdin (); // limpiando el buffer 
	
	ingresar_nombre (nombre_archivo);
	if ( (p_archivo = fopen(nombre_archivo, "w")) == NULL)
	{
		fprintf (stderr, "\n Error al abrir el archivo %s en el modo escritura.\n", nombre_archivo);
		return -1;
	}
	
	// Ahora, escribimos los elementos del arreglo al archivo y al stdout. 
	for (i = 0; i < 5; i++)
	{
		fprintf ( p_archivo, "\n arreglo[%d] = %f", i, arreglo[i] );
		fprintf ( stdout, "\n arreglo[%d] = %f", i, arreglo[i] );
	}
	
	fclose(p_archivo); // cerrando el archivo abierto
	printf("\n");
	return 0;
}

void limpiar_stdin ()
{ // limpia todos los caracteres que permanecen en el buffer.
	char ch = fgetc(stdin);
	while (ch != 10)
		ch = fgetc(stdin);
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
