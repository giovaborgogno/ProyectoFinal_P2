#include <iostream>
#include "administrativos.cpp"

using namespace std;

class BASEDEDATOS{
  private:
  public:
    PROFESIONAL **ProfDB;
    ADMINISTRATIVO **AdminDB;
    BASEDEDATOS(int);
    void AgregarPROFESIONAL(string,string,int,string,string,string,int,float);
    void AgregarADMINISTRATIVO(string,string,int,string,string,float);
    void PrintClientesDeAlta();
    void PrintClientesDeBaja();
    void PrintPROFESIONALES();
    void PrintADMINISTRATIVOS();
    void PrintDB();
    void SortDB();
};
