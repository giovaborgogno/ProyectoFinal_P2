#include <iostream>
#include "clientes.cpp"
using namespace std;

class ADMINISTRATIVO : protected CLIENTE
{
protected:
    string Puesto;

public:
    ADMINISTRATIVO(string, string, int, string, string);
    string getPuesto();
    void setPuesto(string);
};
