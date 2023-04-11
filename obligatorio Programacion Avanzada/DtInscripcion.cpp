#include "DtInscripcion.h"

DtInscripcion::DtInscripcion(DtFecha fecha, DtSocio socio){
    this->_fecha = fecha;
    this->_socio = socio;
}        
DtFecha DtInscripcion::GetFecha(){
    return _fecha;
}
DtSocio DtInscripcion::GetSocio(){
    return _socio;
}
DtInscripcion::~DtInscripcion(){}