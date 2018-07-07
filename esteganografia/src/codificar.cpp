/**
  * @file codificar.cpp
  * @brief Fichero con definiciones para la codificacion de imagenes
  *
  * Permite ocultar y revelar mensajes en una imagen
  *
  */

#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;

void Ocultar(unsigned char * buffer, char * mensaje){
  int p=0;
  char  c;

  for(int i=0; i<strlen(mensaje)+1; i++){
    c=mensaje[i];
    for(int j=7; j>=0;j--){
      if(((1<<j)&c)!=0){
        // Está activo
        buffer[p]=buffer[p]|1;
      }else{
        // Está a cero
        buffer[p]=buffer[p]&~1;
      }
      p++;
    }
  }
}

void Revelar(unsigned char * buffer, char * mensaje){
  char caracter=' ';  // Inicializar para pasar el primer while
  int num_letras=0, p=0;

  while(caracter!='\0'){
    for(int i=0; i<8; i++){
      mensaje[num_letras] = mensaje[num_letras] << 1;
      if((buffer[p]&1)!=0){
        // Está activo
        mensaje[num_letras]=mensaje[num_letras]|1;
      }
      p++;
    }
    caracter=mensaje[num_letras];
    num_letras++;
  }
}
