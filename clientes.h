#include <iostream>
using namespace std;

class CLIENTE{
    protected:
        string Nombre, Apellido;
        int Dni;
        string Email;
    public:
        /* CLIENTE(string, string, int, string); */
        string getNombre();
        string getApellido();
        string getEmail();
        int getDni();
        void setNombre(string);
        void setApellido(string);
        void setDni(int);
        void setEmail(string);
};
