#include "Socio.h"

	Socio::Socio()
	{
	}

	Socio::Socio(char c[9]/*cedula*/, char n[30])
	{
		strcpy_s(ci, c);
		strcpy_s(nombre, n);
	}

	void Socio::setCi(char c[9])
	{
		strcpy_s(ci, c);
	}

	void Socio::setNom(char n[30])
	{
		strcpy_s(nombre, n);
	}

	Socio::~Socio()
	{
	}


