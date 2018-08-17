#ifndef VALIDACIONES_H
#define VALIDACIONES_H

class Validaciones{
	private:
		int mov;
		int col;
	public:
		Validaciones();
		int convertir(char);
		int seleccionar(char**,bool,int,int);
		int valMov(char**,int,int,int,int);
		~Validaciones();
};
#endif
