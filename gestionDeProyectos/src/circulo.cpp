#include <iostream>
#include <cmath> // sqrt, M_PI
#include "circulo.h"
using namespace std;

// Funciones para manejar circulos.

// Lee círculo en formato radio-centro, incluyendo '-' y leyendo "centro" con LeerPunto
Circulo LeerCirculo(istream &is)
{
  Circulo c;
  char ignorar;

  is >> c.radio;
  is >> ignorar; // -
  c.centro=LeerPunto(is);

  return c;
}

// Escribe círculo en formato radio-centro,  incluyendo '-' y escribiendo "centro" con EscribirPunto
void EscribirCirculo(ostream &os, const Circulo &c)
{
  os << c.radio << '-';
  EscribirPunto(os, c.centro);
}

// Inicializa circulo c con centro y radio
void InicializarCirculo (Circulo& c, const Punto &centro, double radio)
{
  c.centro=centro;
  c.radio=radio;
}

// Devuelve del centro de c
Punto Centro (const Circulo &c)
{
  return c.centro;
}

// Devuelve el radio de c
double Radio (const Circulo &c)
{
  return c.radio;
}

// Devuelve el área del círculo c
double Area (const Circulo &c)
{
  return (3.14*pow(c.radio,2));
}

// Devuelve si p está en el interior del círculo c (distancia al centro menor que el radio)
bool Interior (const Punto &p, const Circulo &c)
{
  bool interior=false;

  if(Distancia(p,c.centro)<c.radio)
    interior=true;

  return interior;
}

// Devuelve la distancia de c1 a c2 (distancia entre los centros restándole los radios)
double Distancia (const Circulo &c1, const Circulo &c2)
{
  double distancia;

  distancia=Distancia(c1.centro,c2.centro)-c1.radio-c2.radio;

  return distancia;
}
