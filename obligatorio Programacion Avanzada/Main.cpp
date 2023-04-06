// obligatorio Programacion Avanzada.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#pragma once

#include <iostream>
#include "Socio.h"
#include "Clase.h"
#include "Spinning.h"
#include "Entrenamiento.h"
#include "ServiciosColecciones.h"
#include "Impresiones.h"

using namespace std;
/*
void agregarInscripcion(
	string ciSocio,
	int idClase,
	DtFecha fecha,
	list<Socio*>& socios,
	list<Spinning*>& clasesS,
	list<Entrenamiento*>& clasesE);
*/

int main()
{

	DtSocio dtSocio = DtSocio("123456-7", "Pepe Perez");
	DtSocio dtSocio2 = DtSocio("123458-9", "Marco Marconi");
	DtFecha dtFecha = DtFecha();
	Inscripcion* ins = new Inscripcion(dtFecha, dtSocio);
	Inscripcion* array[MAX_INSCRIPCIONES];
	array[0] = ins;
	ins = new Inscripcion(dtFecha, dtSocio2);
	array[1] = ins;

	Entrenamiento * entrenamiento = new Entrenamiento(false ,1, "nombre", Manana, array, 2);
	
	DtEntrenamiento dtEntrenamiento = DtEntrenamiento(
		entrenamiento->GetEnRambla(),
		entrenamiento->GetId(),
		entrenamiento->GetNombre(),
		entrenamiento->GetCantInscripciones(),
		entrenamiento->GetTurno());

	cout << dtEntrenamiento << endl;

	for (int i = 0; i < min(MAX_INSCRIPCIONES, entrenamiento->GetCantInscripciones()); i++) {
		cout << entrenamiento->GetInscripciones()[i]->GetFecha();
		cout << entrenamiento->GetInscripciones()[i]->GetSocio() << endl;
	}
	cout << entrenamiento->Cupo();
}
/*
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
*/
