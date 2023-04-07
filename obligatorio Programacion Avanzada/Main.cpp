// obligatorio Programacion Avanzada.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#pragma once

#include <iostream>
#include "Socio.h"
#include "Clase.h"
#include "Spinning.h"
#include "Entrenamiento.h"
#include "Impresiones.h"
#include "Sistema.h"

using namespace std;

void Manejador(int& entrada, Sistema& sys);
void agregarSocio(string ci, string nombre);
void agregarInscripcion(string ciSocio, int idClase, DtFecha fecha, Sistema& sys);

int main()
{
	Sistema sistema = Sistema();
	int entrada = 0;

	while (entrada != 6) {
		cout << "---- Menu ----" << endl;
		cout << "1: Agregar socio" << endl;
		cout << "2: Agregar clase" << endl;
		cout << "4: Agregar inscripcion" << endl;
		cout << "5: Borrar inscripcion" << endl;
		cout << "6: Salir" << endl;
		cout << "--------------" << endl;
		cout << endl << "Ingrese opcion: ";
		
		Manejador(entrada, sistema);
	}
	return 0;
}

void Manejador(int& entrada, Sistema& sys) {
	cin >> entrada;
	string nombre, cedula;
	int idClase, dia, mes, anio;
	switch (entrada) {
	case 1:
		cout << "---- 1: Agregar socio ----" << endl;
		cout << "Ingrese nombre: ";
		cin >> nombre;
		cout << "Ingrese cedula: ";
		cin >> cedula;

		agregarSocio(cedula, nombre);
		
		cout << endl;
		break;
	case 2:
		// Preguntar si spinning o entrenamiento
		cout << endl;
		break;
	case 3:
		cout << endl;
		break;
	case 4:
		cout << "---- 4: Agregar inscripcion ----" << endl;
		cout << "Ingrese cedula de socio: ";
		cin >> cedula;
		cout << "Ingrese id de clase: ";
		cin >> idClase;
		cout << "Ingrese fecha de inscripcion" << endl << "Dia: ";
		cin >> dia;
		cout << "Mes: ";
		cin >> mes;
		cout << "Anio: ";
		cin >> anio;

		agregarInscripcion(cedula, idClase, DtFecha(dia, mes, anio), sys);

		cout << endl;
		break;
	case 5:
		cout << endl;
		break;
	case 6:
		cout << "Gracias por utilizar el sistema.";
		break;
	default:
		cout << "La opcion " << entrada << " no esta disponible." << endl;
		cout << "Por favor, ingrese una opcion correcta" << endl << endl;
	}
}

void agregarSocio(string ci, string nombre) {
	try 
	{
		throw invalid_argument("Ya existe el socio");
	}
	catch (exception& ex) 
	{
		cerr << "No se pudo crear el socio." << endl << ex.what() << endl;
	}
}
void agregarInscripcion(string ciSocio, int idClase, DtFecha fecha, Sistema& sys) {
	try
	{
		bool spinning;
		if (!sys.existeSocio(ciSocio))
			throw invalid_argument("No existe el usuario con C.I.: " + ciSocio);
		if (!sys.existeClase(idClase, spinning))
			throw invalid_argument("No existe la clase con ID: " + idClase);
		
		DtInscripcion nuevaIns = DtInscripcion(fecha, sys.GetDtSocioByCi(ciSocio));

		if (spinning)
			sys.insertarInscripcionSpinning(nuevaIns, sys.GetSpinningById(idClase));
		else
			sys.insertarInscripcionEntrenamiento(nuevaIns, sys.GetEntrenamientoById(idClase));
	}
	catch(exception& ex)
	{
		cerr << "No se pudo agregar la inscripción." << endl << ex.what() << endl;
	}
}