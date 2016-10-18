#include <stdio.h>
const int lon 5;
int v[lon];

void leer (void);
void ordenar (void);
void mostrar (void);

int main () 
{
	leer (v);
	mostrar (v);
	ordenar ();
	mostrar (v);
	return 0;
}

void lee (void)
{
	int i;
	for(i = 0; i < 5; i++)
	{
		scanf("%d", &v[i]);
	}
}

void ordenar (void)
{
	int i, j, aux;
	for (i = 0; i < 5; i++)
	{
		for(j = i+1; j < 5; j++)
		{
			if(v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
}

void mostrar (void)
{
	int i;
	for (i = 0; i < 5; i++){
		printf("%i, ",v[i]);}
}
