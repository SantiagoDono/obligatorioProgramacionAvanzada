#pragma once

#ifndef CLASE_H
#define CLASE_H

#include<iostream>
#include<stdio.h>
#include "Constantes.h"
#include "EnumTurno.h"
#include "Inscripcion.h"
#include "DtInscrpcion.h"

using namespace std;

class Clase
{
private:
	//atributos
	int _id;
	string _nombre;
	enumTurno _turno;
	int _cantInscripciones;

	//pseudoatrr
	Inscripcion*  _inscripciones[MAX_INSCRIPCIONES];
	

public:
	Clase();
	Clase(int id, string nombre, enumTurno turno, Inscripcion* inscripciones[MAX_INSCRIPCIONES], int cantInscripciones);

	//getters
	int GetId();
	string GetNombre();
	enumTurno GetTurno();
	Inscripcion ** GetInscripciones();
	int GetCantInscripciones();

	//setters
	void SetId(int id);
	void SetNombre(string nombre);
	void SetTurno(enumTurno turno);
	void SetInscripciones(Inscripcion* inscripciones[MAX_INSCRIPCIONES],int cantInscripciones);
	void SetCantInscripciones(int cantInscripciones);

	virtual int Cupo() = 0;//esto se hace para indicar que no va a haber instancias de esta clase 
	virtual void InsertarInscripcion(DtInscripcion inscripcion) = 0;

	//destructor
	~Clase();
};



#endif // !"CLASE_H"


