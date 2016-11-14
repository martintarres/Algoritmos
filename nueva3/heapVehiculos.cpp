#include <iostream>
#include <math.h>
#include "Vehiculos.cpp"
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 
using namespace std;

const int cant=20;
Vehiculos aux1;
class heapVehiculos {
public:
    heapVehiculos();
    void insert(Vehiculos da);
    int getLeft(int i) { return 2 * i + 1; }
    int getRight(int i) { return 2 * i + 2; }
    int getParent(int i) { return (i - 1) / 2; }
    void print();
    void Build_Max_Heap(Vehiculos heapArray[], int heap_size);
    void Max_Heapify(Vehiculos heapArray[], int i, int heap_size);
    void heapSort(Vehiculos heapArray[]);
    int lugaresDisponibles();
    int size();
    Vehiculos eliminar();
    int esvaciodesde();
    Vehiculos& recorrer(int);

    

private:
    int num;
 //   int* maxHeap;
 //   int index;
    int i;
   Vehiculos vector [cant];
   

};

heapVehiculos::heapVehiculos() {
    num = 0;

}
int heapVehiculos::lugaresDisponibles(){
	int contador=cant;
	for(int i=0; i<cant;i++){
		
			if(vector[i].get_prioridad()>=0){
			
		contador--;
		}
	}
	return contador;
}

int heapVehiculos::size(){
	int contador=0;
	for(int i=0; i<cant;i++){
		contador++;
	}
	return contador;
}

int heapVehiculos::esvaciodesde(){
	for(int i=0 ; i<cant; i++){
		if(vector[i].get_prioridad()== -1){
		//	b++;
			return i;
		}
	
	}

}
void heapVehiculos::insert(Vehiculos da) {
/*		for(int i=0; i<cant; i++){
		cout<<vector[i];
	}*/
//	for(int i= esvaciodesde(); i<cant;i++){
	if(lugaresDisponibles()>0){

	vector[esvaciodesde()]=da;
	}	else {
	cout<<"Cola llena"<< endl;
	}
	
	heapSort( vector);

}

void heapVehiculos::print(){
	for(int i=0;i<cant;i++)	{
		cout<< "vehiculo: "<<i<<endl;
	cout<<vector[i].get_patente()<<endl;//->print();
	cout<<vector[i].get_origen()<<endl;
	cout<<vector[i].get_final()<<endl;
	cout<<vector[i].get_prioridad()<<endl;
	
}

}
void heapVehiculos::Max_Heapify(Vehiculos heapArray[], int i, int heap_size) {
    // int n = size;
    int largest = 0;
    int l = getLeft(i);
    int r = getRight(i);

    if ((l < heap_size) && (heapArray[l].get_prioridad() < heapArray[i].get_prioridad())) {
        largest = l;
    } else {
        largest = i;
    }

    if ((r < heap_size) && (heapArray[r].get_prioridad() < heapArray[largest].get_prioridad())) {
        largest = r;
    }

    if (largest != i) {
        swap(heapArray[i], heapArray[largest]);
        Max_Heapify(heapArray, largest, heap_size);
    }
    return;
}
void heapVehiculos::heapSort(Vehiculos heapArray[]) {
    //size = heap_size;
    int n = size ();
    Build_Max_Heap(heapArray, size());

    for (int i = n - 1; i >= 1; i--) {
        swap(heapArray[0], heapArray[i]);
        n = n - 1;
        Max_Heapify(heapArray, 0,n);
    }
}

void heapVehiculos::Build_Max_Heap(Vehiculos heapArray[], int heap_size) {
    int n = size();
    for (int i = floor((n - 1) / 2); i >= 0; i--) {
        Max_Heapify(heapArray, i, heap_size);
    }
    return;
}

Vehiculos heapVehiculos::eliminar()
{
	//const int pepito=-1;
	Vehiculos aux;
	aux = vector [0];
	for(int i=0; i< cant ; i++){
	if((vector[i+1].get_prioridad()==-1) && (vector[i].get_prioridad() != -1)){
		vector[0]= vector[i];
		vector [i].set_prioridad(-1) ;
		vector [i].set_origen(-1);
		vector [i].set_final(-1);
		vector [i].set_patente(-1);

}else {
	if(lugaresDisponibles()==0){
	vector [0].set_prioridad(-1) ;
		vector [0].set_origen(-1);
		vector [0].set_final(-1);
		vector [0].set_patente(-1);
	}
	}
}
 heapSort( vector);
	
aux1=aux;
return aux;
}

Vehiculos& heapVehiculos::recorrer(int x){
	return vector[x];
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
