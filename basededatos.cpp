#include <iostream>
#include "basededatos.h"
using namespace std;

int ProfDBIndex = 0;
int AdminDBIndex = 0;

BASEDEDATOS::BASEDEDATOS(int DBSize){
  ProfDB = new PROFESIONAL*[P_DBSize];
  AdminDB = new ADMINISTRATIVO*[A_DBSize];
}

void BASEDEDATOS::AgregarPROFESIONAL(string Nombre, string Apellido, string Email, int Dni, string Titulo, string Actividad, int TiempoServicio, float Sueldo){
  ProfDB[ProfDBIndex] = new PROFESIONAL(Nombre,Apellido,Email,Dni,Titulo,Actividad,TiempoServicio,Sueldo);
  ProfDBIndex++;
}

void BASEDEDATOS::AgregarADMINISTRATIVO(string Nombre, string Apellido, int Dni, string Email, string Puesto, float Sueldo){
  AdminDB[AdminDBIndex] = new ADMINISTRATIVO(Nombre,Apellido,Dni,Email,Puesto,Sueldo);
  AdminDBIndex++;
}
