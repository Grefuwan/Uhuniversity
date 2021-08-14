#include "Peluqueria.h"
#include "lista.h"
#include "cola.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>

using namespace std;


void peluqueria::AbrirPeluqueria(char *nombrefichero) {
	ifstream file;
	file.open("inicial.dat", ios::binary);
	if (file.fail())
	cout << "Error al abrir el archivo jamau" << endl;
	else{
        for (int i = 0; i < L.longitud(); i++){
            L.eliminar(i);
        }
        int numPel, numCli;
		peluquero poTMP;
		peluquerof pofTMP;
		cliente cliTMP;
		//cout << "owo" << endl;
		file.read((char *) &numPel, sizeof(int));
		for (int i = 0; i < numPel; i++){
            //cout << "jamau" << endl;
			file.read((char*)&pofTMP, sizeof(pofTMP));
			strcpy(poTMP.Nombre, pofTMP.Nombre);
			strcpy(poTMP.Apellidos, pofTMP.Apellidos);
			poTMP.Codigo = pofTMP.Codigo;
			poTMP.TipoServicio = pofTMP.TipoServicio;
			//cout << "oowowowo" << endl;
            L.insertar(i+1, poTMP);
            cout << L.observar(i+1).Nombre << endl;
			cout << i << endl;
		}

		file.read((char *)&numCli, sizeof(int));
		for (int i = 0; i < numCli; i++) {
			file.read((char *)&cliTMP, sizeof(cliTMP));
			bool incl;
			cout << "cli " << cliTMP.Nombre;
			cout << " Servicio: " << cliTMP.TipoServicio << " ";
            incl = IncorporarCliente(cliTMP);
            if (incl)
                cout << "Incluido correctamente\n";
            else
                cout << "No incluido\n";
        }
	cout << "\n\nCopia cargada en el sistema \n";
	}

	/*MIO -- Da error yo que se -- Grefu

	ifstream file("inicial.dat", ios::binary);
	if (file.fail()) {
		file.clear();
		file.close();
		file.open("inicial.dat", ios::binary);
	}
	else {
		int numPel, numCli;
		peluqueria pTMP;
		peluquero poTMP;
		peluquerof pofTMP;
		cliente cliTMP;

		file.read((char *)&numPel, sizeof(int));
		for (int i = 0; i < numPel; i++){
			file.read((char*)&pofTMP, sizeof(pofTMP));
			strcpy(poTMP.Nombre, pofTMP.Nombre);
			strcpy(poTMP.Apellidos, pofTMP.Apellidos);
			poTMP.Codigo = pofTMP.Codigo;
			poTMP.TipoServicio = pofTMP.TipoServicio;
			L.insertar(i + 1, poTMP);
		}

		file.read((char *)&numCli, sizeof(int));
		for (int i = 0; i < numCli; i++) {
			file.read((char *)&cliTMP, sizeof(cliTMP));
		}

	}*/

	file.close();

}

void peluqueria::IncorporarPeluquero(peluquero t) {
 bool esta=false;
    for(int i=1;i<=L.longitud();i++)
        if(strcmp(L.observar(i).Nombre,t.Nombre)==0 && strcmp(L.observar(i).Apellidos,t.Apellidos)==0){
           esta=true;
           cout<<"Peluquero "<<t.Nombre<<" ya habia sido incorporado con código "<<t.Codigo<<endl;
        }
    if(!esta){
            t.Codigo=L.longitud()+1;
            L.insertar(L.longitud()+1,t);
        cout<<"Peluquero "<<t.Nombre<<" Incorporado con código "<<t.Codigo<<endl;
    }
}

bool peluqueria::RetirarPeluquero(int codigo) {
 cout << "Inserte el codigo del peluquero que desea eliminar: ";
 cin >> codigo;

 if (L.longitud()!= 0){ //Minimo tiene que haber uno de cada tipo, hay que cambiarlo
     for (int i=0; i< L.longitud(); i++){
        if (codigo == L.observar(i).Codigo){
            L.eliminar(i);
        }
     }
 }
 else{
    cout << "No pueden haber 0 peluqueros." << endl;
    system ("pause");
 }

}

bool peluqueria::EliminarCliente(cadena Nombre, cadena Apellido) {
cliente cliTMP;

cout << "Inserte el nombre del cliente que desea borrar: ";
cin >> cliTMP.Nombre;
cout << "Inserte el apellido del cliente a borrar: ";
cin >> cliTMP.Apellidos;
for (int i = 0; i < L.longitud(); i++){
    for (int j = 0; j < L.observar(i).Col.longitud(); j++){
        if (strcmp(cliTMP.Apellidos,L.observar(i).Col.primero().Apellidos) == 0 && strcmp(cliTMP.Nombre , L.observar(i).Col.primero().Nombre) == 0){
            L.observar(i).Col.desencolar();
        }

    }
}
}

bool peluqueria::IncorporarCliente(cliente cli) {
       bool inc=false;
    int cod,i=1;
    cod=pelmenosocupado(cli.TipoServicio,-1);
    while(i<L.longitud() && !inc){
        if(L.observar(i).Codigo==cod){
            L.observar(i).Col.encolar(cli);
            inc=true;
        }
        else i++;
    }
    return inc;
}



void peluqueria::Mostrar() {
peluquero pel;
cliente cli;
cola col;
cadena cadape, cadnom;


    for (int i=1; i<=L.longitud(); i++){
        cout << "\nPeluquero " << i << ": " << L.observar(i).Apellidos << ", " << L.observar(i).Nombre << "\t-Tipo de Servicio: " << L.observar(i).TipoServicio<< endl;
        cout << "Codigo: " << L.observar(i).Codigo << endl;
        cout << "Clientes: " << endl;
        cout << "\tApellidos\t\t\tNombre\t\tEdad\tTipo de Servicio\tHora de llegada" << endl;
        cout << "\t.........\t\t\t.......\t\t....\t.................\t.............." << endl;
        int nc = L.observar(i).Col.longitud();
        if (L.observar(i+1).Col.longitud()>0){
            for (int j=0; j<nc; j++){
            cout << "\t" <<  L.observar(i).Col.primero().Apellidos << "\t\t\t" << L.observar(i).Col.primero().Nombre << "\t\t" << L.observar(i).Col.primero().Edad << "\t\t" << L.observar(i).Col.primero().TipoServicio << "\t\t\t" << L.observar(i).Col.primero().HoraLlegada<< endl;
            L.observar(i).Col.encolar(L.observar(i).Col.primero());
            L.observar(i).Col.desencolar();
        }
        }

    }
}

void peluqueria::VolcarPeluqueria(char *nombrefichero) {

}

int peluqueria::pelmenosocupado(int servicio, int codigo){
int i = 0, npel = L.longitud(), imenor = -1;
    while(i < npel){
        if(L.observar(i).Codigo != codigo && L.observar(i).TipoServicio == servicio &&
           (imenor == -1 || L.observar(i).Col.longitud() < L.observar(imenor).Col.longitud()))
            imenor = i;
        i++;
    }
return imenor;
}

int peluqueria::pelmasocupado(int servicio, int codigo){
int i = 0, npel = L.longitud(), imayor = -1;
    while(i < npel){
        if(L.observar(i).Codigo != codigo && L.observar(i).TipoServicio == servicio &&
           (imayor == -1 || L.observar(i).Col.longitud() > L.observar(imayor).Col.longitud()))
            imayor = i;
        i++;
    }
return imayor;
}
