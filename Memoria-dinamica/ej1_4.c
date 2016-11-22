#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Ordenar(int** Arr, int longitud);
void printArr(int* Arr, int longitud);
void Llenar(int** Arr, int longitud);

int main(){
	time_t t;
	srand((unsigned)time(&t));
	
	int* Arr, temp;
	int longitud = 0;
	Arr = (int*)calloc(1, sizeof(int));
	
	while(1){
		printf("Ingrese una temperatura o '-1' para salir: ");
		scanf("%d", &temp);
		if(temp != -1){
			longitud++;
			Arr = realloc(Arr, longitud*(sizeof(int)));
			Arr[longitud - 1] = temp;
			Ordenar(&Arr, longitud);
			printArr(Arr, longitud);
			printf("\n");
		}
		else{
			return 0;
		}
	}
	
	free(Arr);
	return 0;
}

void Ordenar(int** Arr, int longitud){
	int i, j;
	for(i = 0; i < longitud; i++){
		for(j = i; j > 0; j--){
			if((*Arr)[j] < (*Arr)[j - 1]){
				int aux = (*Arr)[j];
				(*Arr)[j] = (*Arr)[j-1];
				(*Arr)[j-1] = aux;
			}
		}
	}
}

//No se usa 'Llenar()'
void Llenar(int** Arr, int longitud){
	int i;
	for(i = 0; i < longitud; i++){
		(*Arr)[i] = rand()%20;
	}
}

void printArr(int* Arr, int longitud){
	int i;
	for(i = 0; i < longitud; i++){
		printf("[%d]", Arr[i]);
	}
}
