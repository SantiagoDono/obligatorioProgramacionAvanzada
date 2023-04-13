#include "Inscripcion.h"
#include "DtFecha.h"
#include "Constantes.h"

Inscripcion::Inscripcion()
{
	this->_fecha = DtFecha();
	this->_socio = new Socio();
}
Inscripcion::Inscripcion(DtFecha fecha, DtSocio socio)
{
	this->_fecha = fecha;
	this->_socio = new Socio(socio.GetCi(), socio.GetNombre());
}
DtFecha Inscripcion::GetFecha()
{
	return _fecha;
}
DtSocio Inscripcion::GetSocio()
{
	return DtSocio(_socio->GetCi(), _socio->GetNombre());
}
void Inscripcion::SetFecha(DtFecha fecha)
{
	this->_fecha = fecha;
}
void Inscripcion::SetSocio(DtSocio socio)
{
	this->_socio->SetCi(socio.GetCi());
	this->_socio->SetNombre(socio.GetCi());
}
Inscripcion::~Inscripcion()
{
	delete _socio;
}