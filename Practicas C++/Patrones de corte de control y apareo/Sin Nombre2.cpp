#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define _CANT1 100
#define _CANT2 200

typedef int vect100[_CANT1];
typedef int vect200[_CANT2];

void genVect(vect100, int);
void iniVect(vect200, int);
void ordenarVect(vect100, int);
void mostrarVect(vect100, int);
void apareo(vect100, vect100, vect200);
void mostrarVect2(vect200, int);

int main(){
	srand(time(NULL));
	vect100 vector1;
	vect100 vector2;
	vect200 vector3;
	genVect(vector1, _CANT1);
	genVect(vector2, _CANT1);
	iniVect(vector3, _CANT2);
	ordenarVect(vector1, _CANT1);
	ordenarVect(vector2, _CANT1);
	cout<<"Primer vector:"<<endl;
	mostrarVect(vector1, _CANT1);
	cout<<"Segundo vector:"<<endl;
	mostrarVect(vector2, _CANT1);
	apareo(vector1, vector2, vector3);
	cout<<"Emparejamiento vector:"<<endl;
	mostrarVect2(vector3, _CANT2);
	return 0;
}

void genVect(vect100 v, int c){
	for(int i=0;i<c;i++){
		bool ok;
		int num;
		do{
			num=rand()%500+1;
			ok=true;
			for(int j=i+1;j<c;j++){
				if(num==v[j]){
					ok=false;
					break;
				}
			}
		} while (!ok);
		v[i]=num;
	}
}

void iniVect(vect200 v, int c){
	for(int i=0;i<c;i++){
		v[i]=0;
	}
}

void ordenarVect(vect100 v, int c){
		int pos, aux;

	
	for (int k=0; k<=c;k++){
	
		pos=k;
		aux=v[k];
	
		while ((pos>0) and (v[pos-1]>aux) ){
			v[pos]=v[pos-1];
			pos--;
		}
		v[pos]=aux;
	}

}

void mostrarVect(vect100 v, int c){
	for (int i=0;i<c;i++){
		cout<<"Celda "<<i<<": "<<v[i]<<endl;
	}
}

void mostrarVect2(vect200 v, int c){
	for (int i=0;i<c;i++){
		cout<<"Celda "<<i<<": "<<v[i]<<endl;
	}
}

void apareo(vect100 v1, vect100 v2, vect200 v3){

	for(int a=0,b=0,c=0;c<_CANT2;c++){
		if(a==_CANT1){
			v3[c]=v2[b];
			b++;
		}
		else if(b==_CANT1||(v1[a]<=v2[b])){
			v3[c]=v1[a];
			a++;
		}
		else{
			v3[c]=v2[b];
			b++;
		}
	}
}


/*	int aux;
	int max;
	for(int i=0;i<c;i++){
		max=i;
		for(int j=i+1;j<c;j++){
			if(v[j]>v[max]){
				max=j;
			}
		}
		aux=v[i];
		v[i]=v[max];
		v[max]=aux;
	}*/
