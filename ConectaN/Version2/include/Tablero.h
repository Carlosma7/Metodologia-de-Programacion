/**
  * @file Tablero.h
  * @brief Fichero con definiciones para la creación y uso de un tablero de conectaN
  *
  */

#ifndef __TABLERO__H
#define __TABLERO__H

#include "Matriz.h"

class Tablero{
	private:
		Matriz matriz;			// Matriz en la que insertar los datos internos del tablero
		int N;				// Numero de fichas que conectar
		int fichas_turno;		// Fichas que meter por turno
		bool partida_finalizada;	// Comprueba si el tablero esta finalizado
		int turno_actual;		// Turno actual del tablero
		int ganador;			// Ganador del tablero

	public:
		/**
		  * @brief Constructor de Tablero
		  *
		  *
		  */
		Tablero();

		/**
		  * @brief Inicializa un tablero
		  *
		  * @param filas filas del tablero
		  * @param columnas columnas del tablero
		  * @param n_linea cantidad de fichas a conectar
		  * @param fichas fichas a meter por turno
		  *
		  */
		void InicializarTablero(int filas, int columnas, int n_linea, int fichas);

		/**
		  * @brief Obtiene las filas del tablero
		  *
		  * @return int con las filas del tablero
		  *
		  */
		int GetFilasTablero()const;

		/**
		  * @brief Obtiene las columnas del tablero
		  *
		  * @return int con las columnas del tablero
		  *
		  */
		int GetColumnasTablero()const;

		/**
		  * @brief Obtiene las fichas a conectar en el tablero
		  *
		  * @return int con las fichas a conectar
		  *
		  */
		int GetN();

		/**
		  * @brief Obtiene el elemento en una posicion
		  *
		  * @param fils fila de la casilla
		  * @param cols columna de la casilla
		  * @return int con el valor de la casilla
		  *
		  */
		int GetPosicion(int fils, int cols);

		/**
		  * @brief Comprueba si se ha llegado al fin de la partida
		  *
		  * @return bool que comprueba si es el fin de partida
		  *
		  */
		bool FinPartida();

		/**
		  * @brief Obtiene el turno actual del tablero
		  *
		  * @return int con el turno del tablero
		  *
		  */
		int GetTurno();

		/**
		  * @brief Obtiene el ganador de la partida
		  *
		  * @return int con el ganador de la partida, sino devuelve 0
		  *
		  */
		int GetGanador();

		/**
		  * @brief Evalúa la partida y da una puntuación
		  *
		  * @return int con la puntuación de la partida
		  *
		  */
		int Puntuacion() const;

		/**
		  * @brief Comprueba si el tablero esta con la partida finalizada
		  *
		  * @param fil fila en la que empezar a comprobar
		  * @param col columna en la que empezar a comprobar
		  * @return bool que indica si es el fin de partida
		  *
		  */
		bool ComprobarFinPartida(int fil, int col);

		/**
		  * @brief Intenta meter una ficha en una columna y comprueba que se ha podido o no
		  *
		  * @param columna columna en la que insertar la ficha
		  * @return bool que indica si se ha insertado la ficha
		  *
		  */
		bool MeterFicha(int columna);

		/**
		  * @brief Vacia un tablero y lo inicializa al estado inicial
		  *
		  *
		  */
		void VaciarTablero();

		/**
		  * @brief Pinta un tablero con el formato de conectaN
		  *
		  * @param os flujo de salida (por defecto cout)
		  *
		  */
		void prettyPrint(std::ostream & os=std::cout)const;

		/**
		  * @brief Pasa el turno del tablero
		  *
		  *
		  */
		void PasarTurno();

		/**
		  * @brief Comprueba si el tablero esta completo
		  *
		  * @return bool que indica si el tablero esta completo
		  *
		  */
		bool Completo();

		/**
		  * @brief Sobrecarga operador de salida de un Tablero
		  *
		  */
		friend std::ostream & operator << (std::ostream & os, const Tablero & t);

		/**
		  * @brief Sobrecarga operador de entrada de un Tablero
		  *
		  */
		friend std::istream & operator >> (std::istream & is, Tablero & t);

};

#endif
