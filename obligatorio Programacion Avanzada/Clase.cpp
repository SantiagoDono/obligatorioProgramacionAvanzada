#include "Clase.h"
Clase::Clase()
{
}

Clase::Clase(char c[9]/*cedula*/, char n[30])
{
	strcpy_s(ci, c);
	strcpy_s(nombre, n);
}

void Clase::setCi(char c[9])
{
	strcpy_s(ci, c);
}

void Clase::setNom(char n[30])
{
	strcpy_s(nombre, n);
}

Clase::~Clase()
{
}
