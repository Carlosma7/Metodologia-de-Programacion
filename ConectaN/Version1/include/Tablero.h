/**
  * @file Tablero.h
  * @brief Fichero con definiciones para la creación y uso de un tablero de conectaN
  *
  */

#ifndef __TABLERO__H
#define __TABLERO__H

#include "Matriz.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Tablero{
	private:
		Matriz matriz;			// Matriz en la que insertar los datos internos del tablero
		int N;				// Numero de fichas que conectar
		bool partida_finalizada;	// Comprueba si el tablero esta finalizado
		int turno_actual;		// Turno actual del tablero
		int ganador;			// Ganador del tablero

	public:
		/**
		  * @brief Constructor de Tablero
		  *
		  * @param filas filas del tablero
		  * @param columnas columnas del tablero
		  * @param n_linea cantidad de fichas a conectar
		  *
		  */
		Tablero(int filas, int columnas, int n_linea);

		/**
		  * @brief Obtiene las filas del tablero
		  *
		  * @return int con las filas del tablero
		  *
		  */
		int GetFilasTablero();

		/**
		  * @brief Obtiene las columnas del tablero
		  *
		  * @return int con las columnas del tablero
		  *
		  */
		int GetColumnasTablero();

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
		int Puntuacion();

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
		  *
		  */
		void prettyPrint();

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

};

#endif
