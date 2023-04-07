#include "Entrenamiento.h"
#include "Constantes.h"

//Constructores
Entrenamiento::Entrenamiento() : Clase() {
	this->_enRambla = EN_RAMBLA_DEFAULT;
}
Entrenamiento::Entrenamiento(
	bool enRambla, 
	int id, 
	string nombre, 
	enumTurno turno,
	int cantInscrp)
	: Clase(id, nombre, turno, cantInscrp)
{
	this->_enRambla = enRambla;
}
//Getters
bool Entrenamiento::GetEnRambla() {
	return _enRambla;
}
//Setters
void Entrenamiento::SetEnRambla(bool enRambla) {
	this->_enRambla = enRambla;
}
//Operaciones
int Entrenamiento::Cupo() {
	if (this->_enRambla)
		return CUPO_RAMBLA_TRUE - this->GetCantInscripciones();
	else
		return CUPO_RAMBLA_FALSE - this->GetCantInscripciones();
}

void Entrenamiento::InsertarInscripcion(DtInscripcion inscripcion) {
	try
	{
		if (Cupo() == 0)
			throw invalid_argument("No hay cupo disponible.");

		Inscripcion ** inscripciones = this->GetInscripciones();
		inscripciones[this->GetCantInscripciones()] = new Inscripcion(inscripcion.GetFecha(), inscripcion.GetSocio());
		
		this->SetInscripciones(inscripciones, GetCantInscripciones() + 1);
		this->SetCantInscripciones(GetCantInscripciones() + 1);
	}
	catch (exception& ex) 
	{
		cerr << "Error code: " << ex.what();
	}
}

//Destructor
Entrenamiento::~Entrenamiento(){
	/*	this->~Clase();
		Preguntar: cuando se destruyen las clases hijas,
		hay que destruir al padre?
	*/
}

