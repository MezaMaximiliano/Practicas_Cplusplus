#include<stdlib.h>
#include<stdio.h>
#include<ostream>
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

struct nodoSL{
	int dato;
	nodoSL *nodoSigSL;
};

struct nodoLista{
	int dato;
	nodoLista *nodoSig;
	nodoSL *SL;
};


void insertarOrd(nodoLista *&lista, int n);
void mostrarLista(nodoLista *lista);
nodoLista *buscarElem(nodoLista *lista,int n);
void agregarSub(nodoLista *&,nodoSL *&);
void insertarOrdSL(nodoSL *&sub, int n);
void mostrarSub(nodoLista *l1);


int main(){
	
	nodoLista *l1,*aux;
	nodoSL *sub;
	sub=NULL;
	l1=NULL;
	aux=NULL;
	int n;

	insertarOrd(l1,1);
	insertarOrd(l1,2);
	insertarOrd(l1,3);
	
	cout<<"Elemento a buscar: ";
	cin>>n;
	aux=buscarElem(l1,n);
	
	agregarSub(aux,sub);
	
	agregarSub(aux,sub);

	agregarSub(aux,sub);

	mostrarLista(l1);

	

	system("pause");
	return 0;
}

void mostrarSub(nodoSL *sub){
	
	
}

void agregarSub(nodoLista *&l1,nodoSL *&sub){
	int n=0;
	cout<<"Ingrese valor: ";
	cin>>n;
	cout<<endl;
	
	
	if (sub==NULL){
		sub=l1->SL;
		insertarOrdSL(sub,n);
	//	l1->SL=sub;
	
		
	}else{
		sub=l1->SL;
		insertarOrdSL(sub,n);
	
	}
	
}

void insertarOrdSL(nodoSL *&sub, int n){
	
	nodoSL *nuevo_nodo=new nodoSL ();
	nodoSL *aux1,*aux2;
	nuevo_nodo->dato=n;
	aux1=sub;
	
	while ((aux1!=sub)and (aux1->dato<n)){
		aux2 = aux1;
		aux1=aux1->nodoSigSL;
	}
	if (sub==aux1){
		sub=nuevo_nodo;
	}else{
		aux2->nodoSigSL=nuevo_nodo;
	}
	nuevo_nodo->nodoSigSL=aux1;
}


void mostrarLista(nodoLista *lista){
	
//	nodoLista *aux=new nodoLista();
	nodoLista *aux;
	nodoSL *sub;
	aux=lista;
	cout<<endl;
	while (aux!=NULL){
		cout<<aux->dato;
		sub=aux->SL;
		while(sub!=NULL){
			cout<<"			"<<sub->dato;
			sub=sub->nodoSigSL;
			
		}
		aux=aux->nodoSig;
		cout<<"\n\n\n";
	
	}
	
	
	cout<<endl;
	system("pause");
}



nodoLista  *buscarElem(nodoLista *l,int n){
	
	nodoLista *aux;
	aux=l;
	
	while ((aux!=NULL)and (aux->dato!=n)){
		aux=aux->nodoSig;
	}
	
	if (aux==NULL){
		cout<<"No existe el elemento.\n";
	}
	return aux;
	system("pause");
}


void insertarOrd(nodoLista *&lista, int n){
	
	nodoLista *nuevo_nodo=new nodoLista ();
	nodoLista *aux1,*aux2;
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
