
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

struct dato {

	char carrera[30];
	int edad;
		
};

typedef dato vector[60];

void pedirDatos (vector,int &);
void ordenar(vector,int&);
void corte(vector, int &,int&);

int main(){
		int tope=0,cantCarrera=0;
		vector persona;
		
		pedirDatos(persona,tope);
		ordenar(persona,tope);
		corte(persona,tope,cantCarrera);
		
	
	
}

void corte(vector persona, int &tope,int &cantCarrera){
	char carreraAnt[30],carreraAct[30];
	int i =0;
	
		
	while (i<=tope){
		
		strcpy(carreraAnt,persona[i].carrera);
		strcpy(carreraAct, carreraAnt);
		while (((strcmp(carreraAnt,persona[i].carrera))==0) and (i<=tope)){
			
			i++;
			cantCarrera++;
			strcpy(carreraAct,persona[i].carrera);
		
		}
		
		cout<<"La cantidad de alumnos de "<<carreraAnt<<" es de "<<cantCarrera<<endl;
		cantCarrera=0;
	}
		
	}








void pedirDatos(vector persona, int &tope){

	char seguir[]="si";
	int condicion=1;
	int i= 0;
	

	
	for(i ; condicion==1;i++){
			
		cout<<"Ingrese carrera: ";
		cin>>persona[i].carrera;
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
			while ((pos>0) &&  ((strcmp(mayores[pos-1].carrera,aux[0].carrera))>0) ){
				mayores[pos]=mayores[pos-1];
				pos--;
			}
			mayores[pos]=aux[0];
		}
		
		i=0,pos=0;		
		
			
		for (i; i<=nFinalMay;i++){
			pos=i;
			aux[0]=mayores[i];
			while ((pos>0) &&  ((strcmp(mayores[pos-1].carrera,aux[0].carrera))==0) and (mayores[pos-1].edad>aux[0].edad) ){
				mayores[pos]=mayores[pos-1];
				pos--;
			}
			mayores[pos]=aux[0];
		}

}

