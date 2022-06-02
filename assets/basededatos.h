#include <iostream>
#include "administrativos.cpp"

using namespace std;

class BASEDEDATOS{
  private:
    PROFESIONAL **ProfDB;
    ADMINISTRATIVO **AdminDB;
  public:
    BASEDEDATOS(int DBSize=100);
    void AgregarPROFESIONAL(string,string,int,string,string,string,int,float,char);
    void AgregarADMINISTRATIVO(string,string,int,string,string,float);
    void AltaCliente(int);
    void BajaCliente(int);
    void PrintPROFESIONALES();
    void PrintADMINISTRATIVOS();
    void PrintClientesDeAlta(bool);
    void PrintClientesDeBaja(bool);
    void PrintDB();
    CLIENTE* GetCliente(int);
    void SortDB();
};
