#include <stdio.h> // 'standar library' para entrada y salida de datos

int main(){
	int n, factorial = 1, temp = 1; 
	printf("Ingrese un entero positivo:");	
	scanf("%d",&n);  
	for ( printf("Imprimiendo los %d primeros factoriales\n",n) ; temp <= n ; temp++ )
	{
		factorial = factorial*temp; // factorial = 1*2*3
		printf("%d! = %d\n",temp,factorial); 
		// usamos '%d' porque esperamos recibir variables del tipo 'entero'	
		//temp++; // es equivalente a: temp = temp + 1;
	}	
	return 0;
}
