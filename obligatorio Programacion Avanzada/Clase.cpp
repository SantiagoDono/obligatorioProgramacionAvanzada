#include "Clase.h"
#include "Constantes.h"

Clase::Clase(){
	this->_id = ID_NULO;
	this->_nombre = SIN_NOMBRE;
	this->_turno = Manana;
	this->_inscripciones = list<Inscripcion *>();
}
Clase::Clase(int id, string nombre, enumTurno turno, list<Inscripcion *> inscripciones)//va solo el asterisco de adentro
{
	this->_id = id;
	this->_nombre = nombre;
	this->_turno = turno;
	list<Inscripcion*> nuevaLista = list<Inscripcion*>();
	for (Inscripcion * ins : inscripciones)
	{
		nuevaLista.push_back(ins);
	}
	this->_inscripciones = nuevaLista;
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
list<Inscripcion *> Clase::GetInscripciones() {
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
void Clase::SetInscripciones(list<Inscripcion *> inscripciones) {
	this->_inscripciones = inscripciones;
}
int Clase::Cupo()
{
 //Ver como implementarlo 
	return 0;
}
//destructor
Clase::~Clase(){
	for (Inscripcion* ins : this->_inscripciones) {
		delete ins;
	}
}


