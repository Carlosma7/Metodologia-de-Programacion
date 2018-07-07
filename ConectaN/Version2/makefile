
#-----------------------------------------MACROS-------------------------------------#
AR = ar
CXX = g++ -Wall -Wextra -pedantic
LDFLAGS= -L$(LIB)
LDLIBS= -lconectaN
INC= include
SRC= src
OBJ= obj
LIB= lib
BIN= bin

#-----------------------------------EJECUTABLES A GENERAR----------------------------#
all: $(BIN)/conectaN

#--------------------------------GENERACION DE DOCUMENTACIÓN-------------------------#
documentacion:
	doxygen doc/doxys/Doxyfile

#-----------------------------------MODULOS A COMPILAR-------------------------------#
$(OBJ)/Matriz.o : $(INC)/Matriz.h $(SRC)/Matriz.cpp
	$(CXX) -c -o $(OBJ)/Matriz.o $(SRC)/Matriz.cpp -I $(INC)

$(OBJ)/Tablero.o : $(INC)/Matriz.h $(INC)/Tablero.h $(SRC)/Tablero.cpp
	$(CXX) -c -o $(OBJ)/Tablero.o $(SRC)/Tablero.cpp -I $(INC)

$(OBJ)/Jugador.o : $(INC)/Tablero.h $(INC)/Jugador.h $(SRC)/Jugador.cpp
	$(CXX) -c -o $(OBJ)/Jugador.o $(SRC)/Jugador.cpp -I $(INC)

$(OBJ)/conectaN.o : $(INC)/Tablero.h $(INC)/Jugador.h $(SRC)/conectaN.cpp
	$(CXX) -c -o $(OBJ)/conectaN.o $(SRC)/conectaN.cpp -I $(INC)

#-------------------------------COMPILACION EJECUTABLES------------------------------#
$(BIN)/conectaN : $(OBJ)/conectaN.o $(LIB)/libconectaN.a
	$(CXX) -o $(BIN)/conectaN $(OBJ)/conectaN.o $(LDFLAGS) $(LDLIBS)


#------------------------------------LIBRERIAS---------------------------------------#
$(LIB)/libconectaN.a : $(OBJ)/Matriz.o $(OBJ)/Tablero.o $(OBJ)/Jugador.o
	$(AR) rvs $(LIB)/libconectaN.a $(OBJ)/Matriz.o $(OBJ)/Tablero.o $(OBJ)/Jugador.o

#------------------------------------LIMPIEZA----------------------------------------#
clean:
	echo "Limpiando ..."
	-rm $(OBJ)/*.o $(LIB)/lib*.a

mrproper: clean
	-rm $(BIN)/conectaN
