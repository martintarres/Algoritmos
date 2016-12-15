#include <iostream>
#include <fstream>
//#include "prueba3.cpp"
#include "heapdjk2.cpp"
using namespace std;

class di{
	public:
		di();
		int* dijkstra(Lista l[], Semaforo*, int*, Vehiculos*);
		void relajacion(int* , int*, int, Semaforo*);
		int* print(int destino, Vehiculos*, int sourceactual);
		
		
	private:
		int distancia[30];
		int previo[30];

		int* actual;
		int* adyacente;
		bool visitado[30];
		int previos[30];
		bool imprimir;
		heapdjk hsemaforo;
		int peso;
		
};

di::di(){
	for(int i=0; i<9;i++){
		visitado[i]=false;
		distancia[i]=999;
		previo[i]=-1;
		
   		//c;
    //	c.delante = NULL;
    //	c.atras   = NULL;
	}
	imprimir=false;
}

int* di::dijkstra(Lista l[],Semaforo* sourceactual, int* destactual, Vehiculos* v){
//	int actual;
//	cout<< sourceactual->get_numero();

int asd=0;

	hsemaforo.insert(*sourceactual);
	
   //  cout<<"voy a mostrar cola"<<endl;
   // hsemaforo.print();
   // cout<<endl;
     int a=0;
    distancia[*sourceactual->get_source()]= 0;
    //cout<<a<<endl;
   // cout<<endl<<"Soy distancia de " <<*sourceactual->get_source() << " y soy " << distancia[*sourceactual->get_source()]<<endl;
  
   while(hsemaforo.tamano()!=0){
   	Semaforo aux;
   	aux=hsemaforo.eliminaradjk();
   	
   	if(asd==0){
   		actual=aux.get_source();
   		asd++;
	   }else {
	   	actual=aux.get_dest();
	   }
   		
   // 	actual=desencolar(c);
    	//	cout<<"Desencole " << *actual<<endl;
    	//cout<<"Soy actual "<<*actual<<endl;
    	if(visitado[*actual]) continue;
    	visitado[*actual]=true;
    	for(int i=0;i<l[*actual-1].getContador();i++){
    //		if( !visitado[actual->get_numero()] ){
		Semaforo *aux2;
		Semaforo *aux3;
		aux2=l[*actual-1].Sdestinos(i);
	//	cout<<"Soy Semaforo actual: "<<aux2->get_numero()<<endl;
    		adyacente=l[*actual-1].destinos(i);
    
    	aux3=l[*adyacente-1].Sdestinos(i);
    //	cout<<"Soy semaforo adyacente :" << aux3->get_numero()<<endl;
    	//	cout<<"Soy adyacente " << *adyacente<<endl;
    		peso=l[*actual-1].pesos(i);
    	//	peso=aux2->get_weight();
    	//	cout<<"Soy peso "<< peso<<endl;
    		if(!visitado[*adyacente]){
    			relajacion(actual, adyacente, peso, aux2);
			}
	//	}
	}
	}
	
	
	
	print(*destactual, v, *sourceactual->get_source());
	imprimir=false;
	for(int i=0; i<9;i++){
		visitado[i]=false;
		distancia[i]=999;
		previo[i]=-1;
	}
}
	
void di::relajacion(int* actual, int* adyacente, int peso, Semaforo*  aux2){
	if(distancia[*actual]+ peso < distancia[*adyacente]){
	//	cout<<"Soy distancia antes de " << *adyacente << " y soy " << distancia[*adyacente]<<endl;
		distancia[*adyacente] = distancia[*actual] + peso;
	//	cout<<"Soy distancia de " << *adyacente << " y soy " <<distancia[*adyacente]<<endl;
		previo[*adyacente] = *actual;
	//	cout<<"Soy previo "<< previo[*adyacente]<<endl;
	//	cout<<"Voy a encolar "<< *adyacente<<endl;
		hsemaforo.insert(*aux2);

      //   cout<<"voy a mostrar cola"<<endl;
  //  hsemaforo.print();
  //  cout<<endl;
	}
}

int* di::print(int destino,Vehiculos* v, int source){

	if(previo[destino] != -1){// && imprimir==true)
		
		print(previo[destino],v, source);
		

	

	}
	v->set_camino(destino);

}

int main(){

const int N = 3;
int numeroo, arregloo[130], gg;
int h=0;
int k = 0;
int g=0,arreglo[150],numero; 
int numnodos=0;

ifstream archivo("ficheroTexto.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 

arreglo[g++]=numero;	

}

ifstream archivoo("ficheroAutos5.txt"); 
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
	arcos[cont].set_weight(arreglo[j+2]);
	arcos[cont].set_numero(cont);
	cont++;
	j=j+2;
	
}


//cout<<arcos[1].get_source();

/*  ME MUESTRA QUE SE CARGUEN TODOS LOS ARCOS*/
/*
	for(int i=0;i<numnodos;i++){
		cout<<*arcos[i].get_source();
		cout<<" ";
		cout<<*arcos[i].get_dest();
		cout<<" ";
		cout<<*arcos[i].get_weight();
		cout<<endl;
	}
*/

	/* ME AVERIGUA LA CANTIDAD DE NODOS */
	
	int numlistas=0;
	for(int i=0;i<numnodos;i++){
		int* compara=0;
		
		compara= arcos[i].get_source();
	
			if(compara!= arcos[i+1].get_source()){
				numlistas++;
				//cout<<numlistas<<endl;
			
			}	
		}

	getchar();
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
		cout<<*v[i].get_origen();
		cout<<" ";
		cout<<*v[i].get_final();
		cout<<" ";
		cout<<v[i].get_prioridad();
		cout<<endl;
	}*/

getchar();
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
	/*	
	heapdjk hsemaforo;

	
	for(int i=0; i<numnodos;i++){

		hsemaforo.insert((arcos[i]));
	}
	
	getchar();
	hsemaforo.print();
	cout<<endl<<endl;

	for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}
	*/
/*--------------------------------------------------------*/

di djk;

	for (int i=0; i<totalveh;i++){
		
		int num_aleat =0;
		num_aleat = 2+rand()%(10-2);
		int a,b;
		//a=1;
	//	b=3;veh
		//v[i].set_origen(&a);
		v[i].set_final(&num_aleat);
		
	/*	cout<<*v[i].get_origen()<<endl;
		cout<<*v[i].get_final()<<endl;
		cout<<endl<<endl;
	*/		
		int sourceactual=0;	
		for(int j=0;j<numnodos;j++){
			
			if(*v[i].get_origen() == *arcos[j].get_source()){
			//	cout<<"Vehiculo "<<v[i].get_patente()<<" mi origen es el semaforo numero "<<arcos[j].get_numero()<<endl;
				sourceactual=arcos[j].get_numero();
			}
		}	
			
		int destactual=0;	
		for(int j=0;j<numnodos;j++){
			
			if(*v[i].get_final() == *arcos[j].get_source()){
			//	cout<<"Vehiculo "<<v[i].get_patente()<<" mi destino es el semaforo numero "<<arcos[j].get_numero()<<endl;
				destactual=arcos[j].get_numero();
			}
		}
		
		
		djk.dijkstra(l, &arcos[sourceactual], arcos[destactual].get_source() ,&v[i]);
		
		cout<<"Soy camino desde main para auto "<<v[i].get_patente()<<endl;
		cout << "mi origen y destino actual son: " << *v[i].get_origen() << " " << *v[i].get_final();
		cout << "camino: " << endl;
		for(int j=0; j< v[i].tamcamino();j++){
			cout<<v[i].get_camino(j)<<" ";
		//	cout<<endl;
		}
		cout<<endl;
	//	cout<<endl<<endl;
	//	getchar();
	}

		cout<<" aca cada auto ya tiene djk hecho"<<endl;
/*--------------------------------------------------------*/
	heapdjk hsemaforo;

	
	for(int i=0; i<numnodos;i++){

		hsemaforo.insert((arcos[i]));
	}
	
	getchar();
	hsemaforo.print();
	cout<<endl<<endl;

	for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}
	
	heapSemaforos hsemaforo1;
	
	for(int i=0; i<numnodos;i++){

		hsemaforo1.insert((&arcos[i].get_weight()));
	}
	getchar();
	hsemaforo1.print();
	cout<<endl<<endl;
/*--------------------------------------------------------*/
int n =3;
int m =0; //m es reemplazo de N cuando N es mayor que la cantidad de autos a sacar;
	int prin=0;
	int tamano=0;
	tamano=hsemaforo.tamano();
	Vehiculos mio;
	bool terminadomio=false;
	int soy=0;
	for(int i=0;i<totalveh;i++){
		if(v[i].get_patente()==0){
			mio=v[i];
		}
	}
	
	cout<<"Soy vehiculo mio"<<endl;
	cout<<*mio.get_origen()<<endl;
	cout<<*mio.get_final()<<endl;
	cout<<mio.get_patente()<<endl;
	cout<<mio.get_prioridad();
	
	while(terminadomio!=true){
		
		
	
	
	while(prin != tamano){
	
	
//	for(int j=0;j<1;j++){
		
	

//	for(int i=0; i<3;i++){
		
		int a;
		a=hsemaforo.getArco(prin);
		
		if(*arcos[a].get_source()!= 999){
		
		cout<<"Soy semaforo a sacar "<< a<<endl;
		if(arcos[a].get_weight() > 0){
			//////////////////////
			if (arcos[a].get_weight() < N){
				m = arcos[a].get_weight();
			}else m =N;
				for (int k=0; k<m; k++){ 		//comienza sacado.
		cout << "nueva eliminación ///////////////////////////////////////////" << endl;
		Vehiculos* aux;
		Semaforo*  auxsem;
		cout<<"Antes de mover el vehiculo"<<endl;
		hsemaforo1.print();
		
		aux=arcos[a].mover();
		cout<<"Soy vehiculo " <<aux->get_patente()<<endl;
		auxsem=&arcos[aux->get_camino(0)];
		cout<<"Soy a donde voy a insertar "<<auxsem->get_numero()<<endl;
		if(aux->getPase()==false){
			
				for(int i=0;i<totalveh;i++){
					if(v[i].get_prioridad()== 2){
						v[i].set_prioridad(-2);
					}
				if(v[i].get_prioridad()== 0){
					v[i].set_prioridad(-1);
			}
			}
		aux->activarPase();

	//cout<<"Soy vehiculo "<<aux->get_patente()<<" y mi prioridad despues es "<< aux->get_prioridad()<<endl;
	//cout<< "Soy vechiulo sacado de semaforo "<< a <<" y soy "<< aux->get_patente()<<endl; 
	//cout<<"Soy vehiculo "<<aux->get_patente()<<" y me voy a "<<v[aux->get_patente()].get_camino(0)<<endl;
	//cout<<"Soy auxsem"<< auxsem.get_numero()<<endl;
//	cout<<"Voy a mostrar semaforo antes"<<endl;
//	arcos[v[aux->get_patente()].get_camino(0)].print();
	
	auxsem->insertar(aux);
	aux->set_origen(auxsem->get_source());
	cout<<"Despues de mover el vehiculo"<<endl;
	hsemaforo1.print();
//	cout<<"y despues "<<endl;
//	arcos[v[aux->get_patente()].get_camino(0)].print();
	cout<<"soy semaforo "<<auxsem->get_numero()<< " y me acaban de insertar el vehiculo " << aux->get_patente()<< " y quede "<<endl;
	aux->avanzarcamino();
	
	if(aux->get_patente()==0 && aux->get_camino(0)==0){
		terminadomio=true;
		cout<<"terminadomio es true"<<endl;
		getchar();
	}

	
	
	//	for (int i=0; i<totalveh;i++){
	cout<<"Soy camino desde main para auto "<<aux->get_patente()<<endl;
		for(int j=0; j< aux->tamcamino();j++){
			cout<<aux->get_camino(j)<<" ";
		//	cout<<endl;
		}
		cout<<endl;
//	hsemaforo.print();
	
	if(aux->getTermine()!= false){
	//	getchar();
		cout<<aux->get_patente()<< " llegue a mi destino"<<endl;
		Vehiculos* aux1;
			cout<<"Voy a mostrar antes de eliminar que llegue a mi destino"<<endl;
		hsemaforo1.print();
		aux1=auxsem->elminarVehiculos(aux);
		//cout<<"Soy patente devuelta "<<aux1->get_patente()<<endl;
	
	
	
	/*EN ESTA PARTE ES LO QUE TE DIGO */ 
	
		
	
		arcos[numnodos-1].insertarlistos(aux1);
		aux1->set_origen(arcos[numnodos-1].get_source());
		cout<<"Voy a mostrar despues de eliminar que llegue a mi destino"<<endl;
		hsemaforo1.print();
		
	

	}
	}else {
		cout<<aux->get_patente()<<" ya paso"<<endl;
		arcos[a].insertar(aux);
			}
	
		}
	
	}
	}
	prin++;
	getchar();
	//}

	}

	prin=0;


	for(int i=0;i<totalveh;i++){
			v[i].desactivarPase();
					if(v[i].get_prioridad()== -2){
						v[i].set_prioridad(2);
					}
				if(v[i].get_prioridad()== -1){
					v[i].set_prioridad(0);
			}
			}

	

	cout<<"Ya termine, ahora voy a actualizar: "<<endl;
	hsemaforo.borrar();
	for(int i=0; i<numnodos;i++){

		hsemaforo.insert((arcos[i]));
	}
	hsemaforo.print();
	
	
	for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}
	
	
	getchar ();
	for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}
	
	
	
/*	cout<<"voy a mostrar los vehiculos antes"<<endl;
		for(int i=0;i<totalveh;i++){
			cout<<v[i].get_patente()<<endl;
		}
		
	for(int i=0;i<totalveh;i++){
		if(v[i].getTermine()!=false){
			cout<<"Entre en "<<v[i].get_patente()<<endl;
			for(int j=i;j<totalveh;j++){
				v[j]=v[j+1];
			}
			totalveh--;
		}
	}
	cout<<"voy a mostrar los vehiculos despues"<<endl;
		for(int i=0;i<totalveh;i++){
			cout<<v[i].get_patente()<<endl;
		}
	*/
	
			}
	

	
}
