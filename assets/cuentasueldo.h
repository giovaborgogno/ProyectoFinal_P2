#include <iostream>
using namespace std;

class CUENTASUELDO{
  private:
    int NumeroDeCuenta;
    float Saldo;
    char Estado;
    string HistorialDeMovimientos[100][2];
  public:
    CUENTASUELDO(float Saldo=0);
    int getNumeroDeCuenta();
    float getSaldo();
    char getEstado();
    void setNumeroDeCuenta(int);
    void setSaldo(float);
    void setEstado(char);
    void switchEstado();
    void Extraccion(float);
    void Deposito(float);
    void showHistory();
};
