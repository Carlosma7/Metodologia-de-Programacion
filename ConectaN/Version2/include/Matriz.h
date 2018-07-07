/**
  * @file Matriz.h
  * @brief Fichero con definiciones para la creación y uso de una matriz
  *
  */

#ifndef __MATRIZ__H
#define __MATRIZ__H

#include <iostream>

class Matriz{
	private:
		int *datos;		// Representacion interna en un vector dinamico
		int filas,columnas;	// Filas y columnas de la matriz

	public:
		/**
		  * @brief Constructor de Matriz
		  *
		  */
		Matriz(){
			filas=0;
			columnas=0;
			datos=0;
		}

		/**
		  * @brief Constructor de copia de un objeto Matriz
		  *
		  * @param m matriz de la que copiar los datos
		  */
		Matriz(const Matriz & m){
			filas=m.GetFilas();
			columnas=m.GetColumnas();

			if(filas==0 || columnas==0)
				datos=0;
			else{
				datos=new int[filas*columnas];
				for(int i=0; i<filas; i++)
					for(int j=0; j<columnas; j++)
						SetElemento(i,j,m.GetElemento(i,j));
			}
		}

		/**
		  * @brief Destructor de Matriz
		  *
		  */
		~Matriz(){
			if(datos!=0)
				delete [] datos;
		}

		/**
		  * @brief Sobrecarga operador de asignacion de una matriz a otra
		  *
		  * @param m matriz de la que copiar los datos
		  */
		Matriz & operator =(const Matriz & m){
			if(&m!=this){
				if(datos!=0)
					delete [] datos;

				filas=m.GetFilas();
				columnas=m.GetColumnas();

				if(filas==0 || columnas==0)
					datos=0;
				else{
					datos=new int[filas*columnas];
					for(int i=0; i<filas; i++)
						for(int j=0; j<columnas; j++)
							SetElemento(i,j,m.GetElemento(i,j));
				}
			}

			return *this;
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

			if(fils==0 || cols==0)
				datos=0;
			else{
				datos=new int[fils*cols];
				for(int i=0; i<filas; i++)
					for(int j=0; j<columnas; j++)
						SetElemento(i,j,0);
			}
		}

		/**
		  * @brief Obtiene las filas de la matriz
		  *
		  * @return int con las filas de la matriz
		  *
		  */
		int GetFilas() const{
			return filas;
		}

		/**
		  * @brief Obtiene las columnas de la matriz
		  *
		  * @return int con las columnas de la matriz
		  *
		  */
		int GetColumnas() const{
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
		int GetElemento(int fils, int cols) const{
			int pos=cols+(fils*columnas);
			return datos[pos];
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
			int pos=cols+(fils*columnas);
			datos[pos]=valor;
		}

		/**
		  * @brief Sobrecarga operador de salida del tipo Matriz
		  *
		  *
		  */
		friend std::ostream & operator << (std::ostream & os, const Matriz & j);

		/**
		  * @brief Sobrecarga operador de entrada del tipo Matriz
		  *
		  *
		  */
		friend std::istream & operator >> (std::istream & is, Matriz & j);

};



#endif
