//calculo de 1-2+3-4+5-6...n
#include<stdlib.h>
#include<iostream>

using namespace std;
int main(){
	
	int numero, suma=0,resta=0,suma_total=0;
	cout<<"Ingrese un numero: ", cin>>numero;
	for(int i=1; i<=numero; i=i+2){
		
		suma=suma+i;
	}
	for(int j=2;j<=numero;j=j+2){
		resta=resta+j;
		
	}
	resta=resta*-1;
	suma_total=suma+resta;
	cout<<"La secuencia da como resultado: "<<suma_total<<endl;
	
	system("pause");
	return 0;
}
