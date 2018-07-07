#include <iostream>
#include <fstream>
#include "punto.h"
using namespace std;

void Avanzar(std::istream& is)
{
  while (isspace(is.peek()) || is.peek()=='#') {
    if (is.peek()=='#')
      is.ignore(1024,'\n'); // Suponemos que una línea tiene menos de 1024
    else is.ignore();
  }
}

void SumaLongitudPuntos(istream& is,Punto &inicio, double &valor)
{
  Punto final;

  Avanzar(is);

  final=LeerPunto(is);

  valor+=Distancia(inicio,final);

  InicializarPunto(inicio, final.x, final.y);

  Avanzar(is); // Descarta comentarios y para en siguiente dato
}


int main(int argc, char* argv[])
{
  Punto p;
  double longitud=0;
  bool fin_entrada;
  if (argc==1) { // Si no hemos dado parámetros en la línea de órdenes
    cout << "Introduzca la serie de puntos a recorrer (x,y): ";

    while(!cin.eof())
      SumaLongitudPuntos(cin,p,longitud);

    fin_entrada=cin.eof();
  }
  else {
    ifstream f(argv[1]); // Como parámetro, el nombre del archivo
    if (!f) {
      cerr << "Error: no se abre " << argv[1] << endl;
      return 1;
    }

    while(!f.eof())
      SumaLongitudPuntos(f,p,longitud);

    fin_entrada=f.eof();
  }

  if (!fin_entrada) {
     cerr << "Error inesperado. No se ha leído toda la entrada" << endl;
     return 1;
  }

  cout << "\nLa distancia total recorrida es de: " << longitud << ".";
  cout << endl << endl;
}
