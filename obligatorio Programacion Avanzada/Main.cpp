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
void agregarSocio(string ci, string nombre, Sistema& sys);
void agregarInscripcion(string ciSocio, int idClase, DtFecha fecha, Sistema& sys);
enumTurno elegirTurno();
void agregarClase( DtClase& clase, Sistema& sys, bool spinning);
void casosDeTest(Sistema& sys);
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

	string nombre, cedula, nombreClase;
	int idClase, dia, mes, anio, tipoClase;
	enumTurno turno;
	
	switch (entrada) {
	case 1:
		cout << "---- 1: Agregar socio ----" << endl;
		cout << "Ingrese nombre: ";
		cin >> nombre;
		cout << "Ingrese cedula: ";
		cin >> cedula;

		agregarSocio(cedula, nombre, sys);

		cout << endl;
		break;
	case 2:
		//cout << "---- 2: Agregar clase ----" << endl;
		//cout << "Especifique que clase quiere agregar:" << endl << "1: Spinning." << endl << "2: Entrenamiento." << endl;
		//cout << "Ingrese opcion: ";
		//cin >> tipoClase;
		//if (tipoClase == 1)
		//{
		//	cout << "---- 1: Spinning ----" << endl;
		//	cout << "Ingrese id de clase: ";
		//	cin >> idClase;
		//	cout << "Ingrese nombre de clase: ";
		//	cin >> nombreClase;
		//	turno = elegirTurno();
		//	DtClase clase = DtClase(idClase, nombreClase, turno, 0);
		//	agregarClase(clase, sys, true);
		//}
		//else if (tipoClase == 2) {

		//	//entrenamiento
		//}
		//else {


		//	cout << "La opcion " << tipoClase << " no esta disponible." << endl;
		//	cout << "Por favor, ingrese una opcion correcta" << endl << endl;

		//}



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
	case 1111:
		casosDeTest(sys);
	default:
		cout << "La opcion " << entrada << " no esta disponible." << endl;
		cout << "Por favor, ingrese una opcion correcta" << endl << endl;
	}
}

void agregarSocio(string ci, string nombre, Sistema& sys) {
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
enumTurno elegirTurno() {
	int opcion=0;

	while (opcion <1 || opcion > 3)
	{
		cout << "---- Seleccion de turno ----" << endl;
		cout << "1: Manana." << endl << "2: Tarde" << endl << "3: Noche" << endl;
		cout << "Selecciona la opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			return Manana;
			break;
		case 2:
			return Tarde;
			break;
		case 3:
			return Noche;
			break;
		default:
			cout << "Ingrese una opcion valida." << endl;
		}
	}
}

void casosDeTest(Sistema& sys) {
	int entrada = 0;
	while (entrada != 4) {
		cout << "---- Generacion de casos de test ----" << endl;
		cout << "1: Ingresar 3 socios de prueba" << endl;
		cout << "2: Ingresar 2 clases de spinning de prueba" << endl;
		cout << "3: Ingresar 2 clases de entrenamiento prueba" << endl;
		cout << "4: Volver" << endl;
		cout << "Ingrese opcion: ";
		cin >> entrada;
		switch (entrada)
		{
			case 1:
				cout << "---- 1: Ingresar 3 socios de prueba ----" << endl;
				agregarSocio("4.215.368-4", "Martin Loque", sys);
				agregarSocio("5.835.371-6", "Romina Panca", sys);
				agregarSocio("3.145.844-1", "Carla Matt", sys);

				cout << "Se agregaron los socios: " << endl;
				cout << "----------------" << endl;
				cout << sys.GetDtSocioByCi("4.215.368-4");
				cout << "----------------" << endl;
				cout << sys.GetDtSocioByCi("5.835.371-6");
				cout << "----------------" << endl;
				cout << sys.GetDtSocioByCi("3.145.844-1");
				cout << "----------------" << endl;
				break;
			case 2: 
				cout << "No implementado" << endl;
				break;
			case 3:
				cout << "No implementado" << endl;
				break;
			case 4:
				cout << "Finaliza la generacion de casos de test" << endl;
				break;
			default:
				cout << "La opcion " << entrada << " no esta disponible." << endl;
				cout << "Por favor, ingrese una opcion correcta" << endl << endl;
				break;
		}
	}
}
void agregarClase( DtClase& clase, Sistema& sys,bool spinning){
	int cantBicicletas=0;
	if (spinning) {
		while (cantBicicletas > 50 || cantBicicletas < 1) {
			cout << "Ingrese cantidad de bicicletas (entre 1 y 50): ";
			cin >> cantBicicletas;
			if (cantBicicletas > 50 || cantBicicletas < 1)
				cout << "Ingresaste un valor incorrecto."<< endl;
		}
		try
		{
			if (sys.existeClase(clase.GetId(), spinning))
				throw invalid_argument("La clase ya existe");
			
			sys.insertarSpinning(DtSpinning(cantBicicletas,
				clase.GetId(), 
				clase.GetNombre(),
				clase.GetCantInscripciones(),
				clase.GetTurno()));

			

		}catch (exception& ex)
		{
			cerr << "No se pudo agregar la clase." << endl << ex.what() << endl;
		}

	}
	else {
		//entrenamiento 

	}

}
//hacer funcion tipo clase 