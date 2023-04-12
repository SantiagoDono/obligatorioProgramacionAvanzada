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
void borrarInscripcion(string ciSocio, int idClase, Sistema& sys);
enumTurno elegirTurno();
void agregarClase(DtClase& clase, Sistema& sys, bool spinning);
void casosDeTest(Sistema& sys);
void tipoClase(Sistema& sys);
void ingresarClase(Sistema& sys, DtClase clase, bool spinning, int cantBicicletas);
void ingresarClase(Sistema& sys, DtClase clase, bool spinning, bool enRambla);
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
	int idClase, dia, mes, anio, tipoC;
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
		tipoClase(sys);
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
		cout << "---- 5: Borrar inscripcion ----" << endl;
		cout << "Ingrese cedula de socio: ";
		cin >> cedula;
		cout << "Ingrese id de clase: ";
		cin >> idClase;

		borrarInscripcion(cedula, idClase, sys);

		cout << endl;
		break;
	case 6:
		cout << "Gracias por utilizar el sistema.";
		break;
	case 1111:
		casosDeTest(sys);
		break;
	default:
		cout << "La opcion " << entrada << " no esta disponible." << endl;
		cout << "Por favor, ingrese una opcion correcta" << endl << endl;
	}
}

void agregarSocio(string ci, string nombre, Sistema& sys) {
	try
	{
		if (sys.existeSocio(ci))
			throw invalid_argument("Ya existe el socio");
		DtSocio nuevo_socio = DtSocio(ci, nombre);
		sys.insertarSocio(nuevo_socio);
		cout << nuevo_socio << endl;
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
		if (spinning) {

			if (sys.GetSpinningById(idClase)->ExisteInscripcionByCi(ciSocio))
				throw invalid_argument("El socio " + ciSocio + " ya esta inscripto a la clase.");

			sys.insertarInscripcionSpinning(nuevaIns, sys.GetSpinningById(idClase));

			cout << sys.GetSpinningById(idClase)->GetInscripcionByCiSocio(ciSocio);
		}else {
			if (sys.GetEntrenamientoById(idClase)->ExisteInscripcionByCi(ciSocio))
				throw invalid_argument("El socio " + ciSocio + " ya esta inscripto a la clase.");
			sys.insertarInscripcionEntrenamiento(nuevaIns, sys.GetEntrenamientoById(idClase));
			cout << sys.GetEntrenamientoById(idClase)->GetInscripcionByCiSocio(ciSocio);
		}
	}
	catch (exception& ex)
	{
		cerr << "No se pudo agregar la inscripción." << endl << ex.what() << endl;
	}


}

void borrarInscripcion(string ciSocio, int idClase, Sistema& sys) {
	try
	{
		bool spinning;
		if (!sys.existeSocio(ciSocio))
			throw invalid_argument("No existe el usuario con C.I.: " + ciSocio);
		if (!sys.existeClase(idClase, spinning))
			throw invalid_argument("No existe la clase con ID: " + idClase);

		if(spinning)
		{
			if(!sys.GetSpinningById(idClase)->SocioInscripto(sys.GetDtSocioByCi(ciSocio)))
				throw invalid_argument("No existe la inscripcion del usuario en esa clase");

			else{
				sys.GetSpinningById(idClase)->borrarIncripcionDeClase(ciSocio);
			}
		}
		else
		{
			if(!sys.GetEntrenamientoById(idClase)->SocioInscripto(sys.GetDtSocioByCi(ciSocio)))
				throw invalid_argument("No existe la inscripcion del usuario en esa clase");
			else
			{
				sys.GetEntrenamientoById(idClase)->borrarIncripcionDeClase(ciSocio);
			}
		}

		cout << "Se borro la inscripcion del usuario con exito" << endl;
						
	}
	catch(exception& ex)
	{
		cerr << "No se pudo borrar la inscripción." << endl << ex.what() << endl;
	}
}

enumTurno elegirTurno() {
	int opcion = 0;

	while (opcion < 1 || opcion > 3)
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
			break;
		case 2:
			cout << "---- 2: Agregar 2 clases de spinning. ----" << endl;
			ingresarClase(sys, DtClase(1, "s1", Manana, 0), true, 25);
			ingresarClase(sys, DtClase(20, "s20", Tarde, 0), true, 20);
			break;
		case 3:
			cout << "---- 3: Agregar 2 clases de entrenamiento. ----" << endl;
			ingresarClase(sys, DtClase(10, "E10", Manana, 0), true, true);
			ingresarClase(sys, DtClase(11, "E11", Noche, 0), true, false);
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
void agregarClase(DtClase& clase, Sistema& sys, bool spinning) {
	int cantBicicletas = 0;
	if (spinning) {
		while (cantBicicletas > 50 || cantBicicletas < 1) {
			cout << "Ingrese cantidad de bicicletas (entre 1 y 50): ";
			cin >> cantBicicletas;
			if (cantBicicletas > 50 || cantBicicletas < 1)
				cout << "Ingresaste un valor incorrecto." << endl;
		}
		ingresarClase(sys, clase, spinning, cantBicicletas);
	}
	else {
		//entrenamiento
		string rambla;
		while (rambla != "y" && rambla != "Y" && rambla != "n" && rambla != "N")
		{

			cout << "En rambla? [y/n]: ";//ver como ponerlo mas lindo
			cin >> rambla;
			if (rambla == "y" || rambla == "Y")
			{
				ingresarClase(sys, clase, spinning, true);

			}
			else if (rambla == "n" || rambla == "N")
			{

				ingresarClase(sys, clase, spinning, false);

			}
			else {
				cout << "Por favor ingrese una opcion correcta." << endl;
			}
		}
	}

}
void tipoClase(Sistema& sys) {

	string nombreClase;
	int idClase, tipo = 0;
	enumTurno turno;
	cout << "---- 2: Agregar clase ----" << endl;
	while (tipo < 1 || tipo >3) {
		cout << "Especifique que clase quiere agregar:" << endl << "1: Spinning." << endl << "2: Entrenamiento." << endl;
		cout << "Ingrese opcion: ";
		cin >> tipo;
		if (tipo == 1)
		{
			try
			{
				cout << "---- 1: Spinning ----" << endl;
				while (true) {
					cout << "Ingrese id de clase: ";
					string ingreso;
					cin >> ingreso;
					if (isdigit(ingreso[0])) {
						idClase = stoi(ingreso);
						break;
					}
					else {
						cerr << "El valor ingresado no es un numero. Intente de nuevo." << endl;
					}
				}
				cout << "Ingrese nombre de clase: ";
				cin >> nombreClase;
				turno = elegirTurno();
				DtClase clase = DtClase(idClase, nombreClase, turno, 0);
				agregarClase(clase, sys, true);

			}
			catch (exception& e)
			{
				cerr << "Se produjo el erorr: " << e.what() << endl;
			}
		}
		else if (tipo == 2) {
			try
			{

				cout << "---- 2: Entrenamiento ----" << endl;
				cout << "ingrese id de clase: ";
				cin >> idClase;
				cout << "Ingrese nombre de clase: ";
				cin >> nombreClase;
				turno = elegirTurno();
				DtClase clase = DtClase(idClase, nombreClase, turno, 0);
				agregarClase(clase, sys, false);
			}
			catch (exception& e)
			{
				cerr << "Se produjo el erorr: " << e.what() << endl;
			}
		}
		else {


			cout << "La opcion " << tipo << " no esta disponible." << endl;
			cout << "Por favor, ingrese una opcion correcta" << endl << endl;

		}
	}
}
void ingresarClase(Sistema& sys, DtClase clase, bool spinning, int cantBicicletas) {
	try
	{
		if (sys.existeClase(clase.GetId(), spinning))
			throw invalid_argument("La clase ya existe");

		sys.insertarSpinning(DtSpinning(cantBicicletas,
			clase.GetId(),
			clase.GetNombre(),
			clase.GetCantInscripciones(),
			clase.GetTurno()));
		cout << "Se inserto:" << endl;
		DtSpinning spin = DtSpinning(sys.GetSpinningById(clase.GetId())->GetCantBicicletas(),
			sys.GetSpinningById(clase.GetId())->GetId(),
			sys.GetSpinningById(clase.GetId())->GetNombre(),
			sys.GetSpinningById(clase.GetId())->GetCantInscripciones(),
			sys.GetSpinningById(clase.GetId())->GetTurno());
		cout << spin << endl;


	}
	catch (exception& ex)
	{
		cerr << "No se pudo agregar la clase." << endl << ex.what() << endl;
	}
}
void ingresarClase(Sistema& sys, DtClase clase, bool spinning, bool enRambla) {
	try
	{
		if (sys.existeClase(clase.GetId(), spinning))
			throw invalid_argument("la clase ya existe");
		sys.insertarEntrenamiento(DtEntrenamiento(enRambla,
			clase.GetId(),
			clase.GetNombre(),
			clase.GetCantInscripciones(),
			clase.GetTurno()));
		cout << "Se inserto:" << endl;
		DtEntrenamiento entre = DtEntrenamiento(sys.GetEntrenamientoById(clase.GetId())->GetEnRambla(),
			sys.GetEntrenamientoById(clase.GetId())->GetId(),
			sys.GetEntrenamientoById(clase.GetId())->GetNombre(),
			sys.GetEntrenamientoById(clase.GetId())->GetCantInscripciones(),
			sys.GetEntrenamientoById(clase.GetId())->GetTurno());
		cout << entre << endl;
	}
	catch (exception& ex)
	{
		cerr << "No se pudo agregar la clase." << endl << ex.what() << endl;
	}
}