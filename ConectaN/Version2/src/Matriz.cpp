#include <iostream>
#include <fstream>
#include "Matriz.h"

using namespace std;

ostream & operator << (ostream & os, const Matriz & t){
	os << t.filas << " " << t.columnas << endl;

	for(int i=0; i<t.filas; i++){
		for(int j=0; j<t.columnas; j++)
			os << t.GetElemento(i,j) << " ";
		os << endl;
	}

	os << endl;

	return os;
}

istream & operator >> (istream & is, Matriz & t){
	int f,c, dato;
	is >> f;
	is >> c;

	Matriz aux;

	aux.cambiarMatriz(f,c);

	for(int i=0; i<f; i++)
		for(int j=0; j<c; j++){
			is >> dato;
			aux.SetElemento(i,j,dato);
		}

	t = aux;
			
	return is;		
}
