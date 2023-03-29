#include "Clase.h"

Clase::Clase()
{
}

Clase::Clase(int ident, string n,eTurno turn)
{

}

int Clase::getId()
{
	return id;
}

string Clase::getNombre()
{
	return nombre;
}

eTurno Clase::getTurno()
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

void Clase::SetTurno(eTurno turn)
{
	turno = turn;
}

int Clase::cupo()
{
 //Ver como implementarlo 
}

Clase::~Clase()
{
}

Clase::Clase(int ident, string n, eTurno turn) //falta enumerado turno
{
	id = ident;
	nombre = n;
	turno = turn;
}

//destructor
