#pragma once

#ifndef DTINSCRIPCION_H
#define DTINSCRIPCION_H

#include "DtFecha.h"
#include "DtSocio.h"

class DtInscripcion
{
private:
    DtFecha _fecha;
    DtSocio _socio;

public:
    DtInscripcion(DtFecha fecha, DtSocio socio);
    DtFecha GetFecha();
    DtSocio GetSocio();

    ~DtInscripcion();
};
#endif // !DTINSCRIPCION_H