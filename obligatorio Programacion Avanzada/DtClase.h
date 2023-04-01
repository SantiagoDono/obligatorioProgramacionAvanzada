#include <string>
#include <list>
#include "EnumTurno.h"


using namespace std;

class DtClase
{
private:
    int _id;
    string _nombre;
    enumTurno _turno;
// list<Inscripcion *> _inscripciones;

public:
    DtClase(int  id, string nombre, enumTurno turno);
    ~DtClase();
};