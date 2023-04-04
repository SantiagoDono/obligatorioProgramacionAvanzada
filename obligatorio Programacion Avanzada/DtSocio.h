#pragma once
#include <string>

using namespace std;

class DtSocio {
private:
    string _ci;
    string _nombre;
public:
    DtSocio();
    DtSocio(string ci, string nombre);

    string GetCi();
    string GetNombre();

    ~DtSocio();

};
