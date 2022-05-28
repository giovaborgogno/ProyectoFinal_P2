#include <iostream>
#include "validacion.cpp"
using namespace std;

int main(){
  VALIDACION V;
  string val;

  while(true){
    cout << "Ingrese su DNI: "; getline(cin, val);
    cout << V.CharOnly(val) << endl;
  }
  return 0;
}
