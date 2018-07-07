#include <iostream>
#include "circulo.h"
#include "punto.h"
using namespace std;

int main()
{
  Circulo c1;

  cout << "Introduzca un circulo en formato radio-(x,y): ";
  c1= LeerCirculo(cin);

  int area=Area(c1);
  cout << "El area del circulo es: " << area << ".";
  cout << endl;
}
