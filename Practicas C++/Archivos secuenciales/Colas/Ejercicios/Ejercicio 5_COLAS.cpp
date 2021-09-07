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
typedef int num[40];

void inicializar(nodo *&, nodo *&);
void cargarVec(num );
void encolar(nodo *&, nodo *&, int );
void desencolar(nodo *&,nodo *&,int &);
bool cola_vacia(nodo *);
void cargarCola(nodo *&,nodo *&,num);
void pushPila(nodo *&,int);
void popPila(nodo *&,int &);
void puntoA(nodo *, nodo*);
int contarCola(nodo *);
void puntoB(nodo *&,nodo *&,nodo *&,nodo *&);
void concatenarCola(nodo *&,nodo *&,nodo *,nodo *);
void puntoC(nodo *,nodo *);
void buscarCola(nodo *&,nodo *&, int);
void puntoD(nodo *,nodo *);
void colarElemento(nodo *&, nodo *&, int, int);
void mostrarCola(nodo *&,nodo *&);
void puntoE(nodo *, nodo *);
void sacarElemento (nodo *&,nodo *&, int);
void puntoF(nodo *, nodo *);
void separarCola(nodo *&,nodo *&,int,nodo *&,nodo *&);
void puntoG(nodo*,nodo*);
void invertirCola(nodo *&,nodo *&);


int main(){
	
	num v;
	int n;
	nodo *frente,*fin;
	nodo *frente2,*fin2;
	
	inicializar(frente,fin);
	inicializar(frente2,fin2);
	cargarVec(v);
	cargarCola(frente,fin,v);
	cargarVec(v);
	cargarCola(frente2,fin2,v);
	cout<<"PUNTO A:";
	puntoA(frente,fin);
	cout<<"\nPUNTO B:";
	puntoB(frente,fin,frente2,fin2);
	cout<<"\nPUNTO C:\n";
	puntoC(frente,fin);
	cout<<"\nPUNTO D:\n";
	puntoD(frente,fin);
	cout<<"PUNTO E:\n";
	puntoE(frente,fin);
	cout<<endl;
	cout<<"PUNTO F:\n";
	puntoF(frente,fin);
	cout<<"PUNTO G:\n";
	puntoG(frente,fin);
	
	
	system("pause");
	return 0;
}

void puntoG(nodo *frente,nodo *fin){
	
	nodo *frente_aux,*fin_aux;
	frente_aux=frente;
	fin_aux=fin;
	
	invertirCola(frente_aux,fin_aux);
	cout<<"ORDEN DE COLA INVERTIDO:\n";
	mostrarCola(frente_aux,fin_aux);
	cout<<endl;
}

void invertirCola(nodo *&frente, nodo *&fin){
	nodo *pila;
	int n;
	pila=NULL;
	while (frente!=NULL){
		desencolar(frente,fin,n);
		pushPila(pila,n);
	}
	
	while(pila!=NULL){
		popPila(pila,n);
		encolar(frente,fin,n);
	}
}

void puntoF(nodo *frente, nodo *fin){
	nodo *frente_aux, *fin_aux,*frente2,*fin2;
	int cota=0;
	frente2=NULL;
	fin2=NULL;
	frente_aux=frente;
	fin_aux=fin;
	cout<<"Cota: ";
	cin>>cota;
	cout<<endl;
	separarCola(frente_aux,fin_aux,cota,frente2,fin2);
	cout<<"COLA CON ELEMENTOS MENORES A "<<cota<<":"<<endl;
	mostrarCola(frente2,fin2);
	cout<<"\nCOLA CON ELEMENTOS MAYORES O IGUALES A "<<cota<<":"<<endl;
	mostrarCola(frente_aux,fin_aux);
	cout<<endl;
}

void separarCola(nodo *&frente,nodo *&fin,int cota,nodo *&frente2,nodo *&fin2){
	
	nodo *frente_aux,*fin_aux;
	int n;
	frente_aux=NULL;
	fin_aux=NULL;
	while (frente!=NULL){
		desencolar(frente,fin,n);
		encolar(frente_aux,fin_aux,n);
	}
	
	while(frente_aux!=NULL){
		desencolar(frente_aux,fin_aux,n);
		if (n<cota){
			encolar(frente2,fin2,n);
		}else{
			encolar(frente,fin,n);
		}
		
	}
}

void puntoE(nodo *frente, nodo *fin){
	nodo *frente_aux,*fin_aux;
	int elemento=0;
	frente_aux=frente;
	fin_aux=fin;
	
	cout<<"Que elemento desea remover: ";
	cin>>elemento;
	sacarElemento(frente_aux,fin_aux,elemento);
	mostrarCola(frente_aux,fin_aux);
}

void sacarElemento(nodo *&frente, nodo *&fin, int elemento){
	nodo *frente_aux,*fin_aux;
	int n;
	frente_aux=NULL;
	fin_aux=NULL;
	while (frente!=NULL){
		desencolar(frente,fin,n);
		encolar(frente_aux,fin_aux,n);
	}
	
	while (frente_aux!=NULL){
		desencolar(frente_aux,fin_aux,n);
		
		if (n!=elemento){
			encolar(frente,fin,n);
		}
	}
}

void puntoC(nodo *frente, nodo *fin){
	nodo *frente_aux,*fin_aux;
	frente_aux=frente;
	fin_aux=fin;
	int elemento;

	cout<<"Numero a buscar: ";
	cin>>elemento;
	cout<<endl;
	
	buscarCola(frente_aux,fin_aux,elemento);	
	
	
}

void puntoD(nodo *frente,nodo *fin){
	nodo *frente_aux,*fin_aux;
	int elemento=0,posicion=0;
	frente_aux=frente;
	fin_aux=fin;
	
	cout<<"Que numero desea agregar: ";
	cin>>elemento;
	cout<<"\nEn que posicion: ";
	cin>>posicion;
	cout<<endl;
	colarElemento(frente_aux,fin_aux,elemento,posicion);
	mostrarCola(frente_aux,fin_aux);
}

void mostrarCola(nodo *&frente, nodo *&fin){
	int n;
	while(frente!=NULL){
		desencolar(frente,fin,n);
		cout<<n<<" ";
	}
	cout<<endl;	
}

void colarElemento(nodo *&frente, nodo *&fin, int elemento, int posicion){
	nodo *frente_aux,*fin_aux;
	int n;
	int a=1;
	frente_aux=NULL;
	fin_aux=NULL;
	
	while (frente!=NULL){
		desencolar(frente,fin,n);
		encolar(frente_aux,fin_aux,n);
	}
	
	while (frente_aux!=NULL){
		desencolar(frente_aux,fin_aux,n);
		if (a==posicion){
			encolar(frente,fin,elemento);
			encolar(frente,fin,n);
		}else{
			encolar(frente,fin,n);
		}
		a++;
	}
	
}

void buscarCola(nodo *&frente, nodo *&fin, int elemento){
	
	int n;
	
	while(frente!=NULL){
		desencolar(frente,fin,n);
		if ((frente!=NULL)and (n==elemento)){
			cout<<"ELEMENTO ENCONTRADO.\n";
			break;
		}else if (frente==NULL){
			cout<<"NO SE ENCONTRO EL ELEMENTO.\n";
		}
	}
	
	
}


void puntoB(nodo *&frente,nodo *&fin,nodo *&frente2,nodo *&fin2){
		
		int cant=0;
		int n;
		nodo *frente_aux,*fin_aux;
		frente_aux=frente;
		fin_aux=fin;
		concatenarCola(frente_aux,fin_aux,frente2,fin2);
		cant=contarCola(frente);
		cout<<endl<<endl<<"COLA CONCATENADA DE "<<cant<<" ELEMENTOS:\n";
		while(frente_aux!=NULL){
			desencolar(frente_aux,fin_aux,n);
			cout<<n<<" ";
		}
}

void concatenarCola(nodo *&frente,nodo *&fin,nodo *frente2,nodo *fin2){
	
	int n;
	
	nodo *frente_aux,*fin_aux;
	frente_aux=frente2;
	fin_aux=fin2;
	
	while(frente_aux!=NULL){
		desencolar(frente_aux,fin_aux,n);
		encolar(frente,fin,n);
	}
	
}
	


void puntoA(nodo *frente,nodo *fin){
	int cant=0;
	cant=contarCola(frente);
	cout<<"\nCANTIDAD DE ELEMENTOS DE COLA: "<<cant<<endl;
	
}

int contarCola(nodo *frente){
	nodo *aux;
	aux=frente;
	int cant=0;
	while(aux!=NULL){
		aux=aux->nodoSig;
		cant++;
	}
	return cant;
}

void cargarCola(nodo *&frente,nodo *&fin,num v){
	for (int i=0;i<40;i++){
		encolar(frente,fin,v[i]);
	}
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

void inicializar(nodo *&frente, nodo *&fin){
	frente=NULL;
	fin=NULL;
}

void cargarVec(num v){
	for (int i=0;i<40;i++){
		v[i] = rand() % (11 - 1);
	}
}

void pushPila(nodo *&pila,int n){
		nodo *nuevo_nodo=new nodo();
		nuevo_nodo->dato=n;
		nuevo_nodo->nodoSig=pila;
		pila=nuevo_nodo;
}

void popPila(nodo *&pila,int &n){
	nodo *aux=pila;
	n=aux->dato;
	pila=aux->nodoSig;
	delete aux;
}
