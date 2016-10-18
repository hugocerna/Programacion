#include<stdio.h>

void main()
{
	int n,x,y;
    printf("n: ");
    scanf("%d",&n);
    for (y=1; y < n ; y++)
    {
        for (x=1; x <= y; x++)
            printf("*");
        printf("\n");
    }
    for (  ; y > 0 ; y--)
    {
        for (x=1; x <= y; x++)
            printf("*");
        printf("\n");
    }
}
