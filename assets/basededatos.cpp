#include <iostream>
#include <fstream>
#include <iomanip>
#include "basededatos.h"
using namespace std;

int ProfDBIndex = 0;
int AdminDBIndex = 0;
ofstream file;

int Campo=15, EmailCampo=30, DniCampo=9;

BASEDEDATOS::BASEDEDATOS(int DBSize){
  ProfDB = new PROFESIONAL*[DBSize];
  AdminDB = new ADMINISTRATIVO*[DBSize];
}

void BASEDEDATOS::AgregarPROFESIONAL(string Nombre, string Apellido, int Dni, string Email, string Titulo, string Actividad, int TiempoServicio, float Sueldo, char TarjetaSN){
  ProfDB[ProfDBIndex] = new PROFESIONAL(Nombre,Apellido,Dni,Email,Titulo,Actividad,TiempoServicio,Sueldo,TarjetaSN);
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
        cout << endl << "El cliente ingresado no se encuentra en la lista" << endl;
    }
    else{
      cout << endl << "Cliente dado de alta exitosamente!" << endl;
    }
  }
  else{
    cout << endl << "Cliente dado de alta exitosamente!" << endl;
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
        cout << endl << "El cliente ingresado no se encuentra en la lista" << endl;
    }
    else{
      cout << endl << "Cliente dado de baja exitosamente!" << endl;
    }
  }
  else{
    cout << endl << "Cliente dado de baja exitosamente!" << endl;
  }
}

void BASEDEDATOS::PrintPROFESIONALES(bool opt){
  switch(opt){
    case 1:
      file.open("output/Profesionales.csv", ios::out);
      if(file.fail()){
        cout<<"No se pudo abrir el archivo 'Profesionales.csv'";
        exit(1);
      }
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
      break;
    case 0:
      cout << "NRO"
      << '\t' << "ESTADO         "
      << '\t' << "NOMBRE         "
      << '\t' << "APELLIDO       "
      << '\t' << "DNI      "
      << '\t' << "EMAIL                    "
      << '\t' << "TITULO         "
      << '\t' << "ACTIVIDAD      "
      << '\t' << "TIEMPO SERVICIO"
      << '\t' << "SUELDO         "
      << '\t' << "SALDO          "
      << '\t' << "TIPO           " << endl;

      for(int i=0; i<ProfDBIndex; i++){
        if(ProfDB[i]->C->getEstado()=='A'){
          cout << ProfDB[i]->C->getNumeroDeCuenta() << setw(3-to_string(ProfDB[i]->C->getNumeroDeCuenta()).length())
          << '\t' << ProfDB[i]->C->getEstado() << setw(Campo-to_string(ProfDB[i]->C->getEstado()).length())
          << '\t' << ProfDB[i]->getNombre() << setw(Campo-ProfDB[i]->getNombre().length())
          << '\t' << ProfDB[i]->getApellido() << setw(Campo-ProfDB[i]->getApellido().length())
          << '\t' << ProfDB[i]->getDni() << setw(DniCampo-to_string(ProfDB[i]->getDni()).length())
          << '\t' << ProfDB[i]->getEmail() << setw(EmailCampo-ProfDB[i]->getEmail().length())
          << '\t' << ProfDB[i]->getTitulo() << setw(Campo-ProfDB[i]->getTitulo().length())
          << '\t' << ProfDB[i]->getActividad() << setw(Campo-ProfDB[i]->getActividad().length())
          << '\t' << ProfDB[i]->getTiempoServicio() << setw(Campo-to_string(ProfDB[i]->getTiempoServicio()).length())
          << '\t' << ProfDB[i]->getSueldo() << setw((Campo+7)-to_string(ProfDB[i]->getSueldo()).length())
          << '\t' << ProfDB[i]->C->getSaldo() << setw(Campo-to_string(ProfDB[i]->C->getSaldo()).length())
          << '\t' << ProfDB[i]->T->getTipo() << setw(Campo-(ProfDB[i]->T->getTipo()).length()) << '\n';
          cout.flush();
        }
      }
      break;
    }
  }

  void BASEDEDATOS::PrintADMINISTRATIVOS(bool opt){
    switch(opt){
      case 1:
        file.open("output/Administrativos.csv", ios::out);
        if(file.fail()){
          cout<<"No se pudo abrir el archivo 'Administrativos.csv'";
          exit(1);
        }
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
        break;
      case 0:
      cout << "NRO"
      << '\t' << "ESTADO         "
      << '\t' << "NOMBRE         "
      << '\t' << "APELLIDO       "
      << '\t' << "DNI      "
      << '\t' << "EMAIL                    "
      << '\t' << "PUESTO         "
      << '\t' << "SUELDO         "
      << '\t' << "SALDO          " << endl;

      for(int i=0; i<AdminDBIndex; i++){
        if(AdminDB[i]->C->getEstado()=='A'){
          cout << AdminDB[i]->C->getNumeroDeCuenta() << setw(3-to_string(AdminDB[i]->C->getNumeroDeCuenta()).length())
          << '\t' << AdminDB[i]->C->getEstado() << setw(Campo-to_string(AdminDB[i]->C->getEstado()).length())
          << '\t' << AdminDB[i]->getNombre() << setw(Campo-AdminDB[i]->getNombre().length())
          << '\t' << AdminDB[i]->getApellido() << setw(Campo-AdminDB[i]->getApellido().length())
          << '\t' << AdminDB[i]->getDni() << setw(DniCampo-to_string(AdminDB[i]->getDni()).length())
          << '\t' << AdminDB[i]->getEmail() << setw(EmailCampo-AdminDB[i]->getEmail().length())
          << '\t' << AdminDB[i]->getPuesto() << setw(Campo-AdminDB[i]->getPuesto().length())
          << '\t' << AdminDB[i]->getSueldo() << setw((Campo+7)-to_string(AdminDB[i]->getSueldo()).length())
          << '\t' << AdminDB[i]->C->getSaldo() << setw(Campo-to_string(AdminDB[i]->C->getSaldo()).length()) << '\n';
          cout.flush();
        }
      }
        break;
    }
  }

void BASEDEDATOS::PrintClientesDeAlta(bool opt){
    // 1 = CSV / 0 = Terminal
    switch(opt){
      case 1:
        file.open("output/ClientesDeAlta.csv", ios::out);
        if(file.fail()){
          cout<<"No se pudo abrir el archivo 'ClientesDeAlta.csv'";
          exit(1);
        }
        file << "NRO;NOMBRE;APELLIDO;DNI;EMAIL;SUELDO;SALDO"<<endl;
        for (int x = 0; x < AdminDBIndex; x++)
        {
          if(AdminDB[x]->C->getEstado()=='A'){
            file<<AdminDB[x]->C->getNumeroDeCuenta()
            << ";" << AdminDB[x]->getNombre()
            << ";" << AdminDB[x]->getApellido()
            << ";" << AdminDB[x]->getDni()
            << ";" << AdminDB[x]->getEmail()
            << ";" << AdminDB[x]->getSueldo()
            << ";" << AdminDB[x]->C->getSaldo()<< endl;
          }
        }
        for (int x = 0; x < ProfDBIndex; x++)
        {
          if(ProfDB[x]->C->getEstado()=='A'){
            file<<ProfDB[x]->C->getNumeroDeCuenta()
            << ";" << ProfDB[x]->getNombre()
            << ";" << ProfDB[x]->getApellido()
            << ";" << ProfDB[x]->getDni()
            << ";" << ProfDB[x]->getEmail()
            << ";" << ProfDB[x]->getSueldo()
            << ";" << ProfDB[x]->C->getSaldo()<< endl;
          }
        }
        file.close();
        break;

      case 0:
      //impresion en terminal
      cout << "NRO"
      << '\t' << "NOMBRE         "
      << '\t' << "APELLIDO       "
      << '\t' << "DNI      "
      << '\t' << "EMAIL                    "
      << '\t' << "SUELDO         "
      << '\t' << "SALDO          " << endl;
      for(int i=0; i<AdminDBIndex; i++){
        if(AdminDB[i]->C->getEstado()=='A'){
          cout << AdminDB[i]->C->getNumeroDeCuenta() << setw(3-to_string(AdminDB[i]->C->getNumeroDeCuenta()).length())
          << '\t' << AdminDB[i]->getNombre() << setw(Campo-AdminDB[i]->getNombre().length())
          << '\t' << AdminDB[i]->getApellido() << setw(Campo-AdminDB[i]->getApellido().length())
          << '\t' << AdminDB[i]->getDni() << setw(DniCampo-to_string(AdminDB[i]->getDni()).length())
          << '\t' << AdminDB[i]->getEmail() << setw(EmailCampo-AdminDB[i]->getEmail().length())
          << '\t' << AdminDB[i]->getSueldo() << setw((Campo+7)-to_string(AdminDB[i]->getSueldo()).length())
          << '\t' << AdminDB[i]->C->getSaldo() << setw(Campo-to_string(AdminDB[i]->C->getSaldo()).length()) << '\n';
          cout.flush();
        }
      }
      for(int i=0; i<ProfDBIndex; i++){
        if(ProfDB[i]->C->getEstado()=='A'){
          cout << ProfDB[i]->C->getNumeroDeCuenta() << setw(3-to_string(ProfDB[i]->C->getNumeroDeCuenta()).length())
          << '\t' << ProfDB[i]->getNombre() << setw(Campo-ProfDB[i]->getNombre().length())
          << '\t' << ProfDB[i]->getApellido() << setw(Campo-ProfDB[i]->getApellido().length())
          << '\t' << ProfDB[i]->getDni() << setw(DniCampo-to_string(ProfDB[i]->getDni()).length())
          << '\t' << ProfDB[i]->getEmail() << setw(EmailCampo-ProfDB[i]->getEmail().length())
          << '\t' << ProfDB[i]->getSueldo() << setw((Campo+7)-to_string(ProfDB[i]->getSueldo()).length())
          << '\t' << ProfDB[i]->C->getSaldo() << setw(Campo-to_string(ProfDB[i]->C->getSaldo()).length()) << '\n';
          cout.flush();
        }
      }

        break;
  }
}

void BASEDEDATOS::PrintClientesDeBaja(bool opt){
    // 1 = CSV / 0 = Terminal
    switch(opt){
      case 1:
        file.open("output/ClientesDeBaja.csv", ios::out);
        if(file.fail()){
          cout<<"No se pudo abrir el archivo 'ClientesDeBaja.csv'";
          exit(1);
        }
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
      //impresion en terminal
      cout << "NRO"
      << '\t' << "NOMBRE         "
      << '\t' << "APELLIDO       "
      << '\t' << "DNI      "
      << '\t' << "EMAIL                    "
      << '\t' << "SUELDO         "
      << '\t' << "SALDO          " << endl;
      for(int i=0; i<AdminDBIndex; i++){
        if(AdminDB[i]->C->getEstado()=='B'){
          cout << AdminDB[i]->C->getNumeroDeCuenta() << setw(3-to_string(AdminDB[i]->C->getNumeroDeCuenta()).length())
          << '\t' << AdminDB[i]->getNombre() << setw(Campo-AdminDB[i]->getNombre().length())
          << '\t' << AdminDB[i]->getApellido() << setw(Campo-AdminDB[i]->getApellido().length())
          << '\t' << AdminDB[i]->getDni() << setw(DniCampo-to_string(AdminDB[i]->getDni()).length())
          << '\t' << AdminDB[i]->getEmail() << setw(EmailCampo-AdminDB[i]->getEmail().length())
          << '\t' << AdminDB[i]->getSueldo() << setw((Campo+7)-to_string(AdminDB[i]->getSueldo()).length())
          << '\t' << AdminDB[i]->C->getSaldo() << setw(Campo-to_string(AdminDB[i]->C->getSaldo()).length()) << endl;
          cout.flush();
        }
      }
      for(int i=0; i<ProfDBIndex; i++){
        if(ProfDB[i]->C->getEstado()=='B'){
          cout << ProfDB[i]->C->getNumeroDeCuenta() << setw(3-to_string(ProfDB[i]->C->getNumeroDeCuenta()).length())
          << '\t' << ProfDB[i]->getNombre() << setw(Campo-ProfDB[i]->getNombre().length())
          << '\t' << ProfDB[i]->getApellido() << setw(Campo-ProfDB[i]->getApellido().length())
          << '\t' << ProfDB[i]->getDni() << setw(DniCampo-to_string(ProfDB[i]->getDni()).length())
          << '\t' << ProfDB[i]->getEmail() << setw(EmailCampo-ProfDB[i]->getEmail().length())
          << '\t' << ProfDB[i]->getSueldo() << setw((Campo+7)-to_string(ProfDB[i]->getSueldo()).length())
          << '\t' << ProfDB[i]->C->getSaldo() << setw(Campo-to_string(ProfDB[i]->C->getSaldo()).length()) << endl;
        }
      }
        break;
  }
}

void BASEDEDATOS::PrintDB(bool opt){
  switch(opt){
    case 1:
      file.open("output/BaseDeDatos.csv", ios::out);
      if(file.fail()){
        cout<<"No se pudo abrir el archivo 'BaseDeDatos.csv'";
        exit(1);
      }
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
      break;
    case 0:
      cout << "NRO"
      << '\t' << "NOMBRE         "
      << '\t' << "APELLIDO       "
      << '\t' << "DNI      "
      << '\t' << "EMAIL                    "
      << '\t' << "SUELDO         "
      << '\t' << "SALDO          " << endl;
      for(int i=0; i<AdminDBIndex; i++){
        if(AdminDB[i]->C->getEstado()=='A'){
          cout << AdminDB[i]->C->getNumeroDeCuenta() << setw(3-to_string(AdminDB[i]->C->getNumeroDeCuenta()).length())
          << '\t' << AdminDB[i]->getNombre() << setw(Campo-AdminDB[i]->getNombre().length())
          << '\t' << AdminDB[i]->getApellido() << setw(Campo-AdminDB[i]->getApellido().length())
          << '\t' << AdminDB[i]->getDni() << setw(DniCampo-to_string(AdminDB[i]->getDni()).length())
          << '\t' << AdminDB[i]->getEmail() << setw(EmailCampo-AdminDB[i]->getEmail().length())
          << '\t' << AdminDB[i]->getSueldo() << setw((Campo+7)-to_string(AdminDB[i]->getSueldo()).length())
          << '\t' << AdminDB[i]->C->getSaldo() << setw(Campo-to_string(AdminDB[i]->C->getSaldo()).length()) << '\n';
          cout.flush();
        }
      }
      for(int i=0; i<ProfDBIndex; i++){
        if(ProfDB[i]->C->getEstado()=='A'){
          cout << ProfDB[i]->C->getNumeroDeCuenta() << setw(3-to_string(ProfDB[i]->C->getNumeroDeCuenta()).length())
          << '\t' << ProfDB[i]->getNombre() << setw(Campo-ProfDB[i]->getNombre().length())
          << '\t' << ProfDB[i]->getApellido() << setw(Campo-ProfDB[i]->getApellido().length())
          << '\t' << ProfDB[i]->getDni() << setw(DniCampo-to_string(ProfDB[i]->getDni()).length())
          << '\t' << ProfDB[i]->getEmail() << setw(EmailCampo-ProfDB[i]->getEmail().length())
          << '\t' << ProfDB[i]->getSueldo() << setw((Campo+7)-to_string(ProfDB[i]->getSueldo()).length())
          << '\t' << ProfDB[i]->C->getSaldo() << setw(Campo-to_string(ProfDB[i]->C->getSaldo()).length()) << '\n';
          cout.flush();
        }
      }
      break;
    }
  }

bool BASEDEDATOS::isClient(int NRO){
  for(int i=0;i<ProfDBIndex;i++){
    if(ProfDB[i]->C->getEstado()=='A'){
      if(ProfDB[i]->C->getNumeroDeCuenta()==NRO){
        return true;
      }
    }
  }
  for(int i=0;i<AdminDBIndex;i++){
    if(AdminDB[i]->C->getEstado()=='A'){
      if(AdminDB[i]->C->getNumeroDeCuenta()==NRO){
        return true;
      }
    }
  }
  return false;
}

CLIENTE* BASEDEDATOS::GetCliente(int NRO){
  CLIENTE *Cl;
  bool ProfCount = false;
  for(int i=0;i<ProfDBIndex;i++){
    if(ProfDB[i]->C->getEstado()=='A'){
      if(ProfDB[i]->C->getNumeroDeCuenta()==NRO){
        Cl = ProfDB[i];
        return Cl;
      }
    }
  }
  if(ProfCount == false){
    bool AdminCount = false;
    for(int i=0;i<AdminDBIndex;i++){
      if(AdminDB[i]->C->getEstado()=='A'){
        if(AdminDB[i]->C->getNumeroDeCuenta()==NRO){
          Cl = AdminDB[i];
          return Cl;
        }
      }
    }
  }
}
