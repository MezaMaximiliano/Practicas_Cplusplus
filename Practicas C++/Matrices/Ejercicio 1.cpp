//definir un tipo de datos que represente una matriz de números enteros con 10 filas y 5 columnas

#include<iostream>
#include<stdlib.h>
#include<time.h>
typedef int matriz[10][5];



int main (){
	
	srand(time(NULL));
	matriz mNum;
	
	for (int i=0;i<10;i++){
		for(int k=0;k<5;k++){
			mNum[i][k]=rand() % (101-1)	;
		}
		
	}
	
	for (int i=0;i<10;i++){
		for(int k=0;k<5;k++){
			
			printf( "%-4i ",mNum[i][k]);
		}
		printf ("\n \n");
	}
	
	system("pause");
	return 0;
}



	/*for (int i=0;i<=10;i++){
		for(int k=0;k<=5;k++){
			
		}
		
	}*/
