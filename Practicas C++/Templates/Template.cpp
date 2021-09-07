#include <stdlib.h>
#include <iostream>
#include<stdio.h>

using namespace std;

template <typename GEN>
GEN suma(GEN , GEN);

int main(){
	
	float  a=15.454, b=20.65;
	float res;
	res=suma<float>(a,b);
	
	cout<<res<<endl;
	
	
	
	system("pause");
	return 0;
}

template <typename GEN>
GEN suma(GEN a, GEN b){
	GEN res=0;
	res=a+b;
	return res;
}
