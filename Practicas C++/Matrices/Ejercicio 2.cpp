/*definir una estructura de tipo persona (como en la práctica anterior) y una matriz de 10 filas y 20 columnas que representen los 20 estudiantes de cada uno
de 10 cursos.*/

#include<iostream>
#include<stdlib.h>
#define _CANTEST 20
#define _CANTCUR 10
/*scanf("%s",v[c].nombre);*/
struct fecha{
	int dia,mes,anio;
	
};

struct persona {
	fecha fNac;
	char nombre[30];
	int edad;
};
typedef persona matriz[_CANTEST][_CANTCUR];

int main(){
	matriz mAlumno;
	printf("Ingrese el nombre: ");
	scanf("%s",&mAlumno[0][0].nombre);
	printf("Ingrese dia en que nacio: ");
	scanf("%d",&mAlumno[0][0].fNac.dia);
	/*std::cin>>mAlumno[0][0].fNac.dia;*/
	system("cls");
	printf("%s \nNacio el dia: %d",mAlumno[0][0].nombre,mAlumno[0][0].fNac.dia);
		
	return 0;
}
