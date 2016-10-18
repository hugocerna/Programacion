#include <stdio.h>

#include <stdlib.h>  /* necesario para poder llamar a las funciones
						malloc y free */ 

int i, * puntero; // puntero es un puntero a entero

void * asigcont ( unsigned long lon, unsigned short tipo ); 
 
void main ()
{
	puntero = asigcont ( 5, sizeof(int) );
	printf("\n Empleando cont_alloc\n");
	for ( i = 0 ; i < 5 ; i++ )
		printf(" %d\n", *(puntero + i) );
	free(puntero); // liberando espacio reservado por calloc
	
	puntero = calloc ( 5, sizeof(int) );
	printf("\n Empleando calloc\n");
	for ( i = 0 ; i < 5 ; i++ )
		printf(" %d\n", *(puntero + i) );
	free(puntero); // liberando espacio reservado por calloc
}

void * asigcont ( unsigned long lon, unsigned short tipo )
{
	void * ptr;
	i = lon*tipo;
	ptr = malloc (i);
	if (ptr != NULL) 
	{
		unsigned char * p = ptr;
		while (i)
		{
			i -= 1;
			*p++ = (unsigned char) 0;
			// *p = (unsigned char) 0;
			// p += 1; 
		}
	}
	return ptr;
}
