#include <iostream>
#include <string.h> 
#include <stdlib.h> 
#include <fstream>
#include "Semaforo.cpp"
 

using namespace std;
const int tamano_arcos = 420;
const int num_listas= 64;


class Nodo {
	public:
	Semaforo *dato;
	Nodo *next;
	Nodo (Semaforo *numero, Nodo *next_ptr=NULL){
		dato=numero, next= next_ptr;
	}
	Nodo *getNext (){return next;
	}
};

class Lista{
	private:
		Nodo *cabeza;
		int contador;
		Nodo *sgte;
	
		
		
	public:
		Lista(){
			cabeza=NULL;
			contador=0;
	
		}
		void agregar(Semaforo*);
		void mostrar();
		int pesos(int);
		int* destinos(int);
		int getContador();
		Semaforo* recorrerNodo();
		Semaforo* Sdestinos(int);

};

int Lista::pesos(int i){
	Nodo *aux;
	aux= cabeza;
	int pesos[5];
	for(int j=0 ; j<5 ; j++){
		if(cabeza != NULL){
			pesos [j] = cabeza->dato->get_weight();
			cabeza=cabeza->next;
		}
	}
	cabeza=aux;
	return pesos [i];
}

int* Lista::destinos(int i){
	Nodo *aux;
	aux= cabeza;
	int* dest[5];
	for(int j=0 ; j<5 ; j++){
		if(cabeza != NULL){
			dest [j] = cabeza->dato->get_dest();
			cabeza=cabeza->next;
		}
	}
	cabeza=aux;
	return dest [i];	
}

Semaforo* Lista::Sdestinos(int i){
	
	Nodo *aux;
	aux= cabeza;
	Semaforo* dest[5];
	for(int j=0 ; j<5 ; j++){
		if(cabeza != NULL){
			dest [j] = cabeza->dato;
			cabeza=cabeza->next;
		}
	}
	cabeza=aux;
	return dest [i];	
}

void Lista::agregar(Semaforo *edge){
		cabeza= new Nodo(edge, cabeza);
		contador++;

	}
	
int Lista::getContador(){
		return contador;
	}

void Lista::mostrar(){
		

		Nodo *aux;
		aux=cabeza;
		if (cabeza!=NULL){
		
		cout<<"("<< *cabeza->dato->get_source()<<", ";
		cout<< *cabeza->dato->get_dest()<<", ";
		cout<< cabeza->dato->get_weight()<<", ";
		cout<< cabeza->dato->get_numero()<<" )";
		
		cabeza=cabeza->next;
		mostrar();
	

	}
	cabeza=aux;

}

