#include "Clase.h"
#include "EnumTurno.h"
//habria que hacer el llamado del datatype clase? o en el .h


Clase::Clase()
{
}

Clase::Clase(int ident, string n,enumTurno turn)
{
	id = ident;
	nombre = n;
	turno = turn;
}

int Clase::getId()
{
	return id;
}

string Clase::getNombre()
{
	return nombre;
}

enumTurno Clase::getTurno()
{
	return turno;
}

void Clase::setId(int aidi)
{
	id = aidi;
}

void Clase::setNombre(string nom)
{
	nombre = nom;
}

void Clase::SetTurno(enumTurno turn)
{
	turno = turn;
}

int Clase::cupo()
{
 //Ver como implementarlo 
	return 0;
}

Clase::~Clase()
{
}

//destructor
