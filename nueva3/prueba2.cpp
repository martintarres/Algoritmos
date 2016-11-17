#include <iostream>
//#include "Semaforo.cpp"
//#include "Semaforo.cpp"
//#incude "Edge.cpp"
#include "nodo1.cpp"

using namespace std;

const int cantt=140;

class heapSemaforos  {
public:
    heapSemaforos();
    void insert(int&);
   int getLeft(int i) { return 2 * i + 1; }
    int getRight(int i) { return 2 * i + 2; }
    int getParent(int i) { return (i - 1) / 2; }
    void print();
    void Build_Max_Heap(int heapArray[], int heap_size);
    void Max_Heapify(int heapArray[], int i, int heap_size);
    void heapSort(int heapArray[]);
    int lugaresDisponibles();
    int size();
    void eliminar();
    int esvaciodesde();
    //Semaforo& recorre(int);*/
   int eliminarFondo();
 /*  void cargarInt(int*);
    */

private:
   // int num;
    int semaforosadentro;
   // int* maxHeap;
  //  int index;
    //int i;
    int *vector[cantt];
 	  int parasacar[cant];
    
   	int aux;
  // Edge e;
  //	Semaforo;
  	
  //Semaforo *punt[];
//	int k;
};

heapSemaforos::heapSemaforos(){
//	Semaforo vector[cantt];
//	Semaforo s;
	semaforosadentro=0;
	
} /*
    void heapSemaforos::cargarInt (int* a){
   		for(int i=0;i<cantt;i++){
   			parasacar[i]= a;
		   }
	}
*/
int heapSemaforos::lugaresDisponibles(){
	int contador=cantt;
	for(int i=0; i<cantt;i++){
		
			if(vector[i]>=0){
			
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
		if(vector[i]== 0){
	
			return i;
		}
	
	}

}
void heapSemaforos::insert(int& da) {

//	if(da.get_weight()!= 999999999){
//	cout<<"Entre con "<<da.get_source()<<endl;
	if(semaforosadentro<140){

	vector[semaforosadentro]= &da;
	semaforosadentro++;
//	cargarInt((&vector[semaforosadentro]->get_weight()));
//	cout<<semaforosadentro<<endl;
	//cout<<vector[semaforosadentro]<<endl;
	}	else {
	cout<<"Cola llena"<< endl;
	}
	
	heapSort( *vector);

}

void heapSemaforos::print(){
	for(int i=0;i<cantt;i++)	{
	//	cout<< "iteracion "<<i<<endl;
//	cout<<vector[i]->get_source()<<" "<<vector[i]->get_dest()<<" "<< vector[i]->get_weight()<<endl;
	//cout<<vector[i].get_origen()<<endl;
	cout<<*vector[i]<<endl;
//	cout<<vector[i].get_prioridad()<<endl;
//cout<<vector;
	
}
}
/*
Semaforo& heapSemaforos::recorre(int x){
//	punt[x]=&vector[x];
	return *vector[x];
}*/


void heapSemaforos::Max_Heapify(int heapArray[], int i, int heap_size) {
    // int n = size;
    int largest = 0;
    int l = getLeft(i);
    int r = getRight(i);

    if ((l < heap_size) && (heapArray[l] < heapArray[i])) {
        largest = l;
    } else {
        largest = i;
    }

    if ((r < heap_size) && (heapArray[r]) < heapArray[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(heapArray[i], heapArray[largest]);
        Max_Heapify(heapArray, largest, heap_size);
    }
    return;
}
void heapSemaforos::heapSort(int heapArray[]) {
    //size = heap_size;
    int n = size ();
    Build_Max_Heap(heapArray, size());

    for (int i = n - 1; i >= 1; i--) {
        swap(heapArray[0], heapArray[i]);
        n = n - 1;
        Max_Heapify(heapArray, 0,n);
    }
}

void heapSemaforos::Build_Max_Heap(int heapArray[], int heap_size) {
    int n = size();
    for (int i = floor((n - 1) / 2); i >= 0; i--) {
        Max_Heapify(heapArray, i, heap_size);
    }
    return;
}

void heapSemaforos::eliminar()
{
/*	
//	int **ptr;
//	ptr=&vector[0];
	cout<< " soy la cantidad de autos del semaforo " << *vector[0] <<endl;
//	ptr-1;
	*vector[0]-1;
	cout<< " le borre, ahora tiene " << *vector[0]  <<endl;
//	*vector[0]=0;
//	heapSort( *vector);
/*	int **ptr;
	ptr= &vector[0];
	ptr=0;*/

	for(int i=0; i< cantt ; i++){
	if((*vector[i+1]==-1) && (*vector[i] != -1)){
		*vector[0]= *vector[i];
		*vector [i]= 0;
	//	heapSort( *vector); ;
	
	//	vector [i].set_origen(-1);
	//	vector [i].set_final(-1);
	//	vector [i].set_patente(-1);

}else {
	if(lugaresDisponibles()==0){
	*vector [0]=0 ;
//	heapSort( *vector);
		//cout<<" si ";
	//	vector [0].setCant(-1);
	//	vector [0].set_final(-1);
	//	vector [0].set_patente(-1);
	}
	}
	
}
}

 //heapSort( *vector);
//	return aux;
//aux1=aux;
//return aux;

/*
Semaforo heapSemaforos::eliminarFondo(){
	
	int auxDev;
	int lugar=0;
//	lugar= size()-semaforosadentro;
	lugar=semaforosadentro-1;
	cout<<"soy size " << size()<<endl;
	cout<<" Soy semaforosadentro "<< semaforosadentro<<endl;
	cout<< " soy lugar "<<lugar<<endl;;
	auxDev=vector[lugar];
	vector[lugar]=0;	
//	vector[lugar].
	return auxDev;

}



/*
int main(){

//	Edge e =  Edge(5,10,2);
//	Semaforo s= Semaforo (5,10,2);
//	Semaforo s=  Semaforo(e);
//	Edge e1= Edge (99,98,97);
//	Semaforo s1= Semaforo  (99,98,97);
////		Edge e2= Edge (1024,988,95547);
//	Semaforo s2= Semaforo (1024,988,95547);

heapSemaforos t;
	t.print();
	
}
	//t.insert(s1);
	//t.print();
	//t.insert(s);
	//t.print();
	//t.insert(s2);
	//t.print();
//cout<<t.lugaresDisponibles();
/*

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

