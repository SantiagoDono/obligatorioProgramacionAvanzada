#include "Inscripcion.h"
#include "DtFecha.h"

Inscripcion::Inscripcion(){
	this->fecha = DtFecha();
	this->socio = new Socio();
}
Inscripcion::Inscripcion(DtFecha fecha, Socio* socio) {
	this->fecha = fecha;
	this->socio = new Socio(socio->GetCi(), socio->GetNombre());
}
DtFecha Inscripcion::GetFecha(){
	return fecha;
}
void Inscripcion::SetFecha(DtFecha fecha) {
	this->fecha = fecha;
}
Inscripcion::~Inscripcion(){}