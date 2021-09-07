//suma, resta, multiplicacion usando funciones

#include<iostream>
#include<stdlib.h>

using namespace std;

	int sum(int n1, int n2, int s=0){
		
		s=n1+n2;
	
		return s ;
	}
	
	int res(int n1, int n2, int r=0){
		
		r=n1-n2;
		return r;
	}	

	int mul(int n1, int n2, int m=0){
		
		m=n1*n2;
		return m;
	}
int main(){
	int num1,num2, suma=0, resta=0, multi=0;
	cout<<"NUMERO 1 "<<endl;
	cin>>num1;
	cout<<"NUMERO 2 "<<endl;	
	cin>>num2;
	suma=sum(num1,num2);
	resta=res(num1,num2);
	multi=mul(num1,num2);

	cout<<"\n"<<suma<<endl;
	cout<<resta<<endl;
	cout<<multi<<endl;
	system("pause");
	return 0;
}
