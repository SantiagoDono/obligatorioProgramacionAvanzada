#include "ServiciosColecciones.h"

using namespace std;

bool existeSocio(string ciSocio, list<Socio*> socios)
{
	bool retorno = false;
	for (Socio* socio : socios) {
		if (socio->GetCi() == ciSocio) {
			retorno = true;
			break;
		}
	}
	return retorno;
}
bool existeClase(
	int idClase,
	list<Spinning*> clasesS,
	list<Entrenamiento*> clasesE,
	bool& spinning)
{
	bool retorno = false;
	for (Spinning* claseS : clasesS) {
		if (claseS->GetId() == idClase) {
			retorno = true;
			spinning = true;
			break;
		}
	}
	if (!retorno) {
		for (Entrenamiento* claseE : clasesE) {
			if (claseE->GetId() == idClase) {
				retorno = true;
				spinning = false;
				break;
			}
		}
	}
	return retorno;
}

DtSocio GetDtSocioByCi(string ci, list<Socio*> socios) {
	DtSocio socio;
	for (Socio* soc : socios) {
		if (soc->GetCi() == ci) {
			socio = DtSocio(soc->GetCi(), soc->GetNombre());
			break;
		}
	}
	return socio;
}
Spinning* GetSpinningById(int id, list<Spinning*> spinning) {
	try {
		for (Spinning* c : spinning) {
			if (c->GetId() == id) {
				return c;
			}
		}
	}
	catch (exception& ex) {
		cerr << ex.what();
	}
}
Entrenamiento* GetEntrenamientoById(int id, list<Entrenamiento*> entrenamiento) {
	try 
	{
		for (Entrenamiento* c : entrenamiento) {
			if (c->GetId() == id) {
				return c;
			}
		}
	}
	catch (exception& ex) {
		cerr << ex.what();
	}
}