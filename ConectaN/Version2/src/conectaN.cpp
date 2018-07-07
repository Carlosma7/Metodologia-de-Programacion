#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Matriz.h"
#include "Tablero.h"
#include "Jugador.h"

using namespace std;

void Salvar(const Jugador & uno, const Jugador & dos,const Tablero & juego, bool & salvar){
	char opcion;
	cout << "\n¿Desea guardar la partida? (S/N) ";
	cin >> opcion;

	if(opcion=='S' || opcion =='s'){
		ofstream fo;
		char fichero[100];

		cin.ignore();
		cout << "Indique el nombre del fichero en el que realizar el guardado: ";
		cin.getline(fichero,100);
		fo.open(fichero);

		if(!fo){
			cerr << "Error: El fichero de entrada " << fichero << " no existe.";
			cerr << endl;
			exit(1);
		}

		fo << uno << endl << dos << endl << juego;
		cout << "Juego guardado correctamente." << endl << endl;
	}else
		salvar=false;
	
}

void Cargar(char * & fichero, Jugador & uno, Jugador & dos, Tablero & juego){
	ifstream fi;
	fi.open(fichero);

	if(!fi){
		cerr << "Error: El fichero de entrada " << fichero << " no existe.";
		cerr << endl;
		exit(1);
	}
	
	fi >> uno;

	fi >> dos;

	fi >> juego;

	cout << endl << "Partida cargada correctamente. " << endl;
	
}

int main(int argc, char *argv[]){

	int contador_partidas=0;
	int fichas_turno;
	bool fin=false;
	bool fin_juego=false;
	bool metida;
	char opcion;
	bool salvar=false;


	// Creacion de tablero y jugadores
	Tablero t;
	Jugador jugador_1, jugador_2;

	if(argc==2){	// Caso 1: Cargar partida existente
		Cargar(argv[1], jugador_1, jugador_2, t);
	}else if(argc==1){	// Caso 2: Crear nueva partida
		int filas_tablero, columnas_tablero, n;
		char nombre_1[50];
		char nombre_2[50];


		cout << "Introduzca filas: ";
		cin >> filas_tablero;
		cout << "Introduzca columnas: ";
		cin >> columnas_tablero;
		cout << "Introduzca fichas a alinear (3-5): ";
		cin >> n;
		cout << "Introduzca fichas por turno (1-4): ";
		cin >> fichas_turno;

		// Inicializamos el tablero
		t.InicializarTablero(filas_tablero, columnas_tablero, n, fichas_turno);

		cin.ignore();
		cout << "Introduzca nombre del primer jugador: ";
		cin.getline(nombre_1,50);
		cout << "Introduzca nombre del segundo jugador: ";
		cin.getline(nombre_2,50);

		// Inicializamos los jugadores
		jugador_1.InicializarJugador(nombre_1, 1);
		jugador_2.InicializarJugador(nombre_2, 2);
	}else{
		cout << "Error: Numero de parametros incorrecto." << endl;
		return -1;
	}

	while(!fin_juego && !salvar){

		contador_partidas++;

		// Empezamos el juego
		while(!fin && !salvar){
			// Mete ficha uno
			if(t.GetTurno()==1){
				do{
					metida=jugador_1.escogeColumna(t, salvar,fichas_turno);
					if(salvar)
						Salvar(jugador_1,jugador_2,t,salvar);
				}while(!metida && !salvar);

				if(jugador_1.PuedoPasarTurno(fichas_turno))
					t.PasarTurno();
			}else{
				do{
					metida=jugador_2.escogeColumna(t, salvar, fichas_turno);
					if(salvar)
						Salvar(jugador_1,jugador_2,t,salvar);
				}while(!metida && !salvar);

				if(jugador_2.PuedoPasarTurno(fichas_turno))
					t.PasarTurno();
			}

			fin=t.FinPartida();

		}


		if(!salvar){
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
			cout << jugador_2.GetNombre() << ": " <<  jugador_2.GetGanadas() << " ganadas que acumulan " << jugador_2.GetPuntos() << " puntos.\n\n";


			do{
				cout << "¿Jugar de nuevo(S/N)(G para guardar)?:";
				cin >> opcion;

			}while(opcion!='n' && opcion!='N' && opcion!='s' && opcion!='S' && opcion=='G' && opcion=='g');

			if(opcion=='n' || opcion=='N')
				fin_juego=true;
			else if(opcion=='G' || opcion=='g'){
				salvar=true;
				Salvar(jugador_1,jugador_2,t,salvar);
				fin_juego=true;
			}else{
				cout << endl << endl << "Partida nueva creada." << endl << endl;
			}
		}
	}

			if(fin_juego && !salvar){
				cout << endl << endl << "Resultados finales:\n";
				cout << jugador_1.GetNombre() << ": " <<  jugador_1.GetGanadas() << " ganadas que acumulan " << jugador_1.GetPuntos() << " puntos.\n";
				cout << jugador_2.GetNombre() << ": " <<  jugador_2.GetGanadas() << " ganadas que acumulan " << jugador_2.GetPuntos() << " puntos.\n";
				cout << (contador_partidas-jugador_1.GetGanadas()-jugador_2.GetGanadas()) << " empatadas\n\n";
			}

	return 0;

}
