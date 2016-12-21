#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<time.h>
#include "heapdjk.cpp"
using namespace std;

class di{
	public:
		di();
		int* dijkstra(Lista l[], Semaforo*, int*, Vehiculos*);
		void relajacion(int* , int*, int, Semaforo*);
		int* print(int destino, Vehiculos*, int sourceactual);
		
		
	private:
		int distancia[200];
		int previo[200];

		int* actual;
		int* adyacente;
		bool visitado[200];
		int previos[200];
		bool imprimir;
		heapdjk hsemaforo;
		int peso;
		
};

di::di(){
	for(int i=0; i<200;i++){
		visitado[i]=false;
		distancia[i]=999;
		previo[i]=-1;

	}
	imprimir=false;
}

int* di::dijkstra(Lista l[],Semaforo* sourceactual, int* destactual, Vehiculos* v){


int asd=0;

	hsemaforo.insert(*sourceactual);
	

     int a=0;
    distancia[*sourceactual->get_source()]= 0;
    
   
  
   while(hsemaforo.tamano()!=0){
   	Semaforo aux;
   	aux=hsemaforo.eliminarfdjk();
   	
   	if(asd==0){
   		actual=aux.get_source();
   		asd++;
	   }else {
	   	actual=aux.get_dest();
	   }
   		
   
   
    	if(visitado[*actual]) continue;
    	visitado[*actual]=true;
    	for(int i=0;i<l[*actual-1].getContador();i++){
   
		Semaforo *aux2;
		Semaforo *aux3;
		aux2=l[*actual-1].Sdestinos(i);
	
    		adyacente=l[*actual-1].destinos(i);
    
    	aux3=l[*adyacente-1].Sdestinos(i);
    
    		peso=l[*actual-1].pesos(i);
    
    		if(!visitado[*adyacente]){
    			relajacion(actual, adyacente, peso, aux2);
			}

	}
	}
	
	
	
	print(*destactual, v, *sourceactual->get_source());
	imprimir=false;
	for(int i=0; i<200;i++){
		visitado[i]=false;
		distancia[i]=999;
		previo[i]=-1;
	}
}
	
void di::relajacion(int* actual, int* adyacente, int peso, Semaforo*  aux2){

	if(distancia[*actual]+ peso < distancia[*adyacente]){
		
		distancia[*adyacente] = distancia[*actual] + peso;

		previo[*adyacente] = *actual;

		hsemaforo.insert(*aux2);

   
	}
}

int* di::print(int destino, Vehiculos* v, int source){

	if(previo[destino] != -1){
		
		print(previo[destino],v, source);
		

	

	}
	v->set_camino(destino);

}

int main(){

const int N = 12; // constante que determina cuántos autos se van a sacar.
int numeroo, arregloo[1000], gg;
int h=0;
int k = 0;
int g=0,arreglo[1000],numero; 
int numnodos=0;
int semaforoActual[50];
int z =0;



ifstream archivo("ficheroTexto.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 

arreglo[g++]=numero;	

}

ifstream archivoo("ficheroAutos.txt"); 
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
		int* compara1=0;
		compara= arcos[i].get_source();
		compara1=arcos[i+1].get_source();
			if( compara==compara1){
				numlistas++;
				
			
			}	
		}
	
	numlistas=64;
	getchar();
	cout<<"Tengo "<< numlistas<< " listas" << endl;
	cout << "Semaforos:" << endl;
	cout << "(Origen, Destino, Peso, Numero)" << endl;
	cout << endl;
	numlistas=65;
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
				semaforoActual[i] = arcos[j].get_numero();  //guardo dónde se ubico el priimer auto, luego el segundo y así...
			
	
			}
		}
	}
	getchar();
	
	/* Me muestra la lista armada con la cantidad de autos */
	cout << "Semaforos:" << endl;
	cout << "(Origen, Destino, Peso, Numero)" << endl;
	cout << endl;
	for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}
	
	getchar ();


/*--------------------------------------------------------*/

di djk;
srand(time(NULL));
ofstream ficheroSalida;
ficheroSalida.open ("textoDeSalida.txt");
int y=0;
	/*ACA LE DOY A CADA VEHICULO UN NUEVO DESTINO PARA ALEATORIO*/

	for (int i=0; i<totalveh;i++){
	
		if(v[i].get_patente()==0){
			cout<<"Elija el destino de su auto"<<endl;
			int x;
			cin>>x;
			v[i].set_final(&x);
		}else{
		
	
	
		int num_aleat =0;
		num_aleat = 2+rand()%(65-2);
		int a,b;
	
		v[i].set_final(&num_aleat);
		
}
		int sourceactual=0;	
		for(int j=0;j<numnodos;j++){
			
			if(*v[i].get_origen() == *arcos[j].get_source()){
		
				sourceactual=arcos[j].get_numero();
			}
		}	
			
		int destactual=0;	
		for(int j=0;j<numnodos;j++){
			
			if(*v[i].get_final() == *arcos[j].get_source()){
			
				destactual=arcos[j].get_numero();
			}
		}
	
		cout<<"Vehiculo "<<i<< " origen "<< *v[i].get_origen() << " y destino "<< *v[i].get_final() <<endl;
		
		/*LLAMO A DIJKSTRA */
		
		djk.dijkstra(l, &arcos[sourceactual], arcos[destactual].get_source() ,&v[i]);
	
		/* MUESTRO EL CAMINO DE CADA VEHICULO */
		ficheroSalida << "-------------------------------------------------" << endl;
		ficheroSalida <<"Vehiculo "<<i<< " origen "<< *v[i].get_origen() << " y destino "<< *v[i].get_final() <<endl;
		ficheroSalida <<"Se guardó en semaforo " << semaforoActual[i]<< endl;
		cout<<"Camino para auto "<<v[i].get_patente()<<endl;
		for(int j=0; j< v[i].tamcamino();j++){
			cout<<v[i].get_camino(j)<<" ";
			ficheroSalida <<v[i].get_camino(j)<<" ";
			
		
		}
		ficheroSalida << endl;
		ficheroSalida << endl;
		cout<<endl;
		cout<<endl;

	}


/*--------------------------------------------------------*/

	/*ACA SE CREAN LOS HEAP DE SEMAFOROS */
	
	heapdjk hsemaforo;

	
	for(int i=0; i<numnodos;i++){

		hsemaforo.insert((arcos[i]));
	}
	
	getchar();
	cout << "muestro hsemaforo: " << endl;
	hsemaforo.print();
	cout<<endl<<endl;
	cout << "Semaforos:" << endl;
	cout << "(Origen, Destino, Peso, Numero)" << endl;
	cout << endl;
	for(int i=0; i< numlistas ;i++){
		l[i].mostrar();							//mostrador de listas.
		cout<<endl;
	}
	
	heapSemaforos hsemaforo1;
	
	for(int i=0; i<numnodos;i++){

		hsemaforo1.insert((&arcos[i].get_weight()));
	}
	getchar();

	cout<<endl<<endl;
/*--------------------------------------------------------*/

	/*ESTA VENDRIA A SER LA PARTE DE LA SIMULACION QUE CORRE POR SI SOLA */

	int m =0; //m es reemplazo de N cuando N es mayor que la cantidad de autos a sacar;
	int n =3;
	int maxautos=20; //Valor maximo de autos por semáforo.
	int prin=0;
	int tamano=0;
	tamano=hsemaforo.tamano();
	Vehiculos mio;
	bool terminadomio=false;
	int iteracion=0;
	int ii=0;
	Vehiculos* aux;
	Semaforo*  auxsem;
	int numiteraciones=0;
	
	/*ESTE WHILE ES PARA QUE TERMINE DE CORRER EL PROGRAMA LUEGO DE QUE MI VEHICULO LLEGO A SU DESTINO */
	
	while(terminadomio!=true){
		

	/*ESTE WHILE ES PARA QUE SE HABILITEN TODOS LOS SEMAFOROS UNA VEZ, DE ACUERDO A LA CANTIDAD DE AUTOS QUE TENGA CADA UNO */
	
	while(prin != tamano){
	
		
		int a;
		a=hsemaforo.getArco(prin);  //numero de semaforo;
		
		if(*arcos[a].get_source()!= 999){
		cout << "--------------------------------------------------------------" << endl;
		cout<<"Semaforo en verde: "<< a<<endl;
		cout<<"Numero iteraciones " << numiteraciones<<endl;
		if(arcos[a].get_weight() > 0){
			if (arcos[a].get_weight() < N){
				m = arcos[a].get_weight();
			}else m =N;
				for (int k=0; k<m; k++){ 		//comienza sacado.
		cout << "---------------------nueva eliminacion------------------------" << endl;
			
		
		aux=arcos[a].mover();     
	
	/*ESTO LO HAGO PARA CONTROLAR EL CAMINO DE MI AUTO */
	
		if(aux->get_patente()==0){
			cout<<endl;
		}
		
	////////////////////////////////	
		
		auxsem=&arcos[aux->get_camino(1)];  //elijo el semaforo donde voy a insertar
		cout<<"Semaforo destino del vehiculo actual "<<auxsem->get_numero()<<endl;
		if (auxsem->get_weight()<maxautos){
			
		/*ESTO LO HAGO PARA QUE CADA AUTO PASE UNA SOLA VEZ POR CADA ITERACION */
		
		
		if(aux->getPase()==false){
			
				for(int i=0;i<totalveh;i++){
					if(v[i].get_prioridad()== 2){
						v[i].set_prioridad(-2);
					}
				if(v[i].get_prioridad()== 0){
					v[i].set_prioridad(-1);
			}
			}

	
	auxsem->insertar(aux); //
	aux->set_origen(auxsem->get_source());



	cout<<"Semaforo "<<auxsem->get_numero()<< " al que se le acaba insertar el vehiculo " << aux->get_patente()<<endl;
	cout<<endl;
	aux->avanzarcamino();
	
	/* ACA ES DONDE SE HABILITA EL BOOLEANO QUE ME DICE QUE MI VEHICULO YA TERMINO */
	
	
	if(aux->get_patente()==0 && aux->get_camino(0)==0){
		terminadomio=true;

		getchar();
	}

	cout<<endl;
	


	/*ACA MUESTRO EL SEMAFORO QUE YA RECORRIO, Y LOS QUE LES QUEDAN PENDIENTES */
	
	
	cout<<"Camino restante para vehiculo: "<<aux->get_patente()<<endl;
		for(int j=0; j< aux->tamcamino();j++){
			cout<<aux->get_camino(j)<<" ";
		}
		cout<<endl;

	
	/*ACA LO QUE HAGO ES HABILITAR EL BOOLEANO QUE DICE QUE CADA VEHICULO EN PARTICULAR YA TERMINO */
	
	
	if(aux->getTermine()!= false){
		getchar();
	
		Vehiculos* aux1;

		aux1=auxsem->elminarVehiculos(aux);
		
		arcos[numnodos-1].insertarlistos(aux1);
		aux1->set_origen(arcos[numnodos-1].get_source());

		
		}
	}else {
		cout<<aux->get_patente()<<" ya paso"<<endl;
		arcos[a].insertar(aux);
			}
		
		} else{ k =m;// 
		cout << "EL SEMAFORO ESTABA LLENO... CAMBIO" << endl;
			
	}
	}
	}
		
	
	prin++;
	
		cout << "Lista actualmente: " <<endl;
	for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}
	cout << endl;
	getchar();
	
	}
	

		/*EN ESTA PARTE SE HACE LA CONSIGNA QUE PIDE QUE CADA DOS ITERACIONES MI VEHICULO ENCUENTRE UN NUEVO CAMINO */
		
	if(iteracion==1){
			int sourceactual;
			int destactual;
			for(int i=0;i<totalveh;i++){
				if(v[i].get_patente()==0){
				
				/*AVERIGUO EL NUEVO ORIGEN DE MI VEHICULO, SE SUPONE QUE EL DESTINO DEBERIA SER EL MISMO */
					sourceactual=*v[i].get_origen();
					destactual=v[i].get_camino(v[i].tamcamino()-1);
				
					iteracion=-1;
					getchar();
					
				/*	if(sourceactual==destactual){
						cout<<"Termine la simulacion"<<endl;
						getchar();
						break;
					}*/
				}
				
			}
			
	cout<<"Soy camino viejo "<<endl;
			for(int j=0; j< v[0].tamcamino();j++){
			cout<<v[0].get_camino(j)<<" ";
	
		}
		cout<<endl;
		
		/* ACA BORRO EL CAMINO VIEJO PARA PODER ACTUALIZARLO */
		
			v[0].borrarcamino();

			
	
		/*LLAMO A DIJKSTRA CON LOS NUEVOS PARAMETROS */
	
	
			djk.dijkstra(l, &arcos[sourceactual], &destactual ,&v[0]);
		
		/*MUESTRO EL NUEVO CAMINO */
		
		cout<<"Soy camino nuevo para auto "<<v[0].get_patente()<<endl;
		for(int j=0; j< v[0].tamcamino();j++){
			cout<<v[0].get_camino(j)<<" ";
	
		}
		cout<<endl;


	}

	}

	prin=0;

		/*ACA DEVUELVO LAS PRIORIDADES ORIGINALES QUE HABIA CAMBIADO PARA QUE CADA VEHICULO ACTUE SOLO UNA VEZ POR CADA ITERACION*/
		
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
	/*ACA ACTUALIZO EL HEAP DE SEMAFOROS */
	
	hsemaforo.borrar();
	for(int i=0; i<numnodos;i++){

		hsemaforo.insert((arcos[i]));
	}
	hsemaforo.print();
	
	cout<<endl;
	
	
	/* ACA LO MUESTRO */
	
	
	getchar ();
	cout << "--------------Actualizado-------------" <<endl;
	cout << "Semaforos:" << endl;
	cout << "(Origen, Destino, Peso, Numero)" << endl;
	cout << endl;
	for(int i=0; i< numlistas ;i++){
		l[i].mostrar();
		cout<<endl;
	}

	
	
	
	iteracion++;
	cout << endl;
	cout << endl;
	
	/*PARA VER EL ESTADO DE MI AUTO */
	
	cout<<"---Camino para auto propio... "<<v[0].get_patente()<<endl;
		for(int j=0; j< v[0].tamcamino();j++){
			cout<<v[0].get_camino(j)<<" ";
		}
	/////////////////////////////////////////		
		 	
		 
			y++;
			if (y=2){
				ficheroSalida << " fin ";
			ficheroSalida.close();
			
			}
			numiteraciones++;
			getchar();
		}
	}
