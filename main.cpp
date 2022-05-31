#include <iostream>
#include "validacion.cpp"
#include "basededatos.cpp"

using namespace std;

int main(){

  BASEDEDATOS DB(3);
  DB.AgregarADMINISTRATIVO("Santi","Lucero",44653137,"Email@gmail.com","Jefe" ,8000000);
  DB.AgregarADMINISTRATIVO("Santi","Lucero",44653137,"Email@gmail.com","Jefe" ,8000000);
  DB.AgregarADMINISTRATIVO("Santi","Lucero",44653137,"Email@gmail.com","Jefe" ,8000000);
  DB.AgregarADMINISTRATIVO("Santi","Lucero",44653137,"Email@gmail.com","Jefe" ,8000000);
  DB.AgregarPROFESIONAL("Santi","Lucero","Email@gmail.com",44653137,"Ingeniero", "jefesito",4 ,8000000);
  DB.AgregarPROFESIONAL("Santi","Lucero","Email@gmail.com",44653137,"Ingeniero", "jefesito",4 ,8000000);
  DB.AgregarPROFESIONAL("Santi","Lucero","Email@gmail.com",44653137,"Ingeniero", "jefesito",4 ,8000000);
  DB.AgregarPROFESIONAL("Santi","Lucero","Email@gmail.com",44653137,"Ingeniero", "jefesito",4 ,8000000);
  DB.AdminDB[1]->C->switchEstado();
  DB.AdminDB[3]->C->switchEstado();
  DB.ProfDB[1]->C->switchEstado();
  DB.ProfDB[3]->C->switchEstado();
  DB.PrintClientesDeAlta();
  DB.PrintClientesDeBaja();
  return 0;
}
