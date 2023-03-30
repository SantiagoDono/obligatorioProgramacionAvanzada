#include "Entrenamiento.h"

//Constructores
Entrenamiento::Entrenamiento() {
	cantBicicletas = 0;
}
Entrenamiento::Entrenamiento(int cantBicicletas) {
	this->cantBicicletas = cantBicicletas;
}
//Getters
int Entrenamiento::GetCantBicicletas() {
	return cantBicicletas;
}
//Setters
void Entrenamiento::SetCantBicicletas(int cantBicicletas) {
	this->cantBicicletas = cantBicicletas;
}
//Operaciones
int Entrenamiento::cupo() {
	return cantBicicletas;
}
//Destructor
Entrenamiento::~Entrenamiento(){}

