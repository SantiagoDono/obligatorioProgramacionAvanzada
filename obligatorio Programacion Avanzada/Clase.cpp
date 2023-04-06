#include "Clase.h"
#include "Constantes.h"

Clase::Clase(){
	this->_id = ID_NULO;
	this->_nombre = SIN_NOMBRE;
	this->_turno = Manana;
	this->_cantInscripciones = 0;
}
Clase::Clase(int id, string nombre, enumTurno turno, Inscripcion* inscripciones[MAX_INSCRIPCIONES], int cantInscripciones)
{
	this->_id = id;
	this->_nombre = nombre;
	this->_turno = turno;
	this->_cantInscripciones = cantInscripciones;
	for (int i = 0; i < min(MAX_INSCRIPCIONES, cantInscripciones); i++) {
		this->_inscripciones[i] = inscripciones[i];
	}
}

int Clase::GetId()
{
	return _id;
}
string Clase::GetNombre()
{
	return _nombre;
}
enumTurno Clase::GetTurno()
{
	return _turno;
}
int Clase::GetCantInscripciones() {
	return _cantInscripciones;
}
Inscripcion ** Clase::GetInscripciones() {
	return _inscripciones;
}
void Clase::SetId(int id)
{
	this->_id = id;
}
void Clase::SetNombre(string nombre)
{
	this->_nombre = nombre;
}
void Clase::SetTurno(enumTurno turno)
{
	this->_turno = turno;
}
void Clase::SetInscripciones(Inscripcion* inscripciones[MAX_INSCRIPCIONES], int cantInscripciones) {
	for (int i = 0; i < min(MAX_INSCRIPCIONES, cantInscripciones); i++) {
		this->_inscripciones[i] = inscripciones[i];
	}
}
void Clase::SetCantInscripciones(int cantInscripciones) {
	this->_cantInscripciones = cantInscripciones;
}

//destructor
Clase::~Clase(){
	delete[] _inscripciones;
}


