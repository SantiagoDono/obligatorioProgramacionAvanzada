#pragma once
#include "Clase.h"
class Entrenamiento :public Clase
{
	private:
		int cantBicicletas;

	public:
		//Constructores
		Entrenamiento();
		Entrenamiento(int cantBicicletas);
		//Getters
		int GetCantBicicletas();
		//Setters
		void SetCantBicicletas(int cantBicicletas);
		//Operaciones
		int cupo();
		//Destructor
		~Entrenamiento();
};

