/*6-escribir una función que reciba una matriz de 10x5 enteros y un número (entre 0 y 9) que representa una columna y devuelva la suma de los valores
correspondiente a la columna*/
#include<stdlib.h>
#include<iostream>

#define _CANTFILA 10
#define _CANTCOL 5

typedef int matriz[_CANTFILA][_CANTCOL];

void iniM(matriz);
void cargarM(matriz);
void mostrarM(matriz);
int sumaCol(matriz,int,int);

int main(){
	
	matriz mNum;
	int posCM;
	int suma=0;	
	
	iniM(mNum);
	cargarM(mNum);
	
	linea22:	printf("Ingrese un numero de columna (1-5): ");
	scanf ("%i",&posCM);
	if (posCM>0 and posCM<=5){
		
	}else{
		printf("Ingrese un numero de columna invalida.\n");
		goto linea22;
	}
	system("cls");
	mostrarM(mNum);
	suma=sumaCol(mNum,posCM,suma);

	
	printf("\nLa suma de la columna %i es: %i\n",posCM,suma);
	
	
	system("pause");
	return 0;
}

void mostrarM(matriz m){
		for (int i=0;i<_CANTFILA;i++){
		for (int k=0;k<_CANTCOL;k++){
			printf ("%-5d",m[i][k]);
		}
		printf("\n");
	}
	
}

int sumaCol(matriz m, int p, int s){
	s=0;
	p=p-1;
	for (int i=0;i<_CANTFILA;i++){
		s=s+m[i][p];
	}

	return s;
}



void cargarM(matriz m){
	
	for (int i=0;i<_CANTFILA;i++){
		for (int k=0;k<_CANTCOL;k++){
			m[i][k]=(k+1)*(i+1);
			
		}
	}
	
}


void iniM(matriz m){
	
	for (int i=0;i<_CANTFILA;i++){
		for (int k=0;k<_CANTCOL;k++){
			m[i][k]=0;
		}
		
	}
	
	
}

/*	for (int i=0;i<_CANTFILA;i++){
		for (int k=0;k<_CANTCOL;k++){
			printf ("%-5d",mNum[i][k]);
		}
		printf("\n");
	}*/
