#pragma once
#include "Clase.h"
class Entrenamiento :public Clase
{
	private:
		bool _enRambla;

	public:
		//Constructores
		Entrenamiento();
		Entrenamiento(
			bool enRambla, 
			int id, 
			string nombre, 
			enumTurno turno, 
			list<Inscripcion*> inscripciones);

		//Getters
		bool GetEnRambla();

		//Setters
		void SetEnRambla(bool enRambla);

		//Operaciones
		int Cupo();
		void InsertarInscripcion(Inscripcion* inscripcion);

		//Destructor
		~Entrenamiento();
};

