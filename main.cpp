#include <iostream>
#include "validacion.cpp"
#include "basededatos.cpp"

using namespace std;

int main(){

  BASEDEDATOS DB(3);
  DB.AgregarPROFESIONAL("Santi","Lucero","Email@gmail.com",44653137,"Giganta","Ehhh",4,8000000);
  DB.AgregarPROFESIONAL("Santi","Lucero","Email@gmail.com",44653137,"Giganta","Ehhh",4,8000000);
  DB.AgregarPROFESIONAL("Santi","Lucero","Email@gmail.com",44653137,"Giganta","Ehhh",4,8000000);
  DB.AgregarPROFESIONAL("Santi","Lucero","Email@gmail.com",44653137,"Giganta","Ehhh",4,8000000);
  DB.ProfDB[3]->C->switchEstado();
  DB.ProfDB[2]->C->setEstado('E');
  cout << DB.ProfDB[3]->C->getEstado();
  cout << DB.ProfDB[1]->C->getEstado();
  cout << DB.ProfDB[2]->C->getEstado() << endl;
  DB.ProfDB[1]->C->switchEstado();
  cout << DB.ProfDB[0]->C->getEstado();
  cout << DB.ProfDB[1]->C->getEstado();
  cout << DB.ProfDB[2]->C->getEstado();

  return 0;
}
