#include <iostream>
#include <fstream>
//#include "nodo1.cpp"
//#include "Vehiculos.cpp"
//#include "Semaforo.cpp"
#include "prueba2.cpp"
//#include "Heaparr.cpp"
using namespace std;


int main(){
	
int numeroo, arregloo[100], qq;
int h=0;
int k = 0;
int q=0,arreglo[500],numero; 
int total=0;

ifstream archivo("ficheroTexto.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 

arreglo[q++]=numero;	

}

ifstream archivoo("ficheroAutos1.txt"); 
if(archivoo.good()){ 
while(archivoo>>numeroo) 

arregloo[qq++]=numeroo;
}

for(int i=0;i<q;i++){
	total++;
	
}
total=total/3;
cout<<"son "<<total<< " nodos "<<endl;


Semaforo arcos[total];



	/*Me carga la ciudad */
	
	int cont=0;
	for(int j=0;j<q;j++) {
	
	arcos[cont].set_source(arreglo[j]);
	arcos[cont].set_dest(arreglo[j+1]);
	arcos[cont].set_weight(arreglo[j+2]);
	cont++;
	j=j+2;
	
}


//cout<<arcos[1].get_source();

/*  ME MUESTRA QUE SE CARGUEN TODOS LOS ARCOS*/
/*
	for(int i=0;i<total;i++){
		cout<<arcos[i].get_source();
		cout<<" ";
		cout<<arcos[i].get_dest();
		cout<<" ";
		cout<<arcos[i].get_weight();
		cout<<endl;
	}
*/

	/* ME AVERIGUA LA CANTIDAD DE NODOS */
	
	int contador=0;
	for(int i=0;i<total;i++){
		int compara=0;
		
		compara= arcos[i].get_source();
	
			if(compara!= arcos[i+1].get_source()){
				contador++;
			
			}	
		}
	
	
	cout<<"Tengo "<< contador<< " listas" << endl;
	
	Lista l[contador];

	/* Me arma la lista enlazada */ 
	
	int compara=arcos[0].get_source();
	int numlista=0;
	l[numlista].agregar(&arcos[0]);
	for(int i=1; i<total;i++){
		int compara2= arcos[i].get_source();
		if(compara == compara2){
			l[numlista].agregar(&arcos[i]);
		}else {
			numlista++;
			l[numlista].agregar(&arcos[i]);
			compara=arcos[i].get_source();
		}
	}
	
	/* Me muestra la lista armada */

	for(int i=0; i< 64 ;i++){
		l[i].mostrar();
		cout<<endl;
	}
	
	/*Averiguo numero de autos */

	int totalveh=0;
	for(int i=0;i<qq;i++){
	totalveh++;
	
	}
	totalveh=totalveh/4;
	cout<<"son "<<totalveh<< " Vehiculos "<<endl;
	
	/*Me carga los vehiculos*/

	Vehiculos v[totalveh];

	int contt=0;
	
	for(int j=0;j<qq;j++) {
	v[contt].set_patente(arregloo[j]);
	v[contt].set_origen(arregloo[j+1]);
	v[contt].set_final(arregloo[j+2]);
	v[contt].set_prioridad(arregloo[j+3]);
	contt++;
	j=j+3;
	
	}

	/*Muestra vehiculos cargados*/
/*	
	for(int i=0;i<totalveh;i++){
		cout<<v[i].get_patente();
		cout<<" ";
		cout<<v[i].get_origen();
		cout<<" ";
		cout<<v[i].get_final();
		cout<<" ";
		cout<<v[i].get_prioridad();
		cout<<endl;
	}
*/
	/*Creo los semaforos */
/*	
	Semaforo s[total];
	
	for(int i=0; i<total;i++){
		s[i]=&arcos[i];
	

	}
	
	/*Me agrega los autos en el semaforo */

	for(int i=0;i<totalveh;i++){
		for(int j=0; j< total; j++){ 
			
			if(v[i].get_origen() == arcos[j].get_source() && v[i].get_final() == arcos[j].get_dest()  ){
				arcos[j].insertar(v[i]);
	
			//	arcos[j].set_weight(s[j].getCantDeVehiculos());
	
			}
		}
	}
	
	
	/* Me muestra la lista armada con la cantidad de autos */

	for(int i=0; i< 64 ;i++){
		l[i].mostrar();
		cout<<endl;
	}
	
	/* Aca pruebo de aumentar un semaforo y se cambia todo */	
	arcos[2].insertar(v[1]);
	
		for(int i=0; i< 64 ;i++){
		l[i].mostrar();
		cout<<endl;
	}
	
	/*Me hace una lista de mayor a menor de los semaforos */

	heapSemaforos hsemaforo;// [10];
	
	for(int i=0; i<140;i++){
	
		hsemaforo.insert(arcos[i].get_weight());
	}
	

	hsemaforo.print();
//	cout<<endl<<endl;
//	hsemaforo.eliminar();
//	hsemaforo.print();
	//	hsemaforo.eliminar();
//	hsemaforo.print();
/*	cout<<endl<<endl;
		for(int i=0; i< 64 ;i++){
		l[i].mostrar();
		cout<<endl;
	}
*/
	hsemaforo.print();
//	cout<<endl<<endl;
}


