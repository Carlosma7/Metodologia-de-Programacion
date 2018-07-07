#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_

/**
  * @brief Permite ocultar un mensaje en una imagen
  *
  * @param buffer indica la cadena que contiene los pixeles de la imagen
  * @param tam_imagen tamaño de la imagen para comprobar si se puede introducir el mensaje
  * @param mensaje indicia la cadena a ocultar en la imagen
  * @return bool que comprueba si se ha podido ocultar el mensaje en la imagen
  *
  */
  void Ocultar(unsigned char * buffer, char * mensaje);

  /**
    * @brief Permite revelar un mensaje de una imagen
    *
    * @param nombre indica el nombre del archivo de disco a consultar
    *
    */
    void Revelar(unsigned char * buffer, char * mensaje);

#endif
