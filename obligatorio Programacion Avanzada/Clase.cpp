#include "Clase.h"

Clase::Clase()
{
}

Clase::Clase(int ident, string n,enum turn)
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

void Clase::SetTurno(Turno turn)
{

}

Clase::Clase(int ident, string n, enum turn) //falta enumerado turno
{
	id = ident;
	nombre = n;
	

	

}
