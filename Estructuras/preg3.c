/* Ordenando Lista de Nombres */
#include <stdio.h>
#include <stdlib.h> // necesario para invocar malloc y free
#include <string.h> // necesario para invocar strcpy y strcmp
struct guia{
	char nombre[50];
	char telefono[12];

};
void ordenar(struct guia *lista,int N){          /*ESTA FUNCION ORDENARA LISTA*/
       int i,j;
       char aux1[50];
       char aux2[12];

       for(i=0;i<N;i++){
		for(j=i;j<N;j++){

			if(strcmp(lista[i].nombre , lista[j].nombre)>0){
				strcpy(aux1 ,lista[i].nombre);
				strcpy(lista[i].nombre ,lista[j].nombre);
				strcpy(lista[j].nombre , aux1);

				strcpy(aux2 ,lista[i].telefono);
				strcpy(lista[i].telefono ,lista[j].telefono);
				strcpy(lista[j].telefono , aux2);
				}

			}


		}




}
void main(void){
	struct guia *lista;
	int i,j,k,N=5,ban;
	char aux[50],aux2[12];
	lista=(struct guia *)malloc(N*sizeof(struct guia));

	printf("ingrese los nombres en mayusculas y los telefonos\n");
	for (i = 0; i < N; i++)
		{
			printf("Nombre %d: ", i+1);
			gets(lista[i].nombre);
			printf("telefono %d : ",i+1);
			gets(lista[i].telefono);

		}

	/*ordenamos alfabeticamente*/
	ordenar(lista,N);

	for(i=0;i<N;i++){
		for(j=i;j<N;j++){

			if(strcmp(lista[i].nombre , lista[j].nombre)>0){
				strcpy(aux ,lista[i].nombre);
				strcpy(lista[i].nombre ,lista[j].nombre);
				strcpy(lista[j].nombre , aux);

				strcpy(aux2 ,lista[i].telefono);
				strcpy(lista[i].telefono ,lista[j].telefono);
				strcpy(lista[j].telefono , aux2);
				}

			}


		}
	printf("\n\nmostarremos la lista orde nada alfabeticamente\n\n");

	/*mostraremos la guia ordenada al fabeticamente*/
	for(i=0;i<N;i++){
		printf("nombre %d : ",i+1);	puts(lista[i].nombre);
		printf("telefono %d : ",i+1); puts(lista[i].telefono);



	}
	free(lista);

}
