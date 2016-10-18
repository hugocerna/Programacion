#include <stdio.h>

int main ()
{
	int x, y, n;
	
	printf (" Ingrese un entero mayor que uno:");
	scanf ("%d",&n);
	
	for (y = n-1; y >= -(n-1); y = y-1)
	{
		printf (" ");
		for (x = 0; x <= n-1; x = x+1)
		{
			if (abs(x) + abs(y) <= n-1)
				printf ("*");
			else
				printf (" ");
		}
		printf ("\n");
	}

}
