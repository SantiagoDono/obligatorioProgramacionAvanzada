#pragma once

#ifndef DTENTRENAMIENTO_H
#define DTENTRENAMIENTO_H

#include "DtClase.h"

class DtEntrenamiento : DtClase 
{
	private:
		bool _enRambla;
	public:
		DtEntrenamiento(
			bool enRambla,
			int id,
			string nombre,
			enumTurno turno);

		bool GetEnRambla();

		~DtEntrenamiento();
};

#endif // !DTENTRENAMIENTO_H