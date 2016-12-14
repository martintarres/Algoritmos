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
#define maximo 20
#define maximo1 1000
using namespace std;

//const int cant=20;
class Semaforo {
private:
	int cantVehiculos;
	int* dest;
	int* source;
	int weight;
	int numero;
	bool verde;
	bool mano;  // si se puede avanzar en esa direccion, es mano = true;
	bool fueVisitado;
	bool yaPaseSemaforo;
	heapVehiculos h;
	int* cantvehiculos;
	Vehiculos* vectorautos[cant];
	

public: 
	Semaforo(int* source , int* dest , int weight, int numero){
		cantVehiculos=1;
	//	 h;
		fueVisitado=false;
		bool yaPaseeSemaforo=false;
		this->source=source;
		this->dest=dest;
		this->weight=weight;
		this->numero=numero;
	Semaforo s;
	}
	Semaforo(){
		dest= 0;
		source = 0;
		weight = 0;
		numero=0;
		cantVehiculos=0;
		
	}
	int& getCantDeVehiculos();
	void setCantDeVehiculos(int);
	bool esMano();
	bool ponerVerde(); //pone en verde. A su vez da un booleano que ayuda a saber su estado;
	void insertar(Vehiculos* v );
	void insertarlistos(Vehiculos* v );
	Vehiculos eliminaVehiculos();
	heapVehiculos getHeap();
	void setFuiVisitado();
	bool getFuiVisitado();
	bool getYaPase();
	void setYaPase();
	int eliminaVehiculos1();
	void heapify(Vehiculos* arr[], int n, int i);
 	void heapSort(Vehiculos* arr[], int n);
 	void print();
 	Vehiculos* mover();
 	Vehiculos* elminarVehiculos(Vehiculos*);
 
	
		int* get_dest();
		int* get_source();
		int& get_weight();
		void get_print();
		int get_numero();
	
		void set_dest(int*);
		void set_source(int*);
		void set_weight(int);
		void set_numero(int);
//	void yoMismo() { return this }
	
//	typedef void (Semaforo::*obtenerpeso)(int*);
//	obtenerpeso o;

	
};


void Semaforo::heapSort(Vehiculos* arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void Semaforo::heapify(Vehiculos* arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && (arr[l]->get_prioridad()) < arr[largest]->get_prioridad())
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r]->get_prioridad() < arr[largest]->get_prioridad())
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}


void Semaforo::print(){
	for(int i=0;i<cantVehiculos;i++)	{
		cout<< "vehiculo: "<<i<<endl;
	cout<<vectorautos[i]->get_patente()<<endl;//->print();
	cout<<*vectorautos[i]->get_origen()<<endl;
	cout<<*vectorautos[i]->get_final()<<endl;
	cout<<vectorautos[i]->get_prioridad()<<endl;
	
}

}

Vehiculos* Semaforo::mover(){

	Vehiculos *ve;
	ve=vectorautos[0];
	
for(int i=0;i<cantVehiculos; i++){
	Vehiculos *a;

	vectorautos[i]=vectorautos[i+1];
	if(vectorautos[i+1]==0){
	
		vectorautos[i+1]=0;
		free(vectorautos[i+1]);
			
	}
	
}
cantVehiculos=cantVehiculos-1;
set_weight(cantVehiculos);

	return ve;

}

Vehiculos* Semaforo::elminarVehiculos(Vehiculos *aux){

	Vehiculos *ve;
	for(int i=0;i<cantVehiculos;i++){
		if(aux->get_patente()==vectorautos[i]->get_patente()){
			cout<<"Soy igual y soy "<< i<<endl;
				
	ve=vectorautos[i];
	
	for(int i=0;i<cantVehiculos; i++){
	Vehiculos *a;

	vectorautos[i]=vectorautos[i+1];
	if(vectorautos[i+1]==0){
	
		vectorautos[i+1]=0;
		free(vectorautos[i+1]);
			
	}
	
	}
	cantVehiculos=cantVehiculos-1;
	set_weight(cantVehiculos);
		}
		
		
	}

/*
	
for(int i=0;i<cantVehiculos; i++){
	Vehiculos *a;

	vectorautos[i]=vectorautos[i+1];
	if(vectorautos[i+1]==0){
	
		vectorautos[i+1]=0;
		free(vectorautos[i+1]);
			
	}
	
}
cantVehiculos=cantVehiculos-1;
set_weight(&cantVehiculos);

*/
return ve;
}

int& Semaforo::getCantDeVehiculos()
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
	set_weight(cantVehiculos);
	
}


void Semaforo::insertar(Vehiculos* v){

	if(cantVehiculos<maximo){
		
	vectorautos[cantVehiculos]=v;

	cantVehiculos=cantVehiculos+1;
setCantDeVehiculos(cantVehiculos);
//set_weight(&getCantDeVehiculos());

	}else {
		cout<<"Semaforo lleno"<<endl;
	}
	
	heapSort( vectorautos, cantVehiculos);
		
	
	//cout<<"Desde la propia case "<<endl;
//	print();
}

void Semaforo::insertarlistos(Vehiculos* v){
		if(cantVehiculos<maximo1){
		
	vectorautos[cantVehiculos]=v;

	cantVehiculos=cantVehiculos+1;
setCantDeVehiculos(cantVehiculos);
//set_weight(&getCantDeVehiculos());

	}else {
		cout<<"Semaforo lleno"<<endl;
	}
	
	heapSort( vectorautos, cantVehiculos);
	
}

int Semaforo::eliminaVehiculos1(){

	int a=0;
	a=h.eliminar1();
	cantVehiculos--;
	return a;

}

heapVehiculos Semaforo::getHeap(){
//	return h;
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

	void Semaforo::set_dest(int* a){
		dest=a;
	}
	
	void Semaforo::set_source(int* a){
		source=a;
	}
	
	void Semaforo::set_weight(int a){
		weight=a;
	}
	
	void Semaforo::set_numero(int a){
		numero=a;
	}
	int* Semaforo::get_dest(){
		return dest;
	}
	
	int* Semaforo::get_source(){
		return source;
	}
	
	int& Semaforo::get_weight(){
		return weight;
	
	}
	
	void Semaforo::get_print(){
		h.print();
	}
	
	int Semaforo::get_numero(){
		return numero;
	}



