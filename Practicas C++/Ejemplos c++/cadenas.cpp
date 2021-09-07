#include<iostream>
using namespace std;

// Para leer variables de texto se utiliza el operador << del objeto cin, que
// lee solo una palabra. Para leer una linea completa (es decir, incluyendo los
// espacios en blanco) se debe utilzar getline (ej, reemplazar cin>>x por
// getline(cin,x)), pero obliga a agregar un cin.ignore() si antes del getline
// se leyó otra variable con >>.

int main() {
	string frase;
	char palabra[30] ;
	cout << "ingresar palabra"<<endl;
	cin >> palabra	;
	cout << endl;
	
	cout << "ingresar frase"<<endl;
	cin.ignore() ;
	getline(cin,  frase)	;
	cout << endl;
	
	cout << "La palabra es >" << palabra << "<" << endl;
	cout << "La frase es   >" << frase <<  "<" << endl ;
	return 0;
}

