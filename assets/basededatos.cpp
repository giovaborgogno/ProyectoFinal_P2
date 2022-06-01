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
  ProfDB[ProfDBIndex] = new PROFESIONAL(Nombre,Apellido,Dni,Email,Titulo,Actividad,TiempoServicio,Sueldo);
  ProfDBIndex++;
}

void BASEDEDATOS::AgregarADMINISTRATIVO(string Nombre, string Apellido, int Dni, string Email, string Puesto, float Sueldo){
  AdminDB[AdminDBIndex] = new ADMINISTRATIVO(Nombre,Apellido,Dni,Email,Puesto,Sueldo);
  AdminDBIndex++;
}

void BASEDEDATOS::AltaCliente(int NRO){
  bool ProfCount = false;
  for(int i=0;i<ProfDBIndex;i++){
    if(ProfDB[i]->C->getEstado()=='B'){
      if(ProfDB[i]->C->getNumeroDeCuenta()==NRO){
        ProfDB[i]->C->switchEstado();
        ProfCount = true;
        break;
      }
    }
  }
  if(ProfCount == false){
    bool AdminCount = 0;
    for(int i=0;i<AdminDBIndex;i++){
      if(AdminDB[i]->C->getEstado()=='B'){
        if(AdminDB[i]->C->getNumeroDeCuenta()==NRO){
          AdminDB[i]->C->switchEstado();
          AdminCount = true;
          break;
        }
      }
    }
    if(AdminCount == false){
        cout << "El cliente ingresado no se encuentra en la lista" << endl;
    }
    else{
      cout << "Cliente dado de alta exitosamente!" << endl;
    }
  }
  else{
    cout << "Cliente dado de alta exitosamente!" << endl;
  }
}

void BASEDEDATOS::BajaCliente(int NRO){
  bool ProfCount = false;
  for(int i=0;i<ProfDBIndex;i++){
    if(ProfDB[i]->C->getEstado()=='A'){
      if(ProfDB[i]->C->getNumeroDeCuenta()==NRO){
        ProfDB[i]->C->switchEstado();
        ProfCount = true;
        break;
      }
    }
  }
  if(ProfCount == false){
    bool AdminCount = 0;
    for(int i=0;i<AdminDBIndex;i++){
      if(AdminDB[i]->C->getEstado()=='A'){
        if(AdminDB[i]->C->getNumeroDeCuenta()==NRO){
          AdminDB[i]->C->switchEstado();
          AdminCount = true;
          break;
        }
      }
    }
    if(AdminCount == false){
        cout << "El cliente ingresado no se encuentra en la lista" << endl;
    }
    else{
      cout << "Cliente dado de baja exitosamente!" << endl;
    }
  }
  else{
    cout << "Cliente dado de baja exitosamente!" << endl;
  }
}

void BASEDEDATOS::PrintPROFESIONALES(){

    file.open("output/Profesionales.csv", ios::out);

    file << "NRO;ESTADO;NOMBRE;APELLIDO;DNI;EMAIL;TITULO;ACTIVIDAD;TIEMPO DE SERVICIO;SUELDO;SALDO;PLAN"<<endl;
        for (int x = 0; x < ProfDBIndex; x++)
    {
        file <<ProfDB[x]->C->getNumeroDeCuenta()
        << ";" << ProfDB[x]->C->getEstado()
        << ";" << ProfDB[x]->getNombre()
        << ";" << ProfDB[x]->getApellido()
        << ";" << ProfDB[x]->getDni()
        << ";" << ProfDB[x]->getEmail()
        << ";" << ProfDB[x]->getTitulo()
        << ";" << ProfDB[x]->getActividad()
        << ";" << ProfDB[x]->getTiempoServicio()
        << ";" << ProfDB[x]->getSueldo()
        << ";" << ProfDB[x]->C->getSaldo()
        << ";" << ProfDB[x]->T->getTipo()<<endl;

    }
    file.close();
}

void BASEDEDATOS::PrintADMINISTRATIVOS(){

    file.open("output/Administrativos.csv", ios::out);

    file << "NRO;ESTADO;NOMBRE;APELLIDO;DNI;EMAIL;PUESTO;SUELDO;SALDO"<<endl;
        for (int x = 0; x < AdminDBIndex; x++)
    {
        file <<AdminDB[x]->C->getNumeroDeCuenta()
        << ";" << AdminDB[x]->C->getEstado()
        << ";" << AdminDB[x]->getNombre()
        << ";" << AdminDB[x]->getApellido()
        << ";" << AdminDB[x]->getDni()
        << ";" << AdminDB[x]->getEmail()
        << ";" << AdminDB[x]->getPuesto()
        << ";" << AdminDB[x]->getSueldo()
        << ";" << AdminDB[x]->C->getSaldo()<< endl;
    }
    file.close();
}

void BASEDEDATOS::PrintClientesDeAlta(bool opt){
    // 1 = CSV / 0 = Terminal
    switch(opt){
      case 1:
        file.open("output/ClientesDeAlta.csv", ios::out);

        file << "NRO;NOMBRE;APELLIDO;DNI;EMAIL;SUELDO;SALDO"<<endl;

            for (int x = 0; x < AdminDBIndex; x++)
        {
          if(AdminDB[x]->C->getEstado()=='A')
            file<<AdminDB[x]->C->getNumeroDeCuenta()
            << ";" << AdminDB[x]->getNombre()
            << ";" << AdminDB[x]->getApellido()
            << ";" << AdminDB[x]->getDni()
            << ";" << AdminDB[x]->getEmail()
            << ";" << AdminDB[x]->getSueldo()
            << ";" << AdminDB[x]->C->getSaldo()<< endl;
        }
                for (int x = 0; x < ProfDBIndex; x++)
        {
          if(ProfDB[x]->C->getEstado()=='A')
            file<<ProfDB[x]->C->getNumeroDeCuenta()
            << ";" << ProfDB[x]->getNombre()
            << ";" << ProfDB[x]->getApellido()
            << ";" << ProfDB[x]->getDni()
            << ";" << ProfDB[x]->getEmail()
            << ";" << ProfDB[x]->getSueldo()
            << ";" << ProfDB[x]->C->getSaldo()<< endl;
        }
        file.close();
        break;
      case 0:

        break;
  }
}

void BASEDEDATOS::PrintClientesDeBaja(bool opt){
    // 1 = CSV / 0 = Terminal
    switch(opt){
      case 1:
        file.open("output/ClientesDeBaja.csv", ios::out);

        file << "NRO;NOMBRE;APELLIDO;DNI;EMAIL;SUELDO;SALDO"<<endl;

            for (int x = 0; x < AdminDBIndex; x++)
        {
          if(AdminDB[x]->C->getEstado()=='B')
            file<<AdminDB[x]->C->getNumeroDeCuenta()
            << ";" << AdminDB[x]->getNombre()
            << ";" << AdminDB[x]->getApellido()
            << ";" << AdminDB[x]->getDni()
            << ";" << AdminDB[x]->getEmail()
            << ";" << AdminDB[x]->getSueldo()
            << ";" << AdminDB[x]->C->getSaldo()<< endl;
        }
                for (int x = 0; x < ProfDBIndex; x++)
        {
          if(ProfDB[x]->C->getEstado()=='B')
            file<<ProfDB[x]->C->getNumeroDeCuenta()
            << ";" << ProfDB[x]->getNombre()
            << ";" << ProfDB[x]->getApellido()
            << ";" << ProfDB[x]->getDni()
            << ";" << ProfDB[x]->getEmail()
            << ";" << ProfDB[x]->getSueldo()
            << ";" << ProfDB[x]->C->getSaldo()<< endl;
        }
        file.close();
        break;
      case 0:

        break;
  }
}

void BASEDEDATOS::PrintDB(){

    file.open("output/BaseDeDatos.csv", ios::out);

    file << "NRO;ESTADO;NOMBRE;APELLIDO;DNI;EMAIL;SUELDO;SALDO"<<endl;

        for (int x = 0; x < AdminDBIndex; x++)
    {
        file<<AdminDB[x]->C->getNumeroDeCuenta()
        << ";" << AdminDB[x]->C->getEstado()
        << ";" << AdminDB[x]->getNombre()
        << ";" << AdminDB[x]->getApellido()
        << ";" << AdminDB[x]->getDni()
        << ";" << AdminDB[x]->getEmail()
        << ";" << AdminDB[x]->getSueldo()
        << ";" << AdminDB[x]->C->getSaldo()<< endl;
    }
        for (int x = 0; x < ProfDBIndex; x++)
    {
        file<<ProfDB[x]->C->getNumeroDeCuenta()
        << ";" << ProfDB[x]->C->getEstado()
        << ";" << ProfDB[x]->getNombre()
        << ";" << ProfDB[x]->getApellido()
        << ";" << ProfDB[x]->getDni()
        << ";" << ProfDB[x]->getEmail()
        << ";" << ProfDB[x]->getSueldo()
        << ";" << ProfDB[x]->C->getSaldo()<< endl;
    }
    file.close();
  }