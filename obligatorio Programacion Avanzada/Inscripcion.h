#pragma once

#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include "DtFecha.h"
#include "DtSocio.h"
#include "Socio.h"


class Inscripcion
{	
	private:
		DtFecha _fecha;
		Socio * _socio;
	public:
		Inscripcion();
		Inscripcion(DtFecha fecha, DtSocio socio);

		DtFecha GetFecha();
		DtSocio GetSocio();
		void SetFecha(DtFecha fecha);
		void SetSocio(DtSocio socio);

		~Inscripcion();
};

#endif