#include <iostream>
#include "cuentasueldo.h"

using namespace std;

int CUENTASUELDO::getNrodeCuenta(){
  return NumeroDeCuenta;
}

float CUENTASUELDO::getSaldo(){
  return Saldo;
}

void CUENTASUELDO::setNrodeCuenta(int NumeroDeCuenta){
  this->NumeroDeCuenta = NumeroDeCuenta;
}

void CUENTASUELDO::setSaldo(float Saldo){
  this->Saldo = Saldo;
}

void CUENTASUELDO::Extraccion(float Monto){
  if(Saldo>=Monto){
    Saldo-=Monto;
  }
  else{
    cout << "La cantidad a extraer supera el saldo." << endl;
  }
}

void CUENTASUELDO::Deposito(float Monto){
  Saldo+=Monto;
}
