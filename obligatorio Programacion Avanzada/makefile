 # Dependencias
CONSTANTES = Constantes.h

# Objetivo
todo: Main.o Entrenamiento.o Spinning.o Clase.o Inscripcion.o Socio.o DtFecha.o DtClase.o DtEntrenamiento.o DtSpinning.o DtSocio.o DtInscripcion.o Impresiones.o Sistema.o
	g++ -Wall -o main Main.o Entrenamiento.o Spinning.o Clase.o Inscripcion.o Socio.o DtFecha.o DtClase.o DtEntrenamiento.o DtSpinning.o DtSocio.o DtInscripcion.o Impresiones.o Sistema.o

# Principal
Main.o: Main.cpp Sistema.h Sistema.h
	g++ -Wall -c Main.cpp

# Clases
Entrenamiento.o: Entrenamiento.cpp Entrenamiento.h Clase.h DtInscripcion.h $(CONSTANTES)
	g++ -Wall -c Entrenamiento.cpp
Spinning.o: Spinning.cpp Spinning.h DtInscripcion.h Clase.h $(CONSTANTES)
	g++ -Wall -c Spinning.cpp
Clase.o: Clase.cpp Clase.h EnumTurno.h Inscripcion.h $(CONSTANTES)
	g++ -Wall -c Clase.cpp
Inscripcion.o: Inscripcion.cpp Inscripcion.h EnumTurno.h DtSocio.h DtFecha.h $(CONSTANTES) 
	g++ -Wall -c Inscripcion.cpp
Socio.o: Socio.cpp Socio.h $(CONSTANTES)
	g++ -Wall -c Socio.cpp 

# Data Types
DtFecha.o: DtFecha.cpp DtFecha.h $(CONSTANTES)
	g++ -Wall -c DtFecha.cpp

DtSocio.o: DtSocio.cpp DtSocio.h $(CONSTANTES)
	g++ -Wall -c DtSocio.cpp

DtClase.o: DtClase.cpp DtClase.h $(CONSTANTES)
	g++ -Wall -c DtClase.cpp

DtEntrenamiento.o: DtEntrenamiento.cpp DtEntrenamiento.h $(CONSTANTES)
	g++ -Wall -c DtEntrenamiento.cpp

DtSpinning.o: DtSpinning.cpp DtSpinning.h $(CONSTANTES)
	g++ -Wall -c DtSpinning.cpp

DtInscripcion.o: DtInscripcion.cpp DtInscripcion.h $(CONSTANTES)
	g++ -Wall -c DtInscripcion.cpp

# Servicios
Sistema.o: Sistema.cpp Sistema.h Socio.h Spinning.h Entrenamiento.h Impresiones.h $(CONSTANTES)
	g++ -Wall -c Sistema.cpp

# Sistema
Sistema.o: Sistema.cpp Sistema.h Impresiones.h $(CONSTANTES)
	g++ -Wall -c Sistema.cpp

# Impresiones
Impresiones.o: Impresiones.cpp Impresiones.h $(CONSTANTES)
	g++ -Wall -c Impresiones.cpp

# Limpieza
clean:
	rm -f *.o
	rm -f main