//escribir una función que inicialice una matriz de 10x5 números enteros
#include<iostream>
#include<stdlib.h>
#define _CANTFILAS 10
#define _CANTCOL 5 

typedef int matriz[_CANTFILAS][_CANTCOL];

void iniM(matriz);
int main(){
	
	matriz mNum;
	iniM(mNum);
		std::cout<<mNum[2][2]<<"\n";
	system("pause");
	return 0;
}

void iniM(matriz n){
	
	for (int i=0;i<_CANTFILAS;i++){
		for (int k=0;i<_CANTCOL;i++){
			n[i][k]=0;
		}
	}
	
}
