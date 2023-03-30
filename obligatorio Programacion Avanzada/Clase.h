#pragma once
#include<iostream>
#include<stdio.h>
#include"EnumTurno.h"
//AGREGAR TURNO QUE ES EL ENUM
using namespace std;

class Clase
{
	//atributos

	int id;
	string nombre;
	enumTurno turno;
public:
	Clase();
	Clase(int ident, string n, enumTurno turn);

	//getters
	int getId();
	string getNombre();
	enumTurno getTurno();
	//setters
	void setId(int aidi);
	void setNombre(string nom);
	void SetTurno(enumTurno turn);
	//operacion
	virtual int cupo()=0;//esto se hace para indicar que no va a haber instancias de esta clase 
	//destructor
	~Clase();

};

