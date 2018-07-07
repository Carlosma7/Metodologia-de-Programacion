#include <iostream>
#include <cmath> // sqrt, M_PI
#include "rectangulo.h"
using namespace std;

// Funciones para manejar circulos.

// Lee rectangulo en formato esquina superior derecha-esquina inferior izquierda,
// incluyendo '-' y leyendo "centro" con LeerPunto
Rectangulo Leer(istream &is,Rectangulo& r){
  char ignorar;
  Punto p;

  p=LeerPunto(is);
  r.esquina_inf_izq=p;

  is >> ignorar; // -

  p=LeerPunto(is);
  r.esquina_sup_der=p;

  return r;
}

// Escribe rectangulo en formato esquina inferior izquierda-esquina superior derecha
bool Escribir(ostream& os, const Rectangulo& r){
  EscribirPunto(os, r.esquina_inf_izq);

  os << "-";

  EscribirPunto(os, r.esquina_sup_der);

  return os;
}

// Inicializa un rectangulo pasandole las dos esquinas que posee.
void InicializarRectangulo (Rectangulo& r, const Punto& p1, const Punto& p2){
  if(p1.x>p2.x)
    if(p1.y>p2.y){ // p1 esquina superior derecha y p2 esquina inferior izquierda
      r.esquina_sup_der=p1;
      r.esquina_inf_izq=p2;
    }else{         // p1 esquina inferior derecha y p2 esquina superior izquierda
      Punto aux1,aux2;

      InicializarPunto(aux1, p1.x, p2.y);
      InicializarPunto(aux2, p2.x, p1.y);

      r.esquina_sup_der=aux1;
      r.esquina_inf_izq=aux2;
    }
  else
    if(p1.y>p2.y){  // p1 esquina superior izquierda y p2 esquina inferior derecha
      Punto aux1,aux2;

      InicializarPunto(aux1, p2.x, p1.y);
      InicializarPunto(aux2, p1.x, p2.y);

      r.esquina_sup_der=aux1;
      r.esquina_inf_izq=aux2;
    }else{  // p1 esquina inferior izquierda y p2 esquina superior derecha
      r.esquina_sup_der=p2;
      r.esquina_inf_izq=p1;
    }


}

// Devuelve el Punto de la esquina inferior izquierda
Punto InferiorIzquierda (const Rectangulo& r){
  return r.esquina_inf_izq;
}

// Devuelve el Punto de la esquina superior derecha
Punto SuperiorDerecha (const Rectangulo& r){
  return r.esquina_sup_der;
}

// Devuelve el Área del rectángulo pasado como parámetro
double Area(const Rectangulo& r){
  double area;
  Punto p1,p2;

  InicializarPunto(p1, r.esquina_inf_izq.x, r.esquina_sup_der.y);
  InicializarPunto(p2, r.esquina_sup_der.x, r.esquina_inf_izq.y);

  area=(Distancia(r.esquina_inf_izq, p1)*Distancia(r.esquina_inf_izq,p2));

  return area;
}

// Comprueba si un punto está contenido en un rectángulo
bool Interior (const Punto& p, const Rectangulo& r){
  bool interior=false;

  if((p.x<=(SuperiorDerecha(r)).x) && (p.x>=(InferiorIzquierda(r)).x) && (p.y<=(SuperiorDerecha(r)).y) && (p.y>=(InferiorIzquierda(r)).y))
    interior=true;

  return interior;
}
