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
	list<Inscripcion*> inscripciones) 
	: Clase(id, nombre, turno, inscripciones)
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
		return CUPO_RAMBLA_TRUE - (int)this->GetInscripciones().size();
	else
		return CUPO_RAMBLA_FALSE - (int)this->GetInscripciones().size();
}
void Entrenamiento::InsertarInscripcion(DtInscripcion inscripcion) {
	try
	{
		//Hay que manejar dtinscrpcion en este caso?
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

//Destructor
Entrenamiento::~Entrenamiento(){
	/*	this->~Clase();
		Preguntar: cuando se destruyen las clases hijas,
		hay que destruir al padre?
	*/
}

