#include "DtFecha.h"
#include "Constantes.h"
#include <exception>
#include <iostream>

using namespace std;

DtFecha::DtFecha() {
	this->_dia = MIN_FECHA_DIA;
	this->_mes = MIN_FECHA_MES;
	this->_anio = MIN_FECHA_ANIO;
}

DtFecha::DtFecha(int dia, int mes, int anio)
{
	try 
	{
		if (dia < MIN_FECHA_DIA || dia > MAX_FECHA_DIA ||
			mes < MIN_FECHA_MES || mes > MAX_FECHA_MES ||
			anio < MIN_FECHA_ANIO)
		{
			throw invalid_argument("invalid_argument");
		}
		else {
			this->_dia = dia;
			this->_mes = mes;
			this->_anio = anio;
		}
	}
	catch (exception& ex) {
		cerr << "Exception code: " << ex.what();

		this->_dia = MIN_FECHA_DIA; // Hay que devolver algo? o se tiene que mandar
		this->_mes = MIN_FECHA_MES; // la exception para arriba?
		this->_anio = MIN_FECHA_ANIO;

		cout << "Se guarda fecha por defecto: 1/1/1900";
	}
}

int DtFecha::GetAnio() {
	return _anio;
}
int DtFecha::GetMes() {
	return _mes;
}
int DtFecha::GetDia() {
	return _anio;
}

DtFecha::~DtFecha(){}