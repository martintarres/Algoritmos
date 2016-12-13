//#include <iostream>
//#include <string.h> 
//#include <stdlib.h> 
//#include <fstream> 


//using namespace std;

class Vehiculos{
	private:
		int* origen;
		int* final;
		int prioridad;
		int patente;
		bool estoyAdentro;
	//	int porAcaVoy;
		int contador;
		int camino[30];
		int origen1;
		int final1;
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
			estoyAdentro=false;
			//porAcaVoy =0;
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
		void activarAdentro();
		bool estado();
		int getPorAcaVoy();
		void ingresarCamino(int, int);
		int get_camino(int);
		int avanzar();
		void set_camino(int);
		int tamcamino();
		void avanzarcamino();
		void activarPase();
		void desactivarPase();
		bool getPase();
		bool getTermine();
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

void Vehiculos::set_origen(int* orig){
	origen=orig;
//this->origen=origen;
//origen1=origen;
}

void Vehiculos::set_final(int* fin){
	final=fin;	
//this->final=final;
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

void Vehiculos::activarAdentro(){
	estoyAdentro=true;
}
bool Vehiculos::estado(){
	return estoyAdentro;
}

int Vehiculos::getPorAcaVoy(){
	return 1;
}


int Vehiculos::get_camino(int x){
	return camino[x];
}
/*
int Vehiculos::avanzar(){
	int x =0;
	x = camino [contador];
	contador ++;
	return x;
	
}*/

