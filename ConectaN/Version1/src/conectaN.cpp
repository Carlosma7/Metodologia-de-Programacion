#include <iostream>
#include "Matriz.h"
#include "Tablero.h"
#include "Jugador.h"

using namespace std;

int main(){
	int filas_tablero, columnas_tablero, n;
	char nombre_1[50];
	char nombre_2[50];
	char limpia_buffer[100];
	int contador_partidas=0;
	bool fin=false;
	bool fin_juego=false;
	char opcion;

	cout << "Introduzca filas: ";
	cin >> filas_tablero;
	cout << "Introduzca columnas: ";
	cin >> columnas_tablero;
	cout << "Introduzca fichas a alinear (3-5): ";
	cin >> n;

	// Creamos el tablero
	Tablero t(filas_tablero, columnas_tablero, n);

	cin.getline(limpia_buffer,100);
	cout << "Introduzca nombre del primer jugador: ";
	cin.getline(nombre_1,50);
	cout << "Introduzca nombre del segundo jugador: ";
	cin.getline(nombre_2,50);

	// Creamos los jugadores
	Jugador jugador_1(nombre_1, 1);
	Jugador jugador_2(nombre_2, 2);

	while(!fin_juego){

		contador_partidas++;

		// Empezamos el juego
		while(!fin){
			// Mete ficha uno
			if(t.GetTurno()==1){
				jugador_1.escogeColumna(t);
				t.PasarTurno();
			}else{
				jugador_2.escogeColumna(t);
				t.PasarTurno();
			}

			fin=t.FinPartida();

		}

		t.prettyPrint();

		if(t.GetGanador()==1){
			jugador_1.GanaPartida();
			jugador_1.SumarPuntos(t.Puntuacion());
		}else if(t.GetGanador()==2){
			jugador_2.GanaPartida();
			jugador_2.SumarPuntos(t.Puntuacion());
		}

		t.VaciarTablero();
		fin=false;

		cout << endl << endl << "Resultados tras esta partida:" << endl;
		cout << jugador_1.GetNombre() << ": " <<  jugador_1.GetGanadas() << " ganadas que acumulan " << jugador_1.GetPuntos() << " puntos.\n";
		cout << jugador_2.GetNombre() << ": " <<  jugador_2.GetGanadas() << " ganadas que acumulan " << jugador_2.GetPuntos() << " puntos.\n";


		do{
			cout << "¿Jugar de nuevo(S/N)?:";
			cin >> opcion;

		}while(opcion!='n' && opcion!='N' && opcion!='s' && opcion!='S');

		if(opcion=='n' || opcion=='N')
			fin_juego=true;
	}

	cout << endl << endl << "Resultados finales:\n";
	cout << jugador_1.GetNombre() << ": " <<  jugador_1.GetGanadas() << " ganadas que acumulan " << jugador_1.GetPuntos() << " puntos.\n";
	cout << jugador_2.GetNombre() << ": " <<  jugador_2.GetGanadas() << " ganadas que acumulan " << jugador_2.GetPuntos() << " puntos.\n";
	cout << (contador_partidas-jugador_1.GetGanadas()-jugador_2.GetGanadas()) << " empatadas\n\n";

	return 0;

}
