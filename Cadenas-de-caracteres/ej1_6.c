/*
Para consultas: luislve1796@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generarNumAleat(int a, int b);

/*
pseudocódigo:
int main(){
	variable de tiempo t;
	hacemos_que_el_rand()_dependa_de(  (valor_absoluto_de->)time(&t)  );
	
	entero tam, i;
	puntero a caracter cadena;
	
	imprimir("...");
	recibir(tam);
	
	cadena = reservar_memoria(tam + 1 unidades, tamaño de la variable 'char');------------se explica abajo
	
	---barriendo la cadena---
	desde el principio de la cadena (i = 0) hasta el espacio ubicado uno antes del ultimo (i = tam - 1, ya que
	el ultimo es i = tam) hacemos que el elemento cadena[i] = un numero aleatorio
	
	luego, al ultimo elemento (i = tam) le damos el nulo (\0) para indicar el fin de la cadena
	
	---barriendo la cadena al reves---
	desde i = el penúltimo elemento (no quiero imprimir el ultimo dado que es el nulo, pero tampoco
	habría problema, por ser el nulo no se imprimirá nada en la terminal, ni siquiera un ESPACIO ni 
	nada parecido) hasta el elemento i = 0 (osea el primero)
	
	imprimir(cadena[i]);
	
	imprimir (ENTER);
	
	liberar(la memoria separada para: cadena);
	retornar zero;
}
*/

int main(){
	time_t t;
	srand((unsigned)time(&t));

	int tam, i;
	char *cadena;
	printf("Ingrese el tamaño de la cadena: ");
	scanf("%d", &tam);
	
	cadena = (char*)calloc(tam + 1,sizeof(char));
	
	for(i = 0; i <= tam - 1; i++){
		cadena[i] = generarNumAleat(65, 90);
	}
	cadena[tam] = '\0';
	
	for(i = tam - 1; i >= 0; i--){
		printf("%c", cadena[i]);
	}
	printf("\n");
	free(cadena);
	return 0;
}

/*
Linea 47:
cadena = (char*)calloc(tam + 1,sizeof(char));

funcion calloc:
	Estructura: calloc(int cantidad de unidades, int tamano de cada unidad)
	Retorna: un puntero a vacio (void*)
	
como funciona en el problema:
	Al llamar a la funcion calloc(), el primer argumento se da como 'tam + 1'
	indicando que deseamos separar espacio en la memoria para 'tam+1' elementos,
	esto con la intencion que el arreglo posea 'tam+1' caracteres; luego el
	segundo argumento indica cuanto "pesa" cada elemento, como el arreglo será
	de caracteres, debemos separar un total de memoria igual a:
		
			(tam + 1)*(tamaño de 1 caracter)
			
	luego, como la funcion calloc retorna un puntero void* y usted necesita un char*
	para así ligarlo al char* arreglo que creó, se precede a la función con un (char*)
	y se guarda en arreglo

*/

int generarNumAleat(int a, int b){
	/*
	Funcion que genera un numero aleatorio en el rango [a;b]
	*/
	int result;
	result = rand()%(b - a + 1) + a;
	return result;
}
