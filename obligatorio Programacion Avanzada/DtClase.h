#include <iostream>
#include<stdio.h>
#include"EnumTurno.h"
using namespace std;
class DtClase {
	//atributos
private:
	int id;
	string nombre;
	enumTurno turno;
public:
	DtClase();
	DtClase(int aidi, string nom, enumTurno turn);

	//getters, en este caso al ser un datatype no van setters 
	int getId();
	string getNombre();
	enumTurno getTurno();

	//destructor
	~DtClase();

};