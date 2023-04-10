#include "Impresiones.h"
#include <ostream>
using namespace std;

ostream& operator<<(ostream& os,  DtFecha fecha) {
	os << "Fecha: " << fecha.GetDia() << "-" << fecha.GetMes() << "-" << fecha.GetAnio() << endl;
	return os;
}
ostream& operator<<(ostream& os, DtSocio socio) {
    os << "Socio->Cedula: " << socio.GetCi() << endl;
    os << "Socio->Nombre: " << socio.GetNombre() << endl;
    return os;
}
ostream& operator<<(ostream& os, DtSpinning spinning) {
    string turno;
    switch (spinning.GetTurno())
    {
        case Manana:
            turno = "Manana";
            break;
        case Tarde:
            turno = "Tarde";
            break;
        case Noche:
            turno = "Noche";
            break;
    }
    os << "Clase->ID: " << spinning.GetId() << endl;
    os << "Clase->Nombre: " << spinning.GetNombre() << endl;
    os << "Clase->Turno: " << turno << endl;
    os << "Clase->Cant. Bicicletas: " << spinning.GetCantBicicletas() << endl;
    os << "Clase->Cant. Inscripciones: " << spinning.GetCantInscripciones() << endl;
    return os;
}
ostream& operator<<(ostream& os, DtEntrenamiento entrenamiento) {
    string enRambla = "No";
    string turno;
    switch (entrenamiento.GetTurno())
    {
        case Manana:
            turno = "Manana";
            break;
        case Tarde:
            turno = "Tarde";
            break;
        case Noche:
            turno = "Noche";
            break;
    }
    os << "Clase->ID: " << entrenamiento.GetId() << endl;
    os << "Clase->Nombre: " << entrenamiento.GetNombre() << endl;
    os << "Clase->Turno: " << turno << endl;
    if (entrenamiento.GetEnRambla())
         enRambla = "Si";
    os << "Clase->En rambla?: " << enRambla << endl;
    os << "Clase->Cant. Inscripciones: " << entrenamiento.GetCantInscripciones() << endl;
    return os;
}