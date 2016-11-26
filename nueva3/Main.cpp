#include <iostream>
#include <fstream>
//#include "nodo1.cpp"
//#include "Vehiculos.cpp"
//#include "Semaforo.cpp"
#include "prueba3.cpp"
//#include "Heaparr.cpp"
using namespace std;


int main(){
	
int numeroo, arregloo[100], qq;
int h=0;
int k = 0;
int q=0,arreglo[500],numero; 
int numnodos=0;

ifstream archivo("ficheroTexto1.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 

arreglo[q++]=numero;	

}

ifstream archivoo("ficheroAutos2.txt"); 
if(archivoo.good()){ 
while(archivoo>>numeroo) 

arregloo[qq++]=numeroo;
}

for(int i=0;i<q;i++){
	numnodos++;
	
}
numnodos=numnodos/3;
cout<<"son "<<numnodos<< " nodos "<<endl;


Semaforo arcos[numnodos];



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
	
	int numlistas=0;
	for(int i=0;i<numnodos;i++){
		int compara=0;
		
		compara= arcos[i].get_source();
	
			if(compara!= arcos[i+1].get_source()){
				numlistas++;
			
			}	
		}
	
	
	cout<<"Tengo "<< numlistas<< " listas" << endl;
	
	Lista l[numlistas];

	/* Me arma la lista enlazada */ 
	
	int compara=arcos[0].get_source();
	int numlista=0;
	l[numlista].agregar(&arcos[0]);
	for(int i=1; i<numnodos;i++){
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

	for(int i=0; i< numlistas ;i++){
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
	v[contt].set_origen(&arregloo[j+1]);
	v[contt].set_final(&arregloo[j+2]);
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
		for(int j=0; j< numnodos; j++){ 
			
			if(*v[i].get_origen() == arcos[j].get_source() && *v[i].get_final() == arcos[j].get_dest()  ){
				arcos[j].insertar(&v[i]);
	
			//	arcos[j].set_weight(s[j].getCantDeVehiculos());
	
			}
		}
	}
	getchar();
	
	/* Me muestra la lista armada con la cantidad de autos */

	for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}
	
	getchar ();
	
	/* Aca pruebo de aumentar un semaforo y se cambia todo */	
/*	arcos[2].insertar(&v[1]);
	
		for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}*/
	
	
	
	/*Me hace una lista de mayor a menor de los semaforos */

	heapSemaforos hsemaforo;
	
	for(int i=0; i<numnodos;i++){

		hsemaforo.insert(&(arcos[i].get_weight()));
	}
	
/* Aca pruebo eliminar y me elimina de la ciudad */

	/*getchar();
	hsemaforo.print();
	cout<<endl<<endl;
	hsemaforo.eliminar(0);
	hsemaforo.print();
	cout<<endl<<endl;
	getchar();
	
	for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}
*/


	
	
	/*ACA PRUEBO ELIMINAR VEHICULOS Y QUE ELIMINE TAMBIEN DEL HEAPSEMAFOROS*/
	
	/*	hsemaforo.print();
		cout<<endl<<endl;
		getchar();
		
		
		for(int i=0;i<numnodos;i++){
		cout<<"Soy autos de semaforo "<< i<<endl;
		arcos[i].get_print();
		cout<<endl<<endl;;
	}
	
	getchar();
	
	Vehiculos *ve;
	ve=arcos[1].eliminaVehiculos();
	
	
	for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}
	
	hsemaforo.print();
	cout<<endl<<endl;
	
	getchar();
	
	for(int i=0;i<numnodos;i++){
		cout<<"Soy autos de semaforo "<< i<<endl;
		arcos[i].get_print();
		cout<<endl<<endl;;
	}
	*/
	
	/*ACA VOY A PROBARA INSERTAR EL AUTO QUE ACABO DE ELIMINAR */
	

	

	
	hsemaforo.print();
		cout<<endl<<endl;
		getchar();
		
		
		for(int i=0;i<numnodos;i++){
		cout<<"Soy autos de semaforo "<< i<<endl;
		arcos[i].get_print();
		cout<<endl<<endl;;
	}
	
	getchar();
	
	int patedevuelta=0;

	
	patedevuelta=arcos[1].eliminaVehiculos1();
	
	cout<<"Soy patente devuelta "<<patedevuelta<<endl;
	
	int a;
	int b;
	
	a=arcos[2].get_source();
	b= arcos[2].get_dest();
	
	cout<<"Soy nuevo source "<<a<<endl;
	cout<< "Soy nuevo dest "<<b<<endl;
	
	v[patedevuelta].set_origen(&arcos[2].get_source());
	v[patedevuelta].set_final(&arcos[2].get_dest());
	
	arcos[2].insertar(&v[patedevuelta]);
	
	
	hsemaforo.print();
		cout<<endl<<endl;
		getchar();
		
		
		for(int i=0;i<numnodos;i++){
		cout<<"Soy autos de semaforo "<< i<<endl;
		arcos[i].get_print();
		cout<<endl<<endl;;
	}

}


