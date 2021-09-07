#include<stdlib.h>
#include<stdio.h>
#include<ostream>
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

typedef int num[40];

struct nodo{
	int dato;
	nodo *nodoSig;
};

void inicializarCola(nodo *&,nodo *&);
void cargarVec(num );



int main(){
	nodo *frente;
	nodo *fin;
	
	num v;
	int n;
	int cantCola=0;
	cargarVec(v);
	
	inicializarCola(frente,fin);

	
	
	
	printf("\n");
	system("pause");
	return 0;

}

void inicializarCola(nodo *&frente,nodo *&fin){
	frente=NULL;
	fin=NULL;
}

void cargarVec(num v){
	for (int i=0;i<40;i++){
		v[i] = rand() % (11 - 1);
	}
}

