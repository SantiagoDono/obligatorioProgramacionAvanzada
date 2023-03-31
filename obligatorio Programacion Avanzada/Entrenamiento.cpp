#include "Entrenamiento.h"
#include "Constantes.h"

//Constructores
Entrenamiento::Entrenamiento() : Clase() {
	this->enRambla = EN_RAMBLA_DEFAULT;
}
Entrenamiento::Entrenamiento(
	bool enRambla, 
	int id, 
	string nombre, 
	enumTurno turno, 
	list<Inscripcion*>* inscripciones) 
	: Clase(id, nombre, turno, inscripciones)
{
	this->enRambla = enRambla;
}
//Getters
bool Entrenamiento::GetEnRambla() {
	return enRambla;
}
//Setters
void Entrenamiento::SetEnRambla(bool enRambla) {
	this->enRambla = enRambla;
}
//Operaciones
int Entrenamiento::Cupo() {
	if (this->enRambla)
		return CUPO_RAMBLA_TRUE - (int)this->GetInscripciones()->size();
	else
		return CUPO_RAMBLA_FALSE - (int)this->GetInscripciones()->size();
}
//Destructor
Entrenamiento::~Entrenamiento(){}

