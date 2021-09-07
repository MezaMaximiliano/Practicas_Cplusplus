#include<stdlib.h>
#include<stdio.h>
#include<ostream>
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
};

void agregarPila(nodo *&, int);
void quitarPila(nodo*&,int&);



int main(){
	
	nodo *pila=NULL;
	int n1, n2=0;
	cout<<"Ingrese un numero: ";
	cin>>n1;
	do{
	n2++;
	agregarPila(pila,n1);
	cout<<"Ingrese un numero: ";
	cin>>n1;
	
	}while(n1!=0);
	printf("\n");
	while(pila!=NULL){
		
		quitarPila(pila,n1);
		cout<<n1<<endl;
	}
	cout<<"Cantidad de elmentos: "<<n2<<endl;
	system("pause");
	return 0;
}

void quitarPila(nodo *&pila,int &n){
	
	nodo *aux=pila;
	n=aux->dato;
	pila=aux->siguiente;
	delete aux;
	
}

void agregarPila(nodo *&pila, int n){
	
	nodo *nuevo_nodo=new nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->siguiente=pila;
	pila=nuevo_nodo;
	
	
}
