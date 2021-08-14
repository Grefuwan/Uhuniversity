#include "Empresa.h"

//El constructor debe crear un array dinamico de tamaño inicial 10
//Debe inicializar a 0 los contadores de clientes (ncli) y contratos (ncon)
//Y debe inicializar la constante nmaxcli a 100 y la variable nmaxcon a 10

Empresa::Empresa():nmaxcli(100){
    this->ncli=0;
    this->ncon=0;
    this->contratos= new Contrato *[10];    //Inicialmente capacidad para 10 Contratos
    this->nmaxcon=10;
}

//El destructor debe, ademas de eliminar el array dinamico creado en el constructor,
//eliminar los objetos clientes y contratos apuntados por ambos arrays
Empresa::~Empresa(){
    for(int i=0; i<this->ncon; i++) {   //Primero elimino los objetos contratos
        delete this->contratos[i];
    }
    delete [] this->contratos;          //Luego elimino el array de punteros

    for(int i=0; i<this->ncli; i++) {   //Primero elimino los objetos contratos
        delete this->clientes[i];
    }
    //delete [] this->clientes;         //ERROR el array clientes no es dinámico
}

int Empresa::altaCliente(Cliente *c){       //Añade cliente apuntado por c al array clientes
    int pos= -1;                            //Devuelve -1 si no cabe y la posicion donde
    if (this->ncli<nmaxcli){                //lo ha metido si sí cabe
        this->clientes[this->ncli]=c;
        pos=this->ncli;
        this->ncli++;
    }
    else{
        cout << "Lo siento, el cupo de clientes esta lleno";
        pos = -1;
    }
    return pos;
}

int Empresa::buscarCliente(long int dni) const{     //Si no existe devuelve -1 y si existe devuelve la posicion del cliente con ese dni en el array del cliente
    int iCliente=-1, i=0;
    while (i<ncli && iCliente==-1){
        if (clientes[i]->getDni() == dni)
            iCliente=i;
        else
            i++;
    }
    return iCliente;
}

void Empresa::crearContrato(){
long int dni;
    cout << "Introduzca DNI: ";
    cin >> dni;

    int iCliente = -1, i = 0;
    while(i < ncli && iCliente == -1){
        if(clientes[i]->getDni() == dni)
            iCliente = i;
        else i++;
    }

    if(iCliente == -1 && ncli < nmaxcli){
        iCliente = ncli++;
        char nombre[50];
        int dia, mes, anno;
        cout << "Nombre del cliente: ";
        cin.ignore();
        cin.getline(nombre, 50);
        cout << "Fecha de registro (dia, mes, anno): ";
        cin >> dia >> mes >> anno;
        clientes[iCliente] = new Cliente(dni, nombre, Fecha(dia, mes, anno));
    }

    if(iCliente != -1){
        int tipoContrato;
        int minutosHablados;
        int dia, mes, anno;

        cout << "Tipo de contrato a abrir (1-Tarifa Plana,  2-Movil): ";
        cin >> tipoContrato;
        cout << "Fecha del contrato (dia, mes, anno): ";
        cin >> dia >> mes >> anno;
        cout << "Introduzca los minutos hablados: ";
        cin >> minutosHablados;


        if(tipoContrato == 2){
            float precioMinuto;
            cout << "Precio minuto: ";
            cin >> precioMinuto;
            char nac[20];
            cout << "Nacionalidad: ";
            cin >> nac;
            contratos[ncon] = new ContratoMovil(dni, Fecha(dia, mes, anno), precioMinuto, minutosHablados, nac);
            ncon++;
        }else if(tipoContrato == 1){
            //El contrato de tarifa plana no requiere mas datos
            contratos[ncon] = new ContratoTP(dni, Fecha(dia, mes, anno), minutosHablados);
            ncon++;
        }else{
            cout << "Tipo de contrato invalido.\n Operación cancelada.\n";
        }

        //Si la tabla esta llena, la amplio al doble
        if(ncon == nmaxcon){
            nmaxcon *= 2;
            Contrato **tmp = new Contrato*[nmaxcon];
            for(int i = 0; i < ncon; i++)
                tmp[i] = contratos[i];

            delete [] contratos;
            contratos = tmp;
        }
    }else{
        cout << "No se pudo registrar al cliente.\n";
    }
    cout << endl;
}

bool Empresa::cancelarContrato(int idContrato){
    bool cancelado=false;
    int i=0;

    while (i<ncon && !cancelado){
        if (contratos[i]->getIdContrato() == idContrato){
            delete contratos[i];
            while (i<ncon-1){
                contratos[i] = contratos[1+i];
                i++;
            }
            ncon--;
            cancelado=true;
        }
        else
            i++;
    }

    if (ncon<nmaxcon/2){
        nmaxcon /=2;
        Contrato **tmp = new Contrato*[nmaxcon];
        for (int i=0; i<ncon; i++){
            tmp[i]=contratos[i];
        }

        delete[] contratos;
        contratos=tmp;
    }

    return cancelado;
}

bool Empresa::bajaCliente(long int dni){
    bool eliminado = false;
    int i = 0;

    while(i < ncon){
        if(contratos[i]->getDniContrato() == dni){
            cancelarContrato(contratos[i]->getIdContrato());
        }else i++;
    }

    i = 0;
    while(i < ncli && !eliminado){
        if(clientes[i]->getDni() == dni){
            delete clientes[i];
            while(i < ncli-1){
                clientes[i] = clientes[i+1];    //Aqui no le daba la gana de dejarme hacerlo todo una linea
                i++;
            }
            ncli--;
            eliminado = true;
        }else i++;
    }


    return eliminado;
}

int Empresa::descuento(float porcentaje) const{
    int benef=0;
    porcentaje=1-porcentaje/100;

    for(int i=0; i<ncon;i++){
        if (ContratoMovil *c = dynamic_cast<ContratoMovil*>(contratos[i])){
            c->setPrecioMinuto(c->getPrecioMinuto()*porcentaje);
            benef++;
        }
    }

    return benef;
}

int Empresa::nContratosTP() const{
    int tarP = 0;

    for(int i = 0; i < ncon; i++)
        if(typeid(*contratos[i]) == typeid(ContratoTP))
            tarP++;

    return tarP;
}

void Empresa::ver() const {
    cout << "La empresa tiene "<<ncli<<" clientes y "<<ncon<<" contratos" << endl;

    cout << "Clientes:" << endl;
    for(int i = 0; i < ncli; i++)
        cout << *clientes[i] << endl;

    cout << endl << "Contratos:" << endl;
    for(int i = 0; i < ncon; i++){
        contratos[i]->ver();
        cout << endl;
    }
}

void Empresa::cargarDatos(){
    Fecha f1(29,2,2001), f2(31,1,2002), f3(1,2,2002);
    this->clientes[0]=new Cliente(75547001, "Peter Lee", f1);
    this->clientes[1]=new Cliente(45999000, "Juan Perez", Fecha(29,2,2000));
    this->clientes[2]=new Cliente(37000017, "Luis Bono", f2);
    this->ncli=3;

    this->contratos[0] = new ContratoMovil  (75547001, f1, 0.12, 110, "DANES"); //habla 110m a 0.12€/m
    this->contratos[1] = new ContratoMovil  (75547001, f2, 0.09, 170, "DANES"); //habla 170m a 0.09€/m
    this->contratos[2] = new ContratoTP     (37000017, f3, 250); //habla 250m (300m a 10€, exceso 0.15€/m)
    this->contratos[3] = new ContratoTP     (75547001, f1, 312); //habla 312m (300m a 10€, exceso 0.15€/m)
    this->contratos[4] = new ContratoMovil  (45999000, f2, 0.10, 202, "ESPANOL"); //habla 202m a 0.10/m
    this->contratos[5] = new ContratoMovil  (75547001, f2, 0.15, 80, "DANES"); //habla 80m a 0.15€/m
    this->contratos[6] = new ContratoTP     (45999000, f3, 400); //habla 400m (300m a 10€, exceso 0.15€/m)
    this->ncon=7;
}
