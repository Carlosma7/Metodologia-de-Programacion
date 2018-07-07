#include <iostream>
#include <cstring>
#include "Jugador.h"

using namespace std;

Jugador::Jugador(const char* nom, int turn){
	strcpy(nombre,nom);
	turno=turn;
	puntuacion_total=0;
	partidas_ganadas=0;
}

const char* Jugador::GetNombre() const{
	return nombre;			
}

void Jugador::escogeColumna(Tablero &t){
	t.prettyPrint();

	char fin_col=(t.GetColumnasTablero()-1)+'a';
	cout << "Turno: " << nombre << ": ";
	if(turno==1)
		cout << "(x)" << endl;
	else
		cout << "(o)" << endl;

	cout << nombre << ", escoja una columna (letra a-" << fin_col << "): ";

	char col;
	int columna;
	do{
		cin >> col;
	}while(t.GetColumnasTablero()<=(col-'a'));

	columna=(col-'a');

	bool metida=false;
	metida=t.MeterFicha(columna);
	while(!metida){
		cout << "La columna introducida esta completa, por favor selecciona otra columna: ";
		char col;
		int columna;
		do{
			cin >> col;
		}while(t.GetColumnasTablero()<=(col-'a'));

		columna=(col-'a');
		metida=t.MeterFicha(columna);
	}
}

void Jugador::SumarPuntos(int puntos){
	puntuacion_total+=puntos;
}

int Jugador::GetPuntos(){
	return puntuacion_total;
}

void Jugador::GanaPartida(){
	partidas_ganadas++;
}

int Jugador::GetGanadas(){
	return partidas_ganadas;
}
