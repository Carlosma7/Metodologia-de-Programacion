# Compilación de ficheros
## Pasos previos

Para poder realizar la compilación y generación de ejecutable es necesario crear los siguientes directorios: ***lib***, ***obj*** y ***bin***.

```
mkdir -p lib obj bin
```

## Compilación

Para realizar la compilación realizar una orden ***make*** haciendo uso del *Makefile*.

```
make
```

ó

```
make -f makefile
```

# Ejecución

## Area

Para ejecutar el programa:

```
./bin/area
```

El programa calcula el área de un círculo dado un radio y unas coordenadas en el formato *radio-(x,y)*.

Ejemplo:

```
Introduzca un circulo en formato radio-(x,y): 5-(1,2)   
El area del circulo es: 78.
```

## Central

Para ejecutar el programa

```
./bin/central
```

El programa calcula el círculo que pasa por los centros de dos círculos indicados mediante el formato *radio-(x,y)*.

Ejemplo:

```
Introduzca un circulo en formato radio-(x,y): 5-(1,2)                
Introduzca otro circulo: 3-(3,3)
El círculo que pasa por los dos centros es: 1.11803-(2,2.5)
```

## Delimitar

Para ejecutar el programa

```
./bin/delimitar ejemplo.pts
```

El programa calcula las esquinas opuestas de un rectángulo que contiene todos los puntos indicados dentro del fichero *ejemplo.pts*.

Ejemplo:

```
El rectangulo final es: (1.11254e-308,1)-(3,4.103e+181)
```

## Longitud


Para ejecutar el programa

```
./bin/longitud ejemplo.pts
```

El programa calcula la distancia total recorrida por todos los puntos que contiene el fichero *ejemplo.pts*.

Ejemplo:

```
La distancia total recorrida es de: 4.24264.
```
