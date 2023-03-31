#include "DtClase.h"

using namespace std;

DtClase::DtClase(int  id, string nombre, enumTurno turno, list<Inscripcion *> inscripciones)
{
    this->_id = id;
    this->_nombre = nombre;
    this->_turno = turno;
    this->_inscripciones = inscripciones;
}

DtClase::~DtClase(){}
