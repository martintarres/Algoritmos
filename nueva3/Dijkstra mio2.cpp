#include <iostream>
#include <fstream>
#include "prueba3.cpp"
using namespace std;

class Dijkstra{
	private:
		  
		int distancia[num_listas];
		int previo[num_listas];
		heapSemaforos t, t1;
		Semaforo auxiliar;
		int* actual;
		bool visitado[num_listas];
		heapSemaforos q;
		int y;      
		int previoS[30];        // 64  va guardando los previos solamente del auto solicitado;      
		void cargaPrevios(int);
		int p;
		
public:
	Dijkstra(){
		for(int i=0; i< num_listas; i++){	
		visitado[ i ] = false;
		distancia[i]=INF;
		previo[i]=-1;
		previoS[i] = -1;
		}
		t;
		int V;
		p = -1;
		
	}
	void dijkstra(Lista a[], int*, int* );
	void relajacion(int actual, int adyacente, int peso);
	void print (int);
	int getPrevios(int);
	
};

void Dijkstra::dijkstra(Lista a[], int* k, int* y){
	Lista A[MAX];
	int adyacente;
	int peso;
	int x;
	
//	Edge e(k, k, 0);
//	Semaforo s(e);
	
	Semaforo s(*k,*k,0, 0);
	q.insert(&s.get_weight());
	distancia [0]= 0;
	distancia [*k] = 0;
	
	while(q.size()-q.lugaresDisponibles() !=0)
	{
		actual = q.eliminarFondo();
		if (visitado[*actual] ) continue;
			visitado[*actual] = true;
			for(int i= 0; i< a[*actual - 1].getContador() ; i++){
				adyacente = a[*actual-1].destinos(i);
				peso = a[*actual-1].pesos(i);
				if(!visitado[adyacente]){
					relajacion(*actual, adyacente, peso);
				}
			}
	}
	for (int l=0; l<6; l++){
		cout << "Vertice" << l<< endl;
		cout << "distancia l: " << distancia [l] << " " ;
		cout << "previo l: "<<previo [l];
		cout << endl;
	}
	cout << "ingrese destino" << endl;
	//cin >> x;			
	print(*y);
	cargaPrevios(*y);
	cout << "arreglo de previos de x: " << endl;
	
	for (int k = 0; k< 20 ; k++){
	
	cout <<	previoS[k] << " ";
	}
	cout << endl;
}

void Dijkstra::relajacion(int actual, int adyacente, int peso)
{
		if(distancia[actual] + peso < distancia[adyacente]){
			distancia[adyacente] = distancia [actual] + peso;
			previo [adyacente] = actual;
			Semaforo s(actual, adyacente, distancia[adyacente], 0);
			//Edge e(actual, adyacente, distancia[adyacente]);
		//	Semaforo s(e);
			q.insert(&s.get_weight());
		}	

}
void Dijkstra::print(int destino){
	
	if( previo[ destino ] != -1 )    //si aun poseo un vertice previo
        //print (previo [destino]);
		print( previo[ destino ] );  //recursivamente sigo explorando
    //printf("%d " , destino );   
	cout << destino << " ";
}
void Dijkstra::cargaPrevios(int buscaprevio){
	p++ ;
	int l=0;
	if( previo[ buscaprevio ] != -1 ){    //si aun poseo un vertice previo
        l= previo[buscaprevio];
		previoS[p] = l;
		cargaPrevios( previo[ buscaprevio ] );
		}  
}
int Dijkstra::getPrevios(int y){
	return previoS[y];
	}
	
			



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

ifstream archivoo("ficheroAutos1.txt"); 
if(archivoo.good()){ 
while(archivoo>>numeroo) 

arregloo[qq++]=numeroo;
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
	
	/*for(int i=0;i<totalveh;i++){
		cout<<v[i].get_patente();
		cout<<" ";
		cout<<*v[i].get_origen();
		cout<<" ";
		cout<<*v[i].get_final();
		cout<<" ";
		cout<<v[i].get_prioridad();
		cout<<endl;
	}*/


	/*AVERIGUO EL NUMERO DE NODOS QUE VOY A TENER*/

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
	arcos[cont].set_numero(cont);
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

 
/*--------------------------------------------------------*/

/*	 cola c;
	c.delante = NULL;
	c.atras   = NULL;
	int dato;  // numero a encolar
	int op;    // opcion del menu
	int x ;    // numero que devuelve la funcon pop


	/*ACA ESTABA PROBANDO COMO FUNCIONA LA COLA */
	/*	
	for(int i=0;i<numnodos;i++){
		encolar(c,arcos[i]);
	}
	
	
	 cout << "\n\n MOSTRANDO COLA\n\n";
                 if(c.delante!=NULL) muestraCola( c );
                 else   cout<<"\n\n\tCola vacia...!"<<endl;
           
	desencolar(c);
	
	getchar();
	
	
	cout << "\n\n MOSTRANDO COLA\n\n";
                 if(c.delante!=NULL) muestraCola( c );
                 else   cout<<"\n\n\tCola vacia...!"<<endl;

	*/
	
		for(int i=0; i<totalveh;i++){
			
		int num_aleat =0;
		num_aleat = 2+rand()%(65-2);
		
	//	v[i].set_final(&num_aleat);
		int origen;
		int final;
		origen=*v[i].get_origen();
		final=*v[i].get_final();
		
		cout<<origen<<endl;
		cout<<final<<endl;
		cout<<endl<<endl;
	
		Dijkstra p;
	//	p.dijkstra(l, v[i].get_origen() , v[i].get_final());	
	
	}

	//Dijkstra d;
//	d.dijkstra(arcos,numnodos);

	//dijkstra(arcos);
	


}

