#include "Socio.h"
#include "Constantes.h"

//constructores	
Socio::Socio()
{
	_ci = SIN_CI;
	_nombre = SIN_NOMBRE;
}
Socio::Socio(string ci, string nombre)
{
	this->_ci = ci;
	this->_nombre = nombre;
}
string Socio::GetCi() {
	return _ci;
}
string Socio::GetNombre()
{
	return _nombre;
}
void Socio::SetCi(string ci)
{
	this->_ci = ci;
}
void Socio::SetNombre(string nombre)
{
	this->_nombre = nombre;
}
Socio::~Socio()
{
}


