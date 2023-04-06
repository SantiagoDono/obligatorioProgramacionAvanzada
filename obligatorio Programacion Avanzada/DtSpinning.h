#pragma once

#ifndef DTSPINNING_H
#define DTSPINNING_H


#include "EnumTurno.h"
#include "DtClase.h"
#include <string>

using namespace std;

class DtSpinning : public DtClase
{
	private:
		int _cantBicicletas;
	public:
		DtSpinning(
			int cantBicicletas,
			int id,
			string nombre,
			int cantInscripciones,
			enumTurno turno
		);

		int GetCantBicicletas();

		~DtSpinning();

};


#endif // !DTSPINNING_H