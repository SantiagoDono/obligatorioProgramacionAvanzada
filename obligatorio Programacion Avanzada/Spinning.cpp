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
	int cantInscrp)
	: Clase(id, nombre, turno, cantInscrp)
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
	return _cantBicicletas - this->GetCantInscripciones();
}
void Spinning::InsertarInscripcion(DtInscripcion inscripcion) {
	try
	{
		if (Cupo() == 0)
			throw invalid_argument("No hay cupo disponible.");
		if (SocioInscripto(inscripcion.GetSocio()))
			throw invalid_argument("El socio, " + inscripcion.GetSocio().GetNombre() + " (" + inscripcion.GetSocio().GetCi() + "), ya esta inscripto a la clase.");
		Inscripcion** inscripciones = this->GetInscripciones();
		inscripciones[this->GetCantInscripciones()] = new Inscripcion(inscripcion.GetFecha(), inscripcion.GetSocio());

		this->SetInscripciones(inscripciones, GetCantInscripciones() + 1);
		this->SetCantInscripciones(GetCantInscripciones() + 1);
	}
	catch (exception& ex) 
	{
		cerr << "Error code: " << ex.what();
	}
}
bool Spinning::SocioInscripto(DtSocio socio) {
	bool retorno = false;
	if (this->GetCantInscripciones() > 0) {
		Inscripcion** inscripciones = this->GetInscripciones();
		for (int i = 0; i < this->GetCantInscripciones(); i++) {
			if (inscripciones[i]->GetSocio().GetCi() == socio.GetCi()) {
				retorno = true;
				break;
			}
		}
	}
	return retorno;
}

Spinning::~Spinning(){}
