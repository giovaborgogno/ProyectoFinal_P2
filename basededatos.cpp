#include <iostream>
#include <fstream>
#include "basededatos.h"
using namespace std;

int ProfDBIndex = 0;
int AdminDBIndex = 0;

BASEDEDATOS::BASEDEDATOS(int DBSize){
  ProfDB = new PROFESIONAL*[DBSize];
  AdminDB = new ADMINISTRATIVO*[DBSize];
}

void BASEDEDATOS::AgregarPROFESIONAL(string Nombre, string Apellido, string Email, int Dni, string Titulo, string Actividad, int TiempoServicio, float Sueldo){
  ProfDB[ProfDBIndex] = new PROFESIONAL(Nombre,Apellido,Email,Dni,Titulo,Actividad,TiempoServicio,Sueldo);
  ProfDBIndex++;
}

void BASEDEDATOS::AgregarADMINISTRATIVO(string Nombre, string Apellido, int Dni, string Email, string Puesto, float Sueldo){
  AdminDB[AdminDBIndex] = new ADMINISTRATIVO(Nombre,Apellido,Dni,Email,Puesto,Sueldo);
  AdminDBIndex++;
}

void BASEDEDATOS::PrintADMINISTRATIVOS(){
ofstream administrativoscsv;

    administrativoscsv.open("Administrativos.csv", ios::out);

    administrativoscsv << "Nro de Cuenta,Estado,DNI,Apellido,Nombre,Puesto,Sueldo,Saldo,Email"<<endl;
        for (int x = 0; x < AdminDBIndex; x++)
    {
        administrativoscsv <<AdminDB[x]->C->getNumeroDeCuenta() << "," << AdminDB[x]->C->getEstado() << "," << AdminDB[x]->getDni() << "," << AdminDB[x]->getApellido()<< "," << AdminDB[x]->getNombre() << "," << AdminDB[x]->getPuesto()<< "," << AdminDB[x]->getSueldo()<< "," << AdminDB[x]->C->getSaldo()<< "," << AdminDB[x]->getEmail() << endl;
    }
    administrativoscsv.close();
}

void BASEDEDATOS::PrintClientesDeAlta(){
ofstream altacsv;

    altacsv.open("ClientesDeAlta.csv", ios::out);

    altacsv << "Nro de Cuenta,DNI,Apellido,Nombre,Sueldo,Saldo,Email"<<endl;
    
        for (int x = 0; x < AdminDBIndex; x++)
    {
      if(AdminDB[x]->C->getEstado()=='A')
        altacsv <<AdminDB[x]->C->getNumeroDeCuenta() <<  "," << AdminDB[x]->getDni() << "," << AdminDB[x]->getApellido()<< "," << AdminDB[x]->getNombre() << ","  << AdminDB[x]->getSueldo()<< "," << AdminDB[x]->C->getSaldo()<< "," << AdminDB[x]->getEmail() << endl;
    }
            for (int x = 0; x < ProfDBIndex; x++)
    {
      if(ProfDB[x]->C->getEstado()=='A')
        altacsv <<ProfDB[x]->C->getNumeroDeCuenta() <<  "," << ProfDB[x]->getDni() << "," << ProfDB[x]->getApellido()<< "," << ProfDB[x]->getNombre() << ","  << ProfDB[x]->getSueldo()<< "," << ProfDB[x]->C->getSaldo()<< "," << ProfDB[x]->getEmail() << endl;
    }
    altacsv.close();
}

void BASEDEDATOS::PrintClientesDeBaja(){
ofstream bajacsv;

    bajacsv.open("ClientesDeBaja.csv", ios::out);

    bajacsv << "Nro de Cuenta,DNI,Apellido,Nombre,Sueldo,Saldo,Email"<<endl;
    
        for (int x = 0; x < AdminDBIndex; x++)
    {
      if(AdminDB[x]->C->getEstado()=='B')
        bajacsv <<AdminDB[x]->C->getNumeroDeCuenta() <<  "," << AdminDB[x]->getDni() << "," << AdminDB[x]->getApellido()<< "," << AdminDB[x]->getNombre() << ","  << AdminDB[x]->getSueldo()<< "," << AdminDB[x]->C->getSaldo()<< "," << AdminDB[x]->getEmail() << endl;
    }
            for (int x = 0; x < ProfDBIndex; x++)
    {
      if(ProfDB[x]->C->getEstado()=='B')
        bajacsv <<ProfDB[x]->C->getNumeroDeCuenta() <<  "," << ProfDB[x]->getDni() << "," << ProfDB[x]->getApellido()<< "," << ProfDB[x]->getNombre() << ","  << ProfDB[x]->getSueldo()<< "," << ProfDB[x]->C->getSaldo()<< "," << ProfDB[x]->getEmail() << endl;
    }
    bajacsv.close();
}