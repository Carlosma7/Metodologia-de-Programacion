#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <fstream>	/* ostream, istream*/
#include "Tablero.h"

using namespace std;

Tablero::Tablero(){
	partida_finalizada=false;
	turno_actual=0;
	ganador=0;
	fichas_turno=0;
}

void Tablero::InicializarTablero(int filas, int columnas, int n_linea, int fichas){
	matriz.cambiarMatriz(filas,columnas);

	N=n_linea;

	fichas_turno=fichas;

	partida_finalizada=false;

	srand (time(0));	// Establecemos semilla aleatoria
	turno_actual=(rand()%2)+1;	// Establecemos el turno aleatoriamente

	ganador=0;
}

int Tablero::GetFilasTablero() const{
	return matriz.GetFilas();
}

int Tablero::GetColumnasTablero() const{
	return matriz.GetColumnas();
}

int Tablero::GetN(){
	return N;
}

int Tablero::GetPosicion(int fils, int cols){
	return matriz.GetElemento(fils,cols);
}

bool Tablero::FinPartida(){
	return partida_finalizada;
}

int Tablero::GetTurno(){
	return turno_actual;
}

int Tablero::GetGanador(){
	return ganador;
}

int Tablero::Puntuacion() const{
	int puntuacion=GetFilasTablero()*GetColumnasTablero();

	puntuacion*=N;

	int fichas_jugadas=0;
	for(int i=0; i<GetFilasTablero(); i++)
		for(int j=0; j<GetColumnasTablero(); j++)
			if(matriz.GetElemento(i,j)!=0)
				fichas_jugadas++;

	puntuacion+=fichas_jugadas;

	return puntuacion;
}

bool Tablero::ComprobarFinPartida(int fil, int col){
	// Caso Horizontal
	bool finalizada=false;
	int contador_N=0;
	for(int i=0; i<GetColumnasTablero(); i++){
		if(matriz.GetElemento(fil,i)==turno_actual){
			contador_N++;
			if(contador_N==N)
				finalizada=true;
		}else
		contador_N=0;
	}

	// Caso Vertical
	contador_N=0;
	for(int i=0; i<GetFilasTablero(); i++){
		if(matriz.GetElemento(i,col)==turno_actual){
			contador_N++;
			if(contador_N==N)
				finalizada=true;
		}else
		contador_N=0;
	}

	// Caso diagonal hacia la derecha
	int diagonal_i=fil;
	int diagonal_j=col;

	while(diagonal_i!=0 && diagonal_j!=0){
		diagonal_i--;
		diagonal_j--;
	}

	contador_N=0;
	for(; diagonal_i<GetFilasTablero() && diagonal_j<GetColumnasTablero(); diagonal_i++,diagonal_j++){
		if(matriz.GetElemento(diagonal_i,diagonal_j)==turno_actual){
			contador_N++;
			if(contador_N==N)
				finalizada=true;
		}else
		contador_N=0;
	}

	// Caso diagonal hacia la izquierda
	diagonal_i=fil;
	diagonal_j=col;

	while(diagonal_i!=0 && diagonal_j!=(GetColumnasTablero()-1)){
		diagonal_i--;
		diagonal_j++;
	}

	contador_N=0;
	for(; diagonal_i<GetFilasTablero() && diagonal_j>=0; diagonal_i++,diagonal_j--){
		if(matriz.GetElemento(diagonal_i,diagonal_j)==turno_actual){
			contador_N++;
			if(contador_N==N)
				finalizada=true;
		}else
		contador_N=0;
	}
		
	
	return finalizada;
}

bool Tablero::MeterFicha(int columna){
	bool insertada=false;
	int fila_inserta;

	for(int i=GetFilasTablero()-1; i>=0 && !insertada; i--)
		if(matriz.GetElemento(i,columna)==0){	// Caso 1: Encontramos la primera vacía
			matriz.SetElemento(i, columna, turno_actual);
			fila_inserta=i;
			insertada=true;
		}

	// Comprobacion fin partida
	if(Completo()){
		partida_finalizada=true;
	}else if(fila_inserta>=0 && fila_inserta<=GetFilasTablero()-1){
		if(ComprobarFinPartida(fila_inserta,columna)){
			partida_finalizada=true;
			ganador=turno_actual;
		}
	}

	return insertada;
}

void Tablero::VaciarTablero(){
	int movimientos_partida=0;
	for(int i=0; i<GetFilasTablero(); i++)
		for(int j=0; j<GetColumnasTablero(); j++)
			if(matriz.GetElemento(i, j)!=0)
				movimientos_partida++;

	if(movimientos_partida%2==0)	// El jugador que empieza ha perdido
		PasarTurno();		// Cambiamos el turno para que empiece el que no empezó antes

	for(int i=0; i<GetFilasTablero(); i++)
		for(int j=0; j<GetColumnasTablero(); j++)
			matriz.SetElemento(i, j, 0);

	partida_finalizada=false;
	ganador=0;

}

void Tablero::prettyPrint(ostream & os)const{
	char columna;
	os << " ";
	for(int i=0; i<GetColumnasTablero(); i++){
		columna=i+'a';
		cout << columna << " ";
	}

	os << endl;

	for(int i=0; i<GetFilasTablero(); i++){
		for(int j=0; j<GetColumnasTablero(); j++){
			os << "|";
			if(matriz.GetElemento(i,j)==1)
				os << "x";
			else if(matriz.GetElemento(i,j)==2)
				os << "o";
			else
				os << " ";
		}

		os << "|" << endl;
	}

	for(int i=0; i<GetColumnasTablero(); i++)
		os << "==";
	os << "=" << endl;

}

void Tablero::PasarTurno(){
	turno_actual=((turno_actual)%2)+1;
}

bool Tablero::Completo(){
	bool completo=true;

	for(int i=0; i<GetColumnasTablero(); i++)
		if(matriz.GetElemento(0,i)==0)
			completo=false;

	return completo;
}


std::ostream & operator<< (std::ostream & os, const Tablero & t){
	os << t.matriz << endl;

	os << t.N << " " << t.partida_finalizada << " " << t.turno_actual << endl;

	return os;
}

std::istream & operator>> (std::istream & is, Tablero & t){
	is >> t.matriz;

	is >> t.N;
	is >> t.partida_finalizada;
	is >> t.turno_actual;
			
	return is;		
}
