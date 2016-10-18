#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rombo(double x, double y, double r) {
	return abs(x) + abs(y) <= r;
}
double corazon(double x, double y, double r) {
	return x*x + pow((pow(x*x, 1.0/3.0) ) - y, 2) <= r;
}
double elipse(double x, double y, double r) {
	return ((x*x)/16 + (y*y)/9) <= 1;
}
double lineal(double x, double y, double r) {
	return y - x == 0;
}
double cuadrado(double x, double y, double r) {
	return -r <= x <= r && -r <= y <= r;
}
double triangulo(double x, double y, double r) {
	return y <= x+r && y <= -x+r && y >= 0;
}


void draw(double (*f)(double, double, double), double delta) {
	int n; printf("N = "); scanf("%d", &n);
	double r = (n-1)/2;
	
	double i,j;	
	for(i = -r; i <= r; i += delta) {
		for(j = -r; j <= r; j += delta)
				printf("%s", (*f)(i, j, r) ? "*" : " " );
		printf("\n");
	}
}
int main() {
	//Las graficas son dibujadas rotadas 90 grados en sentido horario
	//O visto tambien dibujado en el eje X, Y (No es lo mismo que en Y, X)
	
	
	 draw(corazon, 0.2);
	  /*draw(elipse, 0.4);*/
	  /*draw(cuadrado, 1);*/
    /*draw(triangulo, 1);*/
	 /*draw(rombo, 1);*/
	 /*draw(lineal, 1);*/
}
