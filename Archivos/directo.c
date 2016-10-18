/* Mosttrando el uso de fwrite() y fread(). */
#include <stdio.h>

#define LON 20

int main ()
{
	int i, arreglo1[LON], arreglo2[LON];
	
	FILE * p_archivo;
	
	// Inicializando arreglo1. 
	for (i = 0; i < LON; i++)
		arreglo1[i] = 2*i;
	
	// Abriendo un archivo en modo binario
	if ( (p_archivo = fopen("directo.bin", "wb")) == NULL)
	{
		fprintf (stderr, "\n Error al abrir el archivo.\n");
		return -1;
	}
	
	// Escribiendo arreglo1 en el archivo abierto
	if (fwrite(arreglo1, sizeof(int), LON, p_archivo) != LON)
	{
		fprintf (stderr, "\n Error al escribir en el archivo.\n");
		return -1;
	}
	fclose(p_archivo);
	
	// Ahora, abrimos el mismo archivo para leerlo en modo binario
	if ( (p_archivo = fopen("directo.bin", "rb")) == NULL)
	{
		fprintf (stderr, "\n Error al abrir el archivo.\n");
		return -1;
	}

	// Leyendo la información del archivo en el arreglo2
	if ( fread (arreglo2, sizeof(int), LON, p_archivo) != LON )
	{
		fprintf(stderr, "\n Error al leer el archivo.\n");
		return -1;
	}
	fclose(p_archivo);
	
	// Ahora, mostramos ambos arreglos para mostrar que ellos son iguales
	for (i = 0; i < LON; i++)
		printf(" %d\t%d\n", arreglo1[i], arreglo2[i]);
	printf("\n");
	return 0;
}
