#include<stdlib.h>
#include<iostream>

using namespace std;

typedef int tVecInt[3];
typedef float tVecFloat[3];



template <typename GEN>
GEN fOperacion(GEN,GEN, GEN (*hacer)(GEN, GEN));
template <typename GEN2>
GEN2 fSuma (GEN2,GEN2);
template <typename GEN>
void mostrar(GEN);


int main(){
	
	tVecInt vec1={15,12,6},vec2={8,17,16},vecRes={0,0,0};
	tVecFloat vecF1={15.1,12.1,6.1},vecF2={8.1,17.1,16.1},vecResF={0.0,0.0,0.0};
	
	for (int i=0;i<3;i++){
	vecRes[i]=fOperacion<int>(vec1[i],vec2[i],fSuma);
	vecResF[i]=fOperacion<float>(vecF1[i],vecF2[i],fSuma);
	}

	cout<<"Vectores tipo ENTERO:\n";
	mostrar(vec1);
	cout<<endl;
	mostrar(vec2);
	cout<<"\nVector Resultado Tipo ENTERO: \n";
	mostrar(vecRes);

	cout<<"\n\nVectores tipo FLOAT:\n";
	mostrar(vecF1);
	cout<<endl;
	mostrar(vecF2);
	cout<<"\nVector Resultado Tipo FLOAT:\n";
	mostrar(vecResF);

	
	cout<<endl;
	system("pause");
	return 0;
}

template <typename GEN>
void mostrar(GEN a){
	
	for(int i=0;i<3;i++){
		cout<<"|"<<a[i]<<"\t";
	}
}

template <typename GEN>
GEN fOperacion(GEN a,GEN b,GEN (*suma)(GEN, GEN)){
	
	GEN c=suma(a,b);
	return c;
	
	
}

template <typename GEN2>
GEN2 fSuma(GEN2 a,GEN2 b){
	GEN2 c=0;
	c=a+b;
	return c;	
}
