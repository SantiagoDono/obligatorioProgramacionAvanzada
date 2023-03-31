#include "Socio.h"
#include "Constantes.h"

//constructores	
Socio::Socio()
{
	ci = SIN_CI;
	nombre = SIN_NOMBRE;
}
Socio::Socio(string ci, string nombre)
{
	this->ci = ci;
	this->nombre = nombre;
}
string Socio::GetCi() {
	return ci;
}
string Socio::GetNombre()
{
	return nombre;
}
void Socio::SetCi(string ci)
{
	this->ci = ci;
}
void Socio::SetNombre(string nombre)
{
	this->nombre = nombre;
}
Socio::~Socio()
{
}


