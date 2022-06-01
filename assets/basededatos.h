#include <iostream>
#include "administrativos.cpp"

using namespace std;

class BASEDEDATOS{
  private:
  public:
    PROFESIONAL **ProfDB;
    ADMINISTRATIVO **AdminDB;
    BASEDEDATOS(int DBSize=100);
    void AgregarPROFESIONAL(string,string,int,string,string,string,int,float);
    void AgregarADMINISTRATIVO(string,string,int,string,string,float);
    void AltaCliente(int);
    void BajaCliente(int);
    void PrintPROFESIONALES();
    void PrintADMINISTRATIVOS();
    void PrintClientesDeAlta(bool);
    void PrintClientesDeBaja(bool);
    void PrintDB();
    void SortDB();
};
