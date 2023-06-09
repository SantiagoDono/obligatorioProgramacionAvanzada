#include <string>
#include"EnumTurno.h"

#ifndef CONSTANTES_H
#define CONSTANTES_H

using namespace std;

//Sistema
const int MAX_SOCIOS = 100;
const int MAX_CLASES = 100;
const int CUPO_RAMBLA_TRUE = 20;
const int CUPO_RAMBLA_FALSE = 10;
const int CANT_MAX_BICICLETAS = 50;
const int MAX_INSCRIPCIONES = 50;

//Fecha
const int MIN_FECHA_DIA = 1;
const int MAX_FECHA_DIA = 31;
const int MIN_FECHA_MES = 1;
const int MAX_FECHA_MES = 12;
const int MIN_FECHA_ANIO = 1900;

//Constructores default
const int ID_NULO = 0;
const string SIN_NOMBRE = "Unnamed";
const string SIN_CI = "Undocumented";
const bool EN_RAMBLA_DEFAULT = false;


#endif