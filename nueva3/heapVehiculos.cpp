#include <iostream>
#include <math.h>
#include "Vehiculos.cpp"
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 
using namespace std;

const int cant=20;
//Vehiculos aux1;
class heapVehiculos {
public:
    heapVehiculos();
    void insert(Vehiculos* da);
    void print();
	void heapify(Vehiculos* arr[], int n, int i);
 	void heapSort(Vehiculos* arr[], int n);
    int lugaresDisponibles();
    int size();
    Vehiculos* eliminar();
    int esvaciodesde();
    Vehiculos& recorrer(int);
   	int eliminar1( );

    

private:
    int num;
    int i;
    Vehiculos *vector[cant];
    int vehiculosadentro;

};

heapVehiculos::heapVehiculos() {
    num = 0;
	vehiculosadentro=0;
}
int heapVehiculos::lugaresDisponibles(){
	int contador=cant;
	for(int i=0; i<cant;i++){
		
			if(vector[i]->get_prioridad()>=0){
			
		contador--;
		}
	}
	return contador;
}

int heapVehiculos::size(){
	int contador=0;
	for(int i=0; i<vehiculosadentro;i++){
		contador++;
	}
	return contador;
}

int heapVehiculos::esvaciodesde(){
	for(int i=0 ; i<cant; i++){
		if(vector[i]->get_prioridad()== 0){
		//	b++;
			return i;
		}
	
	}

}
void heapVehiculos::insert(Vehiculos* da) {
	
	if(vehiculosadentro<20){

	vector[vehiculosadentro]= da;

	vehiculosadentro++;


	}	else {
	cout<<"Cola llena"<< endl;
	}
	
	
//	if(vehi==cantt){
			
	heapSort( vector, vehiculosadentro);



//}

}

void heapVehiculos::print(){
	for(int i=0;i<vehiculosadentro;i++)	{
		cout<< "vehiculo: "<<i<<endl;
	cout<<vector[i]->get_patente()<<endl;//->print();
	cout<<*vector[i]->get_origen()<<endl;
	cout<<*vector[i]->get_final()<<endl;
	cout<<vector[i]->get_prioridad()<<endl;
	
}

}

void heapVehiculos::heapSort(Vehiculos* arr[], int n)
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

void heapVehiculos::heapify(Vehiculos* arr[], int n, int i)
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
	
int heapVehiculos::eliminar1(){
	
	for(int i=0;i<vehiculosadentro; i++){
		
		if(vector[i]->get_origen()!=0){
		//	dev = vector[i];
		//	vector [i]->set_prioridad(a) ;
		//	vector [i]->set_origen(a);
		//	vector [i]->set_final(b);
		//	vector [i]->set_patente(d);
		//	break;
		int a=0;
		a= vector[i]->get_patente();
		return a;
			}	
		}
	}

	//const int pepito=-1;
/*	Vehiculos *aux;
	aux = vector [0];
	for(int i=0; i< cant ; i++){
	if((vector[i+1]->get_prioridad()==0) && (vector[i]->get_prioridad() != 0)){
		vector[0]= vector[i];
		vector [i]->set_prioridad(0) ;
		vector [i]->set_origen(0);
		vector [i]->set_final(0);
		vector [i]->set_patente(0);

}else {
	if(vector[i]== vector[0]){
	vector [0]->set_prioridad(0) ;
		vector [0]->set_origen(0);
		vector [0]->set_final(0);
		vector [0]->set_patente(0);
	}
	}
	break;
}*/
 //heapSort( vector);
	
//aux1=aux;
//return aux;


Vehiculos& heapVehiculos::recorrer(int x){
/*	return vector[x];*/
}	

/*

int main(){
	
	heapVehiculos t;
	
	
	int numero, arreglo[100], q;
ifstream archivo("ficheroAutos.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 
arreglo[q++]=numero;


for(int j=0;j<q;j++) {
	Vehiculos *v=new Vehiculos();

		v->set_patente(arreglo[j]);
		v->set_origen(arreglo[j+1]);
		v->set_final(arreglo[j+2]);
		v->set_prioridad(arreglo[j+3]);
		t.insert(*v);
		t.print();
	//cout<< "patente: "<< v->get_patente()<< endl;
//	cout<< "origen: "<< v->get_origen()<< endl;
//	cout<< "final: "<< v->get_final()<< endl;
	
//	cout << "prioridad: " << v->get_prioridad() << endl;
	cout<<endl;
	j=j+3;
}}
    }//               
	
	
*/
