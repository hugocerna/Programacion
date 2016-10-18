//********* Ingresando y ordenando una gu\'ia telef\'onica ************

#include <stdio.h>
#include <stdlib.h> // necesario para usar malloc y free
#include <string.h>

// Declarando un prototipo de estructura 
struct entrada {
	char *nombre;
	char *telefono;
};
int cont; // variable contadora
char buffer1[50];
char buffer2[12];
char *aux;	
	
// Declarando prototipo de funciones
void ingresar_guia(struct entrada *ptr, int N);
void ordenar_guia(struct entrada *ptr, int N);
	void intercambiar_entradas(struct entrada *p1, struct entrada *p2);
void imprimir_guia(struct entrada *ptr, int N);

void main( )
{
	//********************** Ingreso de datos **************************
	//
	printf("\n============================ Ingreso de Datos ");
	printf("=============================\n");
	//
	// Asignando memoria din\'amica 
	int ok = 0, N;
	struct entrada *guia; // declarando un puntero a una estructura
	do
	{
		printf("\n Ingrese el numero de registros de la guia: "); 
		scanf("%d%*c",&N);
		guia = (struct entrada *)malloc( N*sizeof(struct entrada) );
		if (guia != NULL) 
			ok = 1; /* en caso en que el compilador ha separado la
			memoria exitosamente, asignamos ok=1 para salir del bucle */
		else printf("\n Mensaje: No hay suficiente memoria.\n");
	}
	while (ok == 0);
	ingresar_guia(guia, N);
	printf("=============================================");
	printf("==============================\n\n");	
	//	
	//******************************************************************

	ordenar_guia(guia, N);
	imprimir_guia(guia, N);
	free(guia); // Liberando espacio reservado por malloc
}

void ingresar_guia(struct entrada *ptr, int N)
{

	for (cont = 0; cont < N; cont++)
	{
		printf("\n Ingreso del registro guia[%d]",cont);
		printf("\n Ingrese el nombre: ");
		scanf("%[^\n]%*c", buffer1);
		ptr->nombre = (char*)malloc((strlen(buffer1)+1)*sizeof(char));
		strcpy(ptr -> nombre, buffer1);
		printf(" Ingrese el telefono: ");
		scanf("%s%*c", buffer2);
		ptr->telefono = (char*)malloc((strlen(buffer2)+1)*sizeof(char));
		strcpy(ptr -> telefono, buffer2);
		ptr++;
	}
}

void intercambiar_entradas(struct entrada *p1, struct entrada *p2)
{
	aux = p1 -> nombre;
	p1 -> nombre = p2 -> nombre;
	p2 -> nombre = aux;
	aux = p1 -> telefono;
	p1 -> telefono = p2 -> telefono;
	p2 -> telefono = aux;	
}

// Odenando gu\'ia telef\'onica
void ordenar_guia(struct entrada *ptr, int N)
{
	int k; // variable contadora local
	for (cont = 0; cont < N - 1; cont++)
	{
		for (k = cont + 1; k < N; k++)
		{
			if (strcmp((ptr + cont)->nombre, (ptr + k)->nombre) > 0) 
				intercambiar_entradas(ptr + cont, ptr + k);
		}
	}	
}

void imprimir_guia(struct entrada *ptr, int N)
{
	int k; // variable contadora local
	printf("====================== Imprimiendo guia telefonica ");
	printf("========================\n\n");	
	printf("     Nombre\t\t\t\t\t\tTelefono\n");
	printf("---------------------------------------------");
	printf("------------------------------\n");			
	for (cont = 0; cont < N; cont++)
	{
		printf(" %2d. %s", cont + 1, ptr -> nombre);
		for(k = strlen(ptr -> nombre); k < 49; k++)
			printf(" ");
		printf("\t%s\n", ptr -> telefono);
		ptr++;
	}
	printf("=============================================");
	printf("==============================\n\n");
}
