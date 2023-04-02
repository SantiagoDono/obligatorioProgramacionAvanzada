#include "DtFecha.h"
#include "DtSocio.h"
#include "Socio.h"

#pragma once
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

