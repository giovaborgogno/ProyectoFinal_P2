#include <iostream>
#include "tarjetas.h"

using namespace std;

int CardCounter = 0;

TARJETA::TARJETA(float Sueldo){
  this->NumeroDeTarjeta = CardCounter;
  LimiteDeCompra = Sueldo;
  if(Sueldo<=40000){
    Tipo = "Bronce";
  }else if(Sueldo<=80000){
    Tipo = "Plata";
  }else if(Sueldo<=140000){
    Tipo = "Oro";
  }
  CardCounter++;
}

int TARJETA::getNumeroDeTarjeta(){
  return NumeroDeTarjeta;
}

float TARJETA::getLimiteDeCompra(){
  return LimiteDeCompra;
}

string TARJETA::getTipo(){
  return Tipo;
}

void TARJETA::setNumeroDeTarjeta(int NumeroDeTarjeta){
  this->NumeroDeTarjeta = NumeroDeTarjeta;
}

void TARJETA::setLimiteDeCompra(float LimiteDeCompra){
  this->LimiteDeCompra = LimiteDeCompra;
}

void TARJETA::setTipo(string Tipo){
  this->Tipo = Tipo;
}

void TARJETA::reduceLimiteDeCompra(float Monto){
  if(LimiteDeCompra>=Monto){
    LimiteDeCompra-=Monto;
  }
  else{
    cout << "El monto excede el limite de compra." << endl;
  }
}
