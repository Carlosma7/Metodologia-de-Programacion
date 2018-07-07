#include <iostream>
#include <fstream>
#include "rectangulo.h"
using namespace std;

void Avanzar(std::istream& is)
{
  while (isspace(is.peek()) || is.peek()=='#') {
    if (is.peek()=='#')
      is.ignore(1024,'\n'); // Suponemos una línea tiene menos de 1024
    else is.ignore();
  }
}

Rectangulo BoundingBox(istream& is)
{
  Rectangulo box;
  Punto primero, aux;

  Avanzar(is);
  primero=LeerPunto(is);

  // Inicializamos al primero punto
  InicializarRectangulo(box,primero,primero);

  while(!is.eof()){

    Avanzar(is);

    aux=LeerPunto(is);

    if(aux.x<InferiorIzquierda(box).x)
      box.esquina_inf_izq.x=aux.x;

    if(aux.y<InferiorIzquierda(box).y)
      box.esquina_inf_izq.y=aux.y;

    if(aux.x>SuperiorDerecha(box).x)
      box.esquina_sup_der.x=aux.x;

    if(aux.y>SuperiorDerecha(box).y)
      box.esquina_sup_der.y=aux.y;

  }

  return box;
}


int main(int argc, char* argv[])
{
  Rectangulo delimitador;
  if (argc==1) { // Si no hemos dado parámetros en la línea de órdenes
    cout << "Introduzca la serie de puntos a contener (x,y): ";

    while(!cin.eof())
      delimitador=BoundingBox(cin);
  }
  else {
    ifstream f(argv[1]); // Como parámetro, el nombre del archivo
    if (!f) {
      cerr << "Error: no se abre " << argv[1] << endl;
      return 1;
    }

    while(!f.eof())
      delimitador=BoundingBox(f);
  }


  cout << "\nEl rectangulo final es: ";
  Escribir(cout, delimitador);
  cout << endl << endl;
}
