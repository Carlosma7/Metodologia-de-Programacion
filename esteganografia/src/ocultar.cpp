/**
  * @file ocultar.cpp
  * @brief Oculta un mensaje en una imagen
  * @author Carlos Morales Aguilera
  *
  * Un ejemplo de ejecución es:
  *   Introduzca la imagen de entrada: original.ppm
  *   Introduzca la imagen de salida: salida
  *   Introduzca el mensaje: ¡Hola mundo!
  */

#include <iostream>
#include "codificar.h"
#include "imagenES.h"
#include <cstdlib>
using namespace std;

int main()
{
  const int MAXBUFFER= 1000000;
  const int MAXNOMBRE= 100;
  const int MAXMENSAJE=MAXBUFFER/8;
  char nombre_imagen[MAXNOMBRE];
  char nombre_imagen_salida[MAXNOMBRE];
  unsigned char buffer[MAXBUFFER];
  char mensaje[MAXMENSAJE];
  int filas,columnas;
  bool exito=false;

  // Lectura del nombre de la imagen de entrada
  cout << "Introduzca la imagen de entrada: ";
  cin.getline(nombre_imagen,100);
  // Lectura del nombre de la imagen de entrada
  cout << "Introduzca la imagen de salida: ";
  cin.getline(nombre_imagen_salida,100);
  // Lectura del mensaje a ocultar
  cout << "Introduzca el mensaje: ";
  cin.getline(mensaje,100);


  // Comprobamos el tipo de imagen que es
  TipoImagen tipo=LeerTipoImagen(nombre_imagen, filas, columnas);
  if(tipo==IMG_PPM){
    exito=LeerImagenPPM (nombre_imagen, filas, columnas, buffer);
  }else if(tipo==IMG_PGM){
    exito=LeerImagenPGM(nombre_imagen, filas, columnas, buffer);
  }else{
    cout << "El archivo de imagen no es valido." << endl;
    exit(1);
  }

  // Comprobamos que el archivo se puede abrir correctamente
  if(exito==false){
    cout << endl << endl << "No se puede abrir el archivo." << endl;
    exit(1);
  }

  // Ocultamos el mensaje
  Ocultar(buffer, mensaje);

  // Guardamos la nueva imagen
  if(tipo==IMG_PPM)
    exito=EscribirImagenPPM (nombre_imagen_salida, buffer, filas, columnas);
  else if(tipo==IMG_PGM)
    exito=EscribirImagenPGM (nombre_imagen_salida, buffer, filas, columnas);

  // Comprobamos que el archivo se puede escribir correctamente
  if(exito==false){
    cout << endl << endl << "No se puede escribir el archivo." << endl;
    exit(1);
  }else
    cout << endl << endl << "Se ha generado la nueva imagen: " << nombre_imagen_salida << endl << endl;

}
