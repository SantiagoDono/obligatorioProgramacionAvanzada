#include "Clase.h"

Clase::Clase()
{
}

Clase::Clase(int ident, char n[20]) //falta enumerado turno
{
	id = ident;
	strcpy_s(nombre, n);
}
