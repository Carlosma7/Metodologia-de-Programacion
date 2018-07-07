bool Inicializar(MatrizBit& m, int fils, int cols){
	m.dimensiones=0;

	m.dimensiones= (fils << 8) | cols;

	for(unsigned int i=0; i < 4; i++)
			m.matriz[i]=0;

	if ((fils*cols)<=128)
		return true;
  else
		return false;

}

int Filas (const MatrizBit& m){
	int filas=(m.dimensiones >> 8);

  return filas;
}

int Columnas(const MatrizBit& m){
	int columnas=(m.dimensiones & 0xFF);

	return columnas;
}
bool Get(const MatrizBit& m, int f, int c){
	int pos=(f*Columnas(m))+c;
	int posicion_vector=pos/32;
	int bit=pos%32;

	if(((1<<bit)&(m.matriz[posicion_vector]))!=0)
		return true;
	else
		return false;
}

void Set(MatrizBit& m, int f, int c, bool v){
	int pos=(f*Columnas(m))+c;
	int posicion_vector=pos/32;
	int bit=pos%32;

	if(((1<<bit)&(m.matriz[posicion_vector]))!=0){
		if(!v)
			m.matriz[posicion_vector]=~(1<<bit)&(m.matriz[posicion_vector]);
	}else
		if(v)
			m.matriz[posicion_vector]=(1<<bit)|m.matriz[posicion_vector];
}
