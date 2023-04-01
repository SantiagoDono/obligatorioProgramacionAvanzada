# Dependencias
CONSTANTES = Constantes.h

# Objetivo
todo: Main.o Entrenamiento.o Spinning.o Clase.o Inscripcion.o Socio.o DtFecha.o
# Principal
main.o: Entrenamiento.o Main.cpp
	g++ -Wall -c Main.cpp

# Clases
Entrenamiento.o: Entrenamiento.cpp Entrenamiento.h $(CONSTANTES)
	g++ -Wall -c Entrenamiento.cpp
Spinning.o: Spinning.cpp Spinning.h $(CONSTANTES)
	g++ -Wall -c Spinning.cpp
Clase.o: Clase.cpp Clase.h $(CONSTANTES)
	g++ -Wall -c Clase.cpp
Inscripcion.o: Inscripcion.cpp Inscripcion.h EnumTurno.h $(CONSTANTES) 
	g++ -Wall -c Inscripcion.cpp
Socio.o: Socio.cpp Socio.h $(CONSTANTES)
	g++ -Wall -c Socio.cpp 
# Data Types
DtFecha.o: DtFecha.cpp DtFecha.h $(CONSTANTES)
	g++ -Wall -c DtFecha.cpp


# Limpieza
clean:
	rm -f *.o
	rm -f main