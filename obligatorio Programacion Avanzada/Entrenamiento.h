#pragma once

#ifndef ENTRENAMIENTO_H
#define ENTRENAMIENTO_H

#include "Clase.h"
#include "Constantes.h"
#include "DtInscripcion.h"

class Entrenamiento :public Clase
{
	private:
		bool _enRambla;

	public:
		//Constructores
		Entrenamiento();
		Entrenamiento(
			bool enRambla, 
			int id, 
			string nombre, 
			enumTurno turno, 
			int cantInscrp);

		//Getters
		bool GetEnRambla();

		//Setters
		void SetEnRambla(bool enRambla);

		//Operaciones
		int Cupo();
		void InsertarInscripcion(DtInscripcion inscripcion);
		bool SocioInscripto(DtSocio socio);
		bool ExisteInscripcionByCi(string ci);
		DtInscripcion GetInscripcionByCiSocio(string ci);
		void borrarIncripcionDeClase(string ciSocio);
		//Destructor
		~Entrenamiento();
};

#endif