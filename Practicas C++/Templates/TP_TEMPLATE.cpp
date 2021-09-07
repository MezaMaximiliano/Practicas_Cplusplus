#include<stdlib.h>
#include<iostream>

using namespace std;

typedef int tvec[3];
typedef float tvecFloat[3];

template<typename GEN> GEN fOperacion(GEN a, GEN b, GEN (*hacer)(GEN, GEN));
template<typename GEN> GEN suma(GEN,GEN);
template <typename GEN> GEN operacion (GEN,GEN,GEN);



int main (){
	tvec vec1={15,12,6},vec2={8,17,16},vecRes={0,0,0};
	tvecFloat vecF1={15.1,12.1,6.1},vecF2={8.1,17.1,16.1},vecResF={0.0,0.0,0.0};
	operacion(vec1,vec2,vecRes);
	operacion(vecF1,vecF2,vecResF);
	
	cout<<"Vector suma enteros: \n|";
	for(int i=0;i<3;i++){
	cout<<vecRes[i]<<"\t|";
	}
	cout<<"\nVector suma float: \n|";
	for(int i=0;i<3;i++){
		cout<<vecResF[i]<<"\t|";
	}
	cout<<endl;
	system("pause");
	return 0;
}

template <typename GEN> 
GEN operacion (GEN vec1, GEN vec2, GEN vecRes){
	
	for (int i=0;i<3;i++){
		vecRes[i]=fOperacion(vec1[i],vec2[i],suma);
	}
	
}

template <typename GEN2> 
GEN2 fOperacion(GEN2 a, GEN2 b, GEN2(*hacer)(GEN2,GEN2)){
	GEN2 res=0;
	res=hacer(a,b);
	return res;
}

template<typename GEN> 
GEN suma (GEN a,GEN b){
	GEN res=0;
	res=a+b;
	return res;
}
