#include<iostream>
using namespace std;


int fechaAAAAMMDD(int dia, int mes, int anio) {
	int fecha;
	fecha = dia+mes*100+anio*10000;
	return fecha;
}

void fechaSepadada(int AAAAMMDD, int & d, int & m, int & a ) {
	int aux;
	d = AAAAMMDD % 100;
	aux = AAAAMMDD / 100;
	m = aux % 100 ;
	a = aux / 100 ;
}


void pedirdatos(int &dia, int &mes, int &anio, string &nombre) {
	cout << "ingrese anio (0=fin)" << endl;
	cin >> anio;
	if (anio!=0) {
		cout << "ingrese mes" << endl;
		cin >> mes;
		cout << "ingrese dia" << endl;
		cin >> dia;
		cout << "ingrese nombre" << endl;
		cin >> nombre;
	}
}

int main() {
	int anio;
	int mes;	
	int dia;
	int fecha, fechamayor, fechamenor;

	string nombre, nombremayor, nombremenor;
	fechamayor = 0;
	fechamenor = 99999999;
	pedirdatos(dia,mes,anio,nombre);
	while (anio!=0) {
		fecha = fechaAAAAMMDD(dia,mes,anio);
		if (fecha>fechamayor) {
			fechamayor = fecha;
			nombremayor = nombre;
		}
		if (fecha<fechamenor) {
			fechamenor = fecha;
			nombremenor = nombre;
		}
		pedirdatos(dia,mes,anio,nombre);
	}
	if (fechamayor>0){
      fechaSepadada(fechamayor, dia, mes, anio ) ;
	  cout << "El menor es: " << nombremayor << " " << dia << "/" << mes << "/" << anio << endl;
      fechaSepadada(fechamenor, dia, mes, anio ) ;
	  cout << "El mayor es: " << nombremenor << " " << dia << "/" << mes << "/" << anio << endl;
	}
	else
	  cout << "no se ingresaron personas" << endl;
	return 0;
}


