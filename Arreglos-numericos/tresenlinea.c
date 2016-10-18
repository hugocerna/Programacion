/*
NOTAS IMPORTANTE:
-La unica funcion fea es la de "ganoLaFicha()", no te asustes que solo es grande pero no es dificil
-A lo mejor no has trabajado con caracteres antes (char), hay bastante documentacion en internet, pero
en resumen es parecido a trabajar con enteros(int), solo que al hacer, por ejemplo, A[5][3] = 'K' para darle
a la coordenada 5,3 de la matriz A el valor de "KA" debes usar comillas simple (Estas: ''''''')(Estas NO """"""")
-Para jugar al tres en linea, recordar que las posiciones se cuentan desde el (0,0) hasta el (2,2)
-Avisame si ves que cometía algun error. Lo hice un poco apurado
*/

#include <stdio.h>

char Tablero[3][3];//Creamos una matriz de caracteres de 3x3, donde almacenaremos las fichas

void InicTablero();
void printTablero();
int ganoLaFicha(char ficha);

int main(){
	InicTablero();
	int salir = 0;//(Salir = 0 :: NO salir del juego)(Salir = 1 :: SÍ salir del juego)
	int turno = 0;//(Turno = 0 :: Turno del jugador 0)(Turno = 1 :: Turno del jugador 1)
	int i,j; //Indices auxiliares de posicion
	while(salir == 0){//Mientras no se salga del juego
		printTablero();
		if(turno == 0){
			printf("Jugador 0 jugando. Ingrese la posicion de su simbolo: ");
			scanf("%d,%d",&i,&j);//En el terminal deberas escribir, por ejemplo, "1,0" para meter la pieza en Tablero[1][0] (No te olvides de la coma)
			if(Tablero[i][j] == ' '){//Si en la posicion en la que quieres meter hay un ESPACIO ' ' (disponible)
				Tablero[i][j] = 'X';//Mete el caracter (osea la ficha)
			}
			else{//Sino hay un espacio...
				printf("Posicion ya ocupada o inválida\n");
			}
		}
		else if(turno == 1){//Similarmente
			printf("Jugador 1 jugando. Ingrese la posicion de su simbolo: ");
			scanf("%d,%d",&i,&j);
			if(Tablero[i][j] == ' '){
				Tablero[i][j] = 'O';
			}
			else{
				printf("Posicion ya ocupada o inválida\n");
			}
		}
		
		if(ganoLaFicha('X') == 1){
			printf("GANADOR: Jugador 0\n");
			salir = 1;
			printTablero();
		}
		else if(ganoLaFicha('O') == 1){
			printf("GANADOR: Jugador 1\n");
			salir = 1;
			printTablero();
		}
		else{
		/*Esta parte solo hace que cambiemos de jugador.
		Si turno es 0 -> aumentamos a 1 -> le sacamos residuo de dividirlo entre 2
		Osea Residuo(1/2) = 1 -> que es justo el valor del otro jugador
		Si turno es 1 -> aumentamos a 2 -> Residuo(2/2) = 0 -> que es justo el valor
		del otro jugador
		*/
			turno++;
			turno = turno%2;
		}
	}
	return 0;
}



void InicTablero(){	//Esta funcion solo llena la matriz "Tablero" con espacios en blanco
	int i,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			Tablero[i][j] = ' ';
		}
	}
}


void printTablero(){
	int i,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("[%c]", Tablero[i][j]);
		}
		printf("\n");
	}
}


int ganoLaFicha(char ficha){
	/*
	break: en resumen, la sentencia "break" lo que hace es finalizar prematuramente
	un bucle (for, while, etc), en el que este dentro. Lo "mata" sin importar en que
	valor esté el contador. Revisa en internet.
	
	En esta funcion, revisamos todos los posibles casos de hacer 3 en linea. Por ej,
	en el primer "for" revisamos si Tablero[0][0] = Tablero[0][1] = Tablero[0][1] = 'X'
	Si en algun momento alguno de estos NO es 'X', el "for" lo "matamos" con break.
	Luego revisamos abajo de este "for" si la razon por la que se salió del mismo es si
	el valor de "i" llegó a 3 (osea si nunca se mato el "for" y acabó de manera natural)
	entonces, significa que todos los valores eran 'X' y Sí se formó el tres en linea.
	(retornamos 1 para indicar el 3 en linea exitoso)
	
	Esto se hace para cada posibilidad de 3 en linea para ambos caracteres 'X' y 'O'
	*/
	if(ficha == 'X'){
		int i;
		for(i = 0; i < 3; i++){//Primera fila
			if(Tablero[0][i] != 'X'){
				break;
			}
		}
		
		if(i == 3){return 1;}
		for(i = 0; i < 3; i++){//Segunda fila
			if(Tablero[1][i] != 'X'){
				break;
			}
		}
		if(i == 3){return 1;}
		
		for(i = 0; i < 3; i++){//Tercera fila
			if(Tablero[2][i] != 'X'){
				break;
			}
		}
		if(i == 3){return 1;}
		
		for(i = 0; i < 3; i++){//Primera columna
			if(Tablero[i][0] != 'X'){
				break;
			}
		}
		if(i == 3){return 1;}
		
		for(i = 0; i < 3; i++){//Segunda columna
			if(Tablero[i][1] != 'X'){
				break;
			}
		}
		if(i == 3){return 1;}
		
		for(i = 0; i < 3; i++){//Tercera columna
			if(Tablero[i][2] != 'X'){
				break;
			}
		}
		if(i == 3){return 1;}
		
		for(i = 0; i < 3; i++){//Diagonal "\"
			if(Tablero[i][i] != 'X'){
				break;
			}
		}
		if(i == 3){return 1;}
		
		for(i = 0; i < 3; i++){//Diagonal "/"
			if(Tablero[i][2 - i] != 'X'){
				break;
			}
		}
		if(i == 3){return 1;}
		
		return 0;
	}
	if(ficha == 'O'){
		int i;
		for(i = 0; i < 3; i++){//Primera fila
			if(Tablero[0][i] != 'O'){
				break;
			}
		}
		if(i == 3){return 1;}
		
		for(int i = 0; i < 3; i++){//Segunda fila
			if(Tablero[1][i] != 'O'){
				break;
			}
		}
		if(i == 3){return 1;}
		
		for(int i = 0; i < 3; i++){//Tercera fila
			if(Tablero[2][i] != 'O'){
				break;
			}
		}
		if(i == 3){return 1;}

		for(int i = 0; i < 3; i++){//Primera columna
			if(Tablero[i][0] != 'O'){
				break;
			}
		}
		if(i == 3){return 1;}
		
		for(int i = 0; i < 3; i++){//Segunda columna
			if(Tablero[i][1] != 'O'){
				break;
			}
		}
		if(i == 3){return 1;}
		
		for(int i = 0; i < 3; i++){//Tercera columna
			if(Tablero[i][2] != 'O'){
				break;
			}
		}
		if(i == 3){return 1;}
		
		for(int i = 0; i < 3; i++){//Diagonal "\"
			if(Tablero[i][i] != 'O'){
				break;
			}
		}
		if(i == 3){return 1;}
		
		for(int i = 0; i < 3; i++){//Diagonal "/"
			if(Tablero[i][2 - i] != 'O'){
				break;
			}
		}
		if(i == 3){return 1;}
		
		return 0;
	}
}

//©Luis Vasquez-Todos los derechos son diestros
