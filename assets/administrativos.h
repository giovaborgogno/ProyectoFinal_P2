#include <iostream>
#include "profesionales.cpp"
using namespace std;

class ADMINISTRATIVO : public CLIENTE{
  private:
    string Puesto;
  public:
    ADMINISTRATIVO(string, string, int, string, string, float);
    string getPuesto();
    void setPuesto(string);
};
