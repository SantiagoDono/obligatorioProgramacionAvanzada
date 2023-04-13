#include "DtSpinning.h"

DtSpinning::DtSpinning(
	int cantBicicletas,
	int id,
	string nombre,
	int cantInscripciones,
	enumTurno turno) : DtClase(id, nombre, turno, cantInscripciones)
{
	this->_cantBicicletas = cantBicicletas;
}

int DtSpinning::GetCantBicicletas()
{
	return _cantBicicletas;
}

DtSpinning::~DtSpinning() {}