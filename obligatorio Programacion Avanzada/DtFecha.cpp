#include "DtFecha.h"
#include "Constantes.h"
#include <exception>
#include <iostream>

using namespace std;

DtFecha::DtFecha()
{
	this->_dia = MIN_FECHA_DIA;
	this->_mes = MIN_FECHA_MES;
	this->_anio = MIN_FECHA_ANIO;
}
DtFecha::DtFecha(int dia, int mes, int anio)
{
	try
	{
		if (!FechaValida(dia, mes, anio))
			throw invalid_argument("Fecha invalida.");
		this->_dia = dia;
		this->_mes = mes;
		this->_anio = anio;
	}
	catch (exception &ex)
	{
		cerr << "Invalid argument: " << ex.what() << endl;
	}
}
int DtFecha::GetAnio()
{
	return _anio;
}
int DtFecha::GetMes()
{
	return _mes;
}
int DtFecha::GetDia()
{
	return _dia;
}
bool DtFecha::FechaValida(int dia, int mes, int anio)
{
	return !(dia < MIN_FECHA_DIA || dia > MAX_FECHA_DIA ||
			 mes < MIN_FECHA_MES || mes > MAX_FECHA_MES ||
			 anio < MIN_FECHA_ANIO);
}
DtFecha::~DtFecha() {}