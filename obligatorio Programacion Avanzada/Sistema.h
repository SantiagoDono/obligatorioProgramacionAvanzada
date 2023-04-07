#pragma once
#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "Socio.h"
#include "Spinning.h"
#include "Entrenamiento.h"
#include "DtSpinning.h"
#include "DtEntrenamiento.h"

class Sistema
{
	private:
		Socio* _socios[MAX_SOCIOS]{}; // Se inicializa en el atributo, no en el constructor
		int _cantSocios;
		Spinning* _spinning[MAX_CLASES]{};
		int _cantSpinning;
		Entrenamiento* _entrenamiento[MAX_CLASES]{};
		int _cantEntrenamiento;
	public:
		Sistema();

		DtSocio GetDtSocioByCi(string ci);
		Spinning* GetSpinningById(int id);
		Entrenamiento* GetEntrenamientoById(int id);

		void insertarSocio(DtSocio socio);
		void insertarSpinning(DtSpinning spinning);
		void insertarEntrenamiento(DtEntrenamiento entrenamiento);
		void insertarInscripcionSpinning(DtInscripcion inscripcion, Spinning* clase);
		void insertarInscripcionEntrenamiento(DtInscripcion inscripcion, Entrenamiento* clase);

		bool existeSocio(string ciSocio);
		bool existeClase(int idClase, bool& spinning);
		

		~Sistema();

};




;


#endif // !SERVICIOSCOLECCIONES_H