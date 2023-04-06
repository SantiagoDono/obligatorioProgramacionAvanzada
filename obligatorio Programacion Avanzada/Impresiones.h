#pragma once
#include "DtFecha.h"
#include "DtClase.h"
#include "DtSocio.h"
#include "DtSpinning.h"
#include "DtEntrenamiento.h"
#include "DtClase.h"


#ifndef IMPRESIONES_H
#define IMPRESIONES_H

ostream& operator<<(ostream& os, DtFecha fecha);
ostream& operator<<(ostream& os, DtSocio socio);
ostream& operator<<(ostream& os, DtSpinning spinning);
ostream& operator<<(ostream& os, DtEntrenamiento entrenamiento);

#endif // !IMPRESIONES_H
