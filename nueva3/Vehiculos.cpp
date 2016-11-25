#include <iostream>
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 


using namespace std;

class Vehiculos{
	private:
		int origen;
		int final;
		int prioridad;
		int patente;
		bool estoyAdentro;
	//	int porAcaVoy;
		int contador;
		int camino[30];
		
	public:
		Vehiculos(){
			/*this->patente=patente;
			this->final=final;
			this->prioridad=prioridad;   //Sacamos la prioridad del constructor. A lo sumo agregarla de nuevo.
			this->origen=origen;*/
			origen=0;
			final=0;
			prioridad=0;
			patente=0;
			estoyAdentro=false;
			//porAcaVoy =0;
			contador = 0;
			for (int i = 0; i<30; i++){
				camino[i] = -1;
			}
		}
		void set_origen(int);
		void set_final (int);
		void set_prioridad(int);
		void set_patente(int);
		int get_origen();
		int get_final();
		int get_patente();
		int get_prioridad();
		void activarAdentro();
		bool estado();
		int getPorAcaVoy();
		void ingresarCamino(int, int);
		int get_camino(int);
		int avanzar();
};

void Vehiculos::set_origen(int orig){
	origen=orig;
}

void Vehiculos::set_final(int fin){
	final=fin;	
}
	void Vehiculos::set_prioridad(int priori)
	{
		prioridad = priori;
	}
void Vehiculos::set_patente(int paten){
	patente=paten;
}
int Vehiculos::get_origen(){
	return origen;
}

int Vehiculos::get_final(){
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
void Vehiculos::ingresarCamino(int x, int y){				//Posicion x del arreglo, numero y;
	camino [x] = y;
	//contador ++;
}

int Vehiculos::get_camino(int x){
	return camino[x];
}

int Vehiculos::avanzar(){
	int x =0;
	x = camino [contador];
	contador ++;
	return x;
	
}

