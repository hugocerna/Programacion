#include<stdio.h>
#define CU 500
#define SN 200

int main()
{
	int antiguedad;
	char tipo;
	float precio,peso;

	printf("ingrese el tipo , antiguedad y peso respectivamente: ");
	scanf("%c %i %f",&tipo,&antiguedad,&peso);
	
	switch(tipo){
		case 'A':
		case 'a':precio = peso*0.8*CU + peso*0.2*SN; break;
		case 'B':
		case 'b':precio = peso*0.9*CU + peso*0.1*SN; break;
		case 'C':
		case 'c':precio = peso*0.95*CU + peso*0.05*SN; break;
		default :printf("el tipo ingresado es incorrecto\n");
					return 0;
	}
	
	if(antiguedad<=5){
		printf("el precio del reliquia es %.2f\n",precio);
	}
	else if(antiguedad<=20){
	printf("el precio del reliquia es %.2f\n",precio*1.5);
	}
	else if(antiguedad<=50){
	printf("el precio del reliquia es %.2f\n",precio*2.0);
	}
	else{
	printf("el precio del reliquia es %.2f\n",precio*3.0);
	}

	return 0;
}
