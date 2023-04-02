#include "DtFecha.h"
#include "DtSocio.h"

class DtInscripcion{
    private:
        DtFecha _fecha;
		DtSocio _socio;
    public:
        DtInscripcion(DtFecha fecha, DtSocio socio);
        
        DtFecha GetFecha();
        DtSocio GetSocio();

        ~DtInscripcion();
};