#include <iostream>
#include "validacion.cpp"
//#include "administrativos.cpp"
//#include "profesionales.cpp"

using namespace std;

class PROGRAMA{
  private:
    VALIDACION *Verify;
    //PROFESIONAL *Prof;
    //ADMINISTRATIVO *Admin;

  public:
    int Convert(string v);
    void Start();

};
