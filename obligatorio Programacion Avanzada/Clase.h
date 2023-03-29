#pragma once
#include<iostream>
#include<stdio.h>
#include"turno.h"
//AGREGAR TURNO QUE ES EL ENUM
using namespace std;

class Clase
{
	//atributos
private:
	int id;
	string nombre;
	Turno turno;
public:
	Clase();
	Clase(int ident, string n,enum turn);

	//getters
	int getId();
	string getNombre();
	Turno getTurno();
	//setters
	void setId(int aidi);
	void setNombre(string nom);
	void SetTurno(Turno turn);

};

