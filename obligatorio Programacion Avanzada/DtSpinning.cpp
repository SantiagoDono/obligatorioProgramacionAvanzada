#include "DtSpinning.h"

DtSpinning::DtSpinning(
	int cantBicicletas,
	int id,
	string nombre,
	enumTurno turno) : DtClase(id, nombre, turno)
{
	this->_cantBicicletas = cantBicicletas;
}

int DtSpinning::GetCantBicicletas() {
	return _cantBicicletas;
}

DtSpinning::~DtSpinning(){}