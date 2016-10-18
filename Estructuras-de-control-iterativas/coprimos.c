#include<stdio.h>

void main(){
	int a,b,m,i,divMax;
	printf("a: "); scanf("%d",&a);
	printf("b: "); scanf("%d",&b);
	m = a; if (b<a) m = b;
	for ( i = 1 ; i <= m ; i++ )
		if ( (a%i == 0) && (b%i == 0) ) divMax = i;
	if (divMax == 1) printf("son coprimos.\n");
	else printf("no son coprimos.\n");			
}
