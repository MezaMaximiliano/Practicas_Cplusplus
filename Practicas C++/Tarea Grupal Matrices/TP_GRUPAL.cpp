#include<stdlib.h>
#include<iostream>
#include<string.h>

#define _AREA 9
#define _ACT 10
#define _CANTALUM 20

using namespace std;

typedef bool mTarea[_ACT][_AREA];

struct f{
	int dia;
	int mes;
	int anio;
};

struct est{
	f fEnt;
	char nombre[20];
	char apellido[20];
	char codArea[3];
	int nArea;
	int nAct;
	mTarea entrega;

};

typedef est vEst[_CANTALUM];

void pedirDatos(vEst );
int cIndice(vEst,int );
void dEntrega(vEst, int);
void mostrarResultados(vEst);
void iniVec (vEst);
void sumarFila(vEst,int);
void sumarColumna(vEst);

int main(){
	
	vEst alumno;
	string areas[]={"CS", "CN", "PDL", "MA", "MS", "PL", "EF", "TX", "IG","TOTAL"};
	iniVec(alumno);
	pedirDatos(alumno);
	
	system("cls");
	cout<<"\t";
	
	for (int i=0;i<=_AREA;i++){
		cout<<""<<areas[i]<<"\t";
		if (i==8){
			cout<<"\t";
		}
	}
	
	cout<<"\n\n";
	mostrarResultados(alumno);
	sumarColumna(alumno);
		
	return 0;
}

void iniVec(vEst a){
	
	for (int i=0;i<_CANTALUM;i++){
		a[i].fEnt.dia=0;
		a[i].fEnt.mes=0;
		a[i].fEnt.anio=0;
		strcpy(a[i].nombre,"");
		strcpy(a[i].apellido,"");
		strcpy(a[i].codArea,"");
		a[i].nArea=0;
		a[i].nAct=0;
	
		for (int j=0;j<_ACT;j++){
			for (int k=0;k<_AREA;k++){
				a[i].entrega[j][k]=false;
			}
			
		}
		
	}
}

void pedirDatos(vEst a){
	char seguir[]="si";
	int i=0;
	while (i<_CANTALUM){
		cout<<"Nombre estudiante: ";
		cin>>a[i].nombre;
		cout<<"Apellido estudiante: ";
		cin>>a[i].apellido;
		dEntrega(a,i);
		cout<<"¿Desea ingresar otro/a estudiante? si/no: ";
		cin>>seguir;
		i++;
		if ((strcmp(seguir,"no"))==0){
			break;
		}
		
	}
}

void dEntrega(vEst a, int i){
		
	char sArea[]={"si"};
	char sAct[]={"si"};
	char entrega[2];
	strcpy(entrega,"");
	while ((strcmp(sArea,"si"))==0){
		cout<<"Ingrese codigo de area: ";
		cin>>a[i].codArea;
		a[i].nArea=cIndice(a,i);
		char sAct[]={"si"};
		while((strcmp(sAct,"si"))==0){
			cout<<"Ingrese numero de actividad: ";
			cin>>a[i].nAct;
			a[i].entrega[a[i].nAct-1][a[i].nArea]=true;
			cout<<"¿Desea ingresar otra actividad? si/no: ";
			cin>>sAct;
		}
		cout<<"¿Desea ingresar otra area? si/no: ";
		cin>>sArea; 
	}
		
}

void mostrarResultados(vEst a){
	int fila=0;
	
	for (fila;fila<_ACT;fila++){
		cout<<fila+1<<")\t";
		for(int columna=0;columna<_AREA;columna++){
			
			if (a[0].entrega[fila][columna]==true){
				cout<<"SI"<<"\t";
			}else{
				cout<<"\t";
			}
			
			if (columna==_AREA-1){
				sumarFila(a,fila);
			}
			
		}
		cout<<"\n";
	}
	
	cout<<"\n\nTOTAL";
}

void sumarColumna(vEst a){
	int sumaCol=0;
	int i=0;
	cout<<"\t";
		
	for (int columna=0;columna<_AREA;columna++){
		
		for (int fila=0;fila<_ACT;fila++){
			
			if (a[0].entrega[fila][columna]==true){
				sumaCol++;
			}	
		}
		cout<<sumaCol<<"\t";
		sumaCol=0;
	}
	
}

void sumarFila(vEst a,int fila){
	int sumaFila=0;
	for (int i = 0 ; i<_AREA;i++){
		if (a[0].entrega[fila][i]==true){
			sumaFila++;
		}
	}
	cout<<"\t"<<sumaFila;
	
}	

int cIndice(vEst a,int i){
	int b=0;
	if (strcmp(a[i].codArea,"CS")==0){
		b=0;
	}else if (strcmp(a[i].codArea,"CN")==0){
		b=1;
	}else if (strcmp(a[i].codArea,"PDL")==0){
		b=2;
	}else if (strcmp(a[i].codArea,"MA")==0){
		b=3;
	}else if (strcmp(a[i].codArea,"MS")==0){
		b=4;
	}else if (strcmp(a[i].codArea,"PL")==0){
		b=5;
	}else if (strcmp(a[i].codArea,"EF")==0){
		b=6;
	}else if (strcmp(a[i].codArea,"TX")==0){
		b=7;
	}else if (strcmp(a[i].codArea,"IG")==0){
		b=8;
	}
	return b;
	
}



