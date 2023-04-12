#pragma once

#ifndef SPINNING_H
#define SPINNING_H



#include "Clase.h"
#include "DtInscripcion.h"

class Spinning : public Clase
{
	private:
		int _cantBicicletas;

	public:
		//Constructores
		Spinning();
		Spinning(
			int cantBicicletas,
			int id,
			string nombre,
			enumTurno turno,
			int cantInscrp);

		//Getters
		int GetCantBicicletas();

		//Setters
		void SetCantBicicletas(int cantBicicletas);
		
		//Operaciones
		int Cupo();
		void InsertarInscripcion(DtInscripcion inscripcion);
		bool SocioInscripto(DtSocio socio);
		DtInscripcion GetInscripcionByCiSocio(string ci);
		bool ExisteInscripcionByCi(string ci);
		void borrarIncripcionDeClase(string ciSocio);
		//Destructor
		~Spinning();
};

#endif // !SPINNING_H