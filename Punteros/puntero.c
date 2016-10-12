/* Introduccion a los punteros
 * 
 *Un puntero es UNA VARIABLE QUE ALMACENA DIRECCIONES DE MEMORIA
 */ 

/*operadores básicos:

 * : indireccion (solo a punteros)
 & : direccion (cualquiera)       */

/* Demonstración básica del uso de punteros. */
#include <stdio.h>

/* Declarando e inicializando una variable entera */
int var = 1;
/* Declarando un puntero a entero */
int * ptr;

void main ()
{
	/* Inicializando puntero ptr haciéndolo apuntar a var */
	ptr = &var;
	
	/* Accesando a var directamente e indirectamente */
	printf("\n Acceso directo: var = %d", var);
	printf("\n Acceso indirecto: var = %d", *ptr);

	/* Mostrando la dirección de var de dos formas */
	printf("\n\n Dirección de var = %p", &var);
	printf("\n Dirección de var = %p\n\n", ptr);
}
