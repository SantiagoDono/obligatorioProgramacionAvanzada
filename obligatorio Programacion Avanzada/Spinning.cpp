#include "Spinning.h"
#include "Constantes.h"

Spinning::Spinning() : Clase() {
	this->cantBicicletas = CANT_MAX_BICICLETAS;
}
Spinning::Spinning(
	int cantBicicletas,
	int id,
	string nombre,
	enumTurno turno,
	list<Inscripcion*>* inscripciones) 
	: Clase(id, nombre, turno, inscripciones)
{
	this->cantBicicletas = cantBicicletas;
}
//Getters
int Spinning::GetCantBicicletas() {
	return cantBicicletas;
}
//Setters
void Spinning::SetCantBicicletas(int cantBicicletas) {
	this->cantBicicletas = cantBicicletas;
}
//Operaciones
int Spinning::Cupo() {
	return cantBicicletas - (int)this->GetInscripciones()->size();
}
//Destructor
Spinning::~Spinning(){}
