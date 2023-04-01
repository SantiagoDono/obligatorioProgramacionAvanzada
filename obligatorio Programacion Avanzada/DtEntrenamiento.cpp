#include "DtEntrenamiento.h"

DtEntrenamiento::DtEntrenamiento(
	bool enRambla,
	int id,
	string nombre,
	enumTurno turno) : DtClase(id, nombre, turno) {
	this->_enRambla = enRambla;
}

bool DtEntrenamiento::GetEnRambla() {
	return _enRambla;
}

DtEntrenamiento::~DtEntrenamiento() {}