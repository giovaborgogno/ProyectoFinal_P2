#include <iostream>
#include "programa.h"

using namespace std;

int PROGRAMA::Convert(string v)
{
  int aux;
  try{
    aux = stoi(v);
    return 1;
  }
  catch(out_of_range){return -2;}
  catch(invalid_argument){return -2;}
}

void PROGRAMA::Start(){
  //Declaracion de variables
  Verify = new VALIDACION;
  //Prof = new PROFESIONAL;
  //Admin = new ADMINISTRATIVO;
  int cont=0, option=0;
  string val;
  //Inicio del programa
  while (true){
    while (true){//Ciclo de repeticion del menu
      if (cont == 0){
        system("CLS || clear");
        cont++;
      }
      else{
        cout << "Presione enter para continuar...";
        cin.ignore();
        system("CLS || clear");
      }
      cout << "SISTEMA DE GESTION UCC" << endl << endl;
      cout << "1) Nuevo Cliente" << endl;
      cout << "2) Baja Cliente" << endl;
      cout << "3) Alta antiguo Cliente" << endl;
      cout << "4) Imprimir Alta" << endl;
      cout << "5) Imprimir Baja" << endl;
      cout << "6) Realizar movimiento de saldo" << endl;
      cout << "7) Otorgar tarjeta de credito" << endl;
      cout << "8) Salir" << endl;
      cout << endl << "Que desea hacer? "; cin.sync(); getline(cin, val);
      //Validacion de entrada
      if (Verify->NumbersOnly(val)==1){
        if (Convert(val)==1){
          option = stoi(val);
          break;
        }else{
          cout << "El numero ingresado es demasiado grande" << endl << endl;
        }
      }else if(Verify->NumbersOnly(val)==0){
        cout << "El campo no puede quedar vacio" << endl << endl;
      }else if(Verify->NumbersOnly(val)==-1){
        cout << "El ingreso debe ser numerico" << endl << endl;
      }
    }
    switch (option){
      case 1://Nuevo Cliente
      cont=0;
      option=0;
      while (true){
        if (cont == 0){
          system("CLS || clear");
          cont++;
        }
        else{
          cout << "Presione enter para continuar...";
          cin.ignore();
          system("CLS || clear");
        }
        cout << "SISTEMA DE GESTION UCC" << endl << endl;
        cout << "1) Profesional" << endl;
        cout << "2) Administrativo" << endl;
        cout << endl << "Elija una opcion: "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val)==1){
            option = stoi(val);
            break;
          }else{
            cout << "El numero ingresado es demasiado grande" << endl << endl;
          }
        }else if(Verify->NumbersOnly(val)==0){
          cout << "El campo no puede quedar vacio" << endl << endl;
        }else if(Verify->NumbersOnly(val)==-1){
          cout << "El ingreso debe ser numerico" << endl << endl;
        }
      }
      switch (option){
        case 1://Profesional
        //Ingreso Nombre
        while (true){
          cout << "Nombre: ";cin.sync(); getline(cin, val);
          //Validacion de entrada
          if (Verify->AlphaOnly(val)==1){
            break;
          }else if(Verify->AlphaOnly(val)==0){
            cout << "El campo no puede quedar vacio" << endl << endl;
          }else if(Verify->AlphaOnly(val)==-1){
            cout << "El ingreso debe ser numerico" << endl << endl;
          }
        }
        //Ingreso  Apellido
        while (true){
          cout << "Apellido: "; cin.sync(); getline(cin, val);
          //Validacion de entrada
          if (Verify->AlphaOnly(val)==1){
            break;
          }else if(Verify->AlphaOnly(val)==0){
            cout << "El campo no puede quedar vacio" << endl << endl;
          }else if(Verify->AlphaOnly(val)==-1){
            cout << "El ingreso debe ser numerico" << endl << endl;
          }
        }
        //Ingreso DNI
        while (true){
          cout << "DNI: "; cin.sync(); getline(cin, val);
          //Validacion de entrada
          if (Verify->isDNI(val)==-2){
            cout << "Ingrese un DNI valido" << endl << endl;
          }else if (Verify->isDNI(val)==-1){
            cout << "El ingreso debe ser numerico" << endl << endl;
          }else if (Verify->isDNI(val)==0){
            cout << "El campo no puede quedar vacio" << endl << endl;
          }else{
            break;
          }
        }
        //Ingreso Titulo
        while (true){
          cout << "Titulo: "; cin.sync(); getline(cin, val);
          //Validacion de entrada
          if (Verify->AlphaOnly(val)==1){
            break;
          }else if(Verify->AlphaOnly(val)==0){
            cout << "El campo no puede quedar vacio" << endl << endl;
          }else if(Verify->AlphaOnly(val)==-1){
            cout << "El ingreso debe ser numerico" << endl << endl;
          }
        }
        //Ingreso Actividad
        while (true){
          cout << "Actividad: "; cin.sync(); getline(cin, val);
          //Validacion de entrada
          if (Verify->AlphaOnly(val)==1){
            break;
          }else if(Verify->AlphaOnly(val)==0){
            cout << "El campo no puede quedar vacio" << endl << endl;
          }else if(Verify->AlphaOnly(val)==-1){
            cout << "El ingreso debe ser numerico" << endl << endl;
          }
        }
        //Ingreso Tiempo de Servicio
        while (true){
          cout << "Tiempo de servicio: "; cin.sync(); getline(cin, val);
          //Validacion de entrada
          if (Verify->NumbersOnly(val)==1){
            if (Convert(val)==1){
              break;
            }else{
              cout << "El numero ingresado es demasiado grande" << endl << endl;
            }
          }else if(Verify->NumbersOnly(val)==0){
            cout << "El campo no puede quedar vacio" << endl << endl;
          }else if(Verify->NumbersOnly(val)==-1){
            cout << "El ingreso debe ser numerico" << endl << endl;
          }
        }
        break;

        case 2://Administrativo
        //Ingreso Nombre
        while (true){
          cout << "Nombre: "; cin.sync(); getline(cin, val);
          //Validacion de entrada
          if (Verify->AlphaOnly(val)==1){
            break;
          }else if(Verify->AlphaOnly(val)==0){
            cout << "El campo no puede quedar vacio" << endl << endl;
          }else if(Verify->AlphaOnly(val)==-1){
            cout << "El ingreso debe ser numerico" << endl << endl;
          }
        }
        //Ingreso Apellido
        while (true){
          cout << "Apellido: "; cin.sync(); getline(cin, val);
          //Validacion de entrada
          if (Verify->AlphaOnly(val)==1){
            break;
          }else if(Verify->AlphaOnly(val)==0){
            cout << "El campo no puede quedar vacio" << endl << endl;
          }else if(Verify->AlphaOnly(val)==-1){
            cout << "El ingreso debe ser numerico" << endl << endl;
          }
        }
        //Ingreso DNI
        while (true){
          cout << "Dni: ";cin.sync(); getline(cin, val);
          //Validacion de entrada
          if (Verify->isDNI(val)==-2){
            cout << "Ingrese un DNI valido" << endl << endl;
          }else if (Verify->isDNI(val)==-1){
            cout << "El ingreso debe ser numerico" << endl << endl;
          }else if (Verify->isDNI(val)==0){
            cout << "El campo no puede quedar vacio" << endl << endl;
          }else{
            break;
          }
        }
        //Ingreso Puesto
        while (true){
          cout << "Puesto: "; cin.sync(); getline(cin, val);
          //Validacion de entrada
          if (Verify->AlphaOnly(val)==1){
            break;
          }else if(Verify->AlphaOnly(val)==0){
            cout << "El campo no puede quedar vacio" << endl << endl;
          }else if(Verify->AlphaOnly(val)==-1){
            cout << "El ingreso debe ser numerico" << endl << endl;
          }
        }
        break;

        default:
        cout << "La opcion ingresada no es valida" << endl << endl;
        break;
      }
      break;

      case 2://Baja Cliente
      //Ingreso nro de Cuenta
      while (true){
        cout << "Numero de Cuenta: "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val)==1){
            break;
          }else{
            cout << "El numero ingresado es demasiado grande" << endl << endl;
          }
        }else if(Verify->NumbersOnly(val)==0){
          cout << "El campo no puede quedar vacio" << endl << endl;
        }else if(Verify->NumbersOnly(val)==-1){
          cout << "El ingreso debe ser numerico" << endl << endl;
        }
      }
      break;

      case 3://Alta antiguo Cliente
      //Ingreso nro de Cuenta
      while (true){
        cout << "Numero de Cuenta: "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val)==1){
            break;
          }else{
            cout << "El numero ingresado es demasiado grande" << endl << endl;
          }
        }else if(Verify->NumbersOnly(val)==0){
          cout << "El campo no puede quedar vacio" << endl << endl;
        }else if(Verify->NumbersOnly(val)==-1){
          cout << "El ingreso debe ser numerico" << endl << endl;
        }
      }
      break;

      case 4://Imprimir Alta
      break;

      case 5://Imprimir Baja
      break;

      case 6://Realizar movimiento de saldo
      //Ingreso nro de Cuenta
      while (true){
        cout << "Numero de Cuenta: "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val)==1){
            break;
          }else{
            cout << "El numero ingresado es demasiado grande" << endl << endl;
          }
        }else if(Verify->NumbersOnly(val)==0){
          cout << "El campo no puede quedar vacio" << endl << endl;
        }else if(Verify->NumbersOnly(val)==-1){
          cout << "El ingreso debe ser numerico" << endl << endl;
        }
      }
      break;

      case 7://Otorgar tarjeta de credito
      while (true){
        cout << "Numero de Cuenta: "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val)==1){
            break;
          }else{
            cout << "El numero ingresado es demasiado grande" << endl << endl;
          }
        }else if(Verify->NumbersOnly(val)==0){
          cout << "El campo no puede quedar vacio" << endl << endl;
        }else if(Verify->NumbersOnly(val)==-1){
          cout << "El ingreso debe ser numerico" << endl << endl;
        }
      }
      break;

      case 8://Salir
      exit(0);

      default:
      cout << "La opcion ingresada no es valida" << endl << endl;
      break;
    }
  }
}
