#include "Sistema.h"

using namespace std;

Sistema::Sistema() {
	this->_cantSocios = 0;
	this->_cantSpinning = 0;
	this->_cantEntrenamiento = 0;
}

DtSocio Sistema::GetDtSocioByCi(string ci) {
	DtSocio socio;
	for (int i = 0; i < this->_cantSocios; i++) {
		if (_socios[i]->GetCi() == ci) {
			socio = DtSocio(_socios[i]->GetCi(), _socios[i]->GetNombre());
			break;
		}
	}
	return socio;
}
Spinning* Sistema::GetSpinningById(int id) {
	try {
		for (int i = 0; i < this->_cantSpinning; i++) {
			if (_spinning[i]->GetId() == id) {
				return _spinning[i];
			}
		}
	}
	catch (exception& ex) {
		cerr << ex.what();
	}
}
Entrenamiento* Sistema::GetEntrenamientoById(int id) {
	try
	{
		for (int i = 0; i < this->_cantEntrenamiento; i++) {
			if (_entrenamiento[i]->GetId() == id) {
				return _entrenamiento[i];
			}
		}
	}
	catch (exception& ex) {
		cerr << ex.what();
	}
}

void Sistema::insertarSocio(DtSocio socio) {
	try 
	{
		if (this->_cantSocios == MAX_SOCIOS)
			throw invalid_argument("Se alcanzó la canidad maxima de socios del sistema");
		Socio* nuevoSocio = new Socio(socio.GetCi(), socio.GetNombre());
		this->_socios[this->_cantSocios] = nuevoSocio;
		this->_cantSocios += 1;
	}
	catch (exception& ex) 
	{
		cerr << "Error: " << ex.what() << endl;
	}
}
void Sistema::insertarSpinning(DtSpinning spinning) 
{
	try
	{
		if (this->_cantSpinning == MAX_CLASES) // No debería saltar, no hay límite
			throw invalid_argument("Se alcanzó la canidad maxima de clases de spinning del sistema");
		Spinning* nuevaClase = new Spinning(
			spinning.GetCantBicicletas(),
			spinning.GetId(),
			spinning.GetNombre(),
			spinning.GetTurno(),
			spinning.GetCantInscripciones());
		this->_spinning[this->_cantSpinning] = nuevaClase;
		this->_cantSpinning += 1;
	}
	catch (exception& ex)
	{
		cerr << "Error: " << ex.what() << endl;
	}
}
void Sistema::insertarEntrenamiento(DtEntrenamiento entrenamiento) {
	try
	{
		if (this->_cantEntrenamiento == MAX_CLASES)
			throw invalid_argument("Se alcanzó la canidad maxima de clases de entrenamiento del sistema");
		Entrenamiento* nuevaClase = new Entrenamiento(
			entrenamiento.GetEnRambla(),
			entrenamiento.GetId(),
			entrenamiento.GetNombre(),
			entrenamiento.GetTurno(),
			entrenamiento.GetCantInscripciones());
		this->_entrenamiento[this->_cantEntrenamiento] = nuevaClase;
		this->_cantEntrenamiento += 1;
	}
	catch (exception& ex)
	{
		cerr << "Error: " << ex.what() << endl;
	}
}
void Sistema::insertarInscripcionSpinning(DtInscripcion inscripcion, Spinning * clase) {
	try 
	{
		clase->InsertarInscripcion(inscripcion);
	}
	catch (exception& ex) 
	{
		cerr << "Error: " << ex.what() << endl;
	}
}
void Sistema::insertarInscripcionEntrenamiento(DtInscripcion inscripcion, Entrenamiento* clase) {
	try
	{
		clase->InsertarInscripcion(inscripcion);
	}
	catch (exception& ex)
	{
		cerr << "Error: " << ex.what() << endl;
	}
}

bool  Sistema::existeSocio(string ciSocio)
{
	bool retorno = false;
	if (this->_cantSocios > 0) {
		for (int i = 0; i < this->_cantSocios; i++) {
			if (_socios[i]->GetCi() == ciSocio) {
				retorno = true;
				break;
			}
		}
	}
	return retorno;
}
bool Sistema::existeClase(int idClase, bool& spinning)
{
	bool retorno = false;
	if (this->_cantSpinning > 0) {
		for (int i = 0; i < this->_cantSpinning; i++) {
			if (_spinning[i]->GetId() == idClase) {
				retorno = true;
				spinning = true;
				break;
			}
		}
	}
	if (!retorno && this->_cantEntrenamiento > 0) {
		for (int i = 0; i < this->_cantEntrenamiento; i++) {
			if (_entrenamiento[i]->GetId() == idClase) {
				retorno = true;
				spinning = false;
				break;
			}
		}
	}
	return retorno;
}

Sistema::~Sistema() {
	if (this->_cantSocios > 0)
		delete[] _socios;
	if (this->_cantSpinning > 0)
		delete[] _spinning;
	if (this->_cantEntrenamiento > 0)
		delete[] _entrenamiento;
}