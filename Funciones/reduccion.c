#include <stdio.h>


int 	mcd (int m, int n);
void	reducir (int m, int n);


int main ()
{
	int M, N;
	
	printf (" Ingrese el numerador y denominador de una fracción: ");
	scanf ("%d %d", &M, &N);
	
	reducir (M,N);

	return 0;
}


int 	mcd (int m, int n)
{
	int aux, r;
	if (m < n)
	{
		aux = m;
		m = n;
		n = aux;	
	}
	
	r = m%n;
	while (r != 0)
	{
		m = n;
		n = r;
		r = m%n;
	} 
	
	return n;
}


void	reducir (int m, int n)
{
	int MCD = mcd(m,n);
	
	printf (" La fracción reducida es %d/%d\n", m/MCD, n/MCD);
}
