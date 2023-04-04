#pragma once

#ifndef DTCLASE_H
#define DTCLASE_H


#include <string>
#include <list>
#include "EnumTurno.h"

using namespace std;

class DtClase
{
private:
    int _id;
    string _nombre;
    enumTurno _turno;

public:
    DtClase(int  id, string nombre, enumTurno turno);

    int GetId();
    string GetNombre();
    enumTurno GetTurno();
    
    ~DtClase();
};

#endif // !1