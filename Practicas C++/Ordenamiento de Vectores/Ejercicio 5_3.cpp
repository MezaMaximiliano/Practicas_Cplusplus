#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

//no se puede hacer por burbuja

struct dato {
	char nombre[15];
	int dia;
	int mes;
	int anio;
	int fecha;
		
};

typedef dato vector[60];

void pedirDatos (vector persona,int &nFinal);
void compararFecha(vector persona,vector mayores,int &nFinal);
void difFecha(vector persona, int &i);
void ordenar (vector mayores, int &nFinal);

int main(){
	setlocale(LC_ALL, "spanish");
	
	vector persona;
	int nFinal=0;
		
	pedirDatos(persona,nFinal);
	cout<<"nfinal= "<<nFinal<<endl;
	dato mayores[nFinal];
	compararFecha(persona,mayores,nFinal);
	ordenar(mayores,nFinal);
	
		for (int k=0; k<nFinal; k++){
		cout<<mayores[k].nombre<<endl;
		
		
		
	}
	
	system("pause");
	return 0;
}

void ordenar (vector mayores,int &nFinal){
	int i=0,j=0;
	vector varAux;

	for (i=0; i<=nFinal;i++){
	
		for (j=0;j<nFinal-1;j++){ //el segundo bucle se debe ejecutar hasta cantidad de elementos - 1
			vector refActual;
			vector refSig;
			refActual[j]=mayores[j];
			refSig[j+1]=mayores[j+1];
			strlwr(refActual[j].nombre);
			strlwr(refSig[j+1].nombre);
			int comparacion;
			comparacion=strcmp(mayores[j].nombre,mayores[j+1].nombre);
		
			if (comparacion>0){  //si numero actual es mayor a numero siguiente
					
				varAux[0]=mayores[j];	//variable auxiliar es igual a numero actual
				
				
				mayores[j]=mayores[j+1];	//numero actual es igual a numero siguiente
				
				mayores[j+1]=varAux[0];		//numero siguiente es igual a numero actual(que habia sido guardado en la primer linea del if
				
			}
			
		}
			
	}
}

void compararFecha(vector persona, vector mayores, int &nFinal){
	//86400 dias --> 20 años
	
	for (int i=0; i<nFinal;i++){
			
		if (persona[i].fecha >=86400){
		
			mayores[i]=persona[i];
			
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

	anio1=(2020-persona[i].anio)*10000;
	mes1=(5-persona[i].mes)*100;
	persona[i].fecha=anio1+mes1+(21-persona[i].dia);

}
