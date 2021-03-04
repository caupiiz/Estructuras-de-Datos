#include <bits/stdc++.h>

using namespace std;

///Crear nodo
typedef struct NPila{
	int num;
	NPila *ant;
}nodoPila;

typedef nodoPila *pila;

typedef struct pilaEs{
	pila primero;
	pila ultimo;
}pilaItems;



///Insertar
void insertar(pilaItems *p, int num){
	///Verificar que la pila no este vacia
	if(!(*p).primero){
		///Insertar el primer elemento en la pila
		(*p).primero=new(NPila);
		(*p).primero->num = num;
		(*p).primero->ant=NULL;
		return;
	}
	
	/// [(10,Null), (20, x0)]
	///  x0
	
	(*p).ultimo = new(NPila);
	(*p).ultimo->num = num;
	(*p).ultimo->ant = (*p).primero;
	(*p).primero = (*p).ultimo;	
}
///Eliminar
void eliminar(pilaItems *p){
	pila aux = (pila)malloc(sizeof(nodoPila));
	if((*p).ultimo){
		aux = (*p).ultimo;
		cout<<"Se elimino el numero: "<<(*p).ultimo->num<<endl;
		(*p).ultimo = aux -> ant;
		///Elimar nodo auxiliar
		delete(aux);
	}else{
		///No hay datos
		cout<<"No hay datos"<<endl;
	}
}
///Mostrar cima
void mostrarCima(pila p){
	if(p!=NULL){
		///Si hay datos
		cout<<"El numero cima es: "<<p->num<<endl;
	}else{
		///No hay datos
		cout<<"No hay datos"<<endl;
	}
}


///Mostrar todos los elementos
void mostrar(pila p){
	///Utilizar un ciclo y recorrerlo hasta que sea diferente de null
	while(p!=NULL){
		cout<<"Numero: "<<p->num<<endl;
		p = p->ant;
	}
}

///Reto 
///Vacia
///Elimar todos los elementos

int main(){
	
	pilaItems pilaPrograma;
	///Iniciar con valores nulos
	pilaPrograma.primero = NULL;
	pilaPrograma.ultimo = NULL;
	
	insertar(&pilaPrograma, 10);
	insertar(&pilaPrograma, 20);
	insertar(&pilaPrograma, 30);
	insertar(&pilaPrograma, 40);
	
	mostrar(pilaPrograma.primero);
	mostrarCima(pilaPrograma.primero);
	
	eliminar(&pilaPrograma);
	
	mostrar(pilaPrograma.ultimo);
	mostrarCima(pilaPrograma.ultimo);

	return 0;
}
