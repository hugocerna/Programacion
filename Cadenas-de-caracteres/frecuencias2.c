#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void leer(char V[MAX][MAX], int n);
void imprimir(char V[MAX][MAX], int n);
//void fre(char A[][], int frec[], int n);

int main()
{
	int n;
	int frec[26];
	
	printf("ingrese en tamaño de la matriz: ");
	scanf("%d",&n);
	
	//srand( time( NULL ) );
	char C[MAX][MAX];
	leer(C,n);
	imprimir(C,n);
	//fre(C,frec,n);
	return 0;
}

void leer(char V[MAX][MAX], int n)
{
	int i,j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
		  printf("Ingrese el elemnto V[%d][%d]: ",i,j);
		  scanf("%s", &V[i][j]);
		}
	}
}

void imprimir(char V[MAX][MAX], int n)
{
	int i,j;
	printf("\n\nLos elementos de la matriz son:\n\n");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			printf("C[%d][%d] = %c\n", i, j, V[i][j]);
	}
	printf("\n");
}

/*void fre(char A[][], int frec[], int n)
{
    int i,j;
    for(i = 65; i < 91; i++)
		frec[i] = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			frec[A[i][j]]++;
	for(i = 65; i < 91; i++)
		printf(" %c : %d veces \n",i,frec[i]);	
}*/
