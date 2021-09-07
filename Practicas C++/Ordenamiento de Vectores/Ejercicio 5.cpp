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

void pedirDatos (vector persona,int &nFinal);
void compararFecha(vector persona,vector mayores,int &nFinal,int &);
void difFecha(vector persona, int &i);
void ordenar (vector mayores, int &nFinal);

int main(){
	setlocale(LC_ALL, "spanish");
	
	vector persona;
	int nFinal=0,nFinalMay=0;
		
	pedirDatos(persona,nFinal);
	dato mayores[nFinal];
	compararFecha(persona,mayores,nFinal,nFinalMay);
	ordenar(mayores,nFinalMay);
	cout<<"nfinalMay: "<<nFinalMay<<endl;
	for (int k=nFinalMay; k>=0; k--){
	
		cout<<mayores[k].nombre<<endl;
			
	}
	
	system("pause");
	return 0;
}

void ordenar (vector mayores,int &nFinalMay){
	int i=0,j=0;
	vector varAux;

	for (i=0; i<nFinalMay;i++){
	
		for (j=0;j<nFinalMay-1;j++){ 
			vector refActual;
			vector refSig;
			refActual[j]=mayores[j];
			refSig[j+1]=mayores[j+1];
			strlwr(refActual[j].nombre);
			strlwr(refSig[j+1].nombre);
			int comparacion;
			comparacion=strcmp(mayores[j].nombre,mayores[j+1].nombre);
		
			if (comparacion>0){  
					
				varAux[0]=mayores[j];	//variable auxiliar es igual a numero actual
				
				
				mayores[j]=mayores[j+1];	//numero actual es igual a numero siguiente
				
				mayores[j+1]=varAux[0];		//numero siguiente es igual a numero actual(que habia sido guardado en la primer linea del if
				
			}
			
		}
			
	}
}

void compararFecha(vector persona, vector mayores, int &nFinal,int &nFinalMay){
	//7200 dias --> 20 años
	int k=0;
	for (int i=0; i<=nFinal;i++){
			
		if (persona[i].fecha >=7200){
		
			mayores[i]=persona[i];
			nFinalMay=k;
			k++;
			
		}
			
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
		difFecha(persona,i);
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

void difFecha(vector persona,int &i){

	int anio1=0,mes1=0;
	persona[i].fecha=0;

	anio1=(2020-persona[i].anio)*12*30;
	mes1=(5-persona[i].mes)*30;
	persona[i].fecha=anio1+mes1+(21-persona[i].dia);

}
