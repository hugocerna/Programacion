#include<stdio.h>

int main () {
	int num, a, b, c ;
	printf("Ingrese un numero de tres cifras: ");
	scanf("%d", &num);
	a=num/100;
	b=(num-a*100)/10;
	c=(num-a*100)%10;
	printf("El numero invertido es %d%d%d\n", c,b,a);
return 0;
}
