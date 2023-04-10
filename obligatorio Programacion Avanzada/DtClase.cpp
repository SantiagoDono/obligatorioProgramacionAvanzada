#include "DtClase.h"

using namespace std;

DtClase::DtClase() {
    
}

DtClase::DtClase(int  id, string nombre, enumTurno turno, int cantInscripciones)
{
    this->_id = id;
    this->_nombre = nombre;
    this->_turno = turno;
    this->_cantInscripciones = cantInscripciones;
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
int DtClase::GetCantInscripciones() {
    return _cantInscripciones;
}

DtClase::~DtClase() {}