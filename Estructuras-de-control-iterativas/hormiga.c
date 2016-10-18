#include<stdio.h>
#include<math.h>

void main()
{
	float x0, y0, a, b, x, y, m, recorrido = 0;

   printf(" Ingrese las coordenas del primer punto: ");      
   scanf("%d %d", &x0, &y0);
   x = x0; y = y0; // nuestra hormiga está en el punto (x0;y0)
      
   do
	{
   	printf("Ingrese las coordenadas del siguiente punto: ");    
      scanf("%d %d", &a, &b);
            
      m = sqrt((x-a)*(x-a) + (y-b)*(y-b));
      recorrido = recorrido + m;
      x = a; y = b; // ahora la hormiga está en el punto (a;b2)     
	}
   while(a != x0 || b != y0); // esto es la negacion de (a;b) = (x0;y0)
      
   printf(" El recorrido es: %.2f\n", recorrido);

}

