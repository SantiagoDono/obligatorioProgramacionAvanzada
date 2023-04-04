// obligatorio Programacion Avanzada.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#pragma once

#include <iostream>
#include "Socio.h"
#include <list>
#include "Clase.h"
#include "Spinning.h"
#include "Entrenamiento.h"
#include "ServiciosColecciones.h"

using namespace std;

void agregarInscripcion(
	string ciSocio,
	int idClase,
	DtFecha fecha,
	list<Socio*>& socios,
	list<Spinning*>& clasesS,
	list<Entrenamiento*>& clasesE);


int main()
{
	list<Spinning *> clasesS = list<Spinning*>();
	list<Entrenamiento *> clasesE = list<Entrenamiento*>();
	list<Socio *> socios = list<Socio *>();
	
	
}

void agregarInscripcion(
	string ciSocio, 
	int idClase, 
	DtFecha fecha, 
	list<Socio*> & socios,
	list<Spinning*>& clasesS, 
	list<Entrenamiento*>& clasesE) {

	try 
	{ 
		bool spinningBool;
		if (!existeSocio(ciSocio, socios))
			throw invalid_argument("No existe el socio con ci "+ ciSocio);
		if (!existeClase(idClase, clasesS, clasesE, spinningBool))
			throw invalid_argument("No existe la clase con id "+ idClase);
		if (spinningBool)
		{
			Spinning* spinning = GetSpinningById(idClase, clasesS);
			spinning->InsertarInscripcion(DtInscripcion(fecha, GetDtSocioByCi(ciSocio, socios)));
		}
		else 
		{
			Entrenamiento* entrenamiento = GetEntrenamientoById(idClase, clasesE);
			entrenamiento->InsertarInscripcion(DtInscripcion(fecha, GetDtSocioByCi(ciSocio, socios)));
		}
	}
	catch (exception& ex)
	{
		cerr << ex.what();
	}
}
