#include <iostream>
#include <fstream>
#include "basededatos.h"
using namespace std;

int ProfDBIndex = 0;
int AdminDBIndex = 0;
ofstream file;

BASEDEDATOS::BASEDEDATOS(int DBSize){
  ProfDB = new PROFESIONAL*[DBSize];
  AdminDB = new ADMINISTRATIVO*[DBSize];
}

void BASEDEDATOS::AgregarPROFESIONAL(string Nombre, string Apellido, int Dni, string Email, string Titulo, string Actividad, int TiempoServicio, float Sueldo){
  ProfDB[ProfDBIndex] = new PROFESIONAL(Nombre,Apellido,Email,Dni,Titulo,Actividad,TiempoServicio,Sueldo);
  ProfDBIndex++;
}

void BASEDEDATOS::AgregarADMINISTRATIVO(string Nombre, string Apellido, int Dni, string Email, string Puesto, float Sueldo){
  AdminDB[AdminDBIndex] = new ADMINISTRATIVO(Nombre,Apellido,Dni,Email,Puesto,Sueldo);
  AdminDBIndex++;
}

void BASEDEDATOS::PrintPROFESIONALES(){

    file.open("Profesionales.csv", ios::out);

    file << "Nro de Cuenta,Estado,DNI,Apellido,Nombre,Puesto,Sueldo,Saldo,Email"<<endl;
        for (int x = 0; x < ProfDBIndex; x++)
    {
        file <<ProfDB[x]->C->getNumeroDeCuenta()
        << "," << ProfDB[x]->C->getEstado()
        << "," << ProfDB[x]->getDni()
        << "," << ProfDB[x]->getApellido()
        << "," << ProfDB[x]->getNombre()
        << "," << ProfDB[x]->getPuesto()
        << "," << ProfDB[x]->getSueldo()
        << "," << ProfDB[x]->C->getSaldo()
        << "," << ProfDB[x]->getEmail() << endl;
    }
    file.close();
}

void BASEDEDATOS::PrintADMINISTRATIVOS(){

    file.open("Administrativos.csv", ios::out);

    file << "Nro de Cuenta,Estado,DNI,Apellido,Nombre,Puesto,Sueldo,Saldo,Email"<<endl;
        for (int x = 0; x < AdminDBIndex; x++)
    {
        file <<AdminDB[x]->C->getNumeroDeCuenta()
        << "," << AdminDB[x]->C->getEstado()
        << "," << AdminDB[x]->getDni()
        << "," << AdminDB[x]->getApellido()
        << "," << AdminDB[x]->getNombre()
        << "," << AdminDB[x]->getPuesto()
        << "," << AdminDB[x]->getSueldo()
        << "," << AdminDB[x]->C->getSaldo()
        << "," << AdminDB[x]->getEmail() << endl;
    }
    file.close();
}

void BASEDEDATOS::PrintClientesDeAlta(){

    file.open("ClientesDeAlta.csv", ios::out);

    file << "Nro de Cuenta,DNI,Apellido,Nombre,Sueldo,Saldo,Email"<<endl;

        for (int x = 0; x < AdminDBIndex; x++)
    {
      if(AdminDB[x]->C->getEstado()=='A')
        file<<AdminDB[x]->C->getNumeroDeCuenta()
        << "," << AdminDB[x]->getDni()
        << "," << AdminDB[x]->getApellido()
        << "," << AdminDB[x]->getNombre()
        << "," << AdminDB[x]->getSueldo()
        << "," << AdminDB[x]->C->getSaldo()
        << "," << AdminDB[x]->getEmail() << endl;
    }
            for (int x = 0; x < ProfDBIndex; x++)
    {
      if(ProfDB[x]->C->getEstado()=='A')
        file<<ProfDB[x]->C->getNumeroDeCuenta()
        << "," << ProfDB[x]->getDni()
        << "," << ProfDB[x]->getApellido()
        << "," << ProfDB[x]->getNombre()
        << "," << ProfDB[x]->getSueldo()
        << "," << ProfDB[x]->C->getSaldo()
        << "," << ProfDB[x]->getEmail() << endl;
    }
    file.close();
}

void BASEDEDATOS::PrintClientesDeBaja(){

    file.open("ClientesDeBaja.csv", ios::out);

    file << "Nro de Cuenta,DNI,Apellido,Nombre,Sueldo,Saldo,Email"<<endl;

        for (int x = 0; x < AdminDBIndex; x++)
    {
      if(AdminDB[x]->C->getEstado()=='B')
        file<<AdminDB[x]->C->getNumeroDeCuenta()
        << "," << AdminDB[x]->getDni()
        << "," << AdminDB[x]->getApellido()
        << "," << AdminDB[x]->getNombre()
        << "," << AdminDB[x]->getSueldo()
        << "," << AdminDB[x]->C->getSaldo()
        << "," << AdminDB[x]->getEmail() << endl;
    }
            for (int x = 0; x < ProfDBIndex; x++)
    {
      if(ProfDB[x]->C->getEstado()=='B')
        file<<ProfDB[x]->C->getNumeroDeCuenta()
        << "," << ProfDB[x]->getDni()
        << "," << ProfDB[x]->getApellido()
        << "," << ProfDB[x]->getNombre()
        << "," << ProfDB[x]->getSueldo()
        << "," << ProfDB[x]->C->getSaldo()
        << "," << ProfDB[x]->getEmail() << endl;
    }
    file.close();
}
