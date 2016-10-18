#include <stdio.h>
//#include<math.h>

void main()
{
	int y,x,n;

	printf("ingrese el valor de n:");
	scanf("%d",&n);
	
	for(y=n; y>-(n+1); y--)
	{
		for(x=-n; x<n+1; x++)
		{
			if(-abs(x)<=y && y<=abs(x) )
				printf(" *");	
			else 
				printf("  ");
		}
		printf("\n");
	}
}

