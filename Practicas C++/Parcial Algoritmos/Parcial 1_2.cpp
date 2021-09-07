#include <iostream>
#include <stdio.h>

#include <stdlib.h> 
#include <string.h>
#include <math.h>  
#include <fstream>
#include <windows.h>

#define CANT_AUTOS 100

using namespace std;

typedef char pat[7];

struct tFecha{
	int dia;
	int mes;
	int anio;
};


struct tAuto{
	string patente;
	string marca;
	tFecha anioFa; //año de fabricacion
	string modelo;
	int cantKm;
	int precioDiaAlq; //precio diario del alquiler
	int fUltAlq; //feha ultimo alquiler
	int fDevo; //fecha devolucion
	
	bool estado;
	int kmRecorridos;
	int facturacion;
};

typedef tAuto vecAuto[CANT_AUTOS];

void iniAutos(vecAuto);
void ingresarAutos(vecAuto,int &);
void procesarAlquileres(vecAuto,int);
void alquilar(vecAuto,int);
void devolucion(vecAuto,int);
int buscarAuto(vecAuto a, int b, string patAlq);
void difFecha(vecAuto a, int posicion,int &);
void mostrarAutos(vecAuto,int);
void ordenar(vecAuto , int );
void mostrarAlquilados(vecAuto,int);

int main(){
	ifstream ar("AUTOS_DEPOSITO.txt");
	int cantAutos=0;

	
	
	vecAuto autos;
	iniAutos(autos);
	ingresarAutos(autos,cantAutos);
for(int i=0;i<cantAutos;i++){
	cout<<autos[i].patente<<endl;
}
	procesarAlquileres(autos,cantAutos);
	mostrarAutos(autos,cantAutos);
	

	
	
	ar.close();
	return 0;
}
void mostrarAutos(vecAuto a, int b){
	system("cls");
	ordenar(a,b);
		for (int i=0;i<b;i++){
		cout<<"AUTO: "<<a[i].patente<<" KM recorridos: "<<a[i].kmRecorridos<<" Facturacion: "<<a[i].facturacion<<" MODELO: "<<a[i].modelo<<endl;
	}
	
	mostrarAlquilados(a,b);

	
}
void mostrarAlquilados(vecAuto a,int b){
		for(int i=0;i<b;i++){
		cout<<"Autos alquilados: "<<endl;
		if(a[i].estado==false){
			cout<<"Patente: "<<a[i].patente<<" ESTADO: NO ALQUILADO."<<endl;
		}
	}
	
}
void ordenar(vecAuto a, int b){
	int i, j;
	vecAuto varAux;

	
	for (i=0; i<b;i++){
		
		for (j=0;j<b-1;j++){ 
			
			if (strcmp(a[j].modelo.c_str(),a[j+1].modelo.c_str())>0){  
			
				varAux[j]=a[j];	
				a[j]=a[j+1];
				a[j+1]=varAux[j];		
				
			}
			
		}
			
	}
}

void procesarAlquileres(vecAuto a, int b){
	
	char operacion[1];
	char respuesta[1];
	strcpy(operacion,"");
	strcpy(respuesta,"S");
	while(strcmp(respuesta,"S")==0){
	
		cout<<"que operacion desea realiazar? (A para alquilar D para devolucion); "<<endl;
		cin>>operacion;
	
		if (strcmp(operacion,"A")==0){
			alquilar(a,b);
			cout<<endl;
		}else if(strcmp(operacion,"D")==0){
			devolucion(a,b);
			cout<<endl;
		}
	
	cout<<"desea realizar otra operacion? S/N: "<<endl;
	cin>>respuesta;
	
}
	
}

void alquilar(vecAuto a,int b){
	string patAlq;
	int posicion=0;
	patAlq="A";
	while(strcmp(patAlq.c_str(),"0")!=0){
	
		cout<<"Patente del Auto?: (INGRESE 0 PARA SALIR) "<<endl;
		cin>>patAlq;
		if (strcmp(patAlq.c_str(),"0")==0){
			break;
		}else{
	
	
		posicion=buscarAuto(a,b,patAlq);
	
		cout<<"Ingrese datos de alquiler. "<<endl;
		cout<<"Fecha (formato DDMMAAAA): "<<endl;
		cin>>a[posicion].fUltAlq;

		a[posicion].kmRecorridos=0;
		a[posicion].estado=true;
		}
	}
	
}
int buscarAuto(vecAuto a, int b, string patAlq){

	for(int i=0;i<b;i++){
		if (strcmp(a[i].patente.c_str(),patAlq.c_str())==0)
		return i;
		break;
	}
	cout<<"Auto no encontrado. Fin del programa."<<endl;
	exit(0);
	
	}
	

void devolucion(vecAuto a, int b){
	string patente;
	int posicion=0;
	int diasAlq=0;
	patente="A";
	while(strcmp(patente.c_str(),"0")!=0){
	
		cout<<"Patente de auto a devolver: "<<endl;
		cin>>patente;
		if(strcmp(patente.c_str(),"0")!=0){
		
	
			posicion=buscarAuto(a,b,patente);
			cout<<"Ingrese datos del auto devuelto."<<endl;
			cout<<"Fecha (formato DDMMAAAA): "<<endl;
			cin>>a[posicion].fDevo;

			a[posicion].kmRecorridos=0;
			cout<<"Ingresar km recorridos: "<<endl;
			cin>>a[posicion].kmRecorridos;
			difFecha(a,posicion,diasAlq);
			a[posicion].fUltAlq=a[posicion].fDevo;
			a[posicion].facturacion=diasAlq*a[posicion].kmRecorridos;
			a[posicion].estado=false;
		}else{
			break;
		}
	}
	
}
void difFecha(vecAuto a, int posicion,int &diasAlq){
	diasAlq=a[posicion].fDevo-a[posicion].fUltAlq;
	
}

void ingresarAutos(vecAuto a,int &cantAutos){
	
	int primero=0,ultimo=0, i=0;
	string cadena;
	ifstream ar("AUTOS_DEPOSITO.txt");
	while (!ar.eof()){
	
		getline(ar,cadena);
	
		ultimo=cadena.find(";",primero);
		a[i].patente=cadena.substr(primero,ultimo-primero);
		primero=ultimo+1;
		
		ultimo=cadena.find(";",primero);
		a[i].marca=cadena.substr(primero,ultimo-primero);
		primero=ultimo+1;
		
		ultimo=cadena.find(";",primero);
		a[i].anioFa.anio=atoi(cadena.substr(primero,ultimo-primero).c_str());
		primero=ultimo+1;
		
		ultimo=cadena.find(";",primero);
		a[i].modelo=cadena.substr(primero,ultimo-primero);
		primero=ultimo+1;
		
		ultimo=cadena.find(";",primero);
		a[i].cantKm=atoi(cadena.substr(primero,ultimo-primero).c_str());
		primero=ultimo+1;
		
		ultimo=cadena.find(";",primero);
		a[i].precioDiaAlq=atoi(cadena.substr(primero,ultimo-primero).c_str());
		primero=ultimo+1;
		
			
		ultimo=cadena.find(";",primero);
		a[i].fUltAlq=atoi(cadena.substr(primero,ultimo-primero).c_str());
		primero=ultimo+1;
		
		ultimo=cadena.find(";",primero);
		if ((strcmp(cadena.c_str(),"D")==0)){
			a[i].estado=false;
		}else{
			a[i].estado=true;
		}
		primero=ultimo+1;
		
		i++;
		cantAutos++;
	
	}
/*	a[i].fUltAlq.dia=0;
		a[i].fUltAlq.mes=0;
		a[i].fUltAlq.anio=0;
		
	
	tFecha fUltAlq; //feha ultimo alquiler
	tFecha fDevo; //fecha devolucion
	bool estado;*/
	
	
	ar.close();
}

void iniAutos(vecAuto a){
	
	for (int i=0;i<CANT_AUTOS;i++){
		a[i].patente="";
		a[i].marca="";
		a[i].anioFa.anio=0;
		a[i].modelo="";
		a[i].cantKm=0;
		a[i].precioDiaAlq=0;
		a[i].fUltAlq=0;
		a[i].fDevo=0;
		a[i].estado=false;
		a[i].kmRecorridos=0;
		a[i].facturacion=0;
		
	}


	
}


