#include "Sistema.h"

using namespace std;

Sistema::Sistema()
{
	this->_cantSocios = 0;
	this->_cantClases = 0;
}

DtSocio Sistema::GetDtSocioByCi(string ci)
{
	DtSocio socio;
	for (int i = 0; i < this->_cantSocios; i++)
	{
		if (_socios[i]->GetCi() == ci)
		{
			socio = DtSocio(_socios[i]->GetCi(), _socios[i]->GetNombre());
			break;
		}
	}
	return socio;
}
Clase *Sistema::GetClaseById(int id)
{
	try
	{
		for (int i = 0; i < this->_cantClases; i++)
		{
			if (_clases[i]->GetId() == id)
			{
				return _clases[i];
			}
		}
	}
	catch (exception &ex)
	{
		cerr << ex.what();
	}
}

void Sistema::insertarSocio(DtSocio socio)
{
	try
	{
		if (this->_cantSocios == MAX_SOCIOS)
			throw invalid_argument("Se alcanz� la canidad maxima de socios del sistema");
		Socio *nuevoSocio = new Socio(socio.GetCi(), socio.GetNombre());
		this->_socios[this->_cantSocios] = nuevoSocio;
		this->_cantSocios += 1;
	}
	catch (exception &ex)
	{
		cerr << "Error: " << ex.what() << endl;
	}
}
void Sistema::insertarClase(DtClase &clase)
{

	bool spinning = dynamic_cast<DtSpinning *>(&clase) != nullptr;
	try
	{
		if (this->_cantClases == MAX_CLASES) // No deber�a saltar, no hay l�mite
			throw invalid_argument("Se alcanz� la canidad maxima de clases de spinning del sistema");
		if (spinning)
		{

			DtSpinning *spin = dynamic_cast<DtSpinning *>(&clase);
			Spinning *nuevaClase = new Spinning(
				spin->GetCantBicicletas(),
				spin->GetId(),
				spin->GetNombre(),
				spin->GetTurno(),
				spin->GetCantInscripciones());
				

			this->_clases[this->_cantClases] = nuevaClase;
			DtSpinning imp = DtSpinning(
				spin->GetCantBicicletas(),
				spin->GetId(),
				spin->GetNombre(),
				spin->GetCantInscripciones(),
				spin->GetTurno());
			cout << "Se inserto: " << endl
				 << imp << endl;
			
		}
		else
		{
			DtEntrenamiento *ent = dynamic_cast<DtEntrenamiento *>(&clase);
			Entrenamiento *nuevaClase = new Entrenamiento(
				ent->GetEnRambla(),
				ent->GetId(),
				ent->GetNombre(),
				ent->GetTurno(),
				ent->GetCantInscripciones());

			this->_clases[this->_cantClases] = nuevaClase;
			DtEntrenamiento imp = DtEntrenamiento(
				ent->GetEnRambla(),
				ent->GetId(),
				ent->GetNombre(),
				ent->GetCantInscripciones(),
				ent->GetTurno());
			cout << "Se inserto: " << endl
				 << imp << endl;
		}
		this->_cantClases += 1;
	}
	catch (exception &ex)
	{
		cerr << "Error: " << ex.what() << endl;
	}
}

void Sistema::insertarInscripcionClase(DtInscripcion inscripcion, Clase *clase)
{
	try
	{
		clase->InsertarInscripcion(inscripcion);
	}
	catch (exception &ex)
	{
		cerr << "Error: " << ex.what() << endl;
	}
}

bool Sistema::existeSocio(string ciSocio)
{
	bool retorno = false;
	if (this->_cantSocios > 0)
	{
		for (int i = 0; i < this->_cantSocios; i++)
		{
			if (_socios[i]->GetCi() == ciSocio)
			{
				retorno = true;
				break;
			}
		}
	}
	return retorno;
}
bool Sistema::existeClase(int idClase)
{
	bool retorno = false;
	if (this->_cantClases > 0)
	{
		for (int i = 0; i < this->_cantClases; i++)
		{
			if (_clases[i]->GetId() == idClase)
			{
				retorno = true;

				break;
			}
		}
	}

	return retorno;
}

Sistema::~Sistema()
{
	if (this->_cantSocios > 0)
		delete _socios;
	if (this->_cantClases > 0)
		delete _clases;
}