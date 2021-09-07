#include<stdlib.h>
#include<stdio.h>
#include<ostream>
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

typedef char str2[2];

struct nodoSL{
	str2 dato;
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
void agregarSub(nodoLista *&l1);
void insertarOrdSL(nodoSL *&sub, str2 n);

int main(){
	
	nodoLista *l1,*aux;
	l1=NULL;
	aux=NULL;
	int n;

	insertarOrd(l1,1);
	insertarOrd(l1,2);
	insertarOrd(l1,3);
	
	cout<<"Elemento a buscar: ";
	cin>>n;
	aux=buscarElem(l1,n);
	agregarSub(aux);
	
	system("pause");
	return 0;
}

void agregarSub(nodoLista *&l1){
	nodoSL *nuevo_nodoSL=new nodoSL ();
	nuevo_nodoSL=NULL;
	nuevo_nodoSL->nodoSigSL;



}

void insertarOrdSL(nodoSL *&sub, str2 n){
	
	nodoSL *nuevo_nodoSL=new nodoSL ();
	nodoSL *aux1,*aux2;
	strcpy(nuevo_nodoSL->dato , n );
	aux1=sub;
	
	while ((aux1!=NULL)and (strcmp(aux1->dato,n)<0)){
		aux2 = aux1;
		aux1=aux1->nodoSigSL;
	}
	if (sub==aux1){
		sub=nuevo_nodoSL;
	}else{
		aux2->nodoSigSL=nuevo_nodoSL;
	}
	nuevo_nodoSL->nodoSigSL=aux1;
}

void mostrarLista(nodoLista *lista){
	
	nodoLista *aux=new nodoLista();
	aux=lista;
	cout<<endl;
	while (aux!=NULL){
		cout<<aux->dato<<"		->		";
		aux=aux->nodoSig;
		if (aux==NULL){
			cout<<"NULL";
		}
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




