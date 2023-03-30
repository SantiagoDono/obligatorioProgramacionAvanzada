#include "DtFecha.h"
#include "Constantes.h"
#include <stdexcept>

DtFecha::DtFecha()
{
	dia = MIN_FECHA_DIA;
	mes = MIN_FECHA_MES;
	año = MIN_FECHA_AÑO;
}
DtFecha::DtFecha(int dia, int mes, int año)
{
	this->dia = dia;
	this->mes = mes;
	this->año = año;

	if (this->dia < MIN_FECHA_DIA || this->dia > MAX_FECHA_DIA ||
		this->mes < MIN_FECHA_MES || this->mes > MAX_FECHA_MES ||
		this->año < MIN_FECHA_AÑO)
	{
		//std::invalid_argument::invalid_argument;
	}
}
DtFecha::~DtFecha(){}