#include <iostream>
#include "profesionales.cpp"
using namespace std;

int main(){

  while(true){
    cout << "Ingrese su email: "; getline(cin, val);
    cout << V.isEmail(val) << endl;
  }
  return 0;
}
