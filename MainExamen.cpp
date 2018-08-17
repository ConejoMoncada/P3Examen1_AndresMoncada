/*#include "Validaciones.h"*/
#include<iostream>
#include<string>
using namespace std;

char** inicio();
void print(char**);
main(){
	char** tablero = inicio();
	bool fin = false;
	bool turno = true;//true = +
	print(tablero);
	while(!fin){
		cout << "Turno de ";
		if(turno)
			cout << "+";
		else 
			cout << "#";
		cout << endl;
		fin = true;
	}
	for (int i = 0; i < 12; i++){
		delete[] tablero[i];
	}
	delete[] tablero;
}

char** inicio(){
	char** t = new char*[12];
	for(int i = 0; i < 12; i++){
		t[i] = new char[12];
	}
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
