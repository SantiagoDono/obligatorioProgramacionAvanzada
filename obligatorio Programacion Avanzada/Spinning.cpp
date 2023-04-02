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
		//Hay que manejar dtinscrpcion en este caso?
		if (Cupo() == 0)
			throw invalid_argument("No hay cupo disponible.");
		/*
		throw invalid_argument refiere al tipo? 
		en mensaje ponemos algo que queramos o va "invalid_argument"?
		*/

		list<Inscripcion*> listaNueva = this->GetInscripciones();
		listaNueva.push_back(new Inscripcion(inscripcion.GetFecha(), inscripcion.GetSocio()));

		for (Inscripcion* ins : this->GetInscripciones()) {
			delete ins;
		}

		this->SetInscripciones(listaNueva);

		/*
		Hay que borrar memoria de la lista vieja? 
		con la l�nea 42,se copia como un array de punteros?
		No pide explicitamente memoria para los punteros a inscripcio�n
		*/
	}
	catch (exception& ex) 
	{
		cerr << "Error code: " << ex.what();
	}
}

//Destructor
Spinning::~Spinning(){
	/*	this->~Clase(); 
		Preguntar: cuando se destruyen las clases hijas, 
		hay que destruir al padre?
	*/
}
