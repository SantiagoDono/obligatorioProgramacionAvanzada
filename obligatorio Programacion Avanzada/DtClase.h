#pragma once

#ifndef DTCLASE_H
#define DTCLASE_H


#include <string>
#include <list>
#include "EnumTurno.h"
#include"Constantes.h"

using namespace std;

class DtClase
{
private:
    int _id;
    string _nombre;
    enumTurno _turno;
    int _cantInscripciones;

public:
    DtClase();
    DtClase(int  id, string nombre, enumTurno turno, int cantInscripciones);

    int GetId();
    string GetNombre();
    enumTurno GetTurno();
    int GetCantInscripciones();

    ~DtClase();
};

#endif // !1