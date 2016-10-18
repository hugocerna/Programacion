#include <stdio.h>

int main()
{
	int n, x, y;
	
	printf("Ingrese n: ");
	scanf("%d",&n);
	
	for(y=n; y>=-n; y--)
	{
		for(x=-n; x<=n; x++)
		{
			if(abs(x) + abs(y) >= n+1)
				printf(" *");
				
			else
				printf("  ");
				
		}
		printf("\n");
	}
	return 0;
}
