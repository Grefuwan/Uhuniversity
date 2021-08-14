
#include <iostream>
#include "Test.h"
#include <stdlib.h>
#include "ConjuntoInt.h"
#include "Constantes.h"
using namespace std;

/* Programa principal */
int main()
{
	int opcion, opcteor, opcteorcasos;	//opcteor = Opcion Teorica |·| opcteorcasos = Opcion Teorica Casos (Mejor, Medio o Peor)
	int opcempir, opcempircasos;       //opcempir = Opcion Empirica
	cout << " " << endl;
	cout << "\t *** FAA. Practica 1. Curso 18/19 ***" << endl;
	cout << "\t\t\t\t\t\tAutor: Juan Garcia Villagran" << endl;
	cout << " " << endl;
	cout << "*** ESTUDIO DE LA COMPLEJIDAD DEL ALGORITMO BUSQUEDA SECUENCIAL ***" << endl;
	cout << " " << endl;
	cout << "\t\t1.- ESTUDIO TEORICO" << endl;
	cout << "\t\t2.- ESTUDIO EMPIRICO" << endl;
	cout << "\t\t0.- Salir" << endl;
	cout << "\t\t--------" << endl;
	cout << "\t\tElige opcion:";
	cin >> opcion;
	switch (opcion){
	case 1: {
				system("cls");
				cout << "\t*** MENU TEORICO DEL ALGORITMO DE BUSQUEDA SECUENCIAL***" << endl;
				cout << " " << endl;
				cout << "\t1.- Probar el algoritmo busqueda secuencial" << endl;
				cout << "\t2.- Obtener los casos del metodo de busqueda secuencial" << endl;
				cout << "\t3.- Comparar los casos" << endl;
				cout << "\t0.- Volver al menu principal" << endl;
				cout << "\t----------";
				cout << "\tElige opcion: ";
				cin >> opcteor;
				switch (opcteor){

				case 1:{
                    system ("cls");
					TestAlgoritmo Test;
					Test.comprobarAlgoritmo();
					}
					break;


				case 2:{
                    system ("cls");
					TestAlgoritmo Test;
                    cout << "\n\t\t*** Caso a estudiar para la busqueda secuencial ***" << endl;
                    cout << "\t\t0: Caso peor" << endl;
                    cout << "\t\t1: Caso medio" << endl;
                    cout << "\t\t2: Caso mejor" << endl;
                    cout << "\t\t-------------" << endl;
                    cout << "Elige opcion: "; cin >> opcteorcasos;
					Test.costeCasoTeorico(opcteorcasos);
                    }
                break;
				

                case 3:{
                    system ("cls");
					TestAlgoritmo Test;
					Test.compararTeorico(SECUENCIALPEOR, SECUENCIALMEDIO, SECUENCIALMEJOR);
                }
				break;


                case 0:{
					cout << "Taluego maquina fiera bestia mastodonte tiranosaurio" << endl;
                }
				break;


            }
		break;
	}
		
	case 2:{
                system ("cls");
                cout << "\t *** MENU EMPIRICO DEL ALGORITMO DE BUSQUEDA SECUENCIAL ***" << endl;
                cout << "\t1.- Probar el algoritmo busqueda secuencial" << endl;
                cout << "\t2.- Obtener los casos del metodo de busqueda secuencial" << endl;
                cout << "\t3.- Comparar los casos" << endl;
                cout << "\t0.- Volver al menu principal"<< endl;
                cout << "\tElige opcion:";
                cin >> opcempir;
                switch (opcempir){

                case 1: {
							system("cls");
							TestAlgoritmo Test;
							Test.comprobarAlgoritmo();
                }
					break;


				case 2: {
							system("cls");
							TestAlgoritmo Test;
							cout << "\n\t\t*** Caso a estudiar para la busqueda secuencial ***" << endl;
							cout << "\t\t0: Caso peor" << endl;
							cout << "\t\t1: Caso medio" << endl;
							cout << "\t\t2: Caso mejor" << endl;
							cout << "\t\t-------------" << endl;
							cout << "Elige opcion: "; cin >> opcempircasos;
							switch (opcempircasos)
							{
							case 0: {
										Test.costeCasoEmpirico(SECUENCIALPEOR);
							}
								break;

							case 1: {
										Test.costeCasoEmpirico(SECUENCIALMEDIO);
							}
								break;
							case 2: {
										Test.costeCasoEmpirico(SECUENCIALMEJOR);
							}
								break;
							}
				}
					break;


				case 3: {
					system("cls");
					TestAlgoritmo Test;
					Test.compararEmpirico(SECUENCIALPEOR, SECUENCIALMEDIO, SECUENCIALMEJOR);
				}
					break;


				case 0:{

				}
					break;

                }

	}
		break;
	case 0:
		break;
	}







	system ("pause");
return 0;
}

