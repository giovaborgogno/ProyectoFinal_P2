#include <iostream>
#include "validacion.cpp"
#include "basededatos.cpp"

using namespace std;

int main(){

  BASEDEDATOS DB(10,10);
  DB.AgregarPROFESIONAL("Maxi","Lucero","Email@gmail.com",44653137,"GiganteNoble","Gamer",4,8000000);
  cout << DB.ProfDB[0]->getTitulo();
  DB.AgregarPROFESIONAL("Santi","Lucero","Email@gmail.com",44653137,"Giganta","Ehhh",4,8000000);
  cout << DB.ProfDB[1]->getTitulo();
  return 0;
}
