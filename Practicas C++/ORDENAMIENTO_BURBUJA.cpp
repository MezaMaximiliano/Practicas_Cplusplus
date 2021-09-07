//ordenamiento de metedo burbuja

#include<stdlib.h>
#include<iostream>
using namespace std;


int main(){
	int vector[]={5,2,6,7,6,7,6,7,6,7,6,7,6,7,6,7,1};
	int i, j, varAux;
	
	/*for (int acumulador=0;acumulador<5;acumulador++){
		cout<<"Ingrese un numero: "<<endl;cin>> vector[acumulador];
	}*/
	
	for (i=0; i<11;i++){
		
		for (j=0;j<10;j++){ //el segundo bucle se debe ejecutar hasta cantidad de elementos - 1
			
			if (vector[j]>vector[j+1]){  //si numero actual es mayor a numero siguiente
			
				varAux=vector[j];	//variable auxiliar es igual a numero actual
				vector[j]=vector[j+1];	//numero actual es igual a numero siguiente
				vector[j+1]=varAux;		//numero siguiente es igual a numero actual(que habia sido guardado en la primer linea del if
				
			}
			
		}
			
	}
	
	cout<<"Numeros ordenados: ";
	
	for (int k=0;k<11;k++){
		cout<<" "<< vector[k];
	}
	
	cout<<endl;
	system("pause");
	return 0;
}
