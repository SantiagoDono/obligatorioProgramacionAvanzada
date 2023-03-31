#include "DtFecha.h"
#include "Constantes.h"
#include <stdexcept>

DtFecha::DtFecha()
{
	dia = MIN_FECHA_DIA;
	mes = MIN_FECHA_MES;
	anio = MIN_FECHA_ANIO;
}
DtFecha::DtFecha(int dia, int mes, int anio)
{
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;

	if (this->dia < MIN_FECHA_DIA || this->dia > MAX_FECHA_DIA ||
		this->mes < MIN_FECHA_MES || this->mes > MAX_FECHA_MES ||
		this->anio < MIN_FECHA_ANIO)
	{
		//std::invalid_argument::invalid_argument;
	}
}
DtFecha::~DtFecha(){}