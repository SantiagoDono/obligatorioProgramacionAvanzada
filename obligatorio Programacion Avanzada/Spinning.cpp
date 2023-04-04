#pragma once

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
void Spinning::InsertarInscripcion(DtInscripcion inscripcion) {
	try
	{
		if (Cupo() == 0)
			throw invalid_argument("No hay cupo disponible.");

		list<Inscripcion*> listaNueva = this->GetInscripciones();
		listaNueva.push_back(new Inscripcion(inscripcion.GetFecha(), inscripcion.GetSocio()));

		for (Inscripcion* ins : this->GetInscripciones()) {
			delete ins;
		}

		this->SetInscripciones(listaNueva);
	}
	catch (exception& ex) 
	{
		cerr << "Error code: " << ex.what();
	}
}

Spinning::~Spinning(){}
