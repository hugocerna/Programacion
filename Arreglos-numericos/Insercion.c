#include <stdio.h>

void printArr();

int A[10] = {1,6,-2,5,-3,21,88,3,6,777};

int main(){
	int i,j,aux;
	for(j = 1; j < 10; j++){//Empezamos a tomar elementos desde la segunda posicion (A[1])
		aux = A[j];
		i = j - 1;    //Ahora analizamos DESDE una posicion antes
		while((i >= 0)&&(A[i] > aux)){//Mientras que al decrementar el 'i' aun este en el arreglo y este valor A[i] este desordenado
			A[i + 1] = A[i];    //Lo movemos un lugar a la derecha
			i--;    //Y continuamos con el elemento de la izquierda
		}
		A[i + 1] = aux; //Una vez encontremos la posicion idónea del aux, lo colocamos
	}
	printArr();
	return 0;
}


void printArr(){
	int i;
	for(i = 0; i < 10; i++){
		printf("|%d|",A[i]);
	}
	printf("\n");
}
