#include <stdio.h>

void main()
{
	char cad1[50];
	char cad2[50];
	int diferencia;
  
	printf("Ingrese la cadena de caracteres cad1: ");
	gets(cad1);

	printf("Ingrese la cadena de caracteres cad2: ");
    gets(cad2);

	printf("Usted ingresó cad1 = %s\n", cad1);
	printf("Usted ingresó cad2 = %s\n", cad2);
	printf("longitud de la cadena cad1 = %d\n",longitud(cad1));
	printf("longitud de la cadena cad2 = %d\n",longitud(cad2));
	diferencia = strcmp(cad1, cad2);
	if (diferencia < 0)
		printf("cad2 es más grande que cad1.\n");
	else if (diferencia > 0)
		printf("cad2 es más pequeña que cad1.\n");
	else 
		printf("cad1 y cad2 son dek mismo tamaño.\n");		
}

int longitud(char *s)
{
    int length=0;
    while(*s!='\0')
    {    length++; s++; }
    return (length);
}
