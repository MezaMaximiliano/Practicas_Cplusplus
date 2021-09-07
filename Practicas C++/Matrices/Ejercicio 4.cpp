/*escribir un una función que complete una matriz de 10x5 números enteros de acuerdo al siguiente criterio: en la primer fila los 5 primeros múltiplos de 1,
en la segunda fila los 5 primeros múltiplos de 2 y así sucesivamente hasta la fila 10 en la cual escribimos los primeros 5 múltiplos de 9. ESTA FUNCIÓN DEBE
RESOLVER MEDIANTE CÁLCULOS, NO DEBE PEDIR LOS VALORES POR EL TECLADO*/

#include<iostream>
#include<stdlib.h>
#define _CANTFILAS 10
#define _CANTCOL 5 

typedef int matriz[_CANTFILAS][_CANTCOL];
void iniM(matriz);
void cargarM(matriz &);
int main(){
	matriz mNum;
	iniM(mNum);
	cargarM(mNum);
	for (int i=0;i<_CANTFILAS;i++){
		for (int k=0;k<_CANTCOL;k++){
			printf("%-20i",mNum[i][k]);
		}
		printf("\n");
		
	}
	
	system("pause");
	return 0;
}
void cargarM(matriz &n){
	
	for (int i=0;i<_CANTFILAS;i++){
		for (int k=0;k<_CANTCOL;k++){
			n[i][k]=(k+1)*(i+1);
		}
	}
}

void iniM(matriz n){
	for (int i=0;i<_CANTFILAS;i++){
		for (int k=0;k<_CANTCOL;k++){
			n[i][k]=0;
		}
	}
}
