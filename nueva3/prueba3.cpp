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
    void insert(int* );
	  void print();
   int lugaresDisponibles();
    int size();
    void eliminar(int);
    int esvaciodesde();
  int* eliminarFondo();
 void heapify(int* arr[], int n, int i);
 void heapSort(int* arr[], int n);
 int* eliminarfdjk();
 int *eliminaradjk();
 int tamano();


private:
   
    int semaforosadentro;
	//int numero;
    int *vector[cantt];
    int *ptr[cant];
 	int parasacar[cant];
    int total;
   	int aux;
   //	int *numero;
  // Edge e;
  //	Semaforo;
  	
  //Semaforo *punt[];
//	int k;
};

heapSemaforos::heapSemaforos(){
//	Semaforo vector[cantt];
//	Semaforo s;
	semaforosadentro=0;
	total=0;
	for(int i=0;i<cantt;i++){
		vector[i]=0;
	}
//	numero=0;
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
int heapSemaforos::tamano(){
	return semaforosadentro;
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
void heapSemaforos::insert(int* da) {
//	numero=numero1;
	if(semaforosadentro<140){

	vector[semaforosadentro]= da;

	semaforosadentro++;
	//peso=&semaforosadentro;

	}	else {
	cout<<"Cola llena"<< endl;
	}
	
	
//	if(semaforosadentro==cantt){
			
	heapSort( vector, semaforosadentro);



//}
}

void heapSemaforos::heapSort(int* arr[], int n)
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

void heapSemaforos::heapify(int* arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && *arr[l] < *arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && *arr[r] < *arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 

void heapSemaforos::print(){
	for(int i=0;i<semaforosadentro;i++)	{
	//	cout<< "iteracion "<<i<<endl;
//	cout<<vector[i]->get_source()<<" "<<vector[i]->get_dest()<<" "<< vector[i]->get_weight()<<endl;
	//cout<<vector[i].get_origen()<<endl;
	cout<<*vector[i]<< endl;
//	cout<<vector[i].get_prioridad()<<endl;
//cout<<vector;
	
}
}


void heapSemaforos::eliminar(int a)
{
	/*Este eliminar creo lo voy a tener que ir haciendo por cada semaforo*/
	
	*vector[a]=*vector[a]-1;
	
	
	
}

int* heapSemaforos::eliminarfdjk(){
	
	int *ve;
	ve=vector[semaforosadentro-1];
	free(vector[semaforosadentro-1]);
	semaforosadentro=semaforosadentro-1;
	/*
		
for(int i=0;i<semaforosadentro; i++){
	int *a;

	vector[i]=vector[i+1];
	if(vector[i+1]==0){
	
		vector[i+1]=0;
		free(vector[i+1]);
			
	}
	
}
semaforosadentro=semaforosadentro-1;
//set_weight(&cantVehiculos);
*/
	return ve;


	
}

int* heapSemaforos::eliminaradjk(){
	int *ve;
	ve=vector[0];
	
for(int i=0;i<semaforosadentro; i++){
	int *a;

	vector[i]=vector[i+1];
	if(vector[i+1]==0){
	
		vector[i+1]=0;
		free(vector[i+1]);
			
	}
	
}
semaforosadentro=semaforosadentro-1;
//set_weight(&cantVehiculos);

	return ve;
}

int* heapSemaforos::eliminarFondo(){
	
	int* auxDev;
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

