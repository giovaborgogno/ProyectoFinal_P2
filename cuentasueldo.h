#include <iostream>
using namespace std;

class CUENTASUELDO{
  private:
    int NumeroDeCuenta;
    float Saldo;
  public:
    CUENTASUELDO(float Saldo=0);
    int getNrodeCuenta();
    float getSaldo();
    void setNrodeCuenta(int);
    void setSaldo(float);
    void Extraccion(float);
    void Deposito(float);
};
