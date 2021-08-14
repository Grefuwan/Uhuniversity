#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Autobuses.h"
#include "Itinerario.h"

using namespace std;

int main()
{
    cadena matricula;
    int posicion;
    int opcionMenPrin; //Opcion Menu Principal
    do{
        system ("cls");
        cout << " ------ Menu Principal ------ \t\tJuan Garcia Villagran - 2019-20" << endl;
        cout << "1- Gestion de Autobuses" << endl;
        cout << "2- Gestion de Itinerarios" << endl;
        cout << "3- Listar itinerarios segun franja horaria" << endl;
        cout << "4- Salir" << endl;
        cout << "Introduzca la opcion: " ; cin >> opcionMenPrin;

        switch (opcionMenPrin){

        case 1:{    //Menu Autobuses
            Autobuses autoClase;        //Clase
            autobus autoObjeto;         //Objeto
            char opcionMenAutob;        // Opcion Menu Autobuses
            do{
                system("cls");
                cout << " ----- Menu Gestion de Autobuses ----- " << endl;
                cout << "a) Insertar" << endl;
                cout << "b) Borrar" << endl;
                cout << "c) Modificar" << endl;
                cout << "d) Buscar" << endl;
                cout << "e) Listar" << endl;
                cout << "f) Cargar autobuses desde fichero" << endl;
                cout << "g) Guardar autobuses" << endl;
                cout << "v) Volver" << endl;
                cout << "Elige opcion:"; opcionMenAutob = toupper(getchar());
                    switch (opcionMenAutob){
                        case 'A': //Insertar
                                char EstadoActivoInsertar, EstadoITVInsertar;
                                cout << "Introduzca los datos del autobus: "<< endl;
                                cout << "\tMatricula(NNNNLLL): "; cin >> autoObjeto.matricula;
                                cout << "\tIdentificador del conductor(int): "; cin >> autoObjeto.conductor;
                                cout << "\tActivo o no(bool) (Y/N): "; cin >> EstadoActivoInsertar;
                                    if (EstadoActivoInsertar == 'Y'||'y'){
                                        autoObjeto.e.activo = true;}
                                    else{
                                        autoObjeto.e.activo = false;}
                                cout << "\tLitros del Deposito(float): "; cin >> autoObjeto.e.deposito;
                                cout << "\tNumero de plazas(int): "; cin >> autoObjeto.e.plazas;
                                cout << "\tITV pasada(bool) (Y/N): "; cin >> EstadoITVInsertar;
                                    if (EstadoITVInsertar== 'Y'||'y'){
                                        autoObjeto.e.itv = true;}
                                    else{
                                        autoObjeto.e.itv = false;}
                            autoClase.Insertar(autoObjeto);
                        break;
                        case 'B':   //Borrar
                            cadena matricBorrar;
                            char OpcionBorrar;
                            int posicBorrar;
                            cout << "Indique si quiere borrar por matricula (M) o por posicion (P): "; cin >> OpcionBorrar;
                            if (OpcionBorrar=='M'){
                                posicBorrar = -1;
                                cout << "Indique la matricula(NNNNLLL) del autobus que desee borrar: "; cin >> matricBorrar;
                            }
                            else{
                                cout << "Indique la posicion que desea borrar"; cin >> posicBorrar;
                            }


                            autoClase.Borrar(matricBorrar, posicBorrar);
                            system("pause");
                        break;
                        case 'C':   //Modificar
                            cadena matricModificar;
                            char OpcionModificar;
                            int posicModificar;
                            char EstadoActivoModificar, EstadoITVModificar;
                            cout << "Indique si el autobus que desea modificar lo quiere buscar por Matricula(M) o por Posicion(P): "; cin >> OpcionModificar;
                            if (OpcionModificar=='M'){
                                posicModificar=-1;
                                cout << "Indique la matricula (NNNNLLL) del autobus que desee modificar: "; cin >> matricModificar;
                            }
                            else{
                                cout << "Indique la posicion del autobus a modificar: "; cin >> posicModificar;
                            }

                            cout << "Indique los nuevos datos del autobus: " << endl;
                            cout << "\tMatricula(NNNNLLL): "; cin >> autoObjeto.matricula;
                            cout << "\tIdentificador del conductor(int): "; cin >> autoObjeto.conductor;
                            cout << "\tActivo o no(bool) (Y/N): "; cin >> EstadoActivoModificar;
                                if (EstadoActivoModificar == 'Y'||'y'){
                                    autoObjeto.e.activo = true;}
                                else{
                                    autoObjeto.e.activo = false;}
                            cout << "\tLitros del Deposito(float): "; cin >> autoObjeto.e.deposito;
                            cout << "\tNumero de plazas(int): "; cin >> autoObjeto.e.plazas;
                            cout << "\tITV pasada(bool) (Y/N): "; cin >> EstadoITVModificar;
                                if (EstadoITVModificar== 'Y'||'y'){
                                    autoObjeto.e.itv = true;}
                                else{
                                    autoObjeto.e.itv = false;}
                            autoClase.Modificar(autoObjeto, matricModificar, posicModificar);
                            system("pause");
                        break;
                        case 'D':   //Buscar
                            cadena matricBuscar;
                            char OpcionBuscar;
                            int posicBuscar;
                            cout << "Indique si quiere buscar por Matricula (M) o por posicion (P): "; cin >> OpcionBuscar;
                            if (OpcionBuscar=='M'){
                                posicBuscar = -1;
                                cout << "Indique la matricula (NNNNLLL) del autobus que desee buscar: "; cin >> matricBuscar;
                            }
                            else{
                                cout << "Indique la posicion del autobus a buscar: "; cin >> posicBuscar;
                            }

                            autoClase.Mostrar(matricBuscar, posicBuscar);
                            system("pause");
                        break;
                        case 'E':   //Listar
                            autoClase.Listar();
                            system("pause");
                        break;
                        case 'F':   //Cargar
                            autoClase.Cargar();
                            system("pause");
                        break;
                        case 'G':   //Guardar
                            autoClase.Guardar();
                        break;
                    }
                }while (opcionMenAutob!='V');
            break;}
        case 2:{    //Menu Itinerarios
            char opcionMenItin;
            Itinerario ItinClase;
            itinerario ItinObjeto;
            do{
                system("cls");
                cout << " ----- Menu Gestion de Itinerarios ----- " << endl;
                cout << "a) Insertar" << endl;
                cout << "b) Borrar" << endl;
                cout << "c) Modificar" << endl;
                cout << "d) Buscar" << endl;
                cout << "e) Listar" << endl;
                cout << "f) Cargar itinerarios desde fichero" << endl;
                cout << "g) Guardar itinerarios" << endl;
                cout << "v) Volver" << endl;
                cout << "Elige opcion: "; opcionMenItin = toupper(getchar());

                switch (opcionMenItin){
                        case 'A':   //Insertar
                            char InicioAMInsertar, FinAMInsertar;
                            cout << "Introduzca los datos del itinerario: " << endl;
                            cout << "\tNombre del itinerario: "; cin >> ItinObjeto.nombre;
                            cout << "\tOrigen del itinerario: "; cin >> ItinObjeto.origen;
                            cout << "\tDestino del itinerario: "; cin >> ItinObjeto.destino;
                            cout << "\tIndique si la hora de inicio es AM(Y/N): "; cin >> InicioAMInsertar;
                            if (InicioAMInsertar=='Y'){
                                ItinObjeto.inicio.am = true;
                            }
                            else{
                                ItinObjeto.inicio.am = false;
                            }
                            cout << "\tHora de inicio del itinerario: "; cin >> ItinObjeto.inicio.h;
                            cout << "\tMinutos de inicio del itinerario: "; cin >> ItinObjeto.inicio.m;
                            cout << "\tIndique si la hora de fin es AM(Y/N): "; cin >> FinAMInsertar;
                            if (FinAMInsertar == 'Y'){
                                ItinObjeto.fin.am = true;
                            }
                            else{
                                ItinObjeto.fin.am = false;
                            }
                            cout << "\tHora del fin del itinerario: "; cin >> ItinObjeto.fin.h;
                            cout << "\tMinutos del fin del itinerario: "; cin >> ItinObjeto.fin.m;

                            ItinClase.Insertar(ItinObjeto);
                            system("pause");
                        break;

                        case 'B':   //Borrar
                            char ItinBorrar;
                            cadena ItinMatricBorrar, ItinNombreBorrar;
                            int ItinPosBorrar;
                            cout << "Indique si desea buscar el itinerario a borrar por Matricula y Nombre(M) o por Posicion(P): "; cin >> ItinBorrar;
                            if (ItinBorrar=='M'){
                                ItinPosBorrar=-1;
                                cout << "Indique la matricula del itinerario a buscar: "; cin >> ItinMatricBorrar;
                                cout << "Indique el nombre del itinerario a buscar: "; cin >> ItinNombreBorrar;
                            }
                            else{
                                cout << "Indique la posicion del itinerario a buscar: "; cin >> ItinPosBorrar;
                            }

                            ItinClase.Borrar(ItinNombreBorrar, ItinMatricBorrar, ItinPosBorrar);
                            system("pause");
                        break;

                        case 'C':   //Modificar
                            char ItinModificar;
                            cadena ItinModifMat, ItinModifNombre;
                            int ItinModifPos;
                            cout << "Indique si desea buscar el itinerario a modificar por matricula(M) o por posicion(P): "; cin >> ItinModificar;
                            if (ItinModificar=='M'){
                                ItinModifPos=-1;
                                cout << "Indique la matricula(NNNNLLL): "; cin >> ItinModifMat;
                                cout << "Indique el nombre: "; cin >> ItinModifNombre;
                            }
                            else{
                                cout << "Indique la posicion: "; cin >> ItinModifPos;
                            }

                            char InicioAMModif, FinAMModif;
                            cout << "Introduzca los datos del itinerario: " << endl;
                            cout << "\tNombre del itinerario: "; cin >> ItinObjeto.nombre;
                            cout << "\tOrigen del itinerario: "; cin >> ItinObjeto.origen;
                            cout << "\tDestino del itinerario: "; cin >> ItinObjeto.destino;
                            cout << "\tIndique si la hora de inicio es AM(Y/N): "; cin >> InicioAMModif;
                            if (InicioAMModif=='Y'){
                                ItinObjeto.inicio.am = true;
                            }
                            else{
                                ItinObjeto.inicio.am = false;
                            }
                            cout << "\tHora de inicio del itinerario: "; cin >> ItinObjeto.inicio.h;
                            cout << "\tMinutos de inicio del itinerario: "; cin >> ItinObjeto.inicio.m;
                            cout << "\tIndique si la hora de fin es AM(Y/N): "; cin >> FinAMModif;
                            if (FinAMModif == 'Y'){
                                ItinObjeto.fin.am = true;
                            }
                            else{
                                ItinObjeto.fin.am = false;
                            }
                            cout << "\tHora del fin del itinerario: "; cin >> ItinObjeto.fin.h;
                            cout << "\tMinutos del fin del itinerario: "; cin >> ItinObjeto.fin.m;

                            ItinClase.Modificar(ItinObjeto, ItinModifNombre, ItinModifMat, ItinModifPos);
                            system("pause");
                        break;

                        case 'D':   //Buscar
                            char ItinBuscar;
                            int ItinBuscarPos;
                            cadena ItinBuscarMat, ItinBuscarNomb;
                            cout << "Indique si desea buscar por Matricula(M) y Nombre o por Posicion(P): "; cin >> ItinBuscar;
                            if (ItinBuscar=='M'){
                                ItinBuscarPos=-1;
                                cout << "Indique la Matricula(NNNNLLL): "; cin >> ItinBuscarMat;
                                cout << "Indique el nombre: "; cin >> ItinBuscarNomb;
                            }
                            else{
                                cout << "Indique la posicion: "; cin >> ItinBuscarPos;
                            }

                            ItinClase.Mostrar(ItinBuscarNomb, ItinBuscarMat, ItinBuscarPos);
                            system("pause");
                        break;

                        case 'E':   //Listar
                            ItinClase.Listar();
                            system("pause");
                        break;
                        case 'F':   //Cargar
                            ItinClase.Cargar();
                            system("pause");
                        break;
                        case 'G':   //Guardar
                            ItinClase.Guardar();
                            system("pause");
                        break;

                };
                }
                while (opcionMenItin!='V');
        }
        break;
        case 3:{ //Listar segun franja horaria
            itinerario ItinFranjaHoraria;
            char FranjaHoraria;
            cout << "Indique si la hora de inicio es AM(Y/N): "; cin >> FranjaHoraria;
            if (FranjaHoraria=='Y'){
                ItinFranjaHoraria.inicio.am=true;
            }
            else{
                ItinFranjaHoraria.inicio.am=false;
            }
            cout << "Indique si la hora de fin es AM(Y/N): "; cin >> FranjaHoraria;
            if (FranjaHoraria=='Y'){
                ItinFranjaHoraria.fin.am=true;
            }
            else{
                ItinFranjaHoraria.fin.am=false;
            }

            cout << "Indique la hora de inicio: "; cin >> ItinFranjaHoraria.inicio.h;
            cout << "Indique el minuto de inicio: "; cin >> ItinFranjaHoraria.inicio.m;
            cout << "Indique la hora de fin: "; cin >> ItinFranjaHoraria.fin.h;
            cout << "Indique el minuto de fin; "; cin >> ItinFranjaHoraria.fin.m;
            system("cls");
        }
        break;
        case 4: ;
        break;
    }
    }while (opcionMenPrin!=4);
    return 0;
}
