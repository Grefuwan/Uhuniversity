#include "Autobuses.h"

//Casi siempre vamos a tener que poner un if (!cargado) else, para diferenciar si trabajamos en fichero o en memoria
Autobuses::Autobuses(){
    fichero.open("Autobuses.dat", ios::binary|ios::in|ios::out);
    cargado=false;
    tam=0;
    //elementos = new autobus[tam];
    elementos = NULL;
    if (fichero.fail()){
        fichero.clear(); //Limpia el fallo anterior
        fichero.open("Autobuses.dat", ios::binary|ios::out); //Crea el fichero en modo w
        n=0;
        fichero.close(); //Lo cierro para volver a abrirlo en modo r/w
        fichero.open("Autobuses.dat", ios::binary|ios::in|ios::out);
        fichero.read((char*)&n, sizeof(int)); //Carga en N el numero de autobuses
    }
    else{
        fichero.read((char*)&n, sizeof(int)); //Cargo en N el numero de elementos
    }
}

Autobuses::~Autobuses(){
    fichero.close();
    delete[]elementos;
}

void Autobuses::Insertar(autobus a){

    if(cargado==false){       //Fichero
       if(Buscar(a.matricula)==-1){     //Si no encuentra la matricula
            cout << "Fichero" << endl;
            cout << n << endl;
            fichero.seekp(sizeof(int), ios::beg);           //Me salto N, que es un entero
            fichero.seekp(n*sizeof(autobus), ios::cur);     //Desde donde estoy, me salto N Autobuses
            fichero.write((char*)&a, sizeof(autobus));
            n++;
            fichero.seekp(0, ios::beg);                     //Me vuelvo a posicionar al principio
            fichero.write((char*)&n, sizeof(int));          //Actualiza el valor de N en el fichero
            cout << n << endl;
            system("pause");
       }
       else{
            cout << "Error: Matricula ya existente." << endl;
       }
    }

    else{   //Tabla dinamica
        cout << "Tabla dinamica" << endl;
        cout << n;
        if(Buscar(a.matricula)==-1){
            if (tam==n){
                tam+=SALTO;
                autobus *temp=new autobus[tam];
                if (temp!=NULL){
                    for (int i=0;i<n;i++){
                        temp[i]=elementos[i];
                    }
                    delete[]elementos;
                    elementos=temp;
                }
                else{
                    cout << "Error en la memoria pedida" << endl;
                    system("pause");
                }
            }
        }
        elementos[n]=a;
        n++;
        cout << "Anadido correctamente" << endl;
        system("pause");
    }

}

void Autobuses::Borrar(cadena mat, int pos){
    if (cargado == false){      //Fichero
        autobus autoAux;
        cout << "Fichero" << endl;
        if (pos==-1)   //Que borra por matricula
            pos = Buscar(mat);  //Me busca la posicion de la matricula en cuestion
            for (int i = pos; i<n; i++){    //Bucle para sobreponer los autobuses.
                    fichero.seekg (sizeof(int) + (i*sizeof(autobus)), ios::beg);   //Leo el autobus siguiente
                    fichero.read ((char*)&autoAux, sizeof(autobus));
                    fichero.seekp (sizeof(int)+ (i-1)*sizeof(autobus), ios::beg);   //Escribo en el que quiero borrar
                    fichero.write ((char*)&autoAux, sizeof(autobus));
            }
            n--;
            fichero.seekp(0, ios::beg); //Me posiciono al principio
            fichero.write ((char*)&n, sizeof(int));
}

    else{       //Memoria
            cout << "Memoria" << endl;
            if (pos==-1){
                pos = Buscar(mat);
                for (int i = pos; i < n; i++){
                    elementos[i]=elementos[i+1];
                }
            }
    }
}


void Autobuses::Modificar(autobus a, cadena mat, int pos){
    autobus aut;
    if (cargado == false){  //Fichero
        cout << "Fichero" << endl;
        if (pos == -1){
            pos = Buscar(mat);
        }
            pos--;
            cout << mat << endl;
            cout <<"Posicion" <<  pos << endl;
        if (pos == -1){
            cout << "No se ha encontrado el autobus en cuestion" << endl;
        }
        else{
            fichero.seekp(sizeof(int) + sizeof(autobus)*pos, ios::beg);
            fichero.write((char*)&a, sizeof(autobus));
            fichero.seekp(0, ios::beg); //Me vuelvo a posicionar al principio
        }
    }
    else{   //Memoria Dinamica
        cout << "Memoria dinamica" << endl;
        if (pos == -1)
            pos = Buscar(mat);
        if (pos == -1){
            cout << "No se ha encontrado el autobus en cuestion" << endl;
        }
        else{
            elementos[pos]=a;
        }
    }
}

int Autobuses::Buscar(cadena mat){ //Devuelve la posicion del autobus
autobus aut;
bool encontrado = false;
int i=1;
    cout << "\t\n Metodo Buscar" << endl;
    if (cargado == false){
        fichero.seekg(sizeof(int), ios::beg); //Para que pase uno (recordar estructura de la tabla, que el primer valor es el nº de autobuses)
        while (i<=n && !encontrado){
                fichero.read((char*)&aut, sizeof(autobus));
            if(strcmp(aut.matricula,mat)==0)
                encontrado = true;
            else
                i++;
        }
    }
    else {
        while (i<=n && !encontrado){
            if (strcmp(elementos[i].matricula, mat)==0)
                encontrado = true;
            else
                i++;
        }
    }

    if (encontrado==false){
        cout << "Autobus no encontrado" << endl;
        system("pause");
        i = -1;
    }

return i;
}

void Autobuses::Mostrar(cadena mat, int pos){
    autobus aut;

    if(pos==-1){
        pos = Buscar(mat);
    }
    else
        pos--;

    if (cargado == false){  //Fichero
        cout << "Fichero" << endl;
        fichero.seekg(sizeof(autobus)*pos + sizeof(int), ios::beg);
        fichero.read ((char*)&aut, sizeof(autobus));
    }
    else{   //Memoria Dinamica
        aut = elementos[pos];
    }

    cout << "\n\nEl autobus ha sido encontrado." << endl;
    cout << "\tMatricula: " << aut.matricula << endl;
    cout << "\tCapacidad: " << aut.e.plazas << endl;
    cout << "\tActivo: " << aut.e.activo << endl;
    cout << "\tDeposito: " << aut.e.deposito << endl;
    //cout << "\tOcupacion: " << aut.e.ocupacion << endl;
    cout << "\tITV: " << aut.e.itv << endl;
    cout << "\tConductor: " << aut.conductor << endl;
}

void Autobuses::Listar(){
    autobus aut;
    if(cargado==false){   //Fichero
        cout << "Fichero" << endl;
        if (!fichero.fail()){
            fichero.seekg (sizeof(int), ios::beg);
            for (int i=1; i<=n; i++){
                fichero.read ((char *)&aut, sizeof(aut));
                //Mostrar por pantalla todo los datos del autobus
                cout << "\n\nAutobus numero " << i << endl;
                cout << "\tMatricula: " << aut.matricula << endl;
                cout << "\tCapacidad: " << aut.e.plazas << endl;
                cout << "\tActivo: " << aut.e.activo << endl;
                //cout << "\tOcupacion: " << aut.e. << endl;
                cout << "\tITV: " << aut.e.itv << endl;
                cout << "\tConductor: " << aut.conductor << endl;
            }
        }
    }
    else{   //Tabla Dinamica
        cout << "Memoria Dinamica" << endl;
        for (int i = 0; i<n; i++){
                cout << "\n\nAutobus numero " << i << endl;
                cout << "\tMatricula: " << elementos[i].matricula << endl;
                cout << "\tCapacidad: " << elementos[i].e.plazas << endl;
                cout << "\tActivo: " << elementos[i].e.activo << endl;
                //cout << "\tOcupacion: " << aut.e. << endl;
                cout << "\tITV: " << elementos[i].e.itv << endl;
                cout << "\tConductor: " << elementos[i].conductor << endl;
        }

    }

}

bool Autobuses::Cargar(){ //Carga en memoria el fichero. Devuelve true si correcto, false si error
bool carga = false;

    if(elementos != NULL)
        delete [] elementos;

    while(tam<n)
        tam += SALTO;

    elementos = new autobus[tam];

                fichero.seekg(sizeof(int),ios::beg);
                fichero.read((char *)elementos,sizeof(autobus)*n);//lectura directamente de todo

    if(fichero.fail() || elementos==NULL)
        cout<<"No se pudo cargar correctamente."<<endl;
    else  {
                carga = true;
                cargado = true;
                cout << "Carga correcta" << endl;
            }

    return carga;
}

bool Autobuses::Guardar(){  //Hay que ponerlos ordenados por matricula ||
    bool guardado;
    if (cargado==true){
        autobus aut, aux;
        fichero.seekp(0, ios::beg);
        fichero.write((char*)&n, sizeof(int));
        for(int j=0;j<n-1;j++) {
            for(int i=j+1;i<n;i++){
                if(strcmp(elementos[j].matricula,elementos[i].matricula)>0){ //El STRCMP, si el primer elemento es mayor que el segundo, devuelve un numero >0
                    aux=elementos[j];
                    elementos[j]=elementos[i];
                    elementos[i]=aux;
                }
            }
        }

        for (int i=0; i<n; i++){
            aut = elementos[i];
            fichero.seekp(sizeof(int) + sizeof(aut)*i, ios::beg);
            fichero.write((char*)&aut, sizeof(aut));
        }
        guardado = true;
        cout << "Guardado perfe" << endl;
    }
    else{
        guardado = false;
        cout << "Guardado erroneo" << endl;
    }
    return guardado;
}
