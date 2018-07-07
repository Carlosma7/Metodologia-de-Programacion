/**
  * @file Jugador.h
  * @brief Fichero con definiciones para la creación y uso de un jugador
  *
  */

#ifndef __JUGADOR__H
#define __JUGADOR__H

#include "Tablero.h"

class Jugador{
	private:
		char nombre[50];	// Nombre del jugador
		int turno;		// Turno del jugador
		int puntuacion_total;	// Puntuacion total del jugador en el juego
		int partidas_ganadas;	// Partidas ganadas por el jugador

	public:
		/**
		  * @brief Constructor de Jugador
		  *
		  * @param nom nombre del jugador
		  * @param turn turno del jugador en la partida
		  *
		  */
		Jugador(const char* nom, int turn);

		/**
		  * @brief Obtiene el nombre del jugador
		  *
		  * @return const char* con el contenido del nombre
		  *
		  */
		const char* GetNombre() const;

		/**
		  * @brief Escoge una columna e intenta insertar en ella
		  *
		  * @param t tablero en el que intentar introducir una columna
		  *
		  */
		void escogeColumna(Tablero &t);

		/**
		  * @brief Añade puntos a la puntuacion total del jugador
		  *
		  * @param puntos puntos que se le suman al jugador
		  *
		  */
		void SumarPuntos(int puntos);

		/**
		  * @brief Obtiene los puntos del jugador
		  *
		  * @return int con los puntos totales del jugador
		  *
		  */
		int GetPuntos();

		/**
		  * @brief Comprueba si el jugador ha ganado la partida para sumar puntos y partidas ganadas
		  *
		  *
		  */
		void GanaPartida();

		/**
		  * @brief Obtiene las partidas ganadas del jugador
		  *
		  * @return int con las partidas ganadas del jugador
		  *
		  */
		int GetGanadas();

};

#endif
