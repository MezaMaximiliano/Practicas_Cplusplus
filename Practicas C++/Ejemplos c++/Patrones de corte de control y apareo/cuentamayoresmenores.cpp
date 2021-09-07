#include<iostream>
using namespace std;
typedef int vector[100];//defino el vector en el que voy a guardar las edads
void inicializar(vector p,int cant);
int elmayor(vector p,int cant,float prom);
int elmenor(vector p,int cant,float prom);
int main(){
	vector p;
	int cant=0;   // debe comenzar en 0   no en 100
	int sum=0 ;
	int edad;
	float prom;
	inicializar(p,100);   // indicar que se deben inicialziar 100 elementos
	
	
	do{cout<<"ingrese edad: "<<endl;//1[0],7[1],9[2],10[3]
	  cin>>edad;
      p[cant]=edad;
	  cant=cant+1;//  0+1=1, 1+1=2 ,2+1=3 3+1=4  cant=4
	} while((edad!=0)&&(cant<100));
	
	
	for(int i=0;i<cant;i++){
		sum=sum+p[i];   
		
    } 
    
    // el cálculo de promedio se hace al final de las sumas;
    // se divide por la cantidad de valores
    // se multiplica por 1.0 para transformarlo en float
    
	prom=1.0 * sum/(cant - 1);      //0+1=1 , 1+7=8 , 8+9=17 , 17+10=27     sum=27   //  27/4=6
            
	cout<<"el promedio es: "<<prom<<endl;
	cout<<"los que syperan al promedio son: "<<elmayor(p,cant,prom)<<endl;
	cout<<"los que no superan el promedio son: "<<elmenor(p,cant,prom)<<endl;
	
	
	return 0;
}
void inicializar(vector p,int cant){//inicializar para ponerle un cero a todas las celdas y por ende la cantidad es 0 ,es para ajustar el vector a la cantidad de edades que me ingresan
	for(int i=0;i<cant;i++){
		p[i]=0;cant=0;
	}
}

int elmayor(vector p,int cant,float prom){
	int cantmayores=0;
	for(int i=0;i<cant;i++){
		if(p[i]>prom){
			cantmayores=cantmayores+1;
		}
	}
	return cantmayores;
}
int elmenor(vector p,int cant,float prom){
	int cantmenores=0;
	for(int f=0;f<cant;f++){
		if(p[f]<=prom){
			cantmenores=cantmenores+1;
		}
	}
	
	return cantmenores;
}

