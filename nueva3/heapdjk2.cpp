#include <iostream>
//#include "Semaforo.cpp"
//#include "Semaforo.cpp"
//#incude "Edge.cpp"
//#include "nodo1.cpp"
#include "prueba3.cpp"
using namespace std;

//const int cantt=140;

 
class heapdjk  {
public:
    heapdjk();
    void insert(Semaforo);
	  void print();
   int lugaresDisponibles();
    int size();
    void eliminar(int);
    int esvaciodesde();
  int eliminarFondo();
 void heapify(Semaforo arr[], int n, int i);
 void heapSort(Semaforo arr[], int n);
 Semaforo eliminarfdjk();
 Semaforo eliminaradjk();
 int tamano();
 int getArco(int);
 void actualizar();
void borrar();

private:
   
    int semaforosadentro;
	//int numero;
    Semaforo vect[cantt];
    int *ptr[cant];
 	int parasacar[cant];
    int total;
   	int aux;
   	int* pesos[cantt];
   //	int *numero;
  // Edge e;
  //	Semaforo;
  	
  //Semaforo *punt[];
//	int k;
};

heapdjk::heapdjk(){
//	Semaforo vector[cantt];
//	Semaforo s;
	semaforosadentro=0;
	total=0;
	for(int i=0;i<cantt;i++){
		vect[i].set_numero(0);//=0;
	}
//	numero=0;
} /*
    void heapSemaforos::cargarInt (int* a){
   		for(int i=0;i<cantt;i++){
   			parasacar[i]= a;
		   }
	}
*/

int heapdjk::getArco(int a){
	return vect[a].get_numero();
}

int heapdjk::lugaresDisponibles(){
	int contador=cantt;
	for(int i=0; i<cantt;i++){
		
			if(semaforosadentro>=0){
			
		contador--;
		}
	}
	return contador;
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

int heapdjk::esvaciodesde(){
	for(int i=0 ; i<cantt; i++){
		if(semaforosadentro== 0){
	
			return i;
		}
	
	}

}
void heapdjk::insert(Semaforo da) {
//	numero=numero1;
	if(semaforosadentro<140){

	vect[semaforosadentro]= da;
//	pesos[semaforosadentro]=vect[semaforosadentro]->get_weight();
	semaforosadentro++;


	}	else {
	cout<<"Cola llena"<< endl;
	}
	
	//Semaforo s;
//	s.get_weight()
//	if(semaforosadentro==cantt){
	//	pesos[semaforosadentro-1]=vect[semaforosadentro-1]->get_weight();
		
		
	
	/*		if(semaforosadentro==9){
					cout<<"Aca muestro todos los pesos de los semaforos pasados a un vector"<<endl;
		for(int i=0;i<semaforosadentro;i++){
			cout<<*pesos[i]<<endl;
		}
	}
*/

//	cout<<*vect[semaforosadentro-1]->get_weight()<<endl;
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

void heapdjk::heapify(Semaforo arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l].get_weight() < arr[largest].get_weight())
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r].get_weight() < arr[largest].get_weight())
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 

void heapdjk::print(){
	for(int i=0;i<semaforosadentro;i++)	{
	//	cout<< "iteracion "<<i<<endl;
	cout<<*vect[i].get_source()<<" "<<*vect[i].get_dest()<<" "<< vect[i].get_weight()<<" "<<vect[i].get_numero()<<endl;
	//cout<<vector[i].get_origen()<<endl;
//	cout<<vect[i]->get_numero()<< endl;
//	cout<<vector[i].get_prioridad()<<endl;
//cout<<vector;
	
}
}


void heapdjk::eliminar(int a)
{
	/*Este eliminar creo lo voy a tener que ir haciendo por cada semaforo*/
	
//	&vect[a].get_weight()=vect[a].get_weight()-1;
/*	int pesonuevo=0;
	pesonuevo=*vect[a]->get_weight();
	cout<<pesonuevo<<endl;	
*/	
	
}

Semaforo heapdjk::eliminarfdjk(){

	Semaforo ve;
	ve=vect[semaforosadentro-1];
//	free(vect[semaforosadentro-1]);
	semaforosadentro=semaforosadentro-1;

	return ve;


	
}

Semaforo heapdjk::eliminaradjk(){
	Semaforo ve;
	ve=vect[0];
	
for(int i=0;i<semaforosadentro; i++){
	int a;

	vect[i]=vect[i+1];
	if(vect[i+1].get_numero()==0){
	
		vect[i+1].set_numero(0);//=0;
	//	free(vect[i+1].get_numero());
			
	}
	
}
semaforosadentro=semaforosadentro-1;
//set_weight(&cantVehiculos);

	return ve;
}
/*
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
*/

/*
	int main(){


int numeroo, arregloo[200], gg;
int h=0;
int k = 0;
int g=0,arreglo[200],numero; 
int numnodos=0;

ifstream archivo("ficheroTexto2.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 

arreglo[g++]=numero;	

}

ifstream archivoo("ficheroAutos3.txt"); 
if(archivoo.good()){ 
while(archivoo>>numeroo) 

arregloo[gg++]=numeroo;
}

for(int i=0;i<g;i++){
	numnodos++;
	
}
numnodos=numnodos/3;
cout<<"son "<<numnodos<< " nodos "<<endl;


Semaforo arcos[numnodos];



	/*Me carga la ciudad */

/*	int cont=0;
	for(int j=0;j<g;j++) {
	
	arcos[cont].set_source(&arreglo[j]);
	arcos[cont].set_dest(&arreglo[j+1]);
	arcos[cont].set_weight(&arreglo[j+2]);
	arcos[cont].set_numero(cont);
	cont++;
	j=j+2;
	
}


//cout<<arcos[1].get_source();



	/* ME AVERIGUA LA CANTIDAD DE NODOS */
/*
	int numlistas=0;
	for(int i=0;i<numnodos;i++){
		int compara=0;
		
		compara= *arcos[i].get_source();
	
			if(compara!= *arcos[i+1].get_source()){
				numlistas++;
			
			}	
		}
	
	
	cout<<"Tengo "<< numlistas<< " listas" << endl;
	
	Lista l[numlistas];

	/* Me arma la lista enlazada */ 
/*	
	int compara=*arcos[0].get_source();
	int numlista=0;
	l[numlista].agregar(&arcos[0]);
	for(int i=1; i<numnodos;i++){
		int compara2= *arcos[i].get_source();
		if(compara == compara2){
			l[numlista].agregar(&arcos[i]);
		}else {
			numlista++;
			l[numlista].agregar(&arcos[i]);
			compara=*arcos[i].get_source();
		}
	}
	
	/* Me muestra la lista armada */
/*
	for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}
	
	/*Averiguo numero de autos */
/*
	int totalveh=0;
	for(int i=0;i<gg;i++){
	totalveh++;
	
	}
	totalveh=totalveh/4;
	cout<<"son "<<totalveh<< " Vehiculos "<<endl;
	
	/*Me carga los vehiculos*/
/*
	Vehiculos v[totalveh];

	int contt=0;
	
	for(int j=0;j<gg;j++) {
	v[contt].set_patente(arregloo[j]);
	v[contt].set_origen(&arregloo[j+1]);
	v[contt].set_final(&arregloo[j+2]);
	v[contt].set_prioridad(arregloo[j+3]);
	contt++;
		j=j+3;
	
	
	
	
	}


	
	/*Me agrega los autos en el semaforo */
/*
	for(int i=0;i<totalveh;i++){
		for(int j=0; j< numnodos; j++){ 
		int *a,*b,*c,*d;
			a=v[i].get_origen();
			b=arcos[j].get_source();
			c=v[i].get_final();
			d=arcos[j].get_dest();
		
			if((*a == *b) && (*c == *d )){
				arcos[j].insertar(&v[i]);
	
			//	arcos[j].set_weight(s[j].getCantDeVehiculos());
	
			}
		}
	}
	getchar();
	
	/* Me muestra la lista armada con la cantidad de autos */
/*
	for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}
	
	getchar ();
	
		/* Aca pruebo de aumentar un semaforo y se cambia todo */	
/*		
	arcos[2].insertar(&v[1]);
	
		for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}
	
	
	
	/*Me hace una lista de mayor a menor de los semaforos */
/*
	heapSemaforos hsemaforo;
	
	for(int i=0; i<numnodos;i++){

		hsemaforo.insert(&(arcos[i]));
	}
	
/* Aca pruebo eliminar y me elimina de la ciudad */
/*
	getchar();
	cout<<"Aca me deberia mostrar todo ordenado"<<endl;
	hsemaforo.print();
	cout<<endl<<endl;
/*	hsemaforo.eliminar(0);
	hsemaforo.print();
	cout<<endl<<endl;*/
/*	getchar();
	
	for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}



}*/
