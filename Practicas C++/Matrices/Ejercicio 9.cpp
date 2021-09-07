//Escribir una función que reciba una matriz de números de 10x5 y devuelva un vector de 10 elemento que contengan la suma de cada fila

#include <stdlib.h>
#include<iostream>

#define _CANTFILA 10
#define _CANTCOL 5

typedef int matriz[_CANTFILA][_CANTCOL];
typedef int vector[_CANTFILA];

void iniM(matriz);
void iniV(vector);
void cargarM(matriz);
void sumaM(matriz, vector);

int main (){
	
	matriz mNum;
	vector suma;
	
	iniM(mNum);
	iniV(suma);
	cargarM(mNum);
	sumaM(mNum,suma);
	system("cls");
	for (int i=0;i<_CANTFILA;i++){
		for (int k=0;k<_CANTCOL;k++){
			printf ("%-5d",mNum[i][k]);
		}
		printf("\n");
	}
	printf("\n");
	
	for (int i=0;i<_CANTFILA;i++){
		printf("%-5d",suma[i]);
	}
	printf("\n");
	
	
	system("pause");
	return 0;
}

void sumaM(matriz m, vector s){
	int suma=0;
	for (int i=0;i<_CANTFILA;i++){
		for (int k=0;k<_CANTCOL;k++){
			suma=suma+m[i][k];
		}
		s[i]=suma;
		suma=0;
	}
	
	
	
}
void iniV(vector s){
	for (int i=0;i<_CANTFILA;i++){
		s[i]=0;
	}
}

void cargarM(matriz m){
	for (int i=0;i<_CANTFILA;i++){
		for (int k=0;k<_CANTCOL;k++){
			m[i][k]=(i+1)*(k+1);
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
