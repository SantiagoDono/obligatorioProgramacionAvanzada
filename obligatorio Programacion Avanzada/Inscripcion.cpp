#include "Inscripcion.h"
#include "DtFecha.h"
#include "Constantes.h"

Inscripcion::Inscripcion(){
	this->_fecha = DtFecha();
	this->_socio = new Socio();
}
Inscripcion::Inscripcion(DtFecha fecha, Socio* socio) {
	this->_fecha = fecha;
	this->_socio = new Socio(socio->GetCi(), socio->GetNombre());
}
DtFecha Inscripcion::GetFecha(){
	return _fecha;
}
Socio* Inscripcion::GetSocio() {
	return _socio;
}
void Inscripcion::SetFecha(DtFecha fecha) {
	this->_fecha = fecha;
}
void Inscripcion::SetSocio(Socio* socio) {
	this->_socio->SetCi(socio->GetCi());
	this->_socio->SetNombre(socio->GetNombre());
}
Inscripcion::~Inscripcion(){
	delete _socio;
}