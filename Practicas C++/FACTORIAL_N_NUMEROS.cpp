//factorial de n numeros
#include<stdlib.h>
#include<iostream>
using namespace std;
int main(){
	int num,sum_fact=0, sum_total=0;
	cout<<"Ingrese un numero: ";
	cin>>num;
	
	for (int i=num;i>=1;i--){
		
		
		for (int j=i;j>=1;j--){
			sum_fact=sum_fact+j;
			cout<<j<<endl;
			cout<<"suma factorial "<<sum_fact<<endl;
			num=j;
		}
		
		sum_total=sum_total+sum_fact;
		cout<<i<<endl;
		cout<<"sum_total "<<sum_total<<endl;
		sum_fact=0;
	}
	
	cout<<"\n"<<sum_total<<endl;
	
	
	system("pause");
	return 0;
}
