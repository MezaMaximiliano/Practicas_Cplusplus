#include<stdlib.h>
#include<stdio.h>
#include<ostream>
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

typedef char str30[31];
typedef char str6[7];

struct rEstudiante{
	int legajo;
	str30 apellido;
	str30 mail;
	long int cel;
};
struct rMateria{
	str30 nomMateria;
};

struct pEst{
	rEstudiante alumno;
	pEst *nodoSig;
};

struct pListaMat{
	str30 nomMat;
	pListaMat *nodoSig;
	pEst nodoSL;
	
};

int main (){
	
}
