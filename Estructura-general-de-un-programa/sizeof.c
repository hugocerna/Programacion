/* Programa que indica la cantidad de bytes que requiere cada variable. */
#include <stdio.h>

void main(void)
{		
	printf("\n Tipo de variable (keyword) \t  Bytes requeridos\n");
	printf("=====================================");
	printf("=============================\n");	
	printf(" char \t\t\t\t\t%lu\n", sizeof(char));	
	printf(" int  \t\t\t\t\t%lu\n", sizeof(int));	
	printf(" short  \t\t\t\t%lu\n", sizeof(short));	
	printf(" long   \t\t\t\t%lu\n", sizeof(long));	
	printf(" long long \t\t\t\t%lu\n", sizeof(long long));	
	printf("\n");
	printf(" unsigned char \t\t\t\t%lu\n", sizeof(unsigned char));	
	printf(" unsigned int \t\t\t\t%lu\n", sizeof(unsigned int));	
	printf(" unsigned short \t\t\t%lu\n", sizeof(unsigned short));	
	printf(" unsigned long \t\t\t\t%lu\n", sizeof(unsigned long));	
	printf(" unsigned long long \t\t\t%lu\n", sizeof(unsigned long long));	
	printf("\n");
	printf(" float \t\t\t\t\t%lu\n", sizeof(float));	
	printf(" double \t\t\t\t%lu\n", sizeof(double));	
	printf(" long double \t\t\t\t%lu\n", sizeof(long double));
	printf("=====================================");
	printf("=============================\n\n");
}
