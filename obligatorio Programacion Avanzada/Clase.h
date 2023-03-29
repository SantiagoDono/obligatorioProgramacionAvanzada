#pragma once
#include<iostream>
#include<stdio.h>
#include"turno.h"
//AGREGAR TURNO QUE ES EL ENUM
using namespace std;

class Clase
{
	//atributos

	int id;
	string nombre;
	eTurno turno;
public:
	Clase();
	Clase(int ident, string n,eTurno turn);

	//getters
	int getId();
	string getNombre();
	eTurno getTurno();
	//setters
	void setId(int aidi);
	void setNombre(string nom);
	void SetTurno(eTurno turn);
	//operacion
	virtual int cupo();
	//destructor
	~Clase();

};

