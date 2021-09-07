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
void agregarPila(nodo *&,int);
void pasarPilaAux (nodo *&,nodo *&);
void quitarPila(nodo *&, int &);
void mostrarPila(nodo *&);
void punto3(nodo *&, nodo *&,int &);
void compararValor(nodo *&, nodo *&, int ,int &);
void copiarPila(nodo *&,nodo *&);

int main(){
	
	int vecInt[4]={5,18,3,8};
	int cantPila=0;
	nodo *pila;
	nodo *pilaAux;
	nodo *pilaCopia;
	
	inicializar(pila);
	inicializar(pilaAux);
	inicializar(pilaCopia);
	
	for (int i=0;i<4;i++){
		agregarPila(pila,vecInt[i]);
		cout<<"Se ha agregado el numero "<<vecInt[i]<<" a la pila."<<endl;
	}
	
	printf("\n\n");

	pasarPilaAux(pila,pilaAux);
	copiarPila(pilaAux,pilaCopia);
	cout<<"\n\nPila auxiliar:"<<endl;
	mostrarPila(pilaCopia);
	printf("\n\nPUNTO 3: \n\n");
	punto3(pila,pilaAux,cantPila);

	printf("\n");
	system("pause");
	return 0;
}

void copiarPila(nodo *&pilaAux,nodo *&pilaCopia){
	
	nodo *pila_nueva;
	int n;
	inicializar(pila_nueva);
	
	while(pilaAux!=NULL){
		quitarPila(pilaAux,n);
		agregarPila(pilaCopia,n);
	}
	
	while(pilaCopia!=NULL){
		quitarPila(pilaCopia,n);
		agregarPila(pilaAux,n);
		agregarPila(pilaCopia,n);
	}
}


void punto3(nodo *&pila, nodo *&pilaAux,int &cantPila){
	int n;
	nodo *pila_temp;
	inicializar(pila_temp);
	
	copiarPila(pilaAux, pila_temp);	
	
	while(pila_temp!=NULL){
		quitarPila(pila_temp,n);
		compararValor(pila,pilaAux,n,cantPila);
	}
	cout<<"Valores en Pila:"<<endl;
	while(pila!=NULL){
		mostrarPila(pila);
	}
	printf("\n\n");
	cout<<"Valores en Pila Auxiliar:"<<endl;
	while(pilaAux!=NULL){
		mostrarPila(pilaAux);
	}
	
	cout<<"\n\nCantidad de elementos en Pila es "<<cantPila<<"."<<endl;
	
}

void compararValor(nodo *&pila, nodo *&pilaAux, int n,int &cantPila){
	
	if (n<10){
		agregarPila(pila,n);
		cantPila++;
	}else{
		agregarPila(pilaAux,n);
	}
	
}

void mostrarPila(nodo *&pilaAux){
	int n;

	while(pilaAux!=NULL){
		quitarPila(pilaAux,n);
		cout<<n<<endl;
	
	}

	
}


void pasarPilaAux(nodo *&pila,nodo *&pilaAux){
	int nAux;
	
	while (pila!=NULL){
		quitarPila(pila,nAux);
		agregarPila(pilaAux,nAux);
	}
	

	
}

void quitarPila(nodo *&pila, int &n){
	nodo *aux=pila;
	n=aux->dato;
	pila=aux->nodoSig;
	delete aux;
}

void agregarPila(nodo *&pila,int n){
		
		nodo *nuevo_nodo=new nodo();
		nuevo_nodo->dato=n;
		nuevo_nodo->nodoSig=pila;
		pila=nuevo_nodo;
	
	
}

void inicializar(nodo *&pila){
	pila=NULL;
}

