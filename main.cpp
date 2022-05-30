#include <iostream>
#include "validacion.cpp"
using namespace std;

int main(){
  VALIDACION V;
  string val;

  while(true){
    cout << "Ingrese su email: "; getline(cin, val);
    cout << V.isEmail(val) << endl;
  }
  return 0;
}
