#include <iostream>
#include <cmath> // sqrt, M_PI
#include "punto.h"
using namespace std;

// Funciones para manejar puntos.

// Lee un punto en el formato (x,y), incluyendo la lectura de '(' ',' y ')'
Punto LeerPunto(istream &is)
{
  Punto a;
  char ignorar;

  is >> ignorar; // (
  is >> a.x;
  is >> ignorar; // ,
  is >> a.y;
  is >> ignorar; // )

  return a;
}

// Escribe un punto en formato (x,y), incluyendo la escritura de '(' ',' y ')'
void EscribirPunto (ostream &os,const Punto &p)
{
  os << '(' << p.x << ',' << p.y << ')';
}

// Inicializa un punto con dos valores cx cy
void InicializarPunto (Punto &p, double cx, double cy)
{
  p.x=cx;
  p.y=cy;
}

// Devuelve la coordenada X del punto p
double GetX (const Punto p)
{
  return p.x;
}

// Devuelve la coordenada Y del punto p
double GetY (const Punto p)
{
  return p.y;
}

// Devuelve la distancia euclídea entre p1 y p2
double Distancia (const Punto &p1, const Punto &p2)
{
  return (sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2)));
}

// Devuelve el punto que está entre p1 y p2 (más cercano a igual distancia de p1 y p2)
Punto PuntoMedio (const Punto &p1, const Punto &p2)
{
  Punto medio;

  medio.x=(p1.x+p2.x)/2;
  medio.y=(p1.y+p2.y)/2;

  return medio;
}
