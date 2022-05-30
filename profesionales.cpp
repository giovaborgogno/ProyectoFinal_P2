#include <iostream>
#include "profesionales.h"
using namespace std;

  PROFESIONAL::PROFESIONAL(string Nombre, string Apellido, string Email, int Dni, string Titulo, string Actividad, int TiempoServicio, float Sueldo){
    this->Nombre = Nombre;
    this->Apellido = Apellido;
    this->Email = Email;
    this->Dni = Dni;
    this->Titulo = Titulo;
    this->Actividad = Actividad;
    this->TiempoServicio = TiempoServicio;
    this->Sueldo = Sueldo;
  }
  void PROFESIONAL::setTitulo(string Titulo){
    this->Titulo = Titulo;
  }
  void PROFESIONAL::setActividad(string Actividad){
    this->Actividad = Actividad;
  }
  void PROFESIONAL::setTiempoServicio(int TiempoServicio){
    this->TiempoServicio = TiempoServicio;
  }
  string PROFESIONAL::getTitulo(){
    return Titulo;
  }
  string PROFESIONAL::getActividad(){
    return Actividad;
  }
  int PROFESIONAL::getTiempoServicio(){
    return TiempoServicio;
  }
