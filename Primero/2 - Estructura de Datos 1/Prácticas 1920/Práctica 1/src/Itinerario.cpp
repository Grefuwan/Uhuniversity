#include "Itinerario.h"

Itinerario::Itinerario(){
    cargado = false;
    fichero.open("Itinerarios.dat", ios::binary|ios::in|ios::out);
    fichero.seekg(0, ios::end);             //Me posiciono al final
    n=fichero.tellg()/sizeof(itinerario);   //Saco n dividiendo el numero de bytes entre el tamaño de un itinerario
    tam=0;
    elementos = NULL;
}

Itinerario::~Itinerario(){
    fichero.close();
    delete[]elementos;
}

void Itinerario::Insertar(itinerario i){
    if (cargado==false){
        cout << "Error. No se ha cargado el fichero"<< endl;
    }
    else{
            if(Buscar(i.matricula, i.nombre)==-1){
                elementos[n]=i;
                n++;
            }
            else{
                cout <<"El itinerario indicado ya existe" << endl;
            }
    }
}

void Itinerario::Borrar(cadena nombrei, cadena mat, int pos){
    if (cargado==false){
        cout << "Error. No se ha cargado el fichero"<< endl;
    }
    else{
            if (pos==-1){
                pos = Buscar(nombrei, mat);
                for (int i = pos; i < n; i++){
                    elementos[i]=elementos[i+1];
                }
            }
    }
}

void Itinerario::Modificar(itinerario a, cadena nombrei, cadena mat, int pos){
    if (cargado==true){
        cout << "Memoria dinamica" << endl;
        if (pos == -1)
            pos = Buscar(nombrei,mat);
        if (pos == -1){
            cout << "No se ha encontrado el autobus en cuestion" << endl;
        }
        else{
            elementos[pos]=a;
        }
    }
    else{
        cout << "Error. Hay que cargar primero" << endl;
    }
}

int Itinerario::Buscar(cadena nombrei, cadena mat){
    int posicion;
    if (cargado==false){
        cout << "Carga primero." << endl;
    }
    else{
        bool encontrado = false;
    }
    return posicion;
}

void Itinerario::Mostrar(cadena nombrei, cadena mat, int pos){
    if(cargado)
    {
        if(pos==-1){
            pos=Buscar(nombrei,mat);
        }
        else
            pos--;
        if(pos!=-1){
            char HoraFinalUno='P', HoraFinalDos='M', HoraInicioUno='A', HoraInicioDos='M';
            HoraInicioUno='P';
            if (elementos[pos].inicio.am==true){
                HoraInicioUno='A';
            }
            if (elementos[pos].fin.am==true){
                HoraFinalUno='A';
            }
            cout << "Matricula: " << elementos[pos].matricula << endl;
            cout << "Nombre: " << elementos[pos].nombre << endl;
            cout << "Hora Inicio: " << elementos[pos].inicio.h << ":" << elementos[pos].inicio.m << HoraInicioUno << HoraInicioDos << endl;
            cout << "Hora Fin: " << elementos[pos].fin.h << ":" << elementos[pos].fin.m << HoraFinalUno << HoraFinalDos << endl;
            cout << "Origen: " << elementos[pos].origen << endl;
            cout << "Destino: " << elementos[pos].destino << endl;
        }
        else{
            cout<<"No existe el itinerario" << endl;
        }
    }
    else
        cout<<"Error. No se ha cargado previamente" << endl;
}

void Itinerario::Listar(){
    if(cargado==true)
    {
        char Hfini1='P',Hfini2='M', Hini1='P',Hini2='M';
        for(int i=0;i<n;i++)
        {
            Hfini1='P';
            Hini1='P';
            if(elementos[i].inicio.am)
                Hini1='A';
            if(elementos[i].fin.am)
                Hfini1='A';
            cout << "\n\tNombre: " <<elementos[i].nombre << endl;
            cout << "\tHora inicio: " << elementos[i].inicio.h << ":" << elementos[i].inicio.m << " "<< Hini1 << Hini2 << endl;
            cout << "\tHora fin: "<< elementos[i].fin.h << ":" << elementos[i].fin.m << " " << Hfini1 << Hfini2 << endl;
            cout << "\tOrigen: " << elementos[i].origen << endl;
            cout << "\tDestino: " << elementos[i].destino << endl;
            cout << "\tMatricula: " << elementos[i].matricula << endl;
        }
    }else
    {
        cout<<"Error. No se ha cargado previamente" << endl;
    }
}

bool Itinerario::Cargar(){
bool carga = false;

    if(elementos != NULL)
        delete [] elementos;

    while(tam<n)
        tam += SALTO;

    elementos = new itinerario[tam];

    fichero.seekg(0,ios::beg);
    fichero.read((char *)elementos,sizeof(itinerario)*n);//lectura directamente de todo

    if(fichero.fail() || elementos==NULL)
        cout<<"No se pudo cargar correctamente"<<endl;
    else {
            carga = true;
            cargado = true;
            cout << "Carga correcta" << endl;
    }

    return carga;
}

bool Itinerario::Guardar(){
    bool guardado;
    if(cargado)
    {
        itinerario a;
        fichero.seekp(0,ios::beg);
        fichero.write((char *)elementos,sizeof(a)*n);
        guardado=true;
    }else
    {
        guardado=false;
    }

    return guardado;
}

void Itinerario::FranjaHoraria(Hora horaIni, Hora horaFin){
    int tiempo1=0, tiempo2=0, comparar1=0, comparar2=0;
    char Hfini1='P',Hfini2='M', Hini1='P',Hini2='M';
    itinerario a;
    if(!horaIni.am) tiempo1+=720;
    if(!horaFin.am) tiempo2+=720;
    tiempo1 = tiempo1 + horaIni.m + (horaIni.h * 60);
    tiempo2 = tiempo2 + horaFin.m + (horaFin.h *60);
    cout<<endl<<"Ini AM: "<<horaIni.am;
    cout<<endl<<"Fin AM: "<<horaFin.am;
    cout<<endl<<"HoraFin: "<<horaFin.h<<" : "<<horaFin.m;
    cout<<endl<<"Horaini: "<<horaIni.h<<" : "<<horaIni.m;
    cout<<endl<<"T1: "<<tiempo1<<endl<<"T2: "<<tiempo2;
    system("pause");
    fichero.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fichero.seekg(sizeof(a)*i,ios::beg);
        fichero.read((char *)&a,sizeof(a));
        if(!a.inicio.am) comparar1 = 720;
        if(!a.fin.am) comparar2 = 720;
        comparar1 = comparar1 + a.inicio.m + (a.inicio.h*60);
        comparar2 = comparar2 + a.fin.m + (a.fin.h * 60);
        if(tiempo1 <= comparar1 && tiempo2 >= comparar2) //mostramos
        {
            Hfini1='P';
            Hini1='P';
            if(a.inicio.am) Hini1='A';
            if(a.fin.am) Hfini1='A';
            cout<<"Nombre: "<<a.nombre<<endl
                <<"Hora inicio: "<<a.inicio.h<<" : "<<a.inicio.m<<" "<<Hini1<<Hini2<<endl
                <<"Hora fin: "<<a.fin.h<<" : "<<a.fin.m<<" "<<Hfini1<<Hfini2<<endl
                <<"Origen: "<<a.origen<<endl
                <<"Destino: "<<a.destino<<endl
                <<"Matricula: "<<a.matricula<<endl;
        }
    }
}
