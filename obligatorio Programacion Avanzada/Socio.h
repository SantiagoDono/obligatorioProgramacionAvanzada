#pragma once

#ifndef SOCIO_H
#define SOCIO_H

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class Socio
{
private:
	//atributos
	string _ci;
	string _nombre;
public:
	//constructor
	Socio();
	Socio(string ci, string nombre);

	//getters
	string GetCi();
	string GetNombre();
	//setters
	void SetCi(string ci);
	void SetNombre(string nombre);

	//destructor
	~Socio();
};

#endif // !


