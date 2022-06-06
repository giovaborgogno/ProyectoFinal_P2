#include <iostream>
#include <regex>
#include "validacion.h"

using namespace std;

int VALIDACION::NumbersOnly(string v){
  if(v.length()!= 0){
    for(int i=0; i<v.length(); i++){
      if(int(v[i])<48||int(v[i])>57){
        return -1; // No es un número
      }
    }
    return 1; // OK
  }
  else{
    return 0; // Campo vacío
  }
}

int VALIDACION::AlphaOnly(string v){
  if(v.length()!= 0){
    for(int i=0; i<v.length(); i++){
      if((toupper(v[i])<65 && int(v[i])!=32)||toupper(v[i])>90){
        return -1; // No es una letra o un espacio
      }
    }
    return 1; // OK
  }
  else{
    return 0; // Campo vacío
  }
}

int VALIDACION::CharOnly(string v){
  if(v.length()!= 0){
    if(v.length() == 1){
      if(toupper(v[0])<65||toupper(v[0])>90){
        return -1; // No es una letra
      }
      else{
        return 1; // OK
      }
    }
    else return -2; // Más de un caracter ingresado
  }else return 0; // Campo vacío
}

int VALIDACION::FloatOnly(string v){
  if(v.length()!=0){
    int DotCounter = 0;
    for(int i=0; i<v.length(); i++){
      if(int(v[i])<48||int(v[i])>57){
        if(int(v[i])==46){
          DotCounter++;
        }
        else{
          return -1; // No es un número con coma
        }
      }
    }
    if(DotCounter<=1) return 1; // OK
    else return -1; // No es un número con coma
  }
  else{
    return 0; // Campo vacío
  }
}

int VALIDACION::isDNI(string v){
  try{
    int DNI;
    if(NumbersOnly(v) == 1){
      DNI = stoi(v);
      if(DNI>100000&&DNI<110000000){
        return DNI;
      }
      else{
        return -2; // DNI fuera del rango
      }
    }
    else{
      return NumbersOnly(v);
    }
  }catch(out_of_range){
    return -2; // DNI demasiado grande
  }
}

int VALIDACION::isEmail(string v){
  const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  if(v.length()!= 0){
    for(int i=0; i<v.length(); i++){
      if(v[i]==32){
        return -1; // Hay un espacio, no es un email
      }
    }
    return regex_match(v, pattern);
    // 1 = Es un email válido; 0 = No es un email válido
  }
  else{
    return -2; // Campo vacío
  }
}

int VALIDACION::isName(string v){
  return AlphaOnly(v);
}

bool VALIDACION::Espacios(string v){
  if(int(v[0])==32){
    return 0; // El campo empieza con espacio
  }
  else{
    return 1; //OK
  }
}
