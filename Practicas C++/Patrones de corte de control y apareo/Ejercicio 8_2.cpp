#include <stdlib.h>
#include <time.h>
#include<iostream>
#include <cstdlib>
using namespace std;

typedef int num[99];
typedef int numTotal[199];

void carVec(num);

void ordenar (num);
void apareo(num,num,numTotal);

int main(){
	srand(time(NULL));
	num v1,v2;
	numTotal v3;

	int topePar=0,topeImpar=0;
	
	carVec(v1);
	carVec(v2);
	ordenar(v1);
	ordenar(v2);
	apareo(v1,v2,v3);
	for (int i =0;i<200;i++){
		cout<<v3[i]<<" ";
		topePar=i;
	}
	cout<<"\n"<<"valor de i "<<topePar<<"v3 198 "<<v3[199]<<endl;
	system("pause");
	return 0;
}

void apareo(num v1, num v2, numTotal v3){
	int j=0,k=0;

	for (int i =0;i<200;i++){
		if (v1[j]<v2[k]){
			v3[i]=v1[j];
			j++;
		}else if (v2[k]<v1[j]){
			v3[i]=v2[k];
			k++;
		}else if (v1[j]==v2[k]){
			v3[i]=v1[j];
			j++;
		}
		
		
		
		
	}
	
}

void ordenar(num numeros){
	
	int pos, aux;

	
	for (int k=0; k<=99;k++){
	
		pos=k;
		aux=numeros[k];
	
		while ((pos>0) and (numeros[pos-1]>aux) ){
			numeros[pos]=numeros[pos-1];
			pos--;
		}
		numeros[pos]=aux;
	}
}


void carVec(num v){
	
	
  	
    
    for(int c=0 ; c <= 99; c++)
    {
    	
        v[c] = rand() % (1001 - 1);
        
    }	
  

	
}
