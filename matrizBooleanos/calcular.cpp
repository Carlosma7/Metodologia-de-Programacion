#include <iostream>
#include <cstdlib>
#include <cstring>
#include "matriz_operaciones.h"

using namespace std;

int main(int argc, char ** argv){
  if(argc<2){
    cout << "Error: Numero de parametros incorrecto." << endl;
    exit(1);
  }else{
    string opcion=argv[1];

    if(opcion=="NOT"){ // Operacion NOT
      MatrizBit matriz, resultado;

      if(argc==3) // Entrada como parametros
        Leer(argv[2], matriz);
      else        // Entrada estándar
        Leer(cin, matriz);

      Not(resultado, matriz);

      Escribir(cout, resultado);

    }else if(opcion=="AND"){ // Operacion AND
      MatrizBit matriz1, matriz2, resultado;

      if(argc==4){ // Entrada como parametros (2 parametros)
        Leer(argv[2], matriz1);
        Leer(argv[3], matriz2);
      }else if(argc==3){ // Entrada como parametros (1 parametro)
        Leer(argv[2], matriz1);
        Leer(cin, matriz2);
      }else{  // Entrada estándar
        Leer(cin, matriz1);
        Leer(cin, matriz2);
      }

      And(resultado, matriz1, matriz2);

      Escribir(cout, resultado);

    }else if(opcion=="OR"){  // Operacion OR
      MatrizBit matriz1, matriz2, resultado;

      if(argc==4){ // Entrada como parametros (2 parametros)
        Leer(argv[2], matriz1);
        Leer(argv[3], matriz2);
      }else if(argc==3){ // Entrada como parametros (1 parametro)
        Leer(argv[2], matriz1);
        Leer(cin, matriz2);
      }else{  // Entrada estándar
        Leer(cin, matriz1);
        Leer(cin, matriz2);
      }

      Or(resultado, matriz1, matriz2);

      Escribir(cout, resultado);

    }else if(opcion=="TRS"){ // Operacion Traspuesta
      MatrizBit matriz, resultado;

      if(argc==3) // Entrada como parametros
        Leer(argv[2], matriz);
      else        // Entrada estándar
        Leer(cin, matriz);

      Traspuesta(resultado, matriz);

      Escribir(cout, resultado);
    }else{
      cout << "Error: Parametro de operacion invalido." << endl;
      exit(1);
    }
  }
}
