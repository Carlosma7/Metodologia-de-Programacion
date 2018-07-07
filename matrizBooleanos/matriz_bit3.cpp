bool Inicializar(MatrizBit& m, int fils, int cols){
  m.dimensiones=0;

  m.dimensiones= (fils << 16) | cols;

  for(int i=0; i < (fils*cols); i++)
      m.vector[i]='0';

  if((fils*cols)<100)
    return true;
  else
    return false;
}

int Filas (const MatrizBit& m){
  int filas=(m.dimensiones >> 16);

  return filas;
}

int Columnas(const MatrizBit& m){
  int columnas=(m.dimensiones & 0xFFFF);

  return columnas;
}

bool Get(const MatrizBit& m, int f, int c){
  int pos=(f*Columnas(m))+c;

  if(m.vector[pos]=='1')
    return true;
  else
    return false;
}

void Set(MatrizBit& m, int f, int c, bool v){
  int pos=(f*Columnas(m))+c;

  if(v)
    m.vector[pos]='1';
  else
    m.vector[pos]='0';
}
