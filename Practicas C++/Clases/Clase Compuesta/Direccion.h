#include<string>
#include<cstring>
#include<iostream>
using namespace std;
typedef char str30[30];

struct tDireccion{
	str30 calle;
	int altura;
};


class Direccion{
	private:
		tDireccion dir;
		
	public:
		Direccion(str30 _calle, int _altura){
			dir.altura=_altura;
			strcpy(dir.calle,_calle);
		}
		Direccion(){
			
		}
		
		void setDire(str30 cal,int alt){
			dir.altura=alt;
			strcpy(dir.calle,cal);
		}
		
		tDireccion getDire(){
			return dir;
		}
		
		void mostrarDir(){
			cout<<"Direccion: "<<dir.calle<<" "<<dir.altura<<endl;
		}
};
