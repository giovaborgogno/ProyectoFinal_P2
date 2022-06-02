#include <iostream>
#include "administrativos.h"
using namespace std;

ADMINISTRATIVO::ADMINISTRATIVO(string Nombre, string Apellido, int Dni, string Email, string Puesto, float Sueldo)
{
    this->Nombre = Nombre;
    this->Apellido = Apellido;
    this->Dni = Dni;
    this->Email = Email;
    this->Puesto = Puesto;
    this->Sueldo = Sueldo;
    C = new CUENTASUELDO;
    C->Acreditacion(Sueldo);
}

string ADMINISTRATIVO::getPuesto()
{
    return Puesto;
}

void ADMINISTRATIVO::setPuesto(string Puesto)
{
    this->Puesto = Puesto;
}
