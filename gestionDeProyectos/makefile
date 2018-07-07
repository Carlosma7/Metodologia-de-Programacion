.PHONY: clean mrproper all

#-----------------------------------------MACROS-------------------------------------#
AR= ar
CXX = g++
CXXFLAGS= -Wall -g -I $(INC)
LDFLAGS= -L$(LIB)
LDLIBS= -lformas
INC= include
SRC= src
OBJ= obj
LIB= lib
BIN= bin

#-----------------------------------EJECUTABLES A GENERAR----------------------------#
all: $(BIN)/central $(BIN)/area	$(BIN)/longitud	$(BIN)/delimitar

#-----------------------------------MODULOS A COMPILAR-------------------------------#
$(OBJ)/punto.o : $(INC)/punto.h $(SRC)/punto.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/punto.o $(SRC)/punto.cpp

$(OBJ)/circulo.o : $(INC)/punto.h $(INC)/circulo.h $(SRC)/circulo.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/circulo.o $(SRC)/circulo.cpp

$(OBJ)/rectangulo.o : $(INC)/punto.h $(INC)/rectangulo.h $(SRC)/rectangulo.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/rectangulo.o $(SRC)/rectangulo.cpp

$(OBJ)/central.o : $(INC)/punto.h $(INC)/circulo.h $(SRC)/central.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/central.o $(SRC)/central.cpp

$(OBJ)/area.o : $(INC)/punto.h $(INC)/circulo.h $(SRC)/central.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/area.o $(SRC)/area.cpp

$(OBJ)/longitud.o : $(INC)/punto.h $(SRC)/longitud.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/longitud.o $(SRC)/longitud.cpp

$(OBJ)/delimitar.o : $(INC)/punto.h $(SRC)/delimitar.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/delimitar.o $(SRC)/delimitar.cpp

#-------------------------------COMPILACION EJECUTABLES------------------------------#
$(BIN)/central : $(OBJ)/central.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/central $(OBJ)/central.o $(LDFLAGS) $(LDLIBS)

$(BIN)/area : $(OBJ)/area.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/area $(OBJ)/area.o $(LDFLAGS) $(LDLIBS)

$(BIN)/longitud : $(OBJ)/longitud.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/longitud $(OBJ)/longitud.o $(LDFLAGS) $(LDLIBS)

$(BIN)/delimitar : $(OBJ)/delimitar.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/delimitar $(OBJ)/delimitar.o $(LDFLAGS) $(LDLIBS)


#------------------------------------LIBRERIAS---------------------------------------#
$(LIB)/libformas.a : $(OBJ)/punto.o $(OBJ)/circulo.o $(OBJ)/rectangulo.o
	$(AR) rvs $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o $(OBJ)/rectangulo.o

#------------------------------------LIMPIEZA----------------------------------------#
clean:
	echo "Limpiando ..."
	-rm $(OBJ)/*.o $(LIB)/lib*.a

mrproper: clean
	-rm $(BIN)/central $(BIN)/area $(BIN)/longitud	$(BIN)/delimitar
