// obligatorio Programacion Avanzada.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
// #pragma once

#include <iostream>
#include "Socio.h"
#include "Clase.h"
#include "Spinning.h"
#include "Entrenamiento.h"
#include "Impresiones.h"
#include "Sistema.h"

using namespace std;
// funciones solicitadas
void agregarSocio(string ci, string nombre, Sistema &sys);
void agregarClase(DtClase &clase, Sistema &sys);
void agregarInscripcion(string ciSocio, int idClase, DtFecha fecha, Sistema &sys);
void borrarInscripcion(string ciSocio, int idClase, Sistema &sys);
//menu
void Manejador(int &entrada, Sistema &sys);
//utilidades 
enumTurno elegirTurno();

int main()
{
	Sistema sistema = Sistema();
	int entrada = 0;

	while (entrada != 6)
	{
		cout << "---- Menu ----" << endl;
		cout << "1: Agregar socio" << endl;
		cout << "2: Agregar clase" << endl;
		cout << "4: Agregar inscripcion" << endl;
		cout << "5: Borrar inscripcion" << endl;
		cout << "6: Salir" << endl;
		cout << "--------------" << endl;
		cout << endl
			 << "Ingrese opcion: ";

		Manejador(entrada, sistema);
	}
	return 0;
}
void Manejador(int &entrada, Sistema &sys)
{
	cin >> entrada;

	string nombre, cedula, nombreClase, verificador, rambla;
	int idClase, dia, mes, anio, cantB = 0, tipoClase;
	bool enRambla = false;
	enumTurno turno = Manana;
	// DtClase clase = DtClase(idClase, nombreClase, turno, 0);
	DtSpinning *spinning = new DtSpinning(cantB, idClase, nombreClase, 0, turno);
	DtEntrenamiento *entrenamiento = new DtEntrenamiento(false, idClase, nombreClase, 0, turno);
	switch (entrada)
	{
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
		cout << "---- 2: Agregar clase ----" << endl;
		while (tipoClase < 1 || tipoClase > 2)
		{
			cout << "Especifique que clase quiere agregar:" << endl
				 << "1: Spinning." << endl
				 << "2: Entrenamiento." << endl;
			cout << "Ingrese opcion: ";
			cin >> tipoClase;
		}
		if (tipoClase == 1)
		{
			try
			{
				cout << "---- 1: Spinning ----" << endl;
				while (true)
				{
					cout << "Ingrese id de clase: ";

					cin >> verificador;
					if (isdigit(verificador[0]))
					{
						idClase = stoi(verificador);
						break;
					}
					else
					{
						cerr << "El valor ingresado no es un numero. Intente de nuevo." << endl;
					}
				}

				cout << "Ingrese nombre de clase: ";
				cin >> nombreClase;
				turno = elegirTurno();
				while (cantB > 50 || cantB < 1)
				{
					cout << "Ingrese cantidad de bicicletas (entre 1 y 50): ";
					cin >> cantB;
					if (cantB > 50 || cantB < 1)
						cout << "Ingresaste un valor incorrecto." << endl;
				}
				delete spinning;
				spinning = new DtSpinning(cantB, idClase, nombreClase, 0, turno);
				agregarClase(*spinning, sys);
			}
			catch (exception &e)
			{
				cerr << "Se produjo el erorr: " << e.what() << endl;
			}
		}
		else if (tipoClase == 2)
		{
			try
			{

				cout << "---- 2: Entrenamiento ----" << endl;
				cout << "ingrese id de clase: ";
				cin >> idClase;
				cout << "Ingrese nombre de clase: ";
				cin >> nombreClase;
				turno = elegirTurno();
				while (rambla != "y" && rambla != "Y" && rambla != "n" && rambla != "N")
				{
					cout << "En rambla? [y/n]: ";
					cin >> rambla;
					if (rambla == "y" || rambla == "Y")
						enRambla = true;
					else if (rambla == "n" || rambla == "N")
						enRambla = false;
					else
					{
						cout << "Por favor ingrese una opcion correcta." << endl;
					}
				}
				delete entrenamiento;
				entrenamiento = new DtEntrenamiento(enRambla, idClase, nombreClase, 0, turno);
				agregarClase(*entrenamiento, sys);
			}
			catch (exception &e)
			{
				cerr << "Se produjo el erorr: " << e.what() << endl;
			}
		}
		else
		{

			cout << "La opcion " << tipoClase << " no esta disponible." << endl;
			cout << "Por favor, ingrese una opcion correcta" << endl
				 << endl;
		}

		// agregarClase(*spinning, sys);

		break;
	case 3:
		cout << "te la creiste, por que tocaste 3?" << endl;
		break;
	case 4:
		cout << "---- 4: Agregar inscripcion ----" << endl;
		cout << "Ingrese cedula de socio: ";
		cin >> cedula;
		cout << "Ingrese id de clase: ";
		cin >> idClase;
		cout << "Ingrese fecha de inscripcion" << endl
			 << "Dia: ";
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

	default:
		cout << "La opcion " << entrada << " no esta disponible." << endl;
		cout << "Por favor, ingrese una opcion correcta" << endl
			 << endl;
	}
}

void agregarSocio(string ci, string nombre, Sistema &sys)
{
	try
	{
		if (sys.existeSocio(ci))
			throw invalid_argument("Ya existe el socio");
		DtSocio nuevo_socio = DtSocio(ci, nombre);
		sys.insertarSocio(nuevo_socio);
		cout << nuevo_socio << endl;
	}
	catch (exception &ex)
	{
		cerr << "No se pudo crear el socio." << endl
			 << ex.what() << endl;
	}
}
void agregarInscripcion(string ciSocio, int idClase, DtFecha fecha, Sistema &sys)
{
	try
	{

		if (!sys.existeSocio(ciSocio))
			throw invalid_argument("No existe el usuario con C.I.: " + ciSocio);

		if (!sys.existeClase(idClase))

			throw invalid_argument("No existe la clase con ID: " + idClase);

		DtInscripcion nuevaIns = DtInscripcion(fecha, sys.GetDtSocioByCi(ciSocio));

		if (sys.GetClaseById(idClase)->ExisteInscripcionByCi(ciSocio))
			throw invalid_argument("El socio " + ciSocio + " ya esta inscripto a la clase.");

		sys.insertarInscripcionClase(nuevaIns, sys.GetClaseById(idClase));

		cout << sys.GetClaseById(idClase)->GetInscripcionByCiSocio(ciSocio);
	}
	catch (exception &ex)
	{
		cerr << "No se pudo agregar la inscripción." << endl
			 << ex.what() << endl;
	}
}

void borrarInscripcion(string ciSocio, int idClase, Sistema &sys)
{
	try
	{

		if (!sys.existeSocio(ciSocio))
			throw invalid_argument("No existe el usuario con C.I.: " + ciSocio);
		if (!sys.existeClase(idClase))
			throw invalid_argument("No existe la clase con ID: " + idClase);

		if (!sys.GetClaseById(idClase)->SocioInscripto(sys.GetDtSocioByCi(ciSocio)))
			throw invalid_argument("No existe la inscripcion del usuario en esa clase");

		sys.GetClaseById(idClase)->borrarIncripcionDeClase(ciSocio);

		cout << "Se borro la inscripcion del usuario con exito" << endl;
	}
	catch (exception &ex)
	{
		cerr << "No se pudo borrar la inscripción." << endl
			 << ex.what() << endl;
	}
}

enumTurno elegirTurno()
{
	int opcion = 0;

	while (opcion < 1 || opcion > 3)
	{
		cout << "---- Seleccion de turno ----" << endl;
		cout << "1: Manana." << endl
			 << "2: Tarde" << endl
			 << "3: Noche" << endl;
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

void agregarClase(DtClase &clase, Sistema &sys)
{

	try
	{

		if (sys.existeClase(clase.GetId()))
			throw invalid_argument("La clase ya existe");

		sys.insertarClase(clase);
	}
	catch (exception &ex)
	{
		cerr << "No se pudo agregar la clase." << endl
			 << ex.what() << endl;
	}
}
