#include <iostream>
#include "tarjetas.h"
using namespace std;

int CardCounter = 1000;

TARJETA::TARJETA(float Sueldo, bool TarjetaSN){
  this->NumeroDeTarjeta = CardCounter;
  LimiteDeCompra = Sueldo*1.5;
  if(TarjetaSN==1){
    if(Sueldo<=40000){
      Tipo = "Bronce";
    }else if(Sueldo<=80000){
      Tipo = "Plata";
    }else if(Sueldo<=140000){
      Tipo = "Oro";
    }else{
      Tipo="Platino";
    }
    CardCounter++;
  }else{
    Tipo = "Ninguno";
  }
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
