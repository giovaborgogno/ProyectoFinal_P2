#include <iostream>
/* #include "validacion.cpp" */
#include "profesionales.cpp"

using namespace std;

int main(){

  // VALIDACION *V;
  // V = new VALIDACION;
  // string val;
  //
  // while(true){
  //   cout << "Ingrese su email: "; getline(cin, val);
  //   cout << V->isEmail(val) << endl;
  // }
  //
  // delete V;

  PROFESIONAL Felipe("Felipe", "Cañas", "felipecanias@gmail.com", 44369966, "Ingeniere", "Dueño de Google", 2, 2000000);
  cout << Felipe.T->getTipo();

  return 0;
}
