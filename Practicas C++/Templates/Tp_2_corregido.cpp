#include<stdlib.h>
#include<iostream>

using namespace std;

typedef int tVecInt[3];
typedef float tVecFloat[3];



template <typename T>
T fOperacion(T,T, T (*hacer)(T, T));

template <typename T>
T fSuma (T,T);

template <typename T>
void mostrar(T);


int main(){
	
	tVecInt vec1={15,12,6};
	tVecInt vec2={8,17,16};
	tVecInt vecRes={0,0,0};

	tVecFloat vecF1={15.1,12.1,6.1};
	tVecFloat vecF2={8.1,17.1,16.1}; 
	tVecFloat vecResF={0.0,0.0,0.0};
	
	for (int i=0;i<3;i++){
		vecRes[i]=fOperacion<int>(vec1[i],vec2[i],fSuma);
		vecResF[i]=fOperacion<float>(vecF1[i],vecF2[i],fSuma);
	}

	cout<<"Vectores tipo ENTERO:\n";
	mostrar<tVecInt>(vec1);
	cout<<endl;
	mostrar<tVecInt>(vec2);
	cout<<"\nVector Resultado Tipo ENTERO: \n";
	mostrar<tVecInt>(vecRes);

	cout<<"\n\nVectores tipo FLOAT:\n";
	mostrar<tVecFloat>(vecF1);
	cout<<endl;
	mostrar<tVecFloat>(vecF2);
	cout<<"\nVector Resultado Tipo FLOAT:\n";
	mostrar<tVecFloat>(vecResF);

	
	cout<<endl;
	system("pause");
	return 0;
}

template <typename T>
void mostrar(T a){
	
	for(int i=0;i<3;i++){
		cout<<"|"<<a[i]<<"\t";
	}
}

template <typename T>
T fOperacion(T a,T b,T (*suma)(T, T)){
	
	T c=0;
	c=suma(a,b);
	return c;
	
	
}

template <typename T>
T fSuma(T a,T b){
	T c=0;
	c=a+b;
	return c;	
}
