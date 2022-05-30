#include <iostream>
#include "administrativos.h"
using namespace std;

ADMINISTRATIVO::ADMINISTRATIVO(string Nombre, string Apellido, int Dni, string Email, string Puesto)
{
    this->Nombre = Nombre;
    this->Apellido = Apellido;
    this->Dni = Dni;
    this->Email=Email;
    this->Puesto = Puesto;
}

string ADMINISTRATIVO::getPuesto()
{
    return Puesto;
}

void ADMINISTRATIVO::setPuesto(string Puesto)
{
    this->Puesto = Puesto;
}