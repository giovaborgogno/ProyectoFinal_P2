#include <iostream>
#include "programa.h"

using namespace std;

PROGRAMA::PROGRAMA(){
  Verify = new VALIDACION;
  DB = new BASEDEDATOS;
}

void PROGRAMA::PresioneUnaTeclaParaContinuar(){
  cout << "<Presione ENTER para continuar>";
  cin.sync();
  cin.ignore();
  system("CLS || clear");
}

int PROGRAMA::Convert(string v, bool option)
{
  int Iaux;
  float Faux;
  switch(option){
  // 1 = Int / 0 = Float
  case 1:
    try{
      Iaux = stoi(v);
      return 1;
    }
    catch(out_of_range){return -2;}
    catch(invalid_argument){return -2;}
    break;
  case 0:
    try{
      Faux = stof(v);
      return 1;
    }
    catch(out_of_range){return -2;}
    catch(invalid_argument){return -2;}
    break;
    break;
  }
}

void PROGRAMA::Start(){
  //Declaracion de variables
  int cont=0, option=0;
  string val;
  //Variables para agregar Clientes
  string Nombre, Apellido, Titulo, Actividad, Puesto, Email;
  int DNI, TiempoServicio, NRO;
  float Sueldo;
  //Inicio del programa
  while (true){
    while (true){//Ciclo de repeticion del menu
      if (cont == 0){
        system("CLS || clear");
        cont++;
      }
      else{
        PresioneUnaTeclaParaContinuar();
      }
      cout << "SISTEMA DE GESTION BANCARIA - UCC" << endl << endl;
      cout << "1) Nuevo Cliente" << endl;
      cout << "2) Baja Cliente" << endl;
      cout << "3) Alta antiguo Cliente" << endl;
      cout << "4) Imprimir" << endl;
      cout << "5) Realizar movimiento de saldo" << endl;
      cout << "6) Otorgar tarjeta de credito" << endl;
      cout << "7) Salir" << endl;
      cout << endl << "Que desea hacer? "; cin.sync(); getline(cin, val);
      //Validacion de entrada
      if (Verify->NumbersOnly(val)==1){
        if (Convert(val, 1)==1){
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
          PresioneUnaTeclaParaContinuar();
        }
        cout << "SISTEMA DE GESTION BANCARIA - UCC" << endl << endl;
        cout << "1) Profesional" << endl;
        cout << "2) Administrativo" << endl;
        cout << endl << "Elija una opcion: "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val,1)==1){
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
                Nombre = val;
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
                Apellido = val;
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
                DNI = Verify->isDNI(val);
                break;
              }
            }
            //Ingreso Email
            while (true){
              cout << "Email: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->isEmail(val)==1){
                Email = val;
                break;
              }else if (Verify->isEmail(val)==0){
                cout << "Ingrese un Email valido" << endl << endl;
              }else if (Verify->isEmail(val)==-2){
                cout << "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->isEmail(val)==-1){
                cout << "Ingrese un Email sin espacios" << endl << endl;
              }
            }
            //Ingreso Titulo
            while (true){
              cout << "Titulo: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->AlphaOnly(val)==1){
                Titulo = val;
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
                Actividad = val;
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
                if (Convert(val,1)==1){
                  TiempoServicio = stoi(val);
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
            //Ingreso del Sueldo
            while (true){
              cout << "Sueldo: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->FloatOnly(val)==1){
                if (Convert(val,0)==1){
                  Sueldo = stof(val);
                  break;
                }else{
                  cout << "El numero ingresado es demasiado grande" << endl << endl;
                }
              }else if(Verify->FloatOnly(val)==0){
                cout << "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->FloatOnly(val)==-1){
                cout << "El ingreso debe ser numerico y/o contener UN punto" << endl << endl;
              }
            }
            DB->AgregarPROFESIONAL(Nombre,Apellido,DNI,Email,Titulo,Actividad,TiempoServicio,Sueldo);
            break;

        case 2://Administrativo
            //Ingreso Nombre
            while (true){
              cout << "Nombre: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->AlphaOnly(val)==1){
                Nombre = val;
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
                Apellido = val;
                break;
              }else if(Verify->AlphaOnly(val)==0){
                cout << "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->AlphaOnly(val)==-1){
                cout << "El ingreso debe ser numerico" << endl << endl;
              }
            }
            //Ingreso DNI
            while (true){
              cout << "DNI: ";cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->isDNI(val)==-2){
                cout << "Ingrese un DNI valido" << endl << endl;
              }else if (Verify->isDNI(val)==-1){
                cout << "El ingreso debe ser numerico" << endl << endl;
              }else if (Verify->isDNI(val)==0){
                cout << "El campo no puede quedar vacio" << endl << endl;
              }else{
                DNI = Verify->isDNI(val);
                break;
              }
            }
            //Ingreso Email
            while (true){
              cout << "Email: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->isEmail(val)==1){
                Email = val;
                break;
              }else if (Verify->isEmail(val)==0){
                cout << "Ingrese un Email valido" << endl << endl;
              }else if (Verify->isEmail(val)==-2){
                cout << "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->isEmail(val)==-1){
                cout << "Ingrese un Email sin espacios" << endl << endl;
              }
            }
            //Ingreso Puesto
            while (true){
              cout << "Puesto: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->AlphaOnly(val)==1){
                Puesto = val;
                break;
              }else if(Verify->AlphaOnly(val)==0){
                cout << "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->AlphaOnly(val)==-1){
                cout << "El ingreso debe ser numerico" << endl << endl;
              }
            }
            //Ingreso del Sueldo
            while (true){
              cout << "Sueldo: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->FloatOnly(val)==1){
                if (Convert(val,0)==1){
                  Sueldo = stof(val);
                  break;
                }else{
                  cout << "El numero ingresado es demasiado grande" << endl << endl;
                }
              }else if(Verify->FloatOnly(val)==0){
                cout << "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->FloatOnly(val)==-1){
                cout << "El ingreso debe ser numerico y/o contener UN punto" << endl << endl;
              }
            }
            DB->AgregarADMINISTRATIVO(Nombre,Apellido,DNI,Email,Puesto,Sueldo);
            break;

        default:
            cout << "La opcion ingresada no es valida" << endl << endl;
            break;
      }
      break;

      case 2://Baja Cliente
      //Ingreso nro de Cuenta
      // Impresion de la Tabla de clientes de Alta -->
      DB->PrintClientesDeAlta(0);
      while (true){
        cout << "Numero de Cuenta: "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val,1)==1){
            NRO = stoi(val);
            DB->BajaCliente(NRO);
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
      // Impresion de la Tabla de clientes de Baja -->
      DB->PrintClientesDeBaja(0);
      while (true){
        cout << "Numero de Cuenta: "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val,1)==1){
            NRO = stoi(val);
            DB->AltaCliente(NRO);
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

      case 4://Imprimir
      cont=0;
      option=0;
      while (true){
        if (cont == 0){
          system("CLS || clear");
          cont++;
        }
        else{
          PresioneUnaTeclaParaContinuar();
        }
        cout << "SISTEMA DE GESTION BANCARIA - UCC" << endl << endl;
        cout << "1) Imprimir Clientes de Alta" << endl;
        cout << "2) Imprimir Clientes de Baja" << endl;
        cout << "3) Imprimir Administrativos" << endl;
        cout << "4) Imprimir Profesionales" << endl;
        cout << "5) Imprimir Base de Datos" << endl;
        cout << endl << "Elija una opcion: "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val,1)==1){
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
        case 1://Imprimir Clientes de Alta
        DB->PrintClientesDeAlta(1);
        break;

        case 2://Imprimir Clientes de Baja
        DB->PrintClientesDeBaja(1);
        break;

        case 3://Imprimir Administrativos
        DB->PrintADMINISTRATIVOS();
        break;

        case 4://Imprimir Profesionales
        DB->PrintPROFESIONALES();
        break;

        case 5://Imprimir Base de Datos
        DB->PrintDB();
        break;

        default:
            cout << "La opcion ingresada no es valida" << endl << endl;
            break;
      }

      break;

      case 5://Realizar movimiento de saldo
      //Ingreso nro de Cuenta
      while (true){
        cout << "Numero de Cuenta: "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val,1)==1){
            NRO = stoi(val);
            cont=0;
            option=0;
            while (true){
              if (cont == 0){
                system("CLS || clear");
                cont++;
              }
              else{
                PresioneUnaTeclaParaContinuar();
              }
              cout << "SISTEMA DE GESTION BANCARIA - UCC" << endl << endl;
              cout << "SALDO: " << endl;
              cout << "1) Depositar" << endl;
              cout << "2) Extraer" << endl;
              cout << endl << "Elija una opcion: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->NumbersOnly(val)==1){
                if (Convert(val,1)==1){
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
            /*switch (option){
              case 1:

              break;

              case 2:

              break;

              default:
                  cout << "La opcion ingresada no es valida" << endl << endl;
                  break;
            }*/
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

      case 6://Otorgar tarjeta de credito
      while (true){
        cout << "Numero de Cuenta: "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val,1)==1){
            NRO = stoi(val);

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

      case 7://Salir
      exit(0);

      default:
      cout << "La opcion ingresada no es valida" << endl << endl;
      break;
    }
  }
}
