#include <iostream>
#include "clientes.cpp"
using namespace std;

class PROFESIONAL:public CLIENTE{
  protected:
    string Titulo;
    string Actividad;
    int TiempoServicio;

  public:
     PROFESIONAL(string, string, string, int, string, string, int, float);
     void setTitulo(string);
     void setActividad(string);
     void setTiempoServicio(int);
     string getTitulo();
     string getActividad();
     int getTiempoServicio();
};
