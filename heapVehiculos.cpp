#include <iostream>
#include <math.h>
#include "Vehiculos.cpp"
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 
using namespace std;
const int cant=20;

class heapVehiculos {
public:
    heapVehiculos();
    void insert(Vehiculos* da);
    void print();
	void heapify(Vehiculos* arr[], int n, int i);
 	void heapSort(Vehiculos* arr[], int n);
   	int size();
    Vehiculos* eliminar();
  
private:
    
    Vehiculos *vector[cant];
    int vehiculosadentro;

};

heapVehiculos::heapVehiculos() {
 
	vehiculosadentro=0;
}


int heapVehiculos::size(){
	int contador=0;
	for(int i=0; i<vehiculosadentro;i++){
		contador++;
	}
	return contador;
}

void heapVehiculos::insert(Vehiculos* da) {
	
	if(vehiculosadentro<20){

	vector[vehiculosadentro]= da;

	vehiculosadentro++;


	}	else {
	cout<<"Cola llena"<< endl;
	}
				
	heapSort( vector, vehiculosadentro);



}

void heapVehiculos::print(){
	for(int i=0;i<vehiculosadentro;i++)	{
		cout<< "vehiculo: "<<i<<endl;
	cout<<vector[i]->get_patente()<<endl;
	cout<<*vector[i]->get_origen()<<endl;
	cout<<*vector[i]->get_final()<<endl;
	cout<<vector[i]->get_prioridad()<<endl;
	
}

}

void heapVehiculos::heapSort(Vehiculos* arr[], int n)
{
   
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    
    for (int i=n-1; i>=0; i--)
    {
     
        swap(arr[0], arr[i]);
 
       
        heapify(arr, i, 0);
    }
}

void heapVehiculos::heapify(Vehiculos* arr[], int n, int i)
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

Vehiculos* heapVehiculos::eliminar()
{
	Vehiculos *dev;
	for(int i=0;i<vehiculosadentro; i++){
		
		if(vector[i]->get_origen()!=0){
			dev = vector[i];
			vector [i]->set_prioridad(0) ;
			vector [i]->set_origen(0);
			vector [i]->set_final(0);
			vector [i]->set_patente(0);
		
		return dev;	
		}
		
	}
	
	}

