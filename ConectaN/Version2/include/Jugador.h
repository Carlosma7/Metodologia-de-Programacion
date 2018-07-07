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
		char * nombre;		// Nombre del jugador
		int turno;		// Turno del jugador
		int puntuacion_total;	// Puntuacion total del jugador en el juego
		int partidas_ganadas;	// Partidas ganadas por el jugador
		int fichas_metidas;	// Fichas metidas en el tablero por el jugador

	public:
		/**
		  * @brief Constructor de Jugador
		  *
		  *
		  */
		Jugador();

		/**
		  * @brief Inicializa un jugador con un nomre y turno
		  *
		  * @param nom nombre del jugador
		  * @param turn turno del jugador en la partida
		  *
		  */
		void InicializarJugador(const char* nom, int turn);

		/**
		  * @brief Constructor de Jugador
		  *
		  * @param nom nombre del jugador
		  * @param turn turno del jugador en la partida
		  *
		  */
		Jugador(const char* nom, int turn);

		/**
		  * @brief Destructor de Jugador
		  *
		  */
		~Jugador();

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
		  * @param salvar booleano que comprueba si al meter ficha el jugador lo que quiere es salvar la partida
		  * @param fichas_a_meter numero de fichas a meter por el jugador
		  * @return bool que comprueba si se ha podido meter una ficha
		  *
		  */
		bool escogeColumna(Tablero &t, bool & salvar, int fichas_a_meter);

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

		/**
		  * @brief Comprueba si puede pasar turno el jugador
		  *
		  * @param fichas_a_meter cantidad de fichas que tiene que meter el jugador en el turno
		  * @return bool que comprueba si puede pasar turno el jugador
		  *
		  */
		bool PuedoPasarTurno(int fichas_a_meter);

		/**
		  * @brief Operador de salida de un Jugador
		  *
		  */
		friend std::ostream & operator << (std::ostream & os, const Jugador & j);

		/**
		  * @brief Operador de entrada de un Jugador
		  *
		  */
		friend std::istream & operator >> (std::istream & is, Jugador & j);

};

#endif
