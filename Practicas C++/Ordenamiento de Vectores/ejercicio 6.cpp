#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

struct dato {

	char nombre[15];
	int dia;
	int mes;
	int anio;
	int fecha;
		
};

typedef dato vector[60];

void pedirDatos (vector,int &);
void buscar(vector,int &,int & );

int main(){
	setlocale(LC_ALL, "spanish");
	
	vector persona;
	int nFinal=0,posicion=0,i=0;
	char nombreBusqueda[15];
	int respuesta=1;

	pedirDatos(persona,nFinal);

	while (respuesta==1){
		
	buscar(persona,nFinal,respuesta);

	}
	system("pause");
	return 0;
}

void buscar(vector persona,int &nFinal,int &respuesta){
	
	int posicion=0,i=0;
	char nombreBusqueda[15];
	cout<<"Nombre a buscar: ";
	cin>>nombreBusqueda; 
	if (((strcmp(nombreBusqueda,"fin"))!=0)){
	
		while (  ((strcmp(persona[i].nombre,nombreBusqueda))!=0) and (i<=nFinal)    ){
		i++;
			if ( strcmp(persona[i].nombre,nombreBusqueda)==0        ){
				posicion=i;
			
			}
		
		}

	
		if (i<=nFinal){
			cout<<persona[posicion].nombre<<" nacio "<<persona[posicion].anio<<endl;
		}else{
			cout<<"No se encontro el nombre."<<endl;
		}
	}else{
		respuesta=0;
	}
		
	

}

void pedirDatos(vector persona, int &nFinal){

	char seguir[]="s";
	int i=0;
	int condicion=1;
	for(i ; condicion==1;i++){
			
		cout<<"Ingrese nombre: ";
		cin>>persona[i].nombre;
		cout<<"Ingrese dia de nacimiento: ";
		cin>>persona[i].dia;
		cout<<"Ingrese mes de nacimiento: ";
		cin>>persona[i].mes;
		cout<<"Ingrese año de nacimiento: ";
		cin>>persona[i].anio;
		
		cout<<"¿Desea seguir ingresando personas? S/N: ";
		cin>>seguir;
		strlwr(seguir);	
		if (strcmp(seguir,"s")==0){
			condicion=1;
		}else{
			condicion=0;
		}
		
	}
	
	nFinal=i;
	
}



