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

void encolar(nodo *&, nodo *&, int );
void desencolar(nodo *&,nodo *&,int &);
bool cola_vacia(nodo *);

int main(){
	nodo *frente=NULL;
	nodo *fin=NULL;
	
	int vecInt[5]={1,2,3,4,5};
	int n;
	
	for (int i=0;i<5;i++){
		encolar(frente,fin,vecInt[i]);
		cout<<"Se ha agregado el numero "<<vecInt[i]<<" a la cola."<<endl;
	}
	
	cout<<"\n\nCola:"<<endl;
	while(frente!=NULL){
		desencolar(frente,fin,n);
		cout<<n<<endl;
	}
	
	system("pause");
	return 0;
}

void desencolar(nodo *&frente, nodo *&fin, int &n){
	n=frente->dato;
	nodo *aux=frente;
	
	if (frente==fin){
		frente=NULL;
		fin=NULL;
	}else{
		frente=frente->nodoSig;
	}
	
	delete aux;
}

void encolar(nodo *&frente, nodo *&fin, int n){
	
	nodo *nuevo_nodo= new nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->nodoSig=NULL;
	
	if (cola_vacia(frente)){
		frente=nuevo_nodo;
	}else{
		fin->nodoSig=nuevo_nodo;
	}
	
	fin=nuevo_nodo;
	
}

bool cola_vacia(nodo *frente){
	return(frente==NULL)?true:false;
}
