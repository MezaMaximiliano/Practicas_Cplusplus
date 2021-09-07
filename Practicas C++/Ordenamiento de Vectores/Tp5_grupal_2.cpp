#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

struct actual{
	int d;
	int m;
	int a;
	
}f;

struct dato {

	char nombre[15];
	int dia;
	int mes;
	int anio;
	long	int fecha;
	long int difFecha;
		
};

typedef dato vector[60];

void pedirDatos(vector,int &);
void funFecha(vector ,int &);
void ordenar (vector,int& ); 
void comparar (vector,vector,int&,int &);
void pedirActual();


int main(){
	setlocale(LC_ALL, "spanish");
	
	vector persona;
	vector mayores;
	int tope=0, topeMay=0;
	
	cout<<"INGRESE FECHA ACTUAL:\n "<<endl;
	
	pedirActual();
	
	system("cls");
	
	pedirDatos(persona,tope);
	ordenar(persona,tope);
	comparar(persona,mayores,tope,topeMay);
	
	system("cls");
	
	cout<<"Personas ingresadas de menor a mayor por edad:\n"<<endl;
	for(int k =0; k<=tope;k++){
			
		cout<<persona[k].nombre<<" nacio "<<persona[k].dia<<"/"<<persona[k].mes<<"/"<<persona[k].anio<<endl;
	
	}
	
	cout<<"\nPersonas mayores a 25 años:\n"<<endl;
	for (int j=0;j<=topeMay;j++){
		
		cout<<mayores[j].nombre<<" nacio "<<mayores[j].dia<<"/"<<mayores[j].mes<<"/"<<mayores[j].anio<<endl;
	}
	cout<<"\n";
	
	system("pause");
	return 0;
}

void pedirActual(){

	cout<<"Año actual: ";
	cin>>f.a;
	cout<<"Mes actual: ";
	cin>>f.m;
	cout<<"Dia actual: ";
	cin>>f.d;

}

void pedirDatos(vector persona, int &tope){

	char seguir[]="si";
	int condicion=1;
	int i= 0;
	
	cout<<"Ahora los datos de las personas: \n"<<endl;
	
	for(i ; condicion==1;i++){
			
		cout<<"Ingrese nombre: ";
		cin>>persona[i].nombre;
		cout<<"Ingrese dia de nacimiento: ";
		cin>>persona[i].dia;
		cout<<"Ingrese mes de nacimiento: ";
		cin>>persona[i].mes;
		cout<<"Ingrese año de nacimiento: ";
		cin>>persona[i].anio;
		funFecha(persona,i);
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

void funFecha(vector persona,int &i){

	int anio1=0,mes1=0;
	persona[i].fecha=0;

	anio1=(f.a-persona[i].anio)*12*30;
	mes1=(f.m-persona[i].mes)*30;
	persona[i].fecha=anio1+mes1+(f.d-persona[i].dia);

}

void ordenar(vector persona,int &tope){
	int i, j;
	vector varAux;
		
	for (i=0; i<=tope;i++){
		
		for (j=0;j<=tope-1;j++){ 
			
			if (persona[j].fecha>persona[j+1].fecha){ 
			
				varAux[0]=persona[j];	
				persona[j]=persona[j+1];	
				persona[j+1]=varAux[0];		
				
			}
			
		}
	}

}



void comparar(vector persona, vector mayores, int &tope, int&topeMay){

	int i=0; int j=0;
	
	for (i; i<=tope; i++){
		
		if(persona[i].fecha>9000){
			mayores[j]=persona[i];
			topeMay=j;
			j++;
			
		}
		
	}

}
