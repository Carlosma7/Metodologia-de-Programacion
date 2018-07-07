/**
  * @file Matriz.h
  * @brief Fichero con definiciones para la creación y uso de una matriz
  *
  */

#ifndef __MATRIZ__H
#define __MATRIZ__H

class Matriz{
	private:
		int datos[20][20];	// Representacion interna en una matriz
		int filas,columnas;	// Filas y columnas de la matriz

	public:
		/**
		  * @brief Constructor de Matriz
		  *
		  */
		Matriz(){
			filas=0;
			columnas=0;
		}

		/**
		  * @brief Inicializa una matriz al tamaño proporcionado y rellena de 0
		  *
		  * @param fils filas de la matriz
		  * @param cols columnas de la matriz
		  *
		  */
		void cambiarMatriz(int fils, int cols){
			filas=fils;
			columnas=cols;

			for(int i=0; i<filas; i++)
				for(int j=0; j<columnas; j++)
					datos[i][j]=0;

		}

		/**
		  * @brief Obtiene las filas de la matriz
		  *
		  * @return int con las filas de la matriz
		  *
		  */
		int GetFilas(){
			return filas;
		}

		/**
		  * @brief Obtiene las columnas de la matriz
		  *
		  * @return int con las columnas de la matriz
		  *
		  */
		int GetColumnas(){
			return columnas;
		}

		/**
		  * @brief Obtiene el elemento en una posicion
		  *
		  * @param fils fila de la casilla
		  * @param cols columna de la casilla
		  * @return int con el valor de la casilla
		  *
		  */
		int GetElemento(int fils, int cols){
			return datos[fils][cols];
		}

		/**
		  * @brief Modifica el valor de una casilla
		  *
		  * @param fils fila de la casilla
		  * @param cols columna de la casilla
		  * @param valor valor a introducir en la casilla
		  *
		  */
		void SetElemento(int fils, int cols, int valor){
			datos[fils][cols]=valor;
		}

};

#endif
