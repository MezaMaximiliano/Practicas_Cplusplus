#include<stdlib.h>
#include<stdio.h>
#include<ostream>
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

typedef char str6[7];
typedef char str30[31];

struct tAlquiler{
	int nComprobante;
	int fecha;
	str6 codMarca;
};

struct tMarcaAuto{
	str6 codMarca;
	str30 razonSocial;
};

struct pAlquiler{
	tAlquiler alquiler;
	pAlquiler *nodoSig;
};

struct pMarcaAuto{
	tMarcaAuto marcaAuto;
	pMarcaAuto *nodoSig;
	pAlquiler *nodoSL;
	
};

void inicializar(tMarcaAuto);
void inicializarAlq(tAlquiler);
void cargarMarca(pMarcaAuto *&);
void insertarOrd(pMarcaAuto *&, tMarcaAuto);
void mostrarLista(pMarcaAuto *);
void procesarAlquileres(pMarcaAuto *&);
pMarcaAuto *buscar(pMarcaAuto *,str6 );
void insertarOrdSL(pAlquiler *&, tAlquiler);
void listarAlquileres(pMarcaAuto *);

int main(){
	
	pMarcaAuto *lMarcas;
	lMarcas=NULL;
	cargarMarca(lMarcas);
	procesarAlquileres(lMarcas);
	listarAlquileres(lMarcas);
	
	system("pause");
	return 0;
}

void listarAlquileres(pMarcaAuto *lista){
	mostrarLista(lista);
}

void procesarAlquileres(pMarcaAuto *&lista){
		tAlquiler rAux;
		pMarcaAuto *nodoLAux;
		pAlquiler *subLista;
		inicializarAlq(rAux);	
		nodoLAux=NULL;
		subLista=NULL;
		int primero=0,ultimo=0;
		string cadena;
		

		ifstream ar("Alquileres.txt");
		while (!ar.eof()){
	
			getline(ar,cadena);
		
			ultimo=cadena.find(";",primero);
			rAux.nComprobante=atoi(cadena.substr(primero,ultimo-primero).c_str());
			primero=ultimo+1;
		
			ultimo=cadena.find(";",primero);
			rAux.fecha=atoi(cadena.substr(primero,ultimo-primero).c_str());
			primero=ultimo+1;
		
			ultimo=cadena.find(";",primero);
			strcpy(rAux.codMarca,cadena.substr(primero,ultimo-primero).c_str());
			primero=ultimo+1;
			nodoLAux=buscar(lista,rAux.codMarca);
			if (nodoLAux->nodoSL==NULL){
				insertarOrdSL(nodoLAux->nodoSL,rAux);
			//	lista->nodoSL=nodoLAux->nodoSL;
			}else{
				insertarOrdSL(nodoLAux->nodoSL,rAux);
			}
			
		
		}
		
	
}

void insertarOrdSL(pAlquiler *&sub, tAlquiler n){
	
	pAlquiler *nuevo_nodo=new pAlquiler ();
	pAlquiler *aux1,*aux2;
	nuevo_nodo->alquiler=n;
	aux1=sub;
	
	while ((aux1!=NULL)and (aux1->alquiler.nComprobante<n.nComprobante)){
		aux2 = aux1;
		aux1=aux1->nodoSig;
	}
	if (sub==aux1){
		sub=nuevo_nodo;
	}else{
		aux2->nodoSig=nuevo_nodo;
	}
	nuevo_nodo->nodoSig=aux1;
}

pMarcaAuto *buscar(pMarcaAuto *lista,str6 codMarca){
	pMarcaAuto *aux;
	aux=lista;
	
	while ((aux!=NULL)){		//and (strcmp(aux->marcaAuto.codMarca,codMarca)!=0)
		if (strcmp(aux->marcaAuto.codMarca,codMarca)==0){
			
			return aux;
			
		}
		aux=aux->nodoSig;
	}

	return NULL;
	
}

void cargarMarca(pMarcaAuto *&lista){
	tMarcaAuto rAux;
	int primero=0,ultimo=0;
	string cadena;
	inicializar(rAux);

	ifstream ar("MarcasDeAuto.txt");
	while (!ar.eof()){
	
		getline(ar,cadena);
		
		ultimo=cadena.find(";",primero);
		strcpy(rAux.codMarca,cadena.substr(primero,ultimo-primero).c_str());
		primero=ultimo+1;
		
		ultimo=cadena.find(";",primero);
		strcpy(rAux.razonSocial,cadena.substr(primero,ultimo-primero).c_str());
		primero=ultimo+1;
	
		insertarOrd(lista,rAux);
		
	}
	
}

void insertarOrd(pMarcaAuto *&lista, tMarcaAuto n){
	
	pMarcaAuto *nuevo_nodo=new pMarcaAuto ();
	pMarcaAuto *aux1,*aux2;
	nuevo_nodo->marcaAuto=n;
	aux1=lista;
	
	while ((aux1!=NULL)and ((strcmp(aux1->marcaAuto.codMarca,n.codMarca))<0)){
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

void mostrarLista(pMarcaAuto *lista){

	pMarcaAuto *aux;
	pAlquiler *sub;
	aux=lista;
	cout<<endl;
	while (aux!=NULL){
		cout<<"CODIGO MARCA: "<<aux->marcaAuto.codMarca<<"		"<<"RAZON SOCIAL: "<<aux->marcaAuto.razonSocial<<endl;
		sub=aux->nodoSL;
		cout<<"Numero de comprobante		Fecha		Codigo Marca"<<endl;
		while(sub!=NULL){
			cout<<sub->alquiler.nComprobante<<"   		   	        "<<sub->alquiler.fecha<<"  	   "<<sub->alquiler.codMarca<<endl;
			sub=sub->nodoSig;
			
		}
		aux=aux->nodoSig;
		cout<<"\n";
	
	}
	
	
	cout<<endl;
	system("pause");
}

void inicializarAlq(tAlquiler registro){
	registro.nComprobante=0;
	registro.fecha=0;
	strcpy(registro.codMarca,"");
}

void inicializar(tMarcaAuto registro){
	
	strcpy(registro.codMarca,"");
	strcpy(registro.razonSocial,"");
}
