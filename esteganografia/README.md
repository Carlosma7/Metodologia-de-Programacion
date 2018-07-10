
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

## Ocultar

Para ejecutar el programa:

```
./bin/ocultar
```

El programa mediante un algoritmo de modificación de los primeros bits de la imagen seleccionada de formato ***.pgm*** o ***.ppm*** oculta un mensaje invisible en la imagen.

Ejemplo:

```
./bin/ocultar
Introduzca la imagen de entrada: ./imagenes/pajaro.ppm
Introduzca la imagen de salida: ./secreto.ppm
Introduzca el mensaje: github.com/Carlosma7     


Se ha generado la nueva imagen: ./secreto.ppm
```

## Revelar

Para ejecutar el programa:

```
./bin/revelar
```

El programa mediante un algoritmo de modificación de los primeros bits de la imagen seleccionada de formato ***.pgm*** o ***.ppm*** revela un mensaje invisible en la imagen.

Ejemplo:

```
./bin/revelar 
Introduzca la imagen de entrada: ./secreto.ppm


El mensaje obtenido es: github.com/Carlosma7
```
