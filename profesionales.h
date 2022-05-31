#include <iostream>
#include "clientes.cpp"
#include "tarjetas.cpp"

using namespace std;

class PROFESIONAL:public CLIENTE{
  private:
    string Titulo;
    string Actividad;
    int TiempoServicio;
    TARJETA *T;
  public:
    PROFESIONAL(string, string, string, int, string, string, int, float);
    void setTitulo(string);
    void setActividad(string);
    void setTiempoServicio(int);
    string getTitulo();
    string getActividad();
    int getTiempoServicio();
};
