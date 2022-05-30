#include <iostream>
#include "clientes.cpp"
using namespace std;

class ADMINISTRATIVO : public CLIENTE
{
private:
    string Puesto;

public:
    ADMINISTRATIVO(string, string, int, string, string);
    string getPuesto();
    void setPuesto(string);
};
