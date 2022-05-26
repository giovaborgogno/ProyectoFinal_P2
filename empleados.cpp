#include <iostream>
#include "empleados.h"

using namespace std;

string EMPLEADO::getNombre(){
  return Nombre;
}
string EMPLEADO::getApellido(){
  return Apellido;
}
int EMPLEADO::getNro(){
  return Nro;
}
float EMPLEADO::getSalario(){
  return Salario;
}
void EMPLEADO::setNombre(string Nombre){
  this->Nombre = Nombre;
}
void EMPLEADO::setApellido(string Apellido){
  this->Apellido = Apellido;
}
void EMPLEADO::setNro(int Nro){
  this->Nro = Nro;
}
void EMPLEADO::setSalario(float Salario){
  this->Salario = Salario;
}
