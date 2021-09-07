#include "Estatico.h"
#include<iostream>
using namespace std;

int Estatico::contador=0;//inicializa contador

/*El miembro (metodo o atributo) estatico de la clase no puede ser inicializado dentro de la mismo (en el archivo de cabecera),
por lo que se debe crear otro archivo para poder hacerlo.*/
