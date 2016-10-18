//***** C\'alculo de la cantidad de curules ganados por partidos *******

#include <stdio.h>
#include <stdlib.h> // necesario para usar malloc y free
#include <string.h>

// Declarando un prototipo de estructura 
struct partido
{
	char *nombre;
	long votos;
	short curules;
};

int cont; // variable contadora
float aux_Q; // variable auxiliar del cociente en el m\'etodo de D'Hondt
char buffer[45];
char *aux;	
long aux_V; // variable auxiliar de la cantidad de votos
short aux_K; // variable auxiliar de la cantidad de curules
int i_max; // posicion del m\'aximo cociente en el m\'etodo de D'Hondt
	
// Declarando prototipo de funciones
void ingresar_resultados(struct partido *ptr, int P);
void procesar_resultados(struct partido *ptr, int P, int K);
	void posicion_max(struct partido *ptr, int P); 
void ordenar_resultados_procesados(struct partido *ptr, int P);
	void intercambiar(struct partido *p1, struct partido *p2);
void imprimir_ranking(struct partido *ptr, int P);

void main( )
{
	//********************** Ingreso de datos **************************
	//
	printf("\n============================ Ingreso de Datos ");
	printf("=============================\n");
	//
	// Asignando memoria din\'amica 
	int ok = 0, P, K;
	struct partido *lista; // declarando un puntero a una estructura
	do
	{
		printf("\n Ingrese el numero de partidos de la contienda: "); 
		scanf("%d%*c",&P);
		lista = (struct partido *)malloc( P*sizeof(struct partido) );
		if (lista != NULL) 
			ok = 1; /* en caso en que el compilador ha separado la
			memoria exitosamente, asignamos ok=1 para salir del bucle */
		else printf("\n Mensaje: No hay suficiente memoria.\n");
	}
	while (ok == 0);
	printf("\n Ingrese la cantidad de curules: "); 
	scanf("%d%*c",&K);
	ingresar_resultados(lista, P);
	printf("=============================================");
	printf("==============================\n\n");	
	//	
	//******************************************************************
	
	procesar_resultados(lista, P, K);
	ordenar_resultados_procesados(lista, P);
	imprimir_ranking(lista, P);
	free(lista); // Liberando espacio reservado por malloc
}

void ingresar_resultados(struct partido *ptr, int P)
{

	for (cont = 0; cont < P; cont++)
	{
		printf("\n Ingreso del registro partido[%d]", cont + 1);
		printf("\n Ingrese el nombre: ");
		scanf("%[^\n]%*c", buffer);
		ptr->nombre = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(ptr -> nombre, buffer);
		printf(" Ingrese la cantidad de votos ganados: ");
		scanf("%ld%*c", &(ptr -> votos));
		ptr -> curules = 0;
		ptr++;
	}
}

void posicion_max(struct partido *ptr, int P) 
{
	int k; // declarando variable contadora local
	float maximo = 0;
	for(k = 0; k < P; k++)
	{ 
		aux_Q = (ptr -> votos) / ((ptr -> curules) + 1);	
		if( maximo < aux_Q ) 
		{
			maximo = aux_Q;
			i_max = k;
		}
		ptr++;
	}
}

// Actualizando la cantidad de curules ganados mediante 
// el m\'etodo de D'Hondt
void procesar_resultados(struct partido *ptr, int P, int K)
{
	for(cont = 0; cont < K; cont++) 
	{
		posicion_max(ptr, P); // actualizando posici\'on del m\'aximo 
		((ptr + i_max) -> curules)++;
	}
}

void intercambiar(struct partido *p1, struct partido *p2)
{
	// intercambiando nombres
	aux = p1 -> nombre;
	p1 -> nombre = p2 -> nombre;
	p2 -> nombre = aux;
	
	// intercambiando cantidad de votos
	aux_V = p1 -> votos;
	p1 -> votos = p2 -> votos;
	p2 -> votos = aux_V;
	
	// intercambiando cantidad de curules
	aux_K = p1 -> curules;
	p1 -> curules = p2 -> curules;
	p2 -> curules = aux_K;
}

// Odenando la lista de partidos por cantidad de curules ganados
// a trav\'ez del m\'etodo de ordemnamiento de burbuja de manera
// invertida
void ordenar_resultados_procesados(struct partido *ptr, int P)
{
	if(P >= 2)
	{
		for(cont = 0; cont < P - 1; cont++)
			if ((ptr + cont)->curules < (ptr + cont + 1)->curules)
				intercambiar(ptr + cont, ptr + cont + 1);
		ordenar_resultados_procesados(ptr, P - 1);
	}
}

void imprimir_ranking(struct partido *ptr, int P)
{
	int k; // variable contadora local
	printf("====================== Imprimiendo ranking electoral ");
	printf("======================\n\n");	
	printf("     Partido\t\t\t\t\t\tVotos\tCurules\n");
	printf("---------------------------------------------");
	printf("------------------------------\n");			
	for (cont = 0; cont < P; cont++)
	{
		printf(" %2d. %s", cont + 1, ptr -> nombre);
		for(k = strlen(ptr -> nombre); k < 44; k++)
			printf(" ");
		printf("%12ld", ptr -> votos);	
		printf("\t%7hd\n", ptr -> curules);
		ptr++;
	}
	printf("=============================================");
	printf("==============================\n\n");
}
