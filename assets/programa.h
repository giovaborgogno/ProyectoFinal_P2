#include <iostream>
#include "validacion.cpp"
#include "basededatos.cpp"

using namespace std;

class PROGRAMA{
  private:
    VALIDACION *Verify;
    BASEDEDATOS *DB;
    int Convert(string,bool);
    void PresioneUnaTeclaParaContinuar();
  public:
    PROGRAMA();
    void Start();
};
