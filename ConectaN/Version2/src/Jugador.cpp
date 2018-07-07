#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>     /* srand, rand */
#include <ctime>
#include <unistd.h>
#include "Jugador.h"

using namespace std;

Jugador::Jugador(){
	nombre=0;
	turno=0;
	puntuacion_total=0;
	partidas_ganadas=0;
	fichas_metidas=0;
}

void Jugador::InicializarJugador(const char* nom, int turn){
	int tam_nombre=strlen(nom)+1;
	nombre=new char[tam_nombre];
	strcpy(nombre,nom);
	turno=turn;
	puntuacion_total=0;
	partidas_ganadas=0;
}

Jugador::~Jugador(){
	delete [] nombre;
}

const char* Jugador::GetNombre() const{
	return nombre;			
}

bool Jugador::escogeColumna(Tablero &t, bool & salvar, int fichas_a_meter){
	t.prettyPrint();

	char fin_col=(t.GetColumnasTablero()-1)+'a';
	cout << "Turno: " << nombre << ": ";
	if(turno==1)
		cout << "(x)" << endl;
	else
		cout << "(o)" << endl;

	cout << nombre << ", escoja una columna (letra a-" << fin_col << ") para la ficha " << fichas_metidas+1 << " de " << fichas_a_meter << ": ";

	char col;
	int columna;

	if(nombre[0]=='@'){	// Robot
		bool metida=false;
		srand(time(0));
		while(!metida){
			sleep(1);
			columna=rand()%t.GetColumnasTablero();
			cout << "Columna: " << columna << endl;
			metida=t.MeterFicha(columna);
		}
		fichas_metidas++;
		cout << endl;
		return true;
	}else{
		cin >> col;

		columna=col-'a';
		if(t.GetColumnasTablero()<=(col-'a')){
			cout << "La letra proporcionada es inválida." << endl;
			salvar=true;
			return false;
		}

		if(t.MeterFicha(columna)){
			fichas_metidas++;
			return true;
		}else{
			cout << "La columna introducida esta completa, por favor selecciona otra columna: " << endl;
			return false;
		}
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

bool Jugador::PuedoPasarTurno(int fichas_a_meter){
	if(fichas_metidas==fichas_a_meter){
		fichas_metidas=0;
		return true;
	}else
		return false;
}

ostream & operator << (ostream & os, const Jugador & j){
	os << '#' << j.nombre << ' ';
	os << j.turno << " " << j.puntuacion_total << " " << j.partidas_ganadas << endl;

	return os;
}

istream & operator >> (istream & is, Jugador & j){
	is.ignore(256,'#');

	char nombre[500];
	is.getline(nombre,500,' ');
	j.nombre=new char[strlen(nombre)+1];
	strcpy(j.nombre,nombre);

	is >> j.turno;

	is >> j.puntuacion_total;

	is >> j.partidas_ganadas;
	

	return is;
}
