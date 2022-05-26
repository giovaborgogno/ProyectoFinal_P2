#include <iostream>
#include "validacion.h"
using namespace std;

bool VALIDACION::NumbersOnly(string v){
  for(int i=0; i<=v.length(); i++){
    if(int()<48||int()>57){
      return false;
    }
  }
  return true;
}

bool VALIDACION::AlphaOnly(string v){
  for(int i=0; i<=v.length(); i++){
    if((toupper(v[i])<65 && int(v[i])!=32)||toupper(v[i])>90){
      return false;
    }
  }
  return true;
}

bool VALIDACION::CharOnly(string v){
  if(v.length() == 0) return true;
  else return false;
}

bool VALIDACION::FloatOnly(string v){
  int DotCounter = 0;
  for(int i=0; i<=v.length(); i++){
    if(int(v[i])<48||int(v[i])>57){
      if(int(v[i])==46){
        DotCounter++;
      }
      else{
        return false;
      }
    }
  }
  if(DotCounter<=1) return true;
  else return false;
}

int VALIDACION::isDNI(string v){
  try{
    int DNI;
    if(NumbersOnly(v)){
      DNI = stoi(v);
      if(DNI>100000&&DNI<110000000){
        return DNI;
      }
      else{
        throw 7;
      }
    }
    else{
      throw 9;
    }
  }catch(out_of_range){
    cout<<endl<<"ERROR! Ingrese un valores reales"<<endl;
    return -1;
  }catch(int x){
    switch(x){
      case 7:
        cout<<endl<<"ERROR "<<x<<"! Ingrese un valores reales"<<endl;
        return -1;
      case 9:
        cout<<endl<<"ERROR "<<x<<"! Ingrese solo numeros"<<endl;
        return -1;
    }
  }
}
