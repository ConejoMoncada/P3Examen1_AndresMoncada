#include "Validaciones.h"
#include<iostream>
#include<string>
using namespace std;

char** inicio();
void print(char**);
void cambiar(char**,bool,int,int);


main(){
	Validaciones* val = new Validaciones();
	int espacios = 137;
	int v;//para las validaciones
	char ccol;//char columna
	int fi,ci,cd,fd;//filas y columnas iniciales y de destino
	char** tablero = inicio();
	bool fin = false;
	bool turno = true;//true = +
	while(!fin){
		print(tablero);
		cout << "Turno de ";
		if(turno)
			cout << "+";
		else 
			cout << "#";
		cout << endl <<"Seleccionar pieza"<< endl <<"Ingrese una columna (letras minúsculas) o ingrese 'z' para terminar: ";
		cin >> ccol;
		ci = val->convertir(ccol);
		v = 2;//v=2 significa que la columna está bien, para que cuando se reinicie el do-wile revise la fila si la columna está bien
		if(ccol != 'z'){
			//validar seleccion
			//v=1 -> todo está bien
			do{
				if(ci == 0 || v != 2){
					cout << "Valor no válido" << endl <<"Ingrese una columna(letras minúsculas) o ingrese 'z' para terminar: ";
					cin >> ccol;
					ci = val->convertir(ccol);
					v = 2;
				}
				else{
					cout << "Ingrese una fila (números): ";
					cin >> fi;
					v = val->seleccionar(tablero,turno,fi,ci);
					switch(v){
						case -1: cout << "Posición fuera del tablero" << endl;
							 break;
						case 0: cout << "Posición no válida" << endl;
					}
				}
			}while(v != 1);
			do{
				cout << "Ingrese la posición donde se quiere mover" << endl << "Columna (letras): ";
				cin >> ccol;
				cd = val->convertir(ccol);
				cout << "Fila (números: ";
				cin >> fd;
				v = val->valMov(tablero,fi,ci,fd,cd);
				switch(v){
					case -1: cout << "Posición fuera del tablero" << endl;
						 break;
					case 0: cout << "Posición no válida" << endl;
				}
				switch(v){
					case 1: if(turno)
							tablero[fd][cd] = '+';
						else
							tablero[fd][cd] = '#';
						break;
					case 2: if(turno){
							tablero[fd][cd] = '+';
							tablero[fi][ci] = '.';
						}
						else{
							tablero[fd][cd] = '#';
							tablero[fi][ci] = '.';
						}
						break;
				}
			}while(v < 1);
			switch(v){
				case 1: if(turno)
						tablero[fd][cd] = '+';
					else
						tablero[fd][cd] = '#';
					break;
				case 2: if(turno){
						tablero[fd][cd] = '+';
						tablero[fi][ci] = '.';
					}
					else{
						tablero[fd][cd] = '#';
						tablero[fi][ci] = '.';
					}
					break;
			}
			cambiar(tablero,turno,fd,cd);
			turno = !turno;
			if(turno)
				tablero[0][0] = '+';
			else
				tablero[0][0] = '#';
		}
		if(espacios == 0 || ccol == 'z')
			fin = true;
	}
	int cm = 0;//contador +
	int cn = 0;//contador #
	//revisar quien gana
	for(int i = 1; i < 12; i++){
		for (int j = 1; j < 12; j++){
			if(tablero[i][j] == '+')
				cm++;
			else if(tablero[i][j] == '#')
				cn++;
		}
	}
	if(cn<cm)
		cout << "Ganó +" << endl;
	else if(cm<cn)
		cout << "Ganó #" << endl;
	else
		cout << "Empate" << endl;
	for (int i = 0; i < 12; i++){
		delete[] tablero[i];
	}
	delete[] tablero;
	delete val;
}

char** inicio(){
	char** t = new char*[12];
	for(int i = 0; i < 12; i++){
		t[i] = new char[12];
	}
	//llenar la matriz
	for(int i = 1; i < 12; i++){
		for (int j = 1; j < 12; j++){
			t[i][j] = '.';
		}
	}
	t[0][0] = '+';
	t[0][1] = 'a';
	t[0][2] = 'b';
	t[0][3] = 'c';
	t[0][4] = 'd';
	t[0][5] = 'e';
	t[0][6] = 'f';
	t[0][7] = 'g';
	t[0][8] = 'h';
	t[0][9] = 'i';
	t[0][10] = 'j';
	t[0][11] = 'k';
	t[1][0] = '1';
	t[2][0] = '2';
	t[3][0] = '3';
	t[4][0] = '4';
	t[5][0] = '5';
	t[6][0] = '6';
	t[7][0] = '7';
	t[8][0] = '8';
	t[9][0] = '9';
	t[10][0] = '0';
	t[11][0] = '1';
	t[6][1] = '#';
	t[1][6] = '+';
	t[6][11] = '#';
	t[11][6] = '+';
	return t;
}

void print(char** t){
	for (int i = 0; i < 12; i++){
		if(i < 10)
			cout << " ";
		else
			cout << "1";
		for(int j = 0; j < 12; j++){
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
}

void cambiar(char** tab, bool t, int f, int c){
	bool ar = false,ab = false ,d = false,i = false,
	     ar2 = false,ab2 = false,d2 = false,i2 = false;//son para revisar si hay espacio antes del borde
	if(f > 1)
		ar = true;
	if(f < 11)
		ab = true;
	if(c > 1)
		i = true;
	if(c < 11)
		d = true;
	//turno de +
	if(t){
		//fila de arriba
		if(ar){
			//arriba
			if(tab[f-1][c] == '#')
				tab[f-1][c] = '+';
			//arriba izquierda
			if(i){
				if(tab[f-1][c-1] == '#')
					tab[f-1][c-1] = '+';
			}
			//arriba derecha
			if(d){
				if(tab[f-1][c+1] == '#')
					tab[f-1][c+1] = '+';
			}
		}
		//fila de abajo
		if(ab){
			//arriba
			if(tab[f+1][c] == '#')
				tab[f+1][c] = '+';
			//arriba izquierda
			if(i){
				if(tab[f+1][c-1] == '#')
					tab[f+1][c-1] = '+';
			}
			//arriba derecha
			if(d){
				if(tab[f+1][c+1] == '#')
					tab[f+1][c+1] = '+';
			}
		}
		//izquierda
		if(i){
			if(tab[f][c-1] == '#')
				tab[f][c-1] = '+';
		}
		//derecha
		if(d){
			if(tab[f][c+1] == '#')
				tab[f][c+1] = '+';
		}
	}
	//turno de #
	else{
		//fila de arriba
		if(ar){
			//arriba
			if(tab[f-1][c] == '+')
				tab[f-1][c] = '#';
			//arriba izquierda
			if(i){
				if(tab[f-1][c-1] == '+')
					tab[f-1][c-1] = '#';
			}
			//arriba derecha
			if(d){
				if(tab[f-1][c+1] == '+')
					tab[f-1][c+1] = '#';
			}
		}
		//fila de abajo
		if(ab){
			//arriba
			if(tab[f+1][c] == '+')
				tab[f+1][c] = '#';
			//arriba izquierda
			if(i){
				if(tab[f+1][c-1] == '+')
					tab[f+1][c-1] = '#';
			}
			//arriba derecha
			if(d){
				if(tab[f+1][c+1] == '+')
					tab[f+1][c+1] = '#';
			}
		}
		//izquierda
		if(i){
			if(tab[f][c-1] == '+')
				tab[f][c-1] = '#';
		}
		//derecha
		if(d){
			if(tab[f][c+1] == '+')
				tab[f][c+1] = '#';
		}
	}
}
