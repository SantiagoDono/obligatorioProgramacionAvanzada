#pragma once
#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "Socio.h"
#include "Spinning.h"
#include "Entrenamiento.h"
#include "DtSpinning.h"
#include "DtEntrenamiento.h"
#include "Impresiones.h"

class Sistema
{
private:
	Socio *_socios[MAX_SOCIOS]{}; // Se inicializa en el atributo, no en el constructor
	int _cantSocios;
	int _cantClases;
	Clase *_clases[MAX_CLASES]{};

public:
	Sistema();

	DtSocio GetDtSocioByCi(string ci);
	Clase *GetClaseById(int id);

	void insertarSocio(DtSocio socio);
	void insertarClase(DtClase &clase);
	void insertarInscripcionClase(DtInscripcion inscripcion, Clase *clase);

	bool existeSocio(string ciSocio);
	bool existeClase(int idClase);

	~Sistema();
};

;

#endif // !SERVICIOSCOLECCIONES_H