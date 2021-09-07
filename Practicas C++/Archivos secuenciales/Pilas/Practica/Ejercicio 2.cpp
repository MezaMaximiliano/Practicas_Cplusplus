
/*Ejercicio 2
Desarrollar los siguientes algoritmos:
a) Colocar un nuevo elemento a una pila
b) Eliminar de una pila todas las ocurrencias de un elemento dado.
c) Intercambiar los elementos del inicio y del final de la pila, sin modificar el resto
d) Generar una PILA que contenga la pila original y a continuación una copia de la misma
e) Calcular la suma de los elementos de una pila de enteros sin modificar su contenido.
g) Calcular el valor máximo almacenado en una pila de números reales.*/

#include<stdlib.h>
#include<stdio.h>
#include<ostream>
#include<fstream>
#include<iostream>
#include<string.h>
#include <cstdlib>
#include <time.h>
using namespace std;

struct nodo{
	int dato;
	nodo *nodoSig;
};

typedef int num[30];

void cargarVec(num);
void inicializar(nodo *&);
void pushPila(nodo *&,int);
void popPila(nodo *&,int &);
void copiarPila(nodo *&,nodo *&);
void puntoB(nodo *&,nodo *&);
void puntoC(nodo *&);
void puntoD(nodo *&,nodo *&);
void puntoE(nodo *&,nodo *&);
void puntoG(nodo *&);
int contarPila(nodo *);
void clonarPila(nodo *,nodo *&);
void mostrarPila(nodo *);
bool buscarPila(nodo *,int);

int main(){
	
	srand(time(NULL));
	num v1;
	int n=0;
	int valor;
	int cantPila=0;
	nodo *pila;
	nodo *pilaC;
	nodo *pilaD;
	nodo *pilaE;
	nodo *pilaG;
	nodo *pila_prueba;
	nodo *pilaClonada;
	nodo *pO;
	nodo *pila_copia_original;
	
	inicializar(pila);
	inicializar(pilaC);
	inicializar(pilaD);
	inicializar(pilaE);
	inicializar(pilaG);
		inicializar(pO);
	inicializar(pila_prueba);
	inicializar(pilaClonada);
	inicializar(pila_copia_original);
	cargarVec(v1);
	
	for (int i=0;i<30;i++){
		pushPila(pila,v1[i]);
	}

	clonarPila(pila,pila_copia_original);
	clonarPila(pila,pO);
	printf("PUNTO B:\n");
	puntoB(pila,pilaC);
	
	cout<<"\n\nPUNTO C:\n";
	puntoC(pilaC);
	
	cout<<"\n\nPUNTO D:\n";
	puntoD(pila_copia_original,pilaE);
	
	cout<<"\n\nPUNTO E:\n";
	puntoE(pilaE,pilaG);
	clonarPila(pilaG,pila_prueba);
	cout<<"\n\nPUNTO G:\n";
	puntoG(pilaG);
	
	cantPila=contarPila(pila_prueba);
	cout<<"Cantidad de elementos de PILA es: "<<cantPila<<endl;
	int cO=0;
	cO=contarPila(pila_prueba);
	cout<<"\n\notra contada: "<<cO<<endl; 
	clonarPila(pila_prueba,pilaClonada);
	cantPila=0;
	cantPila=contarPila(pilaClonada);
	cout<<"pila clonada:\n";
	mostrarPila(pilaClonada);
	
	cout<<"Numero que desea buscar: ";
	cin>>valor;
	printf("\n");
	bool rta;
	rta=buscarPila(pilaClonada,valor);
	if (!rta){
		cout<<"Valor no encontrado."<<endl;
	}else{
		cout<<"Se encontro el valor."<<endl;
	}
	

	
	printf("\n");
	system("pause");
	return 0;
}

bool buscarPila(nodo *pila,int valor){
	int n;
	bool encontrado=false;
	while (pila!=NULL){
		n=pila->dato;
		pila=pila->nodoSig;
		if (n==valor){
			encontrado=true;
		}
	}
	return encontrado;
	
}

void mostrarPila(nodo *pila){
	int n;
	while(pila!=NULL){
		n=pila->dato;
		pila=pila->nodoSig;
		cout<<n<<" ";
	}
	printf("\n");
}

void clonarPila(nodo *pila, nodo *&pila_clon){
	int n;
	nodo *aux=NULL;
	while(pila!=NULL){
		n=pila->dato;
		pushPila(aux,n);
		pila=pila->nodoSig;
	}
	while(aux!=NULL){
		n=aux->dato;
		pushPila(pila_clon,n);
		aux=aux->nodoSig;
	}


}

int contarPila(nodo *pila){
	int cant=0;
	nodo *aux;
	aux=pila;
		while(aux!=NULL){
		aux=aux->nodoSig;
		cant++;
	}
return cant;
	
}

void puntoG(nodo *&pilaG){
	int n;
	int vMax=-2;
	nodo *pila_aux;
	inicializar(pila_aux);
	
	while(pilaG!=NULL){
		popPila(pilaG,n);
		pushPila(pila_aux,n);
	}
	
	while(pila_aux!=NULL){
		popPila(pila_aux,n);
		pushPila(pilaG,n);
		if (n>vMax){
			vMax=n;
		}
	}
	
	cout<<"Valores de PILA:\n";
	mostrarPila(pilaG);
		
	
	
	cout<<"\nValor maximo almacenado en la PILA: "<<vMax<<endl;
	
}

void puntoE(nodo *&pila,nodo *&pilaG){
	int n;
	int valorTotal=0;
	nodo *pila_aux;
	inicializar(pila_aux);
	
	while(pila!=NULL){
		popPila(pila,n);
		pushPila(pila_aux,n);
	}
	
	while(pila_aux!=NULL){
		popPila(pila_aux,n);
		valorTotal=valorTotal+n;
		pushPila(pila,n);
	}
	copiarPila(pila,pilaG);
	while(pila!=NULL){
		popPila(pila,n);
		cout<<n<<" ";
	}
	cout<<"\nLa suma de los valores de la PILA es: "<<valorTotal<<endl;
}

void puntoD(nodo *&pila,nodo *&pilaE){
	int n;
	nodo *pila_nueva;
	nodo *pila_temp;
	inicializar(pila_nueva);
	inicializar(pila_temp);
	copiarPila(pila,pila_nueva);
	
	while(pila_nueva!=NULL){
		popPila(pila_nueva,n);
		pushPila(pila_temp,n);
	}
	
	while(pila_temp!=NULL){
		popPila(pila_temp,n);
		pushPila(pila,n);
	}
	copiarPila(pila,pilaE);
	cout<<"\nPILA con copia de la PILA original:\n";
	while(pila!=NULL){
		popPila(pila,n);
		cout<<n<<" ";
	}
	
}

void puntoC(nodo *&pilaC){
	int n,pEle,uEle;
	nodo *pila_aux;
	inicializar(pila_aux);
	
	while(pilaC!=NULL){
		popPila(pilaC,n);
		if (pila_aux==NULL){
			pEle=n;
			pushPila(pila_aux,n);
		}else{
			pushPila(pila_aux,n);
		}
	}
	popPila(pila_aux,n);
	uEle=n;
	pushPila(pila_aux,n);
	
	while(pila_aux!=NULL){
		popPila(pila_aux,n);
		if (pilaC==NULL){
			pushPila(pilaC,pEle);
		}else{
			pushPila(pilaC,n);
		}
	}
	popPila(pilaC,n);
	pushPila(pilaC,uEle);
	
	cout<<"PILA con 1er y ultimo elemento intercambiados:\n";
	while(pilaC!=NULL){
		popPila(pilaC,n);
		cout<<n<<" ";
	}
	
}

void puntoB(nodo *&pila,nodo *&pilaC){

	int n;
	int elemento;
	nodo *pila_temp;
	inicializar(pila_temp);
		
	cout<<"PILA ORIGINAL:"<<endl;
	while(pila!=NULL){
		popPila(pila,n);
		pushPila(pila_temp,n);
		cout<<n<<" ";
	}
	
	cout<<"\nNumero a eliminar de la Pila: ";
	cin>>elemento;
	printf("\n");
	
	while(pila_temp!=NULL){
		popPila(pila_temp,n);
		if (elemento!=n){
			pushPila(pila,n);
		}
	}
	copiarPila(pila,pilaC);
	cout<<"\nPILA sin el numero "<<elemento<<":\n";
	while(pila!=NULL){
		popPila(pila,n);
		cout<<n<<" ";
	}
	printf("\n");
	copiarPila(pila,pilaC);
}

void copiarPila(nodo *&pilaAux,nodo *&pilaCopia){
	
	nodo *pila_nueva;
	int n;
	inicializar(pila_nueva);

	while(pilaAux!=NULL){
		popPila(pilaAux,n);
		pushPila(pila_nueva,n);
	}
	
	while(pila_nueva!=NULL){
		popPila(pila_nueva,n);
		pushPila(pilaAux,n);
		pushPila(pilaCopia,n);
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

void inicializar(nodo *&pila){
	pila=NULL;
}

void cargarVec(num v){
	for (int i=0;i<30;i++){
		v[i] = rand() % (11 - 1);
	}
	
}

