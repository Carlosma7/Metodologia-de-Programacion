
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

En este caso, podremos indicar que juegue la máquina poniendo el carácter ***@*** antes del nombre del jugador. Además, podremos indicar que se coloquen varias fichas por turno de un jugador.

Ejemplo:

```
./bin/conectaN 
Introduzca filas: 4
Introduzca columnas: 4
Introduzca fichas a alinear (3-5): 4
Introduzca fichas por turno (1-4): 2
Introduzca nombre del primer jugador: Carlos
Introduzca nombre del segundo jugador: @Juan
 a b c d 
| | | | |
| | | | |
| | | | |
| | | | |
=========
Turno: Carlos: (x)
Carlos, escoja una columna (letra a-d) para la ficha 1 de 2: 

```

Al finalizar la partida se muestra el resultado de la misma y si se desea jugar otra partida, en caso de negarlo se muestran los resultados finales de todas las partidas.

Además, podremos indicar que se guarde la partida para continuar con ella más tarde.

```
Resultados tras esta partida:
Carlos: 1 ganadas que acumulan 78 puntos.
@Juan: 0 ganadas que acumulan 0 puntos.

¿Jugar de nuevo(S/N)(G para guardar)?:N


Resultados finales:
Carlos: 1 ganadas que acumulan 78 puntos.
@Juan: 0 ganadas que acumulan 0 puntos.
0 empatadas
```
