#include "Socio.h"

//constructores	
Socio::Socio()
	{
		ci = "pepe";
	}

Socio::Socio(string c/*cedula*/, string n)
	{
		ci = c;
		nombre = n;
	}
	string Socio::getCi() {
		return ci;
	}

	char Socio::getNombre()
	{
		return 0;
	}



	void Socio::setCi(string c)
	{
		ci = c;
	}

	void Socio::setNom(string n)
	{
		nombre = n;
	}

	

	Socio::~Socio()
	{
	}


