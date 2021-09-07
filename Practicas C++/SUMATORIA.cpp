//factorial de un numero
#include<stdlib.h>
#include<iostream>
using namespace std;
int main(){
	int numero, suma=0;
	cout<<"Ingrese un numero: ",cin>>numero;
	for (int i=numero;i>=1;i--){
		suma=suma+i;
	}
	cout<<suma<<endl;
	
	system("pause");
	return 0;
}
