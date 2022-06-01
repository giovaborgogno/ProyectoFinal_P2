#include <iostream>
#include "cuentasueldo.h"

using namespace std;

int AccountCounter=0;

CUENTASUELDO::CUENTASUELDO(float Saldo){
  NumeroDeCuenta=AccountCounter;
  this->Saldo = Saldo;
  Estado = 'A';
  AccountCounter++;
}

int CUENTASUELDO::getNumeroDeCuenta(){
  return NumeroDeCuenta;
}

float CUENTASUELDO::getSaldo(){
  return Saldo;
}

char CUENTASUELDO::getEstado(){
  return Estado;
}

void CUENTASUELDO::setNumeroDeCuenta(int NumeroDeCuenta){
  this->NumeroDeCuenta = NumeroDeCuenta;
}

void CUENTASUELDO::setSaldo(float Saldo){
  this->Saldo = Saldo;
}

void CUENTASUELDO::setEstado(char Estado){
  this->Estado = Estado;
}

void CUENTASUELDO::switchEstado(){
  if(Estado == 'A'){
    Estado = 'B';
  }else if(Estado == 'B'){
    Estado = 'A';
  }
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
