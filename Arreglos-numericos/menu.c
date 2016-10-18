/* Programa que muestra un menú con 4 opciones: 
 * 1. Pregunta 1.
 * 2. Pregunta 2.
 * 3. Pregunta 3. 
 * 0. Salir */

#include<stdio.h>
#include<math.h>

// difiniendo constantes
#define LonMax 20
#define RETRASO 400000000

// declarando variables globales
float coef[3]; // para almacenar los coeficientes de la ecc. cuadrática
int A[LonMax]; // para almacenar el arreglo ingresado
int B[LonMax]; // para almacenar el arreglo ordenado
int i; // declarando la variable global i para almacenar el índice
int cont; //variable contadora

// Prototipo de funciones
int menu (void);
void retrasar (void);
void ingresar_coeficientes (void);
void raices(float a, float b, float c);
void figura (int n);
int ingresar_longitud (void); 
void ingresar_arreglo (int N); 
void ordenar_arreglo (int N); 
void mostrar_arreglo_ordenado (int N); 
 
void main( void )
{
  	int N, orden;	
  	do
	{
		orden = menu();
		switch(orden)
		{
			case 1:
				system("clear"); // "limpiar pantalla"
				ingresar_coeficientes();
				raices(coef[0], coef[1], coef[2]);
				printf(" Mensaje: presione enter para continuar...");
				getchar();getchar();
				break;
			case 2:
				system("clear"); 
				N = ingresar();
				figura(N);
				printf(" Mensaje: presione enter para continuar...");
				getchar();getchar();
				break;
			case 3: 
				system("clear");
				N = ingresar_longitud();
				ingresar_arreglo(N);
				ordenar_arreglo(N);
				mostrar_arreglo_ordenado(N);
				printf(" Mensaje: presione enter para continuar...");
				getchar();getchar();
				break;
			default: 
				system("clear");
				printf("\n Mensaje: saliendo del programa...\n");
				retrasar();
				system("clear");
		} 
	}
	while(orden != 0);
}

int menu(void)
{
	int opcion;
	system("clear");
	printf("\n================================= Menú ");
	printf("=================================\n\n");
	printf(" 1. Pregunta 1.\n");
	printf(" 2. Pregunta 2.\n");
	printf(" 3. Pregunta 3.\n");
	printf(" 0. Salir.\n");
	printf("================================================");
	printf("===============================\n");
	printf("\n Seleccione una de las opciones: ");	
	scanf("%d", &opcion);
	return opcion;
}

void retrasar (void)
{
	for( cont = 0 ; cont < RETRASO ; )
		cont++;
}

void ingresar_coeficientes (void)
{
	printf("\n Ingrese los coeficientes a b y c de la ecuación cuadrática separados por un espacio: ");
    scanf("%f %f %f", &coef[0], &coef[1], &coef[2]);
}

void raices(float a, float b, float c)
{
	float x, y; // para almacenar las las raices
	float discri = b*b-4*a*c; // calculando el discriminante
	if (discri < 0)
	{
		x = -b/(2*a); y = sqrt(-discri)/(2*a);
		if (b == 0)
			printf("\n Las raíces son %fi y %fi.\n\n", y, -y);
		else
		{
			if (a < 0)
				y = -y;
			printf("\n Las raíces son %f + %fi y %f - %fi.\n\n", x, y, x, y);		
		}		
	}
	else if (discri == 0)
		printf("\n La única raíz es %f.\n\n", -b/(2*a));
	else 
	{
		x = (-b-sqrt(discri))/(2*a); y = (-b+sqrt(discri))/(2*a);
		printf("\n Las raíces son %f y %f.\n\n", x, y );
	}		
}

int ingresar (void)
{
	int n;
	printf("\n Ingrese un entero mayor que 1: ");
    scanf("%d",&n);
    return n;
}

void figura (int n)
{
	printf("\n");
	int x, y;
    for (y = n; y >= -n ; y--)
    {
		printf("\t");
        for (x = -n; x <= n; x++)	
            if ( (abs(x) + abs(y)) > n ) printf("*"); 
            else printf(" ");
        printf("\n");
    }
	printf("\n");
}

int ingresar_longitud (void) 
{
	int N;
	printf("\n Ingrese la longitud, menor o igual a %d,", LonMax); 
	printf(" del arreglo a ingresar: ");
	scanf("%d",&N);
	return N;	
}

void ingresar_arreglo (int N) 
{
	printf("\n Ingrese los elementos del arreglo de enteros A:\n");
	for ( i = 0 ; i < N ; i++ )
	{
		printf(" A[%d] = ",i);
		scanf("%d",&A[i]);
	}
}

/* Esta función ordena, según el método de inserción,
 * los elementos del arreglo A y el arreglo ordenado
 * lo guarda en el arreglo B */
void ordenar_arreglo(int N)
{
	int k;
	if (N == 1) 
		B[0] = A[0];
	else
	{
		ordenar_arreglo(N-1);
		k = 0;
		while ( (A[N-1] > B[k]) && (k < N-1) )
			k++;
		i = N-1;
		while (i > k)
		{
			B[i] = B[i-1];
			i--;
		}
		B[k] = A[N-1];	
	}
}

/* esta función muestra los elementos, del arreglo ordenado */ 
void mostrar_arreglo_ordenado (int N)
{
	printf("\n Arreglo ordenado: %d",B[0]);
	for ( i = 1 ; i < N ; i++)
		printf(", %d",B[i]);
	printf(".\n\n");
}
