#include <iostream>
#include "heapSemaforos.cpp"
using namespace std;
 
class heapdjk  {
public:
    heapdjk();
    void insert(Semaforo);
	void print();
    int size();
    void eliminar(int);
  	int eliminarFondo();
 	void heapify(Semaforo arr[], int n, int i);
 	void heapSort(Semaforo arr[], int n);
 	Semaforo eliminarfdjk();
 	int tamano();
 	int getArco(int);
 	void actualizar();
	void borrar();

private:
   
    int semaforosadentro;	
    Semaforo vect[cantt];
    int total;

};

heapdjk::heapdjk(){

	semaforosadentro=0;
	total=0;
	for(int i=0;i<cantt;i++){
		vect[i].set_numero(0);
	}

} 

int heapdjk::getArco(int a){
	return vect[a].get_numero();
}


int heapdjk::tamano(){
	return semaforosadentro;
}


int heapdjk::size(){
	int contador=0;
	for(int i=0; i<cantt;i++){
		contador++;
	}
	return contador;
}


void heapdjk::insert(Semaforo da) {

	if(semaforosadentro<140){

	vect[semaforosadentro]= da;

	semaforosadentro++;


	}	else {
	cout<<"Cola llena"<< endl;
	}
	
	
	heapSort( vect, semaforosadentro);


}

void heapdjk::actualizar(){
	
	heapSort( vect, semaforosadentro);
}

void heapdjk::borrar(){
	for(int i=0;i<size();i++){
		vect[i]=vect[i+1];
		semaforosadentro--;
	}
	semaforosadentro=0;
}
void heapdjk::heapSort(Semaforo arr[], int n)
{
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    
    for (int i=n-1; i>=0; i--)
    {
        
        swap(arr[0], arr[i]);
 
        
        heapify(arr, i, 0);
    }
}

void heapdjk::heapify(Semaforo arr[], int n, int i)
{
    int largest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  
 
    
    if (l < n && arr[l].get_weight() < arr[largest].get_weight())
        largest = l;
 
    
    if (r < n && arr[r].get_weight() < arr[largest].get_weight())
        largest = r;
 
    
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
       
        heapify(arr, n, largest);
    }
}
 

void heapdjk::print(){
	for(int i=0;i<semaforosadentro;i++)	{

	cout<<*vect[i].get_source()<<" "<<*vect[i].get_dest()<<" "<< vect[i].get_weight()<<" "<<vect[i].get_numero()<<endl;

	
}
}


Semaforo heapdjk::eliminarfdjk(){

	Semaforo ve;
	ve=vect[semaforosadentro-1];

	semaforosadentro=semaforosadentro-1;

	return ve;


	
}

