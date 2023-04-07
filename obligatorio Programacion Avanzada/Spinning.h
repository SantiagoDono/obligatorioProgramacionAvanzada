#pragma once

#ifndef SPINNING_H
#define SPINNING_H



#include "Clase.h"
#include "DtInscrpcion.h"

class Spinning : public Clase
{
	private:
		int _cantBicicletas;

	public:
		//Constructores
		Spinning();
		Spinning(
			int cantBicicletas,
			int id,
			string nombre,
			enumTurno turno,
			int cantInscrp);

		//Getters
		int GetCantBicicletas();

		//Setters
		void SetCantBicicletas(int cantBicicletas);
		
		//Operaciones
		int Cupo();
		void InsertarInscripcion(DtInscripcion inscripcion);
		//Destructor
		~Spinning();
};

#endif // !SPINNING_H