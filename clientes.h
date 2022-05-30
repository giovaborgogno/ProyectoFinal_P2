#include <iostream>
using namespace std;

class CLIENTE{
    protected:
        string Nombre, Apellido;
        int Dni;
        string Email;
        float Sueldo;
    public:
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
