//ordenar por nombre y por edad 

#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

struct dato {

	char nombre[15];
	int edad;
		
};

typedef dato vector[60];

void pedirDatos (vector,int &);
void ordenar(vector,int&);

int main(){
		int tope=0;
		vector persona;
		
		pedirDatos(persona,tope);
		ordenar(persona,tope);
		
		for(int i=0;i<=tope;i++){
			
			cout<<persona[i].nombre<<"   "<<persona[i].edad<<endl;
			
		}
	
}

void pedirDatos(vector persona, int &tope){

	char seguir[]="si";
	int condicion=1;
	int i= 0;
	

	
	for(i ; condicion==1;i++){
			
		cout<<"Ingrese nombre: ";
		cin>>persona[i].nombre;
		cout<<"Ingrese edad: ";
		cin>>persona[i].edad;
		cout<<"¿Desea seguir ingresando personas? S/N: ";
		cin>>seguir;
		strlwr(seguir);	
		if ((strcmp(seguir,"si")==0) or (strcmp(seguir,"s")==0)){
			condicion=1;
		}else{
			condicion=0;
			tope=i;
		}
		
	}
	
}

void ordenar (vector mayores,int &nFinalMay){
	
		int i=0,pos=0;		
		vector aux;
			
		for (i; i<=nFinalMay;i++){
		
			pos=i;
			aux[0]=mayores[i];
			int comparacion= strcmp(mayores[pos-1].nombre,aux[0].nombre);
			cout<<"comparacion "<<comparacion<<endl;
			
			system("pause");
			while ((pos>0) && (comparacion>0) ){
				mayores[pos]=mayores[pos-1];
									
				pos--;
			}
						
			mayores[pos]=aux[0];
		}

	
	
}

