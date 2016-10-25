#include <stdio.h>

/* Declarando e inicializando una variable entera */
int joaquin = 5;
/* Declarando un puntero a entero */
int * johel;
/* Declarando un puntero a puntero a entero */
int ** rodrigo;

void main ()
{
	johel = &joaquin;
    	rodrigo = &johel;    
	
	/* Accesando a var directamente e indirectamente */
	printf("\n Acceso directo: joaquin = %d", joaquin);
	printf("\n Acceso indirecto por johel: joaquin = %d", *johel);	
	printf("\n Acceso indirecto desde rodrigo: joaquin = %d\n\n", **rodrigo);
	
	printf(" &joaquin = %p\n", &joaquin);
	printf(" johel = %p\n\n", johel);
	
	printf(" &johel = %p\n", &johel);
	printf(" rodrigo = %p\n\n", rodrigo);
		
}
