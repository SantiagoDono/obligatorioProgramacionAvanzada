#include "Spinning.h"
#include "Constantes.h"

Spinning::Spinning() : Clase() {
	this->_cantBicicletas = CANT_MAX_BICICLETAS;
}
Spinning::Spinning(
	int cantBicicletas,
	int id,
	string nombre,
	enumTurno turno,
	list<Inscripcion*> inscripciones) 
	: Clase(id, nombre, turno, inscripciones)
{
	this->_cantBicicletas = cantBicicletas;
}
//Getters
int Spinning::GetCantBicicletas() {
	return _cantBicicletas;
}
//Setters
void Spinning::SetCantBicicletas(int cantBicicletas) {
	this->_cantBicicletas = cantBicicletas;
}
//Operaciones
int Spinning::Cupo() {
	return _cantBicicletas - (int)this->GetInscripciones().size();
}
//Destructor
Spinning::~Spinning(){
	/*	this->~Clase(); 
		Preguntar: cuando se destruyen las clases hijas, 
		hay que destruir al padre?
	*/
}
