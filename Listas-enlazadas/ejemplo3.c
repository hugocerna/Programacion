// Programa que simula el llenado de una guía telefónica en orden alfabético a los nombres ingresados. 

#include <stdio.h>
#include <stdlib.h> 

// Definiendo constantes
#define LONGITUD_NOM 50
#define LONGITUD_TEL 12
#define DEMORA 400000000

// Definiendo la estructura para la lista enlazada y un puntero a esta
typedef struct plantilla_contacto
{
	char nom[LONGITUD_NOM]; // nombre del contacto 
	char tel[LONGITUD_TEL]; // número de celular del contacto (944-020-090)
	struct plantilla_contacto * sgte; // puntero al siguiente contacto 
} contacto ;
typedef contacto * enlace;
//typedef int * p_int;
      
// Prototipo de funciones 
enlace adicionar_a_guia (enlace cab);
enlace liberar_memoria (enlace cab);
void mostrar_guia (enlace cab);
void ingresar_nombre (char * p_ch);
void ingresar_telefono (char * p_ch);
int loncad (char * cad);
int comcad (char * A, char * B); // cadcmp ()
int menu (void);
void demorar (void);

void main()
{
  	enlace cabeza = NULL; // Creando LES para nuestra guía 
	int opcion;	
	do
	{
		opcion = menu();
		switch(opcion)
		{
			case 1:
			{
				system("clear");
				cabeza = adicionar_a_guia (cabeza);
				printf("\n Mensaje: presione enter para continuar...");
				getchar();
				break;
			}
			case 2:
			{
				system("clear");
				mostrar_guia (cabeza);
				printf("\n Mensaje: presione enter para continuar...");
				getchar();
				break;
			}
			case 3: 
			{
				system("clear");
				cabeza = liberar_memoria (cabeza);
				printf("\n Mensaje: memoria asignada liberada;");
				printf(" presione enter para continuar...");
				getchar();
				break;	
			}
			default: 
			{
				system("clear");
				printf("\n Mensaje: saliendo del programa...\n");
				demorar();
				system("clear");
			}
		} 
	}
	while(opcion != 0);
}

int menu(void)
{
	int i;
	system("clear");
	printf("\n=============================== Guia telefonica ");
	printf("==============================\n\n");
	printf(" 1. Adicionar un contacto a la guia.\n");
	printf(" 2. Mostrar guia.\n");
	printf(" 3. Liberar memoria asignada.\n");
	printf(" 0. Salir del programa.\n");
	printf("================================================");
	printf("==============================\n");
	printf("\n Seleccione una de las opciones: ");	
	scanf("%d", &i);
	fgetc(stdin); // getchar(); para limpiar el buffer
	return i;	
}

// Insertando un nuevo contacto a la lista
enlace adicionar_a_guia (enlace cab)
{
	enlace nuevo;
	enlace actual; 
	enlace previo; 

	// asignando memoria 
	nuevo = malloc( sizeof(contacto) );
	if (nuevo == NULL)
	{
		printf("\n Mensaje: no se pudo asignar memoria.\n");
		return cab;
	}	
	
	// ingresando nombre y teléfono al nuevo contacto
	ingresar_nombre (nuevo->nom);
	ingresar_telefono (nuevo->tel);
	
	if (cab == NULL)
	{	// adicionando el primer contacto a la lista
		nuevo->sgte = NULL;
		return nuevo;
	}
		
	if ( comcad(cab->nom, nuevo->nom) > 0 )
	{	// adicionando el nuevo contacto antes del primer contacto
		nuevo->sgte = cab;
		return nuevo;
	}
					
	if ( cab->sgte == NULL )
	{	// adicionando el nuevo conctacto como segundo contacto
		cab->sgte = nuevo; 
		nuevo->sgte = NULL;
		return cab;
	}
	
	actual = cab->sgte;
	previo = cab;

	while (actual->sgte != NULL)
	{
		if ( comcad(actual->nom, nuevo->nom) > 0 )
		{// adicionando antes del contacto actual
			nuevo->sgte = actual;
			previo->sgte = nuevo;
			return cab; 
		}
		else
		{// pasando a revisar el siguiente contacto 
			actual = actual->sgte;
			previo = previo->sgte;
		}
	}
	
	if ( comcad(actual->nom, nuevo->nom) > 0 )
	{ 	// adicionando antes del último contacto
		nuevo->sgte = actual;
		previo->sgte = nuevo;
	}
	else 
	{ 	// adicionando al final
		actual->sgte = nuevo;
		nuevo->sgte = NULL;
	}
	return cab;	
}

// Mostrando toda la información contenida en la lista
void mostrar_guia (enlace cab)
{
	enlace actual = cab;
	int k, cont = 1; 
	printf("======================== Mostrando guia telefonica ");
	printf("========================\n\n");	
	printf("     Nombre\t\t\t\t\t\tTelefono\n");
	printf("---------------------------------------------");
	printf("------------------------------\n");
	while (actual != NULL )
	{
		printf(" %2d. %s", cont, actual->nom);
		for(k = loncad(actual->nom); k < LONGITUD_NOM - 1; k++)
			printf(" ");
		printf("\t%s\n", actual->tel);
		actual = actual->sgte;
		cont++;
	}
	printf("=============================================");
	printf("==============================\n");	
}

void ingresar_nombre (char * p_ch)
{
	char ch;
	int i = 0;
	printf(" Ingrese el nombre: ");
	ch = fgetc(stdin);
	while ( (ch != '\n') && (i < LONGITUD_NOM - 1) )
	{
		*(p_ch + i) = ch;
		ch = fgetc(stdin);
		i += 1;
	}
	*(p_ch + i) = '\0';
}

void ingresar_telefono (char * p_ch)
{
	char ch;
	int i = 0;
	printf(" Ingrese el número de celular: ");
	ch = fgetc(stdin);
	while ( (ch != '\n') && (i < LONGITUD_TEL - 1) )
	{
		*(p_ch + i) = ch;
		ch = fgetc(stdin);
		i += 1;
	}
	*(p_ch + i) = '\0';
}

int loncad (char * cad)
{
	int i = 0;
	while (*(cad + i) != '\0')
		i += 1;
	return i;
}

int comcad (char * A, char * B) // comparando cadenas
{
	int i = 0;
	while ( *(A + i) != '\0'  &&  *(A + i) == *(B + i) )
		i += 1;
	return *(A + i) - *(B + i);
}
/*
A ->   "Juan"
B ->   "Jub"
		*(A+i)  *(B+i)
i = 0	'J'		'J'
i = 1   'u'		'u'
i = 2   'a'		'b'
*/

// Borrando toda nuestra lista (y liberando memoria asignada a TODA ella)
enlace liberar_memoria (enlace cab)
{
	enlace actual, siguiente;
	actual = cab;
	while (actual != NULL)
	{
		siguiente = actual->sgte;
		free(actual);
		actual = siguiente;
	}	
	return NULL;
}

void demorar (void)
{
	int cont;
	for( cont = 0; cont < DEMORA; )
		cont++;
}
