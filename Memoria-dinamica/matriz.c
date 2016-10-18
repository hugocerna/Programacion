 #include <stdio.h>
 #include <stdlib.h>

 void MostrarMatriz (int m, int n, float ** p);
 float ** transpuesta (int m, int n, float ** mat);

 int main()
 {
 	float ** p, ** q;
 	int i, j;
  	p = calloc (5, sizeof(float *));
	for (i = 0 ; i < 5 ; i++)
       		p[i] = calloc (3, sizeof(float));

	printf("Ingrese los coeficientes de la matriz\n");
   	for (i = 0 ; i < 5 ; i++)
	{
      		printf (" Fila %d:  ", i+1);
      		for (j = 0 ; j < 3 ; j++)  scanf("%f", &p[i][j]);
   	}
   	printf (" Matriz ingresada\n");
   	MostrarMatriz (5,3,p);
   	q = transpuesta (5,3,p);
   	printf (" Matriz transpuesta\n");
   	MostrarMatriz (3,5,q);

 	//liberando memoria usada
 	for (i = 0 ; i < 5 ; i++)  free (p[i]);
 	free(p);

 	for (i = 0 ; i < 3 ; i++)  free (q[i]);
 	free(q);
 }


 void MostrarMatriz (int m, int n, float ** p)
 {
	int i, j;
    	for (i = 0 ; i < m ; i++)
	{
        	for (j = 0; j < n ; j++)  printf ("%7.2f", p[i][j]);
		printf ("\n");
	}
 }

 float ** transpuesta (int m, int n, float ** mat)
 {
	int i, j;
     	float ** trp;
     	/* reserva matriz transpuesta con n filas y m columnas */
     	trp = malloc ( n*sizeof(float *) );
    	for (i = 0 ; i < n ; i++)
        	trp[i] = malloc ( m*sizeof(float) );
     	/* rellena matriz */
    	for (i = 0 ; i < m ; i++)
        	for (j = 0; j < n ; j++)  trp[j][i] = mat[i][j];
  	return trp;
 }
