#include <iostream>
#include "assets/validacion.cpp"
#include "assets/basededatos.cpp"

using namespace std;

int main(){

  BASEDEDATOS DB(3);
  DB.AgregarADMINISTRATIVO("Santi","Lucero",44653137,"Email@gmail.com","Jefe" ,8000000);
  DB.AgregarADMINISTRATIVO("Santi","Lucero",44653137,"Email@gmail.com","Jefe" ,8000000);
  DB.AgregarADMINISTRATIVO("Santi","Lucero",44653137,"Email@gmail.com","Jefe" ,8000000);
  DB.AgregarADMINISTRATIVO("Santi","Lucero",44653137,"Email@gmail.com","Jefe" ,8000000);
  DB.AgregarPROFESIONAL("Santi","Lucero",44653137,"Email@gmail.com","Ingeniero", "jefesito",4 ,8000000);
  DB.AgregarPROFESIONAL("Santi","Lucero",44653137,"Email@gmail.com","Ingeniero", "jefesito",4 ,8000000);
  DB.AgregarPROFESIONAL("Santi","Lucero",44653137,"Email@gmail.com","Ingeniero", "jefesito",4 ,8000000);
  DB.AgregarPROFESIONAL("Santi","Lucero",44653137,"Email@gmail.com","Ingeniero", "jefesito",4 ,8000000);
  DB.AdminDB[1]->C->switchEstado();
  DB.AdminDB[3]->C->switchEstado();
  DB.ProfDB[1]->C->switchEstado();
  DB.ProfDB[3]->C->switchEstado();
  DB.PrintPROFESIONALES();
  return 0;
}
