

class Vehiculos{
	private:
		int* origen;
		int* final;
		int prioridad;
		int patente;
		int contador;
		int camino[30];
		int contadorcamino;
		bool pase;
		bool ter;
		
	public:
		Vehiculos(){
		contadorcamino=0;
		origen=0;
		final=0;
		prioridad=0;
		patente=0;
		pase =false;
		ter=false;
		contador = 0;
			for (int i = 0; i<30; i++){
				camino[i] = 0;
			}
		}
		void set_origen(int*);
		void set_final (int*);
		void set_prioridad(int);
		void set_patente(int);
		int* get_origen();
		int* get_final();
		int get_patente();
		int get_prioridad();
		void ingresarCamino(int, int);
		int get_camino(int);
		int avanzar();
		void set_camino(int);
		void set_camino1(int, int);
		int tamcamino();
		void avanzarcamino();
		void activarPase();
		void desactivarPase();
		bool getPase();
		bool getTermine();
		void borrarcamino();
};

bool Vehiculos::getPase(){
	return pase;
}
void Vehiculos::activarPase(){
	pase=true;
}

void Vehiculos::desactivarPase(){
	pase=false;
}

bool Vehiculos::getTermine(){

	return ter;
}
void Vehiculos::avanzarcamino(){
	for(int i=0;i<contadorcamino;i++){
		camino[i]=camino[i+1];
		if(i==contadorcamino-1){
			camino[i]=0;
		}
		
		if(camino[0]==0){
			ter=true;
		}
	}
	
}
int Vehiculos::tamcamino(){
	return contadorcamino;
}
void Vehiculos::set_camino(int a){
	camino[contadorcamino]=a;
	contadorcamino++;
}

void Vehiculos::set_camino1(int a, int b){
	contadorcamino=b;
	camino[contadorcamino]=a;
	contadorcamino++;
}

void Vehiculos::borrarcamino(){
	
	for(int i=0;i<contadorcamino;i++){
		camino[i]=camino[i+1];
		contadorcamino--;
	}
	contadorcamino=0;
}
void Vehiculos::set_origen(int* orig){
	origen=orig;

}

void Vehiculos::set_final(int* fin){
	final=fin;	

}
	void Vehiculos::set_prioridad(int priori)
	{
		prioridad = priori;
	}
void Vehiculos::set_patente(int paten){
	patente=paten;
}
int* Vehiculos::get_origen(){
	return origen;
}

int* Vehiculos::get_final(){
	return final;
}
int Vehiculos::get_patente(){
	return patente;
}

int Vehiculos::get_prioridad(){
	return prioridad;
}


int Vehiculos::get_camino(int x){
	return camino[x];
}


