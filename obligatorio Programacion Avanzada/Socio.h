#pragma once
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class Socio
{
	private:
		//atributos
		string ci;
		string nombre;
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

