#include "DtClase.h"

using namespace std;

DtClase::DtClase(int  id, string nombre, enumTurno turno)
{
    this->_id = id;
    this->_nombre = nombre;
    this->_turno = turno;
}

int DtClase::GetId() {
    return _id;
}
string DtClase::GetNombre() {
    return _nombre;
}
enumTurno DtClase::GetTurno() {
    return _turno;
}

DtClase::~DtClase() {}