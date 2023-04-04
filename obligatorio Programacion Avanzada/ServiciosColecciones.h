#pragma once
#ifndef SERVICIOSCOLECCIONES_H
#define SERVICIOSCOLECCIONES_H

#include <string>
#include <list>
#include "Socio.h"
#include "Spinning.h"
#include "Entrenamiento.h"

bool existeSocio(string ciSocio, list<Socio*> socios);

bool existeClase(
	int idClase,
	list<Spinning*> clasesS,
	list<Entrenamiento*> clasesE,
	bool& spinning);

DtSocio GetDtSocioByCi(string ci, list<Socio*> socios);

DtSocio GetDtSocioByCi(string ci, list<Socio*> socios);

Spinning* GetSpinningById(int id, list<Spinning*> spinning);

Entrenamiento* GetEntrenamientoById(int id, list<Entrenamiento*> entrenamiento);

#endif // !SERVICIOSCOLECCIONES_H