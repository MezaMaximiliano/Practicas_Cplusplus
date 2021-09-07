#include<stdlib.h>
#include<stdio.h>
#include<ostream>
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

struct nodo{
	int dato;
	nodo *nodoSig;
};

void inicializar(nodo *&);
void insertarOrd(nodo *&, int);
void eliminarLista(nodo *&, int);
void mostrarLista(nodo *);
void agregarElementos(nodo *&);
void eliminarElementos(nodo *&);
void eliminar1erElemento(nodo *&);

int menu(){
	int op;
	
	do{
		system("cls");
		cout<<"-->MENU<--"<<endl;
		cout<<"1.Agregar elementos."<<endl;
		cout<<"2.Eliminiar elementos."<<endl;
		cout<<"3.Mostrar lista."<<endl;
		cout<<"INGRESE OPCION (0 para salir): ";
		cin>>op,
		cout<<endl;
	}while((op<0)or(op>4));
	return op;
}

int main(){
	 int op ;
	 nodo *lista;
	 inicializar(lista);
 	 do {
   		 op = menu() ;
   		 switch (op)  {
    	 	case 1: agregarElementos(lista) ;  break ;
	   	    case 2: eliminarElementos(lista)  ; break ;
    	    case 3: mostrarLista(lista); break ;
                
            default: break ;
     		} ; 
 	  } while (op!=0) ;
	
	system("pause");
	return 0;
}

void agregarElementos(nodo *&lista){
	int dato;
	cout<<"\nElemento a agregar: ";
	cin>>dato;
	cout<<endl;
	insertarOrd(lista,dato);
}

void eliminarElementos(nodo *&lista){
	int dato;
	cout<<"\nElemento a eliminar: ";
	cin>>dato;
	cout<<endl;
	eliminarLista(lista,dato);
}



void insertarOrd(nodo *&lista, int n){
	
	nodo *nuevo_nodo=new nodo ();
	nodo *aux1,*aux2;
	nuevo_nodo->dato=n;
	aux1=lista;
	
	while ((aux1!=NULL)and (aux1->dato<n)){
		aux2 = aux1;
		aux1=aux1->nodoSig;
	}
	if (lista==aux1){
		lista=nuevo_nodo;
	}else{
		aux2->nodoSig=nuevo_nodo;
	}
	nuevo_nodo->nodoSig=aux1;
}

void eliminarLista(nodo *&lista, int n){
	if (lista!=NULL){
		nodo *aux_borrar;
		nodo *anterior;
		anterior=NULL;
		aux_borrar=lista;
		
		while ((aux_borrar!=NULL)and(aux_borrar->dato!=n)){
			anterior=aux_borrar;
			aux_borrar=aux_borrar->nodoSig;
			
			if (aux_borrar==NULL){
				cout<<"\nNO EXISTE EL ELEMENTO."<<endl;
			}else if(anterior==NULL){
				lista=lista->nodoSig;
				delete aux_borrar;
			}else{
				anterior->nodoSig=aux_borrar->nodoSig;
				delete aux_borrar;
			}
		}
		
	}
}

void eliminar1erElemento(nodo *&lista){
	nodo *aux;
	aux=lista;
	lista=aux->nodoSig;
	delete aux;
}

void mostrarLista(nodo *lista){
	
	nodo *aux=new nodo();
	aux=lista;
	cout<<endl;
	while (aux!=NULL){
		cout<<aux->dato<<"->";
		aux=aux->nodoSig;
		if (aux==NULL){
			cout<<"NULL";
		}
	}
	cout<<endl;
	system("pause");
}

void inicializar(nodo *&lista){
	lista=NULL;
}
