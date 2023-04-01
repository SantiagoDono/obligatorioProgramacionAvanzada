#pragma once
#include "EnumTurno.h"
#include "DtClase.h"
#include <string>

using namespace std;

class DtSpinning : DtClase
{
	private:
		int _cantBicicletas;
	public:
		DtSpinning(
			int cantBicicletas,
			int id,
			string nombre,
			enumTurno turno
		);

		int GetCantBicicletas();

		~DtSpinning();

};

