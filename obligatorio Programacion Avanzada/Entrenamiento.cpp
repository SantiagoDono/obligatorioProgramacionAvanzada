#include "Entrenamiento.h"
#include "Constantes.h"

// Constructores
Entrenamiento::Entrenamiento() : Clase()
{
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
// Getters
bool Entrenamiento::GetEnRambla()
{
	return _enRambla;
}
DtInscripcion Entrenamiento::GetInscripcionByCiSocio(string ci)
{
	for (int i = 0; i < this->GetCantInscripciones(); i++)
	{
		if (this->GetInscripciones()[i]->GetSocio().GetCi() == ci)
		{
			return DtInscripcion(this->GetInscripciones()[i]->GetFecha(), this->GetInscripciones()[i]->GetSocio());
		}
	}
}
// Setters
void Entrenamiento::SetEnRambla(bool enRambla)
{
	this->_enRambla = enRambla;
}
// Operaciones
int Entrenamiento::Cupo()
{
	if (this->_enRambla)
		return CUPO_RAMBLA_TRUE - this->GetCantInscripciones();
	else
		return CUPO_RAMBLA_FALSE - this->GetCantInscripciones();
}

void Entrenamiento::InsertarInscripcion(DtInscripcion inscripcion)
{
	try
	{
		if (Cupo() == 0)
			throw invalid_argument("No hay cupo disponible.");
		if (SocioInscripto(inscripcion.GetSocio()))
			throw invalid_argument("El socio, " + inscripcion.GetSocio().GetNombre() + " (" + inscripcion.GetSocio().GetCi() + "), ya esta inscripto a la clase.");
		Inscripcion **inscripciones = this->GetInscripciones();
		inscripciones[this->GetCantInscripciones()] = new Inscripcion(inscripcion.GetFecha(), inscripcion.GetSocio());

		this->SetInscripciones(inscripciones, GetCantInscripciones() + 1);
		this->SetCantInscripciones(GetCantInscripciones() + 1);
	}
	catch (exception &ex)
	{
		cerr << "Error code: " << ex.what();
	}
}
bool Entrenamiento::SocioInscripto(DtSocio socio)
{
	bool retorno = false;
	if (this->GetCantInscripciones() > 0)
	{
		Inscripcion **inscripciones = this->GetInscripciones();
		for (int i = 0; i < this->GetCantInscripciones(); i++)
		{
			if (inscripciones[i]->GetSocio().GetCi() == socio.GetCi())
			{
				retorno = true;
				break;
			}
		}
	}
	return retorno;
}
bool Entrenamiento::ExisteInscripcionByCi(string ci)
{
	bool retorno = false;
	for (int i = 0; i < this->GetCantInscripciones(); i++)
	{
		if (this->GetInscripciones()[i]->GetSocio().GetCi() == ci)
		{
			retorno = true;
			break;
		}
	}
	return retorno;
}

void Entrenamiento::borrarIncripcionDeClase(string ciSocio)
{
	int iter, cantInscripciones = this->GetCantInscripciones();
	Inscripcion **inscripciones = this->GetInscripciones();
	for (int i = 0; i < cantInscripciones; i++)
	{
		if (inscripciones[i]->GetSocio().GetCi() == ciSocio)
		{
			inscripciones[i]->~Inscripcion();
			iter = i;
		}
	}
	for (iter; iter + 1 < cantInscripciones; iter++)
	{
		inscripciones[iter] = inscripciones[iter + 1];
		if (iter + 1 == cantInscripciones - 1)
			inscripciones[iter + 1]->~Inscripcion();
	}
	this->SetCantInscripciones(cantInscripciones - 1);
}

// Destructor
Entrenamiento::~Entrenamiento()
{
	/*	this->~Clase();
		Preguntar: cuando se destruyen las clases hijas,
		hay que destruir al padre?
	*/
}
