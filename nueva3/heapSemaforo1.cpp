
	/*ESTA CLASE TODAVIA NO ANDA; ESTOY TRATANDO DE MODIFICAR PARA QUE SEA UN ARREGLO Y VER QUE ONDA */
	
	
	
	
	
	
/*
#include <iostream>
//#include "Semaforo.cpp"
//#include "Semaforo.cpp"
//#incude "Edge.cpp"
#include "nodo1.cpp"

using namespace std;

const int cantt=140;

class heapSemaforos{
	public:
		heapSemaforos();
		void insert(Semaforo da);
    	int getLeft(int i) { return 2 * i + 1; }
    	int getRight(int i) { return 2 * i + 2; }
 	  	int getParent(int i) { return (i - 1) / 2; }
 	   	void print();
   	 void Build_Max_Heap(Semaforo heapArray[], int heap_size);
    void Max_Heapify(Semaforo heapArray[], int i, int heap_size);
    void heapSort(Semaforo heapArray[]);
    int lugaresDisponibles();
    int size();
    void eliminar();
    int esvaciodesde();
    Semaforo& recorre(int);
    Semaforo eliminarFondo();
    
  

private:
    int num;
   // int* maxHeap;
  //  int index;
    int i;
   	Semaforo vector;
   	Semaforo aux;
   //	Semaforo arcos[140];
  // Edge e;
 // 	Semaforo s;
  	
  //Semaforo *punt[];

};

heapSemaforos::heapSemaforos(){
//	Semaforo vector[cantt];
//	Semaforo s;
/*	for(int i=0;i<cantt;i++){
	vector[i]=arcos[i];
	}*/
	/*
} 
    

int heapSemaforos::lugaresDisponibles(){
	int contador=cantt;
	for(int i=0; i<cantt;i++){
		
			if(i.getCantDeVehiculos()>=0){
			
		contador--;
		}
	}
	return contador;
}

int heapSemaforos::size(){
	int contador=0;
	for(int i=0; i<cantt;i++){
		contador++;
	}
	return contador;
}

int heapSemaforos::esvaciodesde(){
	for(int i=0 ; i<cantt; i++){
		if(i.getCantDeVehiculos()== -1){
	
			return i;
		}
	
	}

}
void heapSemaforos::insert(Semaforo da) {

	if(lugaresDisponibles()>0){

	esvaciodesde()=da;
	}	else {
	cout<<"Cola llena"<< endl;
	}
	
	heapSort( vector);

}

void heapSemaforos::print(){
	for(int i=0;i<cantt;i++)	{
	//	cout<< "iteracion "<<i<<endl;
	cout<<vector[i].get_source()<<" "<<vector[i].get_dest()<<" "<< vector[i].getCantDeVehiculos()<<endl;
	//cout<<vector[i].get_origen()<<endl;
//	cout<<vector[i].get_final()<<endl;
//	cout<<vector[i].get_prioridad()<<endl;
	
}
}

Semaforo& heapSemaforos::recorre(int x){
//	punt[x]=&vector[x];
	return vector[x];
}


void heapSemaforos::Max_Heapify(Semaforo heapArray[], int i, int heap_size) {
    // int n = size;
    int largest = 0;
    int l = getLeft(i);
    int r = getRight(i);

    if ((l < heap_size) && (heapArray[l].getCantDeVehiculos() < heapArray[i].getCantDeVehiculos())) {
        largest = l;
    } else {
        largest = i;
    }

    if ((r < heap_size) && (heapArray[r].getCantDeVehiculos() < heapArray[largest].getCantDeVehiculos())) {
        largest = r;
    }

    if (largest != i) {
        swap(heapArray[i], heapArray[largest]);
        Max_Heapify(heapArray, largest, heap_size);
    }
    return;
}
void heapSemaforos::heapSort(Semaforo heapArray[]) {
    //size = heap_size;
    int n = size ();
    Build_Max_Heap(heapArray, size());

    for (int i = n - 1; i >= 1; i--) {
        swap(heapArray[0], heapArray[i]);
        n = n - 1;
        Max_Heapify(heapArray, 0,n);
    }
}

void heapSemaforos::Build_Max_Heap(Semaforo heapArray[], int heap_size) {
    int n = size();
    for (int i = floor((n - 1) / 2); i >= 0; i--) {
        Max_Heapify(heapArray, i, heap_size);
    }
    return;
}

void heapSemaforos::eliminar()
{
	//const int pepito=-1;
	//Semaforo aux;
	aux = vector [0];
	
	for(int i=0; i< cantt ; i++){
	if((vector[i+1].getCantDeVehiculos()==-1) && (vector[i].getCantDeVehiculos() != -1)){
		vector[0]= vector[i];
		vector [i].setCantDeVehiculos(-1) ;
	//	vector [i].set_origen(-1);
	//	vector [i].set_final(-1);
	//	vector [i].set_patente(-1);

}else {
	if(lugaresDisponibles()==0){
	vector [0].setCantDeVehiculos(-1) ;
	//	vector [0].setCant(-1);
	//	vector [0].set_final(-1);
	//	vector [0].set_patente(-1);
	}
	}
	
}

 heapSort( vector);
//	return aux;
//aux1=aux;
//return aux;
}	

Semaforo heapSemaforos::eliminarFondo(){
	
	Semaforo auxDev;
	int lugar=0;
	lugar= size()-lugaresDisponibles()-1;
	auxDev=vector[lugar];
	vector[lugar].setCantDeVehiculos(-1);	
	return auxDev;

}



/*
int main(){

	Edge e =  Edge(5,10,2);
	Semaforo s=  Semaforo(e);
	Edge e1= Edge (99,98,97);
	Semaforo s1= Semaforo (e1);
		Edge e2= Edge (1024,988,95547);
	Semaforo s2= Semaforo (e2);

	heapSemaforos t;
	t.insert(s1);
//	cout<<endl;
//	t.print();
	t.insert(s);
	t.insert(s2);
///	cout<<endl;
	t.print();
	cout<<endl;
	t.eliminarFondo();
	t.print();
//	t.insert(s2);
//	t.print();
//	cout<<endl;
//	t.eliminar();
//	t.print();
//	t.mostarubi();
}

*/


