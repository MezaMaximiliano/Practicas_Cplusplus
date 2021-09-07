#include<stdlib.h>
#include<iostream>

using namespace std;

template <typename GEN>
GEN suma(GEN , GEN);
template <typename GEN>
GEN resta(GEN , GEN);
template <typename GEN>
GEN producto(GEN , GEN);
template <typename GEN2>
GEN2 fOperacion(GEN2 a, GEN2 b, GEN2(*hacer)(GEN2,GEN2));

int main(){
	int a=15,b=8,res=0;
	cout<<"suma: "<<fOperacion<int>(a,b,suma)<<endl;
	cout<<"resta: "<<fOperacion<int>(a,b,resta)<<endl;
	cout<<"producto: "<<fOperacion<int>(a,b,producto)<<endl;
	
	system("pause");
	return 0;
}

template <typename GEN2>
GEN2 fOperacion(GEN2 a, GEN2 b, GEN2(*hacer)(GEN2,GEN2)){
	GEN2 res=0;
	res=hacer(a,b);
	return res;
}

template <typename GEN>
GEN suma(GEN a, GEN b){
	GEN res=0;
	res=a+b;
	return res;
}

template <typename GEN>
GEN resta(GEN a, GEN b){
	GEN res=0;
	res=a-b;
	return res;
}

template <typename GEN>
GEN producto(GEN a, GEN b){
	GEN res=0;
	res=a*b;
	return res;
}
