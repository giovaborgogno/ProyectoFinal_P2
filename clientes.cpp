#include <iostream>
#include "clientes.h"

using namespace std;

/* CLIENTE::CLIENTE(string Nombre, string Apellido, int Dni, string Email){
  this->Nombre=Nombre;
  this->Apellido=Apellido;
  this->Dni=Dni;
  this->Email=Email;
} */

string CLIENTE::getNombre(){
  return Nombre;
}
string CLIENTE::getApellido(){
  return Apellido;
}
int CLIENTE::getDni(){
  return Dni;
}
string CLIENTE::getEmail(){
  return Email;
}
float CLIENTE::getSueldo(){
  return Sueldo;
}
void CLIENTE::setNombre(string Nombre){
  this->Nombre = Nombre;
}
void CLIENTE::setApellido(string Apellido){
  this->Apellido = Apellido;
}
void CLIENTE::setDni(int Dni){
  this->Dni = Dni;
}
void CLIENTE::setEmail(string Email){
  this->Email = Email;
}
void CLIENTE::setSueldo(float Sueldo){
  this->Sueldo = Sueldo;
}
