#include <iostream>
#include <fstream>
#include "prueba3.cpp"
using namespace std;

struct nodo
{
    int* nro;
    struct nodo *sgte;
};
 
 
/*                      Estructura de la cola      
------------------------------------------------------------------------*/
struct cola
{
    nodo *delante;
    nodo *atras  ;
    
};
 
 
/*                        Encolar elemento      
------------------------------------------------------------------------*/
void encolar( struct cola &q, int* valor )
{
     struct nodo *aux = new(struct nodo);
     
     aux->nro = valor;
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;   // encola el primero elemento
     else
         (q.atras)->sgte = aux;
         
     q.atras = aux;        // puntero que siempre apunta al ultimo elemento
     
}
 
/*                        Desencolar elemento      
------------------------------------------------------------------------*/
int* desencolar( struct cola &q )
{
     int* num ;
     struct nodo *aux ;
     
     aux = q.delante;      // aux apunta al inicio de la cola
     num = aux->nro;
     q.delante = (q.delante)->sgte;
     delete(aux);          // libera memoria a donde apuntaba aux
     //contador--;
     return num;
}
 
/*                        Mostrar Cola      
------------------------------------------------------------------------*/
void muestraCola( struct cola q )
{
     struct nodo *aux;
     
     aux = q.delante;
         
     while( aux != NULL )
     {
            cout<<"("<< *aux->nro<<") ";
          //  cout<<*aux->nro->get_dest()<<")"<<endl;
            aux = aux->sgte;
     }    
}


/*------------------------------------------------------------------------*/

/*                        Tamaño Cola      
------------------------------------------------------------------------*/
int tamCola( struct cola q )
{
     struct nodo *aux;
     int contador=0;
     aux = q.delante;
         
     while( aux != NULL )
     {
            contador++;
            aux = aux->sgte;
     } 
	 return contador;   
}


/*------------------------------------------------------------------------*/




class di{
	public:
		di();
		void dijkstra(Lista l[], int*, int*);
		void relajacion(int* , int*, int);
		void print(int destino);
		
		
	private:
		int distancia[50];
		int previo[50];
	//	heapSemaforos qas;
		int* actual;
		int* adyacente;
		bool visitado[50];
		int previos[30];
		struct cola c;
		int peso;
		
};

di::di(){
	for(int i=0; i<9;i++){
		visitado[i]=false;
		distancia[i]=999;
		previo[i]=-1;
		
   		c;
    	c.delante = NULL;
    	c.atras   = NULL;
	}
}

void di::dijkstra(Lista l[],int* k, int* y){
//	int actual;
	int* s;
	s=l[0].getSource();
	cout<<*s<<endl;
	
	encolar (c,s);
	
		cout << "\n\n MOSTRANDO COLA\n\n";
                 if(c.delante!=NULL) muestraCola( c );
                 else   cout<<"\n\n\tCola vacia...!"<<endl;
     
     int a=0;
    distancia[*s]= 0;
    //cout<<a<<endl;
    	cout<<endl<<"Soy distancia de " << *s << " y soy " << distancia[*s]<<endl;
   while(tamCola(c)!=0){
   	
    	actual=desencolar(c);
    		cout<<"Desencole " << *actual<<endl;
    	cout<<"Soy actual "<<*actual<<endl;
    	if(visitado[*actual]) continue;
    	visitado[*actual]=true;
    	for(int i=0;i<l[*actual-1].getContador();i++){
    //		if( !visitado[actual->get_numero()] ){
		
    		adyacente=l[*actual-1].destinos(i);
    		cout<<"Soy adyacente " << *adyacente<<endl;
    		peso=l[*actual-1].pesos(i);
    		cout<<"Soy peso "<< peso<<endl;
    		if(!visitado[*adyacente]){
    			relajacion(actual, adyacente, peso);
			}
	//	}*/
	}
	}
	
	print(3);
}
	
void di::relajacion(int* actual, int* adyacente, int peso){
	if(distancia[*actual]+ peso < distancia[*adyacente]){
		cout<<"Soy distancia antes de " << *adyacente << " y soy " << distancia[*adyacente]<<endl;
		distancia[*adyacente] = distancia[*actual] + peso;
		cout<<"Soy distancia de " << *adyacente << " y soy " <<distancia[*adyacente]<<endl;
		previo[*adyacente] = *actual;
		cout<<"Soy previo "<< previo[*adyacente]<<endl;
		cout<<"Voy a encolar "<< *adyacente<<endl;
		encolar(c, adyacente);
			cout << "\n\n MOSTRANDO COLA\n\n";
                 if(c.delante!=NULL) muestraCola( c );
                 else   cout<<"\n\n\tCola vacia...!"<<endl;
	}
}

void di::print(int destino){
	if(previo[destino] != -1)
		print(previo[destino]);
	cout<<destino<< " ";	
	
}
//	actual=
//	for
	
/*	int adyacente;
	int peso;
	
	int* a;
	int* b;
	int c;
	int d;
	a=l[0].getSource();
	cout<<*a<<endl;
	b=l[0].getDest();
	cout<<*b<<endl;
	c=l[0].pesos(0);
	cout<<c<<endl;
	d=l[0].numeros(0);
	cout<<d<<endl;
	getchar();
	Semaforo s[20];  
	int sema;
	sema=tamCola(c);
	cout<<"soy numero semaforo "<<sema<<endl;
	s[sema].set_source(a);
	s[sema].set_dest(l[0].getDest());
	s[sema].set_weight(&b);
	s[sema].set_source(0);
	
	cout<<s[sema].get_source()<<endl;
	cout<<*s[sema].get_dest()<<endl;
	cout<<*s[sema].get_weight()<<endl;
//	cout<<*s[sema].get_weight()<<endl;
	
	encolar(c,s[0]);

	cout << "\n\n MOSTRANDO COLA\n\n";
                 if(c.delante!=NULL) muestraCola( c );
                 else   cout<<"\n\n\tCola vacia...!"<<endl;
  //      int a;        
 //   a=tamCola(c);
//	cout<<a;*/



/*	distancia[0]=0;
	distancia[*k]=0;
	
	while (tamCola(c)!=0){
		Semaforo aux;
		aux=desencolar(c);
	//	a--;
	//	aux.get_dest();
		actual=aux.get_source();
		cout<<"Soy actual "<<aux.get_numero()<<endl;
		
		if(visitado[*actual]) continue;
			visitado[*actual]= true;
			
		for(int i=0;i<l[*actual-1].getContador(); i++ ){
			adyacente= l[*actual-1].destinos(i);
			cout<<"Soy adyacente " << adyacente<<endl;
			peso=l[*actual-1].pesos(i);
			cout<<"Soy peso "<< peso<<endl;
			if(!visitado[adyacente]){
				relajacion(actual, adyacente, peso);
			//cout<<"entre a relajacion"<<endl;
			}
		}
	}
*/

/*
void di::relajacion(int* actual, int adyacente, int peso){
	int a=1;
	if(distancia[*actual]+peso < distancia[adyacente]){
		distancia[adyacente]=distancia[*actual] + peso;
		previo[adyacente]= *actual;
		cout<<"Soy previo "<<previo[adyacente];
		Semaforo s(actual, &adyacente, &distancia[adyacente], a);
		encolar(c, s);
			cout << "\n\n MOSTRANDO COLA\n\n";
                 if(c.delante!=NULL) muestraCola( c );
                 else   cout<<"\n\n\tCola vacia...!"<<endl;
	}
}
*/
int main(){


int numeroo, arregloo[300], gg;
int h=0;
int k = 0;
int g=0,arreglo[250],numero; 
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
	
	int cont=0;
	for(int j=0;j<g;j++) {
	
	arcos[cont].set_source(&arreglo[j]);
	arcos[cont].set_dest(&arreglo[j+1]);
	arcos[cont].set_weight(&arreglo[j+2]);
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
		
		compara= *arcos[i].get_source();
	
			if(compara!= *arcos[i+1].get_source()){
				numlistas++;
			
			}	
		}
	
	
	cout<<"Tengo "<< numlistas<< " listas" << endl;
	
	Lista l[numlistas];

	/* Me arma la lista enlazada */ 
	
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

	for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}
	
	/*Averiguo numero de autos */

	int totalveh=0;
	for(int i=0;i<gg;i++){
	totalveh++;
	
	}
	totalveh=totalveh/4;
	cout<<"son "<<totalveh<< " Vehiculos "<<endl;
	
	/*Me carga los vehiculos*/

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
		int *a,*b,*c,*d;
			a=v[i].get_origen();
			b=arcos[j].get_source();
			c=v[i].get_final();
			d=arcos[j].get_dest();
		/*	
			cout<<*a<<" Soy a"<<endl;
			cout<<*b<<" Soy b"<<endl;
			cout<<*c<<" Soy c"<<endl;
			cout<<*d<<" Soy d"<<endl;*/
			if((*a == *b) && (*c == *d )){
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

di djk;
	for (int i=0; i<1;i++){
		
		int num_aleat =0;
		num_aleat = 2+rand()%(65-2);
		int a,b;
		//a=1;
	//	b=3;
		//v[i].set_origen(&a);
		v[i].set_final(&num_aleat);
		
		cout<<*v[i].get_origen()<<endl;
		cout<<*v[i].get_final()<<endl;
		cout<<endl<<endl;
			
		djk.dijkstra(l, v[i].get_origen(),v[i].get_final());
	}
	
/*	struct cola c;
   
    c.delante = NULL;
    c.atras   = NULL;
   
   
    int dato;  // numero a encolar
    int op;    // opcion del menu
    int x ;    // numero que devuelve la funcon pop
   
	//cola c;
	encolar(c,arcos[0]);
	encolar (c,arcos[1]);
	
	
	 cout << "\n\n MOSTRANDO COLA\n\n";
                 if(c.delante!=NULL) muestraCola( c );
                 else   cout<<"\n\n\tCola vacia...!"<<endl;
	
	desencolar( c );
 cout << "\n\n MOSTRANDO COLA\n\n";
                 if(c.delante!=NULL) muestraCola( c );
                 else   cout<<"\n\n\tCola vacia...!"<<endl;
*/

	
}

	





