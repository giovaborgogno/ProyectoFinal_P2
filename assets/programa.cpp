#include <iostream>
#include "programa.h"

using namespace std;

PROGRAMA::PROGRAMA(){
  Verify = new VALIDACION;
  DB = new BASEDEDATOS;
}

void PROGRAMA::PresioneUnaTeclaParaContinuar(){
  string *s;
  s = new string;
  cout << "<Presione ENTER para continuar>";
  getline(cin, *s);
  delete s;
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
  }
}

void PROGRAMA::Start(){
  //Declaracion de variables
  int option;
  string val;
  //Variables para agregar Clientes
  string Nombre, Apellido, Titulo, Actividad, Puesto, Email;
  int DNI, TiempoServicio, NRO;
  char TarjetaSN;
  float Sueldo, Monto;
  //Base de Datos Load
  DB->loadAdminDB();
  DB->loadProfDB();
  //Inicio del programa
  while (true){
    while (true){//Ciclo de repeticion del menu
      system("CLS || clear");
      cout << "SISTEMA DE GESTION BANCARIA - UCC" << endl << endl;
      cout << "1) Nuevo Cliente" << endl;
      cout << "2) Baja Cliente" << endl;
      cout << "3) Alta antiguo Cliente" << endl;
      cout << "4) Imprimir" << endl;
      cout << "5) Realizar movimiento de saldo" << endl;
      cout << "6) Salir" << endl;
      cout << endl << "Que desea hacer? "; cin.sync(); getline(cin, val);
      //Validacion de entrada
      if (Verify->NumbersOnly(val)==1){
        if (Convert(val, 1)==1){
          option = stoi(val);
          break;
        }else{
          cout << endl<< "El numero ingresado es demasiado grande" << endl << endl;
          PresioneUnaTeclaParaContinuar();
        }
      }else if(Verify->NumbersOnly(val)==0){
        cout << endl<< "El campo no puede quedar vacio" << endl << endl;
        PresioneUnaTeclaParaContinuar();
      }else if(Verify->NumbersOnly(val)==-1){
        cout << endl<< "El ingreso debe ser numerico" << endl << endl;
        PresioneUnaTeclaParaContinuar();
      }
    }
    switch (option){
      case 1://Nuevo Cliente
      while (true){
        system("CLS || clear");
        cout << "AGREGAR UN NUEVO CLIENTE" << endl << endl;
        cout << "1) Profesional" << endl;
        cout << "2) Administrativo" << endl;
        cout << "0) Volver" << endl;
        cout << endl << "Elija una opcion: "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val,1)==1){
            option = stoi(val);
            if(option<=2){
              break;
            }
            else{
              cout<< endl<< "Ingrese un numero valido"<< endl << endl;
              PresioneUnaTeclaParaContinuar();
            }
          }else{
            cout << endl<< "El numero ingresado es demasiado grande" << endl << endl;
            PresioneUnaTeclaParaContinuar();
          }
        }else if(Verify->NumbersOnly(val)==0){
          cout << endl<< "El campo no puede quedar vacio" << endl << endl;
          PresioneUnaTeclaParaContinuar();
        }else if(Verify->NumbersOnly(val)==-1){
          cout << endl<< "El ingreso debe ser numerico" << endl << endl;
          PresioneUnaTeclaParaContinuar();
        }
        }

      switch (option){
        case 0:
        break;
        case 1://Profesional
            system("CLS || clear");
            cout << "DATOS DEL PROFESIONAL" << endl << endl;
            //Ingreso Nombre
            while (true){
              cout << "Nombre: ";cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->AlphaOnly(val)==1 && Verify->Espacios(val)==1){
                Nombre = val;
                break;
              }
              else if(Verify->Espacios(val)==0){
                cout<< endl<< "Nombre invalido"<<endl<<endl;
              }else if(Verify->AlphaOnly(val)==0){
                cout << endl<< "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->AlphaOnly(val)==-1){
                cout << endl<< "Ingrese caracteres validos" << endl << endl;
              }
            }
            //Ingreso  Apellido
            while (true){
              cout << "Apellido: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->AlphaOnly(val)==1 && Verify->Espacios(val)==1){
                Apellido = val;
                break;
              }
              else if(Verify->Espacios(val)==0){
                cout<< endl<< "Apellido invalido"<<endl<<endl;
              }else if(Verify->AlphaOnly(val)==0){
                cout << endl<< "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->AlphaOnly(val)==-1){
                cout << endl<< "Ingrese caracteres validos" << endl << endl;
              }
            }
            //Ingreso DNI
            while (true){
              cout << "DNI: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->isDNI(val)==-2){
                cout << endl<< "Ingrese un DNI valido" << endl << endl;
              }else if (Verify->isDNI(val)==-1){
                cout << endl<< "El ingreso debe ser numerico" << endl << endl;
              }else if (Verify->isDNI(val)==0){
                cout << endl<< "El campo no puede quedar vacio" << endl << endl;
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
                cout << endl<< "Ingrese un Email valido" << endl << endl;
              }else if (Verify->isEmail(val)==-2){
                cout << endl<< "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->isEmail(val)==-1){
                cout << endl<< "Ingrese un Email sin espacios" << endl << endl;
              }
            }
            //Ingreso Titulo
            while (true){
              cout << "Titulo: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->AlphaOnly(val)==1 && Verify->Espacios(val)==1){
                Titulo = val;
                break;
              }
              else if(Verify->Espacios(val)==0){
                cout<< endl<< "Titulo invalido"<<endl<<endl;
              }else if(Verify->AlphaOnly(val)==0){
                cout << endl<< "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->AlphaOnly(val)==-1){
                cout << endl<< "Ingrese caracteres validos" << endl << endl;
              }
            }
            //Ingreso Actividad
            while (true){
              cout << "Actividad: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->AlphaOnly(val)==1 && Verify->Espacios(val)==1){
                Actividad = val;
                break;
              }
              else if(Verify->Espacios(val)==0){
                cout<< endl<< "Actividad invalida"<<endl<<endl;
              }else if(Verify->AlphaOnly(val)==0){
                cout << endl<< "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->AlphaOnly(val)==-1){
                cout << endl<< "El ingreso debe ser numerico" << endl << endl;
              }
            }
            //Ingreso Tiempo de Servicio
            while (true){
              cout << "Anios de servicio: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->NumbersOnly(val)==1){
                if (Convert(val,1)==1){
                  TiempoServicio = stoi(val);
                  break;
                }else{
                  cout << endl<< "El numero ingresado es demasiado grande" << endl << endl;
                }
              }else if(Verify->NumbersOnly(val)==0){
                cout << endl<< "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->NumbersOnly(val)==-1){
                cout << endl<< "El ingreso debe ser numerico" << endl << endl;
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
                  cout << endl<< "El numero ingresado es demasiado grande" << endl << endl;
                }
              }else if(Verify->FloatOnly(val)==0){
                cout << endl<< "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->FloatOnly(val)==-1){
                cout << endl<< "El ingreso debe ser numerico y/o contener UN punto" << endl << endl;
              }
            }
            // Tarjeta Si/No
            while (true){
              cout << "Desea solicitar una tarjeta de credito? (S/N): "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->CharOnly(val)==1){
                TarjetaSN = toupper(val[0]);
                if(TarjetaSN == 'S'||TarjetaSN == 'N'){
                  break;
                }else{
                  cout << endl<< "Ingrese una opcion valida" << endl << endl;
                }
              }else if(Verify->CharOnly(val)==0){
                cout << endl<< "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->CharOnly(val)==-1){
                cout << endl<< "El ingreso debe ser alfabetico" << endl << endl;
              }else if(Verify->CharOnly(val)==-2){
                cout << endl<< "Ingrese un solo caracter" << endl << endl;
              }
            }
            DB->AgregarPROFESIONAL(Nombre,Apellido,DNI,Email,Titulo,Actividad,TiempoServicio,Sueldo,TarjetaSN);
            cout << endl << "Cliente agregado exitosamente!" << endl << endl;
            PresioneUnaTeclaParaContinuar();
            break;

        case 2://Administrativo
            system("CLS || clear");
            cout << "DATOS DEL ADMINISTRATIVO" << endl << endl;

            //Ingreso Nombre
            while (true){
              cout << "Nombre: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->AlphaOnly(val)==1 && Verify->Espacios(val)==1){
                Nombre = val;
                break;
              }
              else if(Verify->Espacios(val)==0){
                cout<< endl<< "Nombre invalido"<<endl<<endl;
              }else if(Verify->AlphaOnly(val)==0){
                cout << endl<< "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->AlphaOnly(val)==-1){
                cout << endl<< "El ingreso debe ser numerico" << endl << endl;
              }
            }
            //Ingreso Apellido
            while (true){
              cout << "Apellido: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->AlphaOnly(val)==1 && Verify->Espacios(val)==1){
                Apellido = val;
                break;
              }
              else if(Verify->Espacios(val)==0){
                cout<< endl<< "Apellido invalido"<<endl<<endl;
              }else if(Verify->AlphaOnly(val)==0){
                cout << endl<< "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->AlphaOnly(val)==-1){
                cout << endl<< "El ingreso debe ser numerico" << endl << endl;
              }
            }
            //Ingreso DNI
            while (true){
              cout << "DNI: ";cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->isDNI(val)==-2){
                cout << endl<< "Ingrese un DNI valido" << endl << endl;
              }else if (Verify->isDNI(val)==-1){
                cout << endl<< "El ingreso debe ser numerico" << endl << endl;
              }else if (Verify->isDNI(val)==0){
                cout << endl<< "El campo no puede quedar vacio" << endl << endl;
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
                cout << endl<< "Ingrese un Email valido" << endl << endl;
              }else if (Verify->isEmail(val)==-2){
                cout << endl<< "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->isEmail(val)==-1){
                cout << endl<< "Ingrese un Email sin espacios" << endl << endl;
              }
            }
            //Ingreso Puesto
            while (true){
              cout << "Puesto: "; cin.sync(); getline(cin, val);
              //Validacion de entrada
              if (Verify->AlphaOnly(val)==1 && Verify->Espacios(val)==1){
                Puesto = val;
                break;
              }
              else if(Verify->Espacios(val)==0){
                cout<< endl<< "Puesto invalido"<<endl<<endl;
              }else if(Verify->AlphaOnly(val)==0){
                cout << endl<< "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->AlphaOnly(val)==-1){
                cout << endl<< "El ingreso debe ser numerico" << endl << endl;
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
                  cout << endl<< "El numero ingresado es demasiado grande" << endl << endl;
                }
              }else if(Verify->FloatOnly(val)==0){
                cout << endl<< "El campo no puede quedar vacio" << endl << endl;
              }else if(Verify->FloatOnly(val)==-1){
                cout << endl<< "El ingreso debe ser numerico y/o contener UN punto" << endl << endl;
              }
            }
            DB->AgregarADMINISTRATIVO(Nombre,Apellido,DNI,Email,Puesto,Sueldo);
            cout << endl << "Cliente agregado exitosamente!" << endl << endl;
            PresioneUnaTeclaParaContinuar();
            break;
      }
      break;

      case 2://Baja Cliente
      while (true){
      system("CLS || clear");
      //Ingreso nro de Cuenta
      cout << "TABLA DE CLIENTES DE ALTA" << endl << endl;
      // Impresion de la Tabla de clientes de Alta -->
      DB->PrintClientesDeAlta(0);
        cout << endl << "Numero de Cuenta (0 para salir): "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val,1)==1){
            NRO = stoi(val);
            if(NRO==0){
              break;
            }
            else{
              DB->BajaCliente(NRO);
              cout << endl;
              PresioneUnaTeclaParaContinuar();
            }
          }else{
            cout <<endl<< "El numero ingresado es demasiado grande" << endl << endl;
            PresioneUnaTeclaParaContinuar();
          }
        }else if(Verify->NumbersOnly(val)==0){
          cout <<endl<< "El campo no puede quedar vacio" << endl << endl;
          PresioneUnaTeclaParaContinuar();
        }else if(Verify->NumbersOnly(val)==-1){
          cout <<endl<< "El ingreso debe ser numerico" << endl << endl;
          PresioneUnaTeclaParaContinuar();
        }
      }
      break;

      case 3://Alta antiguo Cliente
      while (true){
      system("CLS || clear");
      //Ingreso nro de Cuenta
      cout << "TABLA DE CLIENTES DE BAJA" << endl << endl;
      // Impresion de la Tabla de clientes de Baja -->
      DB->PrintClientesDeBaja(0);
        cout << endl << "Numero de Cuenta (0 para salir): "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val,1)==1){
            NRO = stoi(val);
            if(NRO == 0){
              break;
            }
            else{
              DB->AltaCliente(NRO);
              cout << endl;
              PresioneUnaTeclaParaContinuar();
            }
          }else{
            cout <<endl<<"El numero ingresado es demasiado grande" << endl << endl;
            PresioneUnaTeclaParaContinuar();
          }
        }else if(Verify->NumbersOnly(val)==0){
          cout <<endl<<"El campo no puede quedar vacio" << endl << endl;
          PresioneUnaTeclaParaContinuar();
        }else if(Verify->NumbersOnly(val)==-1){
          cout <<endl<< "El ingreso debe ser numerico" << endl << endl;
          PresioneUnaTeclaParaContinuar();
        }
      }
      break;

      case 4://Imprimir
      while (true){
        system("CLS || clear");
        cout << "OPCIONES DE IMPRESION" << endl << endl;
        cout << "1) Clientes de Alta" << endl;
        cout << "2) Clientes de Baja" << endl;
        cout << "3) Administrativos" << endl;
        cout << "4) Profesionales" << endl;
        cout << "5) Base de Datos" << endl;
        cout << "0) Volver" << endl;
        cout << endl << "Elija una opcion: "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val,1)==1){
            option = stoi(val);
            if(option<=5){
              break;
            }
            else{
              cout << endl << "Ingrese una opcion valida" << endl << endl;
              PresioneUnaTeclaParaContinuar();
            }
          }else{
            cout << endl<< "El numero ingresado es demasiado grande" << endl << endl;
            PresioneUnaTeclaParaContinuar();
          }
        }else if(Verify->NumbersOnly(val)==0){
          cout << endl<< "El campo no puede quedar vacio" << endl << endl;
          PresioneUnaTeclaParaContinuar();
        }else if(Verify->NumbersOnly(val)==-1){
          cout << endl<< "El ingreso debe ser numerico" << endl << endl;
          PresioneUnaTeclaParaContinuar();
        }
      }
      switch (option){
        case 0:
        break;

        case 1://Imprimir Clientes de Alta
        system("CLS || clear");
        DB->PrintClientesDeAlta(0);
        DB->PrintClientesDeAlta(1);
        cout<< endl << "Archivo generado exitosamente!" << endl << endl;
        PresioneUnaTeclaParaContinuar();
        break;

        case 2://Imprimir Clientes de Baja
        system("CLS || clear");
        DB->PrintClientesDeBaja(1);
        DB->PrintClientesDeBaja(0);
        cout<< endl<< "Archivo generado exitosamente!" << endl << endl;
        PresioneUnaTeclaParaContinuar();
        break;

        case 3://Imprimir Administrativos
        system("CLS || clear");
        DB->PrintADMINISTRATIVOS(1);
        DB->PrintADMINISTRATIVOS(0);
        cout<< endl << "Archivo generado exitosamente!" << endl << endl;
        PresioneUnaTeclaParaContinuar();
        break;

        case 4://Imprimir Profesionales
        system("CLS || clear");
        DB->PrintPROFESIONALES(1);
        DB->PrintPROFESIONALES(0);
        cout<< endl << "Archivo generado exitosamente!" << endl << endl;
        PresioneUnaTeclaParaContinuar();
        break;

        case 5://Imprimir Base de Datos
        system("CLS || clear");
        DB->PrintDB(1);
        DB->PrintDB(0);
        cout<< endl << "Archivo generado exitosamente!" << endl << endl;
        PresioneUnaTeclaParaContinuar();
        break;
      }

      break;

      case 5://Realizar movimiento de saldo
      system("CLS || clear");
      cout << "MOVIMIENTOS" << endl << endl;
      //Ingreso nro de Cuenta
      while (true){
        cout << "Numero de Cuenta (0 para salir): "; cin.sync(); getline(cin, val);
        //Validacion de entrada
        if (Verify->NumbersOnly(val)==1){
          if (Convert(val,1)==1){
            NRO = stoi(val);
            if(NRO==0){
                break;
            }
            else{
              if(DB->isClient(NRO)==true){
                while (true){
                  system("CLS || clear");
                  cout << "CLIENTE - " << DB->GetClient(NRO)->getNombre() << " " << DB->GetClient(NRO)->getApellido() << endl << endl;
                  cout << "SALDO: " << DB->GetClient(NRO)->C->getSaldo() << endl << endl;
                  cout << "1) Depositar" << endl;
                  cout << "2) Extraer" << endl;
                  cout << "3) Ver historial de movimientos" << endl;
                  cout << "0) Volver" << endl;
                  cout << endl << "Elija una opcion: "; cin.sync(); getline(cin, val);
                  //Validacion de entrada
                  if (Verify->NumbersOnly(val)==1){
                    if (Convert(val,1)==1){
                      option = stoi(val);
                      if(option<=3){
                        break;
                      }
                      else{
                        cout << endl << "Ingrese una opcion valida" << endl << endl;
                        PresioneUnaTeclaParaContinuar();
                      }
                    }else{
                      cout << endl<< "El numero ingresado es demasiado grande" << endl << endl;
                      PresioneUnaTeclaParaContinuar();
                    }
                  }else if(Verify->NumbersOnly(val)==0){
                    cout << endl<< "El campo no puede quedar vacio" << endl << endl;
                    PresioneUnaTeclaParaContinuar();
                  }else if(Verify->NumbersOnly(val)==-1){
                    cout << endl<< "El ingreso debe ser numerico" << endl << endl;
                    PresioneUnaTeclaParaContinuar();
                  }
                }
                switch (option){
                  case 0:
                  break;
                  case 1:
                    while (true){
                      cout << endl << "Ingrese el monto a DEPOSITAR: "; cin.sync(); getline(cin, val);
                      //Validacion de entrada
                      if (Verify->FloatOnly(val)==1){
                        if (Convert(val,0)==1){
                          Monto = stof(val);
                          break;
                        }else{
                          cout << endl<< "El numero ingresado es demasiado grande" << endl << endl;
                        }
                      }else if(Verify->FloatOnly(val)==0){
                        cout << endl<< "El campo no puede quedar vacio" << endl << endl;
                      }else if(Verify->FloatOnly(val)==-1){
                        cout << endl<< "El ingreso debe ser numerico y/o contener UN punto" << endl << endl;
                      }
                    }
                    DB->GetClient(NRO)->C->Deposito(Monto);
                    DB->saveProfDB();
                    DB->saveAdminDB();
                    PresioneUnaTeclaParaContinuar();
                  break;

                  case 2:
                  while (true){
                    cout << endl << "Ingrese el monto a EXTRAER: "; cin.sync(); getline(cin, val);
                    //Validacion de entrada
                    if (Verify->FloatOnly(val)==1){
                      if (Convert(val,0)==1){
                        Monto = stof(val);
                        break;
                      }else{
                        cout << endl<< "El numero ingresado es demasiado grande" << endl << endl;
                      }
                    }else if(Verify->FloatOnly(val)==0){
                      cout << endl<< "El campo no puede quedar vacio" << endl << endl;
                    }else if(Verify->FloatOnly(val)==-1){
                      cout << endl<< "El ingreso debe ser numerico y/o contener UN punto" << endl << endl;
                    }
                  }
                  DB->GetClient(NRO)->C->Extraccion(Monto);
                  DB->saveProfDB();
                  DB->saveAdminDB();
                  PresioneUnaTeclaParaContinuar();
                  break;

                  case 3:
                  system("CLS || clear");
                  DB->GetClient(NRO)->C->showHistory();
                  cout << endl;
                  PresioneUnaTeclaParaContinuar();
                  break;
                }
                break;
              }
              else{
                cout << endl <<"El cliente no se encuentra en el sistema o esta dado de baja" << endl << endl;
              }
            }
          }else{
            cout << endl<< "El numero ingresado es demasiado grande" << endl << endl;
          }
        }else if(Verify->NumbersOnly(val)==0){
          cout << endl<< "El campo no puede quedar vacio" << endl << endl;
        }else if(Verify->NumbersOnly(val)==-1){
          cout << endl<< "El ingreso debe ser numerico" << endl << endl;
        }
      }
      break;

      case 6://Salir
      DB->saveProfDB();
      DB->saveAdminDB();
      exit(0);

      default:
      cout << endl<< "La opcion ingresada no es valida" << endl << endl;
      PresioneUnaTeclaParaContinuar();
      break;
    }
  }
}
