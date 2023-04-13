#pragma once

#ifndef DTFECHA_H
#define DTFECHA_H

class DtFecha
{
private:
	int _dia;
	int _mes;
	int _anio;

public:
	DtFecha();
	DtFecha(int dia, int mes, int anio);

	int GetAnio();
	int GetMes();
	int GetDia();

	bool FechaValida(int dia, int mes, int anio);

	~DtFecha();
};

#endif
