#include<stdio.h>

void main ()
{
	unsigned int i = 33;
	for ( ; i < 127 ; i++ )
	{
		printf("%c%cAl codigo ASCII %d le corresponde el caracter %c%c%c",62,32,i,9,i,10);
		if (i%32 == 0) 
		{
			printf("Presione enter para continuar...");
			getchar();
		}
	}
}
