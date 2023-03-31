#include "Inscripcion.h"
#include "DtFecha.h"

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
void Inscripcion::SetFecha(DtFecha fecha) {
	this->_fecha = fecha;
}
Inscripcion::~Inscripcion(){}