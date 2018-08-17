#include "Validaciones.h"
#include<math.h>
#include<iostream>
using namespace std;

Validaciones::Validaciones(){
}

int Validaciones::convertir(char c){
	col = 0;
	switch(c){
		case 'a': col = 1;
			  break;
		case 'b': col = 2;
			  break;
		case 'c': col = 3;
			  break;
		case 'd': col = 4;
			  break;
		case 'e': col = 5;
			  break;
		case 'f': col = 6;
			  break;
		case 'g': col = 7;
			  break;
		case 'h': col = 8;
			  break;
		case 'i': col = 9;
			  break;
		case 'j': col = 10;
			  break;
		case 'k': col = 11;
			  break;
	}
	return col;
}

int Validaciones::seleccionar(char** tab,bool t, int f, int c){
	//-1=fuera del tablero, 0=espacio vacio o con pieza equivocada, 1=pieza correcta
	if(f<1 || c<1 || f>11 || c>11)
		return -1;
	else{
		if(t){
			if(tab[f][c] == '+')
				return 1;
			else
				return 0;
		}
		else {
			if(tab[f][c] == '#')
				return 1;
			else
				return 0;
		}
	}
}

int Validaciones::valMov(char** tab, int fi, int ci, int fd, int cd){
	//-1=fuera del tablero 0=espacio ocupado o muy lejos 1=clonar 2=mover
	if(fd<1 || cd<1 || fd>11 || cd>11)
		return -1;
	else {
		if(abs((fd-fi)) < 3 && abs((cd-ci)) < 3){// < 3 para que no me de problemas si abs() retorna double
			if(abs((fd-fi)) < 2 && abs((cd-ci)) < 2){
				if(tab[fd][cd]=='.')
					return 1;
				else
					return 0;
			}
			else{
				if(tab[fd][cd]=='.')
					return 2;
				else
					return 0;
			}
		}
		else return 0;
	}
}

Validaciones::~Validaciones(){
	cout << "Gracias por jugar" << endl;
}
