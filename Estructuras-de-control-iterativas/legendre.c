#include <stdio.h>

int main ()
{
	int n, i, d, primos, propios;
	
	for (n = 1; n <= 50; n = n +1)
	{
		i = n*n;
		primos = 0;
		while (primos == 0)
		{
			i = i + 1;
			propios = 0;
			for (d = 2; d < i; d = d + 1)
			{
				if (i%d == 0)
					propios = propios + 1;
			}
			if (propios == 0)
				primos = primos + 1;	
		}
		printf ("Entre (%d)^2 y (%d)^2 esta el primo: %d\n",n,n+1,i);
	}
}
