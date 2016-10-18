//********************* M\'etodo de D'Hondt **************************** 

#include <stdio.h>
#include <stdlib.h> // necesario para evocar las funciones malloc y free

int cont; // variable contadora
float aux; // variable auxiliar
int i_max;

// Prototipo de funciones
void ingrear_votos(long *ptr, int P);
void DHondt(long *ptr, short *p, int P, int K);
	void posicion_max(long *ptr, short *p, int P);
void mostrar(short *p, int P);

void main(void) 
{
	int P; // en N almacenar\'e la cantidad de partido pol\'iticos
	int K; // en K almacenar\'e la cantidad de curules
	
	//********************** Ingreso de datos **************************
	//
	printf("\n============================ Ingreso de Datos ");
	printf("=============================\n");
	//
	// Asignando memoria din\'amica 
	int OK = 0; // declarando e inicializando variable validadora
	long *partidos; // declarando un puntero a long 
	short *curules; // declarando un puntero a short	
	do
	{
		printf("\n Ingrese la cantidad de partidos politicos: "); 
		scanf("%d%*c",&P);
		partidos = (long*)malloc( P*sizeof(long) );
		curules = (short*)calloc(P, sizeof(short) ); 
		if ((partidos != NULL) && (curules != NULL)) 
			// en caso en que el compilador ha separado la
			// memoria exitosamente, asignamos OK=1 para salir del bucle 
			OK = 1;
		else printf("\n Mensaje: No hay suficiente memoria.\n");
	}
	while (OK == 0);
	printf("\n Ingrese la cantidad de curules: "); 
	scanf("%d%*c",&K);
	ingrear_votos(partidos, P); // ingresando la cantidad de votos  
	printf("=============================================");
	printf("==============================\n\n");
	//	
	//******************************************************************

	DHondt(partidos, curules, P, K);
	mostrar(curules, P);
	free(partidos); // liberando memoria reservada por malloc
	free(curules); // liberando memoria reservada por malloc	
}

void ingrear_votos(long *ptr, int P)
{
	printf("\n Ingrese la cantidad de votos que obtuvo cada partido:\n\n");
	for(cont = 0; cont < P; cont++) 
	{ 
		printf(" partido[%d] : ",cont);
		scanf("%ld", (ptr + cont));
	}
}

void DHondt(long *ptr, short *p, int P, int K)
{
	for(cont = 0; cont < K; cont++) 
	{ 
		posicion_max(ptr, p, P);
		*(p + i_max) = *(p + i_max) + 1;
	}
}

void posicion_max(long *ptr, short *p, int P) 
{
	int k; // declarando variable contadora local
	long maximo = 0;
	for(k = 0; k < P; k++)
	{ 
		aux = *(ptr + k) / (*(p + k) + 1);	
		if( maximo < aux ) 
		{
			maximo = aux;
			i_max = k;
		}
	}
}

void mostrar(short *p, int P)
{
	printf("=============== Cantidad de curules que gana cada ");
	printf("partido =================\n\n");
	for(cont = 0; cont < P; cont++) 
		printf(" partido[%d] : %hd\n", cont, *(p + cont));
	printf("=============================================");
	printf("==============================\n\n");	
}
