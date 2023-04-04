#include "DtSocio.h"
#include "Constantes.h"

DtSocio::DtSocio() {
    this->_ci = SIN_CI;
    this->_nombre = SIN_NOMBRE;
}

DtSocio::DtSocio(string ci, string nombre) {
    this->_ci = ci;
    this->_nombre = nombre;
}
string DtSocio::GetCi() {
    return _ci;
}
string DtSocio::GetNombre() {
    return _nombre;
}
DtSocio::~DtSocio() {}