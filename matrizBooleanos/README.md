# Compilación de ficheros

Para realizar la compilación realizar una orden ***make*** haciendo uso del *Makefile*.

```
make
```

ó

```
make -f makefile
```

# Ejecución

Para realizar operaciones lógicas sobre los ficheros de matrices (*ejemplo1.mat*, *ejemplo2.mat*, *ejemplo3.mat*, *ejemplo4.mat*, *ejemplo5.mat*) es necesario indicar la operación. Existen diferentes formas de operar.

Por ejemplo, con el fichero *ejemplo1.mat*:

```
4 6

0 1 0 1 0 1

0 1 0 0 0 0

0 0 1 0 0 0

0 0 0 1 0 0
```

Podemos realizar las siguientes operaciones:

```
./calcular NOT ejemplo1.mat 
4 6
1 0 1 0 1 0 
1 0 1 1 1 1 
1 1 0 1 1 1 
1 1 1 0 1 1
```

```
./calcular AND ejemplo1.mat ejemplo1.mat 
4 6
0 1 0 1 0 1 
0 1 0 0 0 0 
0 0 1 0 0 0 
0 0 0 1 0 0
```

```
./calcular NOT ejemplo1.mat | ./calcular AND ejemplo1.mat 
4 6
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0
```

```
./calcular NOT ejemplo1.mat | ./calcular OR ejemplo1.mat 
4 6
1 1 1 1 1 1 
1 1 1 1 1 1 
1 1 1 1 1 1 
1 1 1 1 1 1
```
