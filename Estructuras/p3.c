/* Ordenando Lista de Nombre*/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
/*estructura de entrada*/
struct entrada{
	char nombre[50];
	char numero[12];
};
/*funcion que ordena los nombres alfabeticamente*/
int compare(const void *s1, const void *s2)
{
  struct entrada *e1 = (struct entrada *)s1;
  struct entrada *e2 = (struct entrada *)s2;
  int r = strcmp(e1->nombre,e2->nombre);
   return r;
}
/*funcion main*/
void main(void){
	struct entrada *agenda;
	int i,N;
	char temp[30];
	char temp1[10];
	printf("************AGENDA TELEFONICA************\n");
	printf("*****************************************\n");
	do{
	printf("ingrese el numero de personas\n");
	scanf("%d",&N);
	}while(N<=0);
	gets(temp);
	agenda = (struct entrada*)malloc(N*sizeof(struct entrada));
	for (i = 0; i < N; i++){
		printf("Nombre %d: ", i+1);
		gets(temp);
		strcpy(agenda[i].nombre, temp);
		printf("Numero :");
		gets(temp1); 
		strcpy(agenda[i].numero,temp1);				
	}
	/*llamada a la funcion que ordena los nombres*/		
   qsort(agenda,N,sizeof(struct entrada),compare);
	/*imprimiendo la lista ordenada*/	
	printf("\n\nLa lista ordenada es:\n");
	for (i=0; i < N ; i++)
	printf("%s\t%s\n", agenda[i].nombre,agenda[i].numero);
	/*liberando espacio en la memoria*/
	free(agenda);
}
