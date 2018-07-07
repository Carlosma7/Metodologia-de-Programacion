#include "matriz_operaciones.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

bool Leer(std::istream& is, MatrizBit& m){
  int filas=0, columnas=0;
  bool formato_especial=false;
  bool lectura_correcta=true;

  if(is.peek()=='X' || is.peek()=='.')
    formato_especial=true;

  if(formato_especial){  // Formato de X y .
    char todo[1024];
    char linea[100];

    is.getline(todo,1024);
    columnas=strlen(todo);
    filas++;

    while(is.peek()=='X' || is.peek()=='.'){
      is.getline(linea,100);
      strcat(todo,linea);
      filas++;
    }


    lectura_correcta=Inicializar(m,filas,columnas);

    int pos=0;

    for(int i=0; i<filas; i++){
      for(int j=0; j<columnas;j++){
        if(todo[pos]=='X')
          Set(m,i,j,true);
        else if(todo[pos]=='.')
          Set(m,i,j,false);
        else
          return false;

        pos++;
      }
    }

  }else{  // Formato de 0 y 1
    is >> filas;
    is >> columnas;

    lectura_correcta=Inicializar(m,filas, columnas);

    bool valor_b;

    for(int i=0; i<filas; i++)
      for(int j=0; j<columnas; j++){
        is >> valor_b;
        Set(m, i, j, valor_b);
      }
  }


    return lectura_correcta;
}

bool Escribir(std::ostream& os, const MatrizBit& m){
  os << Filas(m) << " " << Columnas(m) << std::endl;
  for(int i=0; i<Filas(m); i++){
    for(int j=0; j<Columnas(m);j++)
      os << Get(m,i,j) << " ";

    os << std::endl;
  }

  return true;
}

bool Leer(const char nombre[], MatrizBit& m){
  std::ifstream fi(nombre, std::ifstream::in);
  bool lectura;

  lectura = Leer(fi, m);

  return lectura;
}

bool Escribir(const char nombre[], const MatrizBit& m){
  std::ofstream fo(nombre, std::ifstream::out);
  bool escritura;

  escritura = Escribir(fo, m);

  return escritura;
}

void And(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2){
  bool inicializar_correcto=true;

  inicializar_correcto=Inicializar(res, Filas(m1), Columnas(m1));

  if(!inicializar_correcto){
    std::cout << "La matriz AND no se inicializo correctamente." << std::endl;
    exit(1);
  }


  for(int i=0; i <Filas(m1); i++)
    for(int j=0; j <Columnas(m1); j++)
      Set(res,i,j,(Get(m1,i,j) & Get(m2,i,j)));
}

void Or(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2){
  bool inicializar_correcto=true;

  inicializar_correcto=Inicializar(res, Filas(m1), Columnas(m1));

  if(!inicializar_correcto){
    std::cout << "La matriz OR no se inicializo correctamente." << std::endl;
    exit(1);
  }

  for(int i=0; i <Filas(m1); i++)
    for(int j=0; j <Columnas(m1); j++)
      Set(res,i,j,(Get(m1,i,j) | Get(m2,i,j)));

}

void Not(MatrizBit& res, const MatrizBit& m){
  bool inicializar_correcto=true;

  inicializar_correcto=Inicializar(res, Filas(m), Columnas(m));

  if(!inicializar_correcto){
    std::cout << "La matriz NOT no se inicializo correctamente." << std::endl;
    exit(1);
  }

  for(int i=0; i <Filas(m); i++)
    for(int j=0; j <Columnas(m); j++)
      if(Get(m,i,j) ==true)
        Set(res,i,j,false);
      else
        Set(res,i,j,true);
}

void Traspuesta(MatrizBit& res, const MatrizBit& m){
  bool inicializar_correcto=true;

  inicializar_correcto=Inicializar(res, Columnas(m), Filas(m));

  if(!inicializar_correcto){
    std::cout << "La matriz Traspuesta no se inicializo correctamente." << std::endl;
    exit(1);
  }

  for(int i=0; i <Filas(m); i++)
    for(int j=0; j <Columnas(m); j++)
      Set(res,i,j,Get(m, j, i));
}
