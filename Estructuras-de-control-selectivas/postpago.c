#include<stdio.h>

void main()
{
      float a, b, pago, imp, adicmin=0, adicmb=0, min, mb;
      
      printf("Ingrese los minutos y mb gastados: ");  
      scanf("%f%f", &a, &b);
      
      min = a - 100;
      mb = b - 500;
      
      if (min > 0)
            adicmin = 0.2*min;
      if (mb > 0)
            adicmb = 0.05*mb;  
         
      pago = 20 + 1.5 + adicmin + adicmb;
      imp = 0.18*pago;
         
      printf("Cuenta básica: 20 soles\n"); 
      printf("Cuenta por minutos adicionales: %.2f soles\n", adicmin);
      printf("Cuenta por mb adicionales: %.2f soles\n", adicmb);
      printf("Cuenta por seguro: 1.5 soles\n");            
      printf("Cuenta impuesto: %.2f soles\n", imp);
      printf("Cuenta total: %.2f \n", pago + imp);     
}             





