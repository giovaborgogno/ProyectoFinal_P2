/*
  Agregar mensajes de error segun el error
*/

#include <iostream>
#include "validacion.h"
using namespace std;

bool VALIDACION::NumbersOnly(string v){
  if(v.length()!= 0){
    for(int i=0; i<v.length(); i++){
      if(int(v[i])<48||int(v[i])>57){
        return false;
      }
    }
    return true;
  }
  else{
    return false;
  }
}

bool VALIDACION::AlphaOnly(string v){
  if(v.length()!= 0){
    for(int i=0; i<v.length(); i++){
      if((toupper(v[i])<65 && int(v[i])!=32)||toupper(v[i])>90){
        return false;
      }
    }
    return true;
  }
  else{
    return false;
  }
}

bool VALIDACION::CharOnly(string v){
  if(v.length() == 1){
      if(toupper(v[0])<65||toupper(v[0])>90){
        return false;
      }
      else{
        return true;
      }
  }
  else return false;
}

bool VALIDACION::FloatOnly(string v){
  if(v.length()!=0){
    int DotCounter = 0;
    for(int i=0; i<v.length(); i++){
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
  else{
    return false;
  }
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
    return -1;
  }catch(int x){
    switch(x){
      case 7:
        return -1;
      case 9:
        return -1;
    }
  }
}
