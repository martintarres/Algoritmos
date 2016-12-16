#include <iostream>
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 
#include <math.h>
#include "heapVehiculos.cpp"

#define maximo 20
#define maximo1 1000
using namespace std;


class Semaforo {
private:
	int cantVehiculos;
	int* dest;
	int* source;
	int weight;
	int numero;
	bool fueVisitado;
	bool yaPaseSemaforo;
	heapVehiculos h;
	int* cantvehiculos;
	Vehiculos* vectorautos[cant];
	

public: 
	Semaforo(int* source , int* dest , int weight, int numero){
		cantVehiculos=1;
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
	
	void insertar(Vehiculos* v );
	void insertarlistos(Vehiculos* v );
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
	
};


void Semaforo::heapSort(Vehiculos* arr[], int n)
{
   
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    
    for (int i=n-1; i>=0; i--)
    {
       
        swap(arr[0], arr[i]);
 
        
        heapify(arr, i, 0);
    }
}

void Semaforo::heapify(Vehiculos* arr[], int n, int i)
{
    int largest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  
 
    
    if (l < n && (arr[l]->get_prioridad()) < arr[largest]->get_prioridad())
        largest = l;
 
    
    if (r < n && arr[r]->get_prioridad() < arr[largest]->get_prioridad())
        largest = r;
 
  
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        
        heapify(arr, n, largest);
    }
}


void Semaforo::print(){
	for(int i=0;i<cantVehiculos;i++)	{
		cout<< "vehiculo: "<<i<<endl;
	cout<<vectorautos[i]->get_patente()<<endl;
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

return ve;
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


	}else {
		cout<<"Semaforo lleno"<<endl;
	}
	
	heapSort( vectorautos, cantVehiculos);
		

}

void Semaforo::insertarlistos(Vehiculos* v){
		if(cantVehiculos<maximo1){
		
	vectorautos[cantVehiculos]=v;

	cantVehiculos=cantVehiculos+1;
setCantDeVehiculos(cantVehiculos);

	}else {
		cout<<"Semaforo lleno"<<endl;
	}
	
	heapSort( vectorautos, cantVehiculos);
	
}

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



