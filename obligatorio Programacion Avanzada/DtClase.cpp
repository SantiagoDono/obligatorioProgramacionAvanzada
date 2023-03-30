#include "DtClase.h"

DtClase::DtClase()
{
}

DtClase::DtClase(int aidi, string nom, enumTurno turn)
{
	id = aidi;
	nombre = nom;
	turno = turn;
}

int DtClase::getId()
{
	return id;
}

string DtClase::getNombre()
{
	return nombre;
}

enumTurno DtClase::getTurno()
{
	return turno;
}

DtClase::~DtClase()
{
}

