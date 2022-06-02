#include <iostream>
#include "cuentasueldo.cpp"
using namespace std;

class CLIENTE{
    protected:
        string Nombre, Apellido, Email;
        int Dni;
        float Sueldo;
    public:
        CUENTASUELDO *C;
        string getNombre();
        string getApellido();
        string getEmail();
        int getDni();
        float getSueldo();
        void setNombre(string);
        void setApellido(string);
        void setDni(int);
        void setEmail(string);
        void setSueldo(float);
};
