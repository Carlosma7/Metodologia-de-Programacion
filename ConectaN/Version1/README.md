
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

Para ejecutar el programa:

```
./bin/conectaN

```



Ejemplo:

```
./bin/conectaN 
Introduzca filas: 4
Introduzca columnas: 4
Introduzca fichas a alinear (3-5): 3
Introduzca nombre del primer jugador: Carlos
Introduzca nombre del segundo jugador: Juan
 a b c d 
| | | | |
| | | | |
| | | | |
| | | | |
=========
Turno: Juan: (o)
Juan, escoja una columna (letra a-d):
 a b c d 
| | | | |
| | | | |
| | | | |
|o| | | |
=========
Turno: Carlos: (x)
Carlos, escoja una columna (letra a-d): d
 a b c d 
| | | | |
| | | | |
| | | | |
|o| | |x|
=========
Turno: Juan: (o)
Juan, escoja una columna (letra a-d): 
```

Al finalizar la partida se muestra el resultado de la misma y si se desea jugar otra partida, en caso de negarlo se muestran los resultados finales de todas las partidas.

```
Resultados tras esta partida:
Carlos: 0 ganadas que acumulan 0 puntos.
Juan: 1 ganadas que acumulan 53 puntos.
¿Jugar de nuevo(S/N)?:N


Resultados finales:
Carlos: 0 ganadas que acumulan 0 puntos.
Juan: 1 ganadas que acumulan 53 puntos.
0 empatadas
```
