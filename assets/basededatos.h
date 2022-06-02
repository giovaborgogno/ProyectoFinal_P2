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
    void PrintPROFESIONALES(bool);
    void PrintADMINISTRATIVOS(bool);
    void PrintClientesDeAlta(bool);
    void PrintClientesDeBaja(bool);
    void PrintDB(bool);
    bool isClient(int);
    CLIENTE* GetCliente(int);
    void SortDB();
};
