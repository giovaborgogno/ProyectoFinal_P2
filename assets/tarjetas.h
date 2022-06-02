#include <iostream>
using namespace std;

class TARJETA{
  private:
    int NumeroDeTarjeta;
    float LimiteDeCompra;
    string Tipo;
  public:
    TARJETA(float,bool);
    int getNumeroDeTarjeta();
    float getLimiteDeCompra();
    string getTipo();
    void setNumeroDeTarjeta(int);
    void setLimiteDeCompra(float);
    void setTipo(string);
    void reduceLimiteDeCompra(float);
};
