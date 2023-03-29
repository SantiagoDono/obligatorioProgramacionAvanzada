#pragma once
#include<iostream>
#include<stdio.h>
class Clase
{
	//atributos
private:
	char ci[9];
	char nombre[30];//puse 30 pensando que es nombre completo
public:
	//constructor
	Clase();//constructor por defecto
	Clase(char c[9], char n[30]);//contructor comun 

	//getters
	char getCi[9];
	char getNombre[30];
	//setters
	void setCi(char c[9]);
	void setNom(char n[30]);

	//operaciones

	//destructor
	~Clase();


};

