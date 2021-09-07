#include<stdlib.h>
#include<iostream>

using namespace std;
typedef int vector[100];
void pedirNumero(int &num, int &res);
void parImpar(vector par, vector impar, int &iPar, int &iImpar,int res,int numero);
int main(){
	vector par;
	int iPar=0;
	vector impar;
	int iImpar=0;
	int numero,maximo=0, resultado=0;
		
	pedirNumero(numero, resultado);
	for (numero;numero!=0;){
		
		parImpar(par,impar,iPar,iImpar,resultado,numero);
		pedirNumero(numero,resultado);
		maximo++;
		if (maximo==99){
			numero=0;
		}
	}
	
	cout<<endl<<"Vector par posicion 5: "<<par[5];
	system("pause");
	return 0;
}

void parImpar(vector par, vector impar, int &iPar, int &iImpar, int res,int numero){
	if (res==0){
		par[iPar]=numero;
		iPar++;
	}else if (res!=0){
		impar[iImpar]=numero;
		iImpar++;
	}
}

void pedirNumero(int &num, int &res){
	cout<<"Ingrese un numero: ";
	cin>>num;
	res=num%2;
}
