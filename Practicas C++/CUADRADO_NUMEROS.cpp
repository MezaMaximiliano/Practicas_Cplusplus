//La suma de los cuadrados de los 10 primeros enteros mayores a 0
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main(){
	
	int resultado,num,contador;
	num=1,contador=1,resultado=0;
	
	do{
		resultado=(pow(num,2))+(pow (num,2));
		cout<<resultado<<endl;
		num++,contador++;
		
	}while(contador<=10);
	cout<<"\n";
	system("pause");
	return 0;
}
