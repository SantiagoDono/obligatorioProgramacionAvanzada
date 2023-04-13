#include "DtEntrenamiento.h"

DtEntrenamiento::DtEntrenamiento(
	bool enRambla,
	int id,
	string nombre,
	int cantInscripciones,
	enumTurno turno) : DtClase(id, nombre, turno, cantInscripciones)
{
	this->_enRambla = enRambla;
}

bool DtEntrenamiento::GetEnRambla()
{
	return _enRambla;
}

DtEntrenamiento::~DtEntrenamiento()
{
}