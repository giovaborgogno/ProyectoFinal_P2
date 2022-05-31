#include <iostream>
#include "administrativos.cpp"

using namespace std;

class BASEDEDATOS{
  private:
    PROFESIONAL **ProfDB;
    ADMINISTRATIVO **AdminDB;
  public:
    BASEDEDATOS(int);
    void AgregarPROFESIONAL(string,string,string,int,string,string,int,float);
    void AgregarADMINISTRATIVO(string,string,int,string,string,float);
    void PrintClientesDeAlta();
    void PrintClientesDeBaja();
    void PrintPROFESIONALES();
    void PrintADMINISTRATIVOS();
    void PrintDB();
    void SortDB();
};
