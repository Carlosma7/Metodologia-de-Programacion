bool Inicializar(MatrizBit& m, int fils, int cols){
  m.filas=fils;
  m.columnas=cols;
  int p=0;

  for(int i=0; i < fils; i++)
    for(int j=0; j < cols; j++){
      m.vector[p]=false;
      p++;
    }

  if((fils*cols)<100)
    return true;
  else
    return false;
}

int Filas (const MatrizBit& m){
  return m.filas;
}

int Columnas( const MatrizBit& m){
  return m.columnas;
}

bool Get(const MatrizBit& m, int f, int c){
  int pos=1+c+(f*Columnas(m));

  return m.vector[pos];
}

void Set(MatrizBit& m, int f, int c, bool v){
  int pos=1+c+(f*Columnas(m));

  m.vector[pos]=v;
}
