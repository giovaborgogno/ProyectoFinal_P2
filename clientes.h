#include <iostream>
using namespace std;

class CLIENTE{
    protected:
        string Nombre, Apellido;
        int Nro;
        float Salario;
    public:
        CLIENTE();
        string getNombre();
        string getApellido();
        int getNro();
        float getSalario();
        void setNombre(string);
        void setApellido(string);
        void setNro(int);
        void setSalario(float);
};
