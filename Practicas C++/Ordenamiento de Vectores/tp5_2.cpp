#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;


struct dato {

	char nombre[15];
	int dia;
	int mes;
	int anio;
	long	int fecha;
		
};

typedef dato vector[60];

void pedirDatos(vector,int &);
void funFecha(vector ,int &);
void ordenar (vector,int& ); 
void comparar (vector,vector,int&,int &);

int main(){
	setlocale(LC_ALL, "spanish");
	
	vector persona;
	vector mayores;
	int tope=0, topeMay=0;
	
	pedirDatos(persona,tope);
	ordenar(persona,tope);
	comparar(persona,mayores,tope,topeMay);
	
	cout<<"Personas ingresadas de menor a mayor por edad:"<<endl;
	for(int k =0; k<=tope;k++){
		
		
		cout<<persona[k].nombre<<" nacio "<<persona[k].dia<<"/"<<persona[k].mes<<"/"<<persona[k].anio<<endl;
	}
	
	cout<<"Personas mayores a 25 a?os:"<<endl;
	for (int j=0;j<=topeMay;j++){
		
		cout<<mayores[j].nombre<<" nacio "<<mayores[j].dia<<"/"<<mayores[j].mes<<"/"<<mayores[j].anio<<endl;
	}
	
	
	system("pause");
	return 0;
}

void comparar(vector persona, vector mayores, int &tope, int&topeMay){
//108000 --> 25 a?os
	int i=0; int j=0;
	for (i; i<=tope; i++){
		
		if(persona[i].fecha>108000){
			mayores[j]=persona[i];
			j++;
			topeMay=j;
		}
		
	}


}





void ordenar(vector persona,int &tope){
	int i, j;
	vector varAux;
	

	
	for (i=0; i<=tope;i++){
		
		for (j=0;j<=tope-1;j++){ //el segundo bucle se debe ejecutar hasta cantidad de elementos - 1
			
			if (persona[j].fecha>persona[j+1].fecha){  //si numero actual es mayor a numero siguiente
			
				varAux[0]=persona[j];	//variable auxiliar es igual a numero actual
				persona[j]=persona[j+1];	//numero actual es igual a numero siguiente
				persona[j+1]=varAux[0];		//numero siguiente es igual a numero actual(que habia sido guardado en la primer linea del if
				
			}
			
		}
	}

}

void pedirDatos(vector persona, int &tope){

	char seguir[]="s";
	int condicion=1;
	int i= 0;
	for(i ; condicion==1;i++){
			
		cout<<"Ingrese nombre: ";
		cin>>persona[i].nombre;
		cout<<"Ingrese dia de nacimiento: ";
		cin>>persona[i].dia;
		cout<<"Ingrese mes de nacimiento: ";
		cin>>persona[i].mes;
		cout<<"Ingrese a?o de nacimiento: ";
		cin>>persona[i].anio;
		funFecha(persona,i);
		cout<<"?Desea seguir ingresando personas? S/N: ";
		cin>>seguir;
		strlwr(seguir);	
		if (strcmp(seguir,"s")==0){
			condicion=1;
		}else{
			condicion=0;
			tope=i;
		}
		
	}
	
}

void funFecha(vector persona,int &i){

	int anio1=0,mes1=0;
	persona[i].fecha=0;

	anio1=(2020-persona[i].anio)*10000;
	mes1=(5-persona[i].mes)*100;
	persona[i].fecha=anio1+mes1+(21-persona[i].dia);
	

}
