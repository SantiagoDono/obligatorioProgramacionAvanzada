#include "DtFecha.h"
#include "Socio.h"

#pragma once
class Inscripcion
{	
	private:
		DtFecha fecha;
		Socio * socio;
	public:
		Inscripcion();
		Inscripcion(DtFecha fecha, Socio* socio);

		DtFecha GetFecha();
		Socio * GetSocio();
		void SetFecha(DtFecha fecha);
		void SetSocio(Socio* socio);

		~Inscripcion();
};

