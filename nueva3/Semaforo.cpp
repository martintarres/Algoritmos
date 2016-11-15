#include <iostream>
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 
#include <math.h>
#include "heapVehiculos.cpp"

//#include <math.h>

//#include "Nodo1.cpp"
//#include "heapVehiculos.cpp"
//#include <string.h> 
//#include <stdlib.h> 
//#include <fstream> 


using namespace std;

//const int cant=10;
class Semaforo {
private:
	int cantVehiculos;
	int dest;
	int source;
	int weight;
	int numero;
	bool verde;
	bool mano;  // si se puede avanzar en esa direccion, es mano = true;
	bool fueVisitado;
	bool yaPaseSemaforo;
	heapVehiculos h;

public: 
	Semaforo(int source , int dest , int weight){
		cantVehiculos=-1;
	//	 h;
		fueVisitado=false;
		bool yaPaseeSemaforo=false;
		this->source=source;
		this->dest=dest;
		this->weight=weight;
		this->numero=numero;
	}
	Semaforo(){
		dest= -1;
		source = -1;
		weight = 0;
	}
	int getCantDeVehiculos();
	void setCantDeVehiculos(int);
	bool esMano();
	bool ponerVerde(); //pone en verde. A su vez da un booleano que ayuda a saber su estado;
	void insertar(Vehiculos v );
	Vehiculos eliminaVehiculos();
	heapVehiculos getHeap();
	void setFuiVisitado();
	bool getFuiVisitado();
	bool getYaPase();
	void setYaPase();
	
		int get_dest();
		int get_source();
		int get_weight();
	
		void set_dest(int);
		void set_source(int);
		void set_weight(int);
		void set_numero(int);
//	void yoMismo() { return this }


	
};



int Semaforo::getCantDeVehiculos()
{
	return cantVehiculos;
}
/*
int Semaforo::getUbicacion()
{
	return source;
}

int Semaforo::getOrigen(){
	return origen;
}*/

bool Semaforo::ponerVerde()   //Saca el verde si está en verde y al revés.
{
	if (verde){
		verde = false;
	}else {
		verde = true;
	}
	return verde;
}

bool Semaforo::esMano()
{
	if(mano){
		return true;
	}else
	return false;

}

void Semaforo::setCantDeVehiculos(int cant){
	cantVehiculos=cant;
	
}

void Semaforo::insertar(Vehiculos v){
	h.insert(v);
	if(cantVehiculos == 999999999){
	cantVehiculos= 0;
	cantVehiculos++;
	set_weight(cantVehiculos);	
	}else {
	cantVehiculos++;
	set_weight(cantVehiculos);	
	}
		}

Vehiculos Semaforo::eliminaVehiculos(){
	Vehiculos v;
	v= h.eliminar();
	cantVehiculos--;
	return v;
}

heapVehiculos Semaforo::getHeap(){
	return h;
}

void Semaforo::setFuiVisitado(){
	if(fueVisitado=true){
		fueVisitado=false;
	}else {
		fueVisitado=true;
	}
}

bool Semaforo::getFuiVisitado(){
	return fueVisitado;
}

bool Semaforo::getYaPase(){
	return yaPaseSemaforo;
}

void Semaforo::setYaPase(){
	if(yaPaseSemaforo == false){
		yaPaseSemaforo = true;
	}else {
		yaPaseSemaforo= false;
	}
}

/* De edge */

	void Semaforo::set_dest(int a){
		dest=a;
	}
	
	void Semaforo::set_source(int a){
		source=a;
	}
	
	void Semaforo::set_weight(int a){
		weight=a;
	}
	
	void Semaforo::set_numero(int a){
		numero=a;
	}
	int Semaforo::get_dest(){
		return dest;
	}
	
	int Semaforo::get_source(){
		return source;
	}
	
	int Semaforo::get_weight(){
		return weight;
	}

/*	
int main(){
		Semaforo s= Semaforo (5,10,2, 0);
		Semaforo s1= Semaforo  (99,98,97,1);
		Semaforo s2= Semaforo (1024,988,95547,2);
		
}

*/

