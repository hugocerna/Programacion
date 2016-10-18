#include <stdio.h>
#include <stdlib.h>

unsigned int loncad (char * cade); // LONgitud de la CADena
void concad (char * cade1, char * cade2); // CONcatenando CADenas
char * ingcad (char * cade); // INGresando CADena

char * cad1, * cad2;

void main()
{
	// ingresando una línea de texto 
	// y haciendo cad1 apuntar al primer caracter de esta
	cad1 = ingcad (cad1); 
	printf(" cad1: %s", cad1);	
	
	// ingresando una línea de texto 
	// y haciendo cad2 apuntar al primer caracter de la misma
	cad2 = ingcad (cad2); 
	printf(" cad2: %s", cad2);	
	
	cad1 = realloc (cad1, loncad(cad1) + loncad(cad2) + 1 );
	
	concad (cad1, cad2);
	printf("\n nueva cad1: %s\n\n", cad1);	
}

char * ingcad (char * cade)
{
	char ch;
	unsigned int lon = 0;
	
	printf ("\n Ingrese una línea de texto: ");
	ch = getchar ();
	while (ch != '\n')
	{
		lon += 1;
		cade = realloc ( cade, (lon+1)*sizeof(char) );
		*(cade + lon-1) = ch;
		ch = getchar ();	
	}
	*(cade + lon) = '\0';
	return cade;
}

unsigned int loncad (char * cade)
{
	unsigned int lon = 0;
	while (*cade++ != '\0')
		lon += 1;
	return lon;
}

void concad (char * cade1, char * cade2)
{
	unsigned int i, lon1 = loncad (cade1);
	printf("\n lon1 = %u\n", lon1);
	unsigned int lon2 = loncad (cade2);
	printf(" lon2 = %u\n", lon2);
	
	for ( i = 0 ; i < lon2 ; i += 1 )
		*(cade1 + lon1 + i) = *(cade2 + i);
		
	*(cade1 + lon1 + lon2) = '\0'; 
}
