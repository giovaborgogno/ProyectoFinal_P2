#include <iostream>
using namespace std;

class CUENTASUELDO{
  private:
    int NumeroDeCuenta;
    float Saldo;
    char Estado;
  public:
    CUENTASUELDO(float Saldo=0);
    int getNrodeCuenta();
    float getSaldo();
    char getEstado();
    void setNrodeCuenta(int);
    void setSaldo(float);
    void setEstado(char);
    void switchEstado();
    void Extraccion(float);
    void Deposito(float);
};
