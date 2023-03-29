#pragma once
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class Socio
{
	
		//atributos
	private:
		 string ci;// probando
		string nombre;//puse 30 pensando que es nombre completo
	public:
		//constructor
		Socio();//constructor por defecto
		Socio(string c, string n);
		//contructor comun 

		//getters
		
		string getCi();
		string getNombre();
		//setters
		void setCi(string c);
		void setNom(string n);

		//operaciones

		//destructor
		~Socio();
};

