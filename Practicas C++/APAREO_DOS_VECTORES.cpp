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
	cout<<"v1 : "<<endl;
	for (int k =0;k<=9;k++){
		cout<<v1[k]<<" ";
		
	}
	cout<<"\n";
	cout<<"v2 : "<<endl;
	for (int j =0;j<=9;j++){
		cout<<v2[j]<<" ";
		
	}
cout<<"\n";
cout<<"v3 : "<<endl;
	for (int i =0;i<=19;i++){
		cout<<v3[i]<<" ";
		
	}
cout<<"\n";
	system("pause");
	return 0;
}

void apareo(num v1, num v2, numTotal v3){
	int a = 0, b = 0;
	
	
		
	for( int c = 0; c < 20; c++ ){
 
 		 if( a == 10 ){
   		 	v3[c] = v2[b];
    		b++;
  		}
  		else if( b == 10 or v1[a] <= v2[b] ){
    		v3[c] = v1[a];
    		a++;
  		}else{
   			 v3[c] = v2[b];
   			 b++;
 		 }
	}
		
		
	
	
}

void ordenar(num numeros){
	
	int pos, aux;

	
	for (int k=0; k<=9;k++){
	
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
	    
    for(int c=0 ; c <=9; c++)
    {
    	
        v[c] = rand() % (1001 - 1);
        
    }	
  

	
}
