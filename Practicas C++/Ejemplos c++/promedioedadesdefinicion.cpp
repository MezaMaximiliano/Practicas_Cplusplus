#include<iostream>
using namespace std;

int main() {
	//int contaredades;
	int ncantedades;
	int nedad;
	int promedio;  // real
	int sumaredades;
	// PROMEDIA EDADES HASTA UNA CANTIDAD FIJA QUE SE PIDE AL INICIO
	// SE TRATA DE UN PROCESO DE REPETICION EXACTA
	std::cout << "calculo del promedio de edad de 30 personas" << std::endl;
	cout << "Cuantas edades quiere promediar" << endl;
	cin >> ncantedades;
	if (ncantedades>0) {
		sumaredades = 0;
		for (int contaredades=1;contaredades<=ncantedades;
		                    contaredades++) {
			cout << "Ingresar la edad numero " << contaredades << endl;
			cin >> nedad;
			sumaredades = sumaredades+nedad; 	//sumaredades += nedad;
		}  // for
		promedio = sumaredades/ncantedades;
		cout << "El promedio es " << promedio << endl;
	} else {
		   cout << "No hay edades a promediar" << endl;
	}  // if
	return 0;
}


