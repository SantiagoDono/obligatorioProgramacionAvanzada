#include "Clase.h"

Clase::Clase()
{
}

Clase::Clase(int ident, string n,Turno turn)
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

Turno Clase::getTurno()
{
	return turno;
}

void Clase::setId(int aidi)
{
	id = aidi;
}

void Clase::SetTurno(Turno turn)
{
	turno = turn;
}

Clase::Clase(int ident, string n, Turno turn) //falta enumerado turno
{
	id = ident;
	nombre = n;
	

	

}
