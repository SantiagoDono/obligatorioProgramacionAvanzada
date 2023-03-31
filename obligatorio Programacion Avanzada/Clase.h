#pragma once
#include<iostream>
#include<stdio.h>
#include<list>
#include"EnumTurno.h"
#include"Inscripcion.h"

using namespace std;

class Clase
{
	private:
		//atributos
		int _id;
		string _nombre;
		enumTurno _turno;

		//pseudoatrr
		list<Inscripcion *> * _inscripciones;

	public:
		Clase();
		Clase(int id, string nombre, enumTurno turno, list<Inscripcion*> * inscripciones);

		//getters
		int GetId();
		string GetNombre();
		enumTurno GetTurno();
		list<Inscripcion *> * GetInscripciones();

		//setters
		void SetId(int id);
		void SetNombre(string nombre);
		void SetTurno(enumTurno turno);
		void SetInscripciones(list<Inscripcion *> * inscripciones);

		//operacion
		virtual int Cupo()=0;//esto se hace para indicar que no va a haber instancias de esta clase 
		
		//destructor
		~Clase();
};

