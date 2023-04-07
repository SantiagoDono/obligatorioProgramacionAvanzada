#pragma once

#ifndef ENTRENAMIENTO_H
#define ENTRENAMIENTO_H

#include "Clase.h"
#include "Constantes.h"
#include "DtInscrpcion.h"

class Entrenamiento :public Clase
{
	private:
		bool _enRambla;

	public:
		//Constructores
		Entrenamiento();
		Entrenamiento(
			bool enRambla, 
			int id, 
			string nombre, 
			enumTurno turno, 
			int cantInscrp);

		//Getters
		bool GetEnRambla();

		//Setters
		void SetEnRambla(bool enRambla);

		//Operaciones
		int Cupo();
		void InsertarInscripcion(DtInscripcion inscripcion);

		//Destructor
		~Entrenamiento();
};

#endif