#include <stdio.h>
#define n 2

void ingresar();
void sumar();
void restar();
void multiplicar();
void mostrar();

//const int n = 2;
int A[n][n], B[n][n], S[n][n];// R[n][n], P[n][n];

int main ()
{
    ingresar ();
    sumar ();
    //restar ();
    //multiplicar ();
    mostrar ();
    return 0;
}

void ingresar()
{
    int i,j;
    printf ("\n Ingrese las entradas de la matriz A:\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf (" A[%d][%d] = ", i,j);
            scanf ("%d", &A[i][j]);
        }
    }
    printf ("\n Ingrese las entradas de la matriz B:\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf (" B[%d][%d] = ", i,j);
            scanf ("%d", &B[i][j]);
        }
    }
}

void sumar()
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            S[i][j] = A[i][j] + B[i][j];
        }
    }
}

//void restar();
//void multiplicar();

void mostrar()
{
    int i,j;
    printf ("\n A + B =\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf ("%4d", S[i][j]);
        }
        printf ("\n");
    }
}
