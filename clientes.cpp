#include <iostream>
#include "clientes.h"

using namespace std;

string CLIENTE::getNombre(){
  return Nombre;
}
string CLIENTE::getApellido(){
  return Apellido;
}
int CLIENTE::getNro(){
  return Nro;
}
float CLIENTE::getSalario(){
  return Salario;
}
void CLIENTE::setNombre(string Nombre){
  this->Nombre = Nombre;
}
void CLIENTE::setApellido(string Apellido){
  this->Apellido = Apellido;
}
void CLIENTE::setNro(int Nro){
  this->Nro = Nro;
}
void CLIENTE::setSalario(float Salario){
  this->Salario = Salario;
}
