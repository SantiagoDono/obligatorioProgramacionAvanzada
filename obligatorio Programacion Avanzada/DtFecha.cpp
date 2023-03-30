#include "DtFecha.h"
#include "Constantes.h"
#include <stdexcept>

DtFecha::DtFecha()
{
	dia = MIN_FECHA_DIA;
	mes = MIN_FECHA_MES;
	a�o = MIN_FECHA_A�O;
}
DtFecha::DtFecha(int dia, int mes, int a�o)
{
	this->dia = dia;
	this->mes = mes;
	this->a�o = a�o;

	if (this->dia < MIN_FECHA_DIA || this->dia > MAX_FECHA_DIA ||
		this->mes < MIN_FECHA_MES || this->mes > MAX_FECHA_MES ||
		this->a�o < MIN_FECHA_A�O)
	{
		//std::invalid_argument::invalid_argument;
	}
}
DtFecha::~DtFecha(){}