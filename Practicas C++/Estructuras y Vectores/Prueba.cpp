#include <iostream>
using namespace std;
typedef char str30[30] ;
struct  str100[100] {
	char str100[100];
}
//prototipo
void pedirDatos (str30 & nbe , str100 & mail);
int main (){

str30 nombre ;
str100 email;
pedirDatos (nombre , email);
cout <<endl <<nombre<<" "<< email<<endl;
return 0;
}
void pedirDatos (str30 & nbe , str100 & mail){

cout<<"ingresar nombre y mail"<<endl;
cin >>nbe >>mail;
}
