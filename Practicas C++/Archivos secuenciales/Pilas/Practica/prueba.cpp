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
struct cola{
	nodo *frente;
	nodo *fin;
};
void ini(cola );
void encolar(cola);
bool cola_vacia(cola );

int main (){
	cola c1;
	ini(c1);
	encolar(c1);
}
void ini(cola c1){
	c1.frente=NULL;
	c1.fin=NULL;
}

void encolar(cola c1, int n){
	
	nodo *nuevo_nodo= new nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->nodoSig=NULL;
	
	if (cola_vacia(c1)){
		c1.frente=nuevo_nodo;
	}else{
		c1.fin->c1.fin=nuevo_nodo;
	}
	
	c1.fin=nuevo_nodo;
}

bool cola_vacia(cola c){
	return(c.frente==NULL)?true:false;
}
