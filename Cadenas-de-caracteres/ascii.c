// Programa que muestra el código ASCII de algunos caracteres 
#include<stdio.h>

void main ()
{
	int ch, i = 33;
	for ( ; i < 127 ; i++ )
	{
		printf("%c%cAl codigo ASCII %d le corresponde el caracter %c%c%c",62,32,i,9,i,10);
		if (i%20 == 0) 
		{
			printf(" Presione enter para continuar...");
			ch = getchar(); // getchar() retorna 10
			printf(" ch = %d, ch = %c", ch, ch);
		}
	}
}
