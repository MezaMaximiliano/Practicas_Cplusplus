/*Desarrollar una función que reciba un vector de hasta 100 números enteros y devuelva dos vectores, uno con los números que se a n pares y el otro con los
números que sean impares*/

#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;

typedef int num[99];

void carVec(num);
void ordenar (num);
void separar(num,num,num,int&,int&);

int main(){
	
	num numeros;
	num par;
	num impar;
	int topePar=0,topeImpar=0;
	
	carVec(numeros);
	ordenar(numeros);
	separar(numeros,par,impar,topePar,topeImpar);

	cout<<"Hay "<<topePar<<" numeros pares y son: "<<endl;
	for (int i=0;i<topePar;i++){
		cout<<par[i]<<" ";
	}
    cout<<"\n"<<endl;
	
	cout<<"Hay "<<topeImpar<<" numeros impares y son: "<<endl;
	for (int i=0;i<topeImpar;i++){
		cout<<impar[i]<<" ";
	}    
 	cout<<"\n"<<endl;
	system("pause");
	return 0;
}

void separar(num a, num b, num c, int &topePar, int &topeImpar ){
	
	int k=0,j=0;
	
	for (int i=0;i<=99;i++){
		if ( (a[i]%2)==0  ){
			b[k]=a[i];
			k++;
			topePar=k;
			
			
		}else if ( (a[i]%2)!=0  ){
			c[j]=a[i];
			j++;
			topeImpar=j;
			
		}
		
		
	}
	
}

void ordenar(num numeros){
	
	int k=0, pos, aux;
	
	
	
	for (k; k<=99;k++){
	
		pos=k;
		aux=numeros[k];
	
		while ((pos>0) and (numeros[pos-1]>aux) ){
			numeros[pos]=numeros[pos-1];
			pos--;
		}
		numeros[pos]=aux;
	}
}



void carVec(num num){
	int c;
  	srand(time(NULL));
    
    for(c = 0; c <= 99; c++)
    {
        num[c] = rand() % (1001 - 1);
        
    }	
	
}
