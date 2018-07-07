/**
  * @file revelar.cpp
  * @brief Revela un mensaje oculto en una imagen
  * @author Carlos Morales Aguilera
  *
  * Un ejemplo de ejecución es:
  *   Introduzca la imagen de entrada: salida.ppm
  *   Revelando...
  *   El mensaje obtenido es:
  *   ¡Hola mundo!
  */

#include <iostream>
#include <cstdlib>
#include "codificar.h"
#include "imagenES.h"
using namespace std;

int main()
{
  const int MAXBUFFER= 1000000;
  const int MAXNOMBRE= 100;
  const int MAXMENSAJE=MAXBUFFER/8;
  char nombre_imagen[MAXNOMBRE];
  unsigned char buffer[MAXBUFFER];
  char mensaje[MAXMENSAJE];
  int fila, columna;
  bool exito=false;

  // Lectura del nombre de la imagen de entrada
  cout << "Introduzca la imagen de entrada: ";
  cin.getline(nombre_imagen,100);


  // Comprobamos el tipo de imagen que es
  TipoImagen tipo=LeerTipoImagen(nombre_imagen, fila, columna);
  if(tipo==IMG_PPM)
    exito=LeerImagenPPM (nombre_imagen, fila, columna, buffer);
  else if(tipo==IMG_PGM)
    exito=LeerImagenPGM(nombre_imagen, fila, columna, buffer);
  else{
    cout << endl << endl << "El archivo de imagen no es valido." << endl;
    exit(1);
  }

  // Comprobamos que el archivo se puede abrir correctamente
  if(exito==false){
    cout << endl << endl << "No se puede abrir el archivo." << endl;
    exit(1);
  }

  Revelar(buffer, mensaje);

  // Mostramos el mensaje por pantalla
  cout << endl << endl << "El mensaje obtenido es: ";
  cout << mensaje << endl << endl;
}
