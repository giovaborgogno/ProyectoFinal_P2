#include <iostream>
#include <iomanip>
#include "cuentasueldo.h"

using namespace std;

int AccountCounter=1;
int HistoryIndex=0;

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
    HistorialDeMovimientos[HistoryIndex][0]= "E";
    HistorialDeMovimientos[HistoryIndex][1]= to_string(Monto);
    HistoryIndex++;
  }
  else{
    cout << "La cantidad a extraer supera el saldo." << endl;
  }
}

void CUENTASUELDO::Deposito(float Monto){
  Saldo+=Monto;
  HistorialDeMovimientos[HistoryIndex][0]= "D";
  HistorialDeMovimientos[HistoryIndex][1]= to_string(Monto);
  HistoryIndex++;
}

void CUENTASUELDO::showHistory(){
  cout << "MOVIMIENTOS" << '\t' << "MONTO" << endl;
  for(int i = 0; i <HistoryIndex; i++){
    cout << setw(5) << HistorialDeMovimientos[i][0] << setw(5) << '\t' << HistorialDeMovimientos[i][1] << endl;
  }
}
