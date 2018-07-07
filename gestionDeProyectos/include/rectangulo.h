#ifndef _RECTANGULO_H_
#define _RECTANGULO_H_

#include "punto.h"
#include <iostream>

// Definimos tipo Rectangulo.

struct Rectangulo {
    Punto esquina_sup_der, esquina_inf_izq;
};

// Funciones para manejar rectangulos.


// Lee rectangulo en formato esquina superior derecha-esquina inferior izquierda,
// incluyendo '-' y leyendo "centro" con LeerPunto
Rectangulo Leer(std::istream &is,Rectangulo& r);

// Escribe rectangulo en formato esquina inferior izquierda-esquina superior derecha
bool Escribir(std::ostream& os, const Rectangulo& r);

// Inicializa un rectangulo pasandole las dos esquinas que posee.
void InicializarRectangulo (Rectangulo& r, const Punto& p1, const Punto& p2);

// Devuelve el Punto de la esquina inferior izquierda
Punto InferiorIzquierda (const Rectangulo& r);

// Devuelve el Punto de la esquina superior derecha
Punto SuperiorDerecha (const Rectangulo& r);

// Devuelve el Área del rectángulo pasado como parámetro
double Area(const Rectangulo& r);

// Comprueba si un punto está contenido en un rectángulo
bool Interior (const Punto& p, const Rectangulo& r);

#endif
