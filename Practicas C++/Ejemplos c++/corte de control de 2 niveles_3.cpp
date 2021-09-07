//ordenar por nombre y por edad 
/*void procesarCorte(tVectorEst vEst, int cant){
	str30 carAnt;  //char[30]
	int i =0;
	tRegEst r; //estructura con dni, carrera, apellido, nombre, anio ingreso
	bool fin;
	int total=0;
	int totalCar;
	traer(vEst,t,cant,i,fin);  //tVectorEst vector de estructuras tRegEst 
	while(!fin){
		strcpy(carAnt,r.carrera);
		totalCar=0;
		cout<<"Carrera "<<cartAnt<<endl;
		while ((!fin)and (strcmp(carAnt,r.carrera)==0)){
			totalCar++;
			traer(vEst,r,cant,i,fin);
		}
		
		cout<<"Total Carrera "<<totalCar<<endl;
		total=total+totalCar;
	}
	
	cout<<"Total ingreso de las carreras es "<<total<<endl;
}

void traer(tVectorEst v, tRegEst &r,int cant, int &ptro,bool &fin){
	if (ptro<cant){
		r=v[ptro];
		ptro++;
		fin=false;
	}else fin=true;
}*/



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
void corte(vector, int &);

int main(){
		int tope=0;
		vector persona;
		
		pedirDatos(persona,tope);
		ordenar(persona,tope);
		corte(persona,tope);
		
		for(int i=0;i<=tope;i++){
			
			cout<<persona[i].carrera<<"   "<<persona[i].edad<<endl;
			
		}
	
}

void corte(vector persona, int &tope){
	
	
	char carreraAnt[30],carreraAct[30];
	int i =0;
	
	strcpy(persona[i].carrera,carreraAnt);
	strcpy(carreraAnt,carreraAct);
	
	
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

