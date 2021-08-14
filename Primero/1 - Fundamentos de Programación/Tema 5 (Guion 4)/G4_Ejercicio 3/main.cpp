#include <iostream>

using namespace std;

typedef char Cadena[50];    //Tipo de datos Cadena
#define MAX_CUENTAS 100     //Número de Cuentas
class Cuenta                //Contiene los datos de una cuenta bancaria
{
    float Saldo;            //Saldo de la cuenta
    int NoCuenta;           //Número de la cuenta
    bool Bloqueada;         //true si está bloqueada
public:
    Cuenta();
    Cuenta(int pNo, float pSal);
    bool ActualizarSaldo(int pSal);
    void ActualizarBloqueo(bool pBloq);
    float DameSaldo();
    int DameNoCuenta();
    bool EstaBloqueada();
};

Cuenta::Cuenta()
{
    Saldo = 0;
    NoCuenta = 0;
    Bloqueada = false;
}

Cuenta::Cuenta(int Pno, float pSal)
{
    NoCuenta = Pno;
    Saldo = pSal;
    Bloqueada = false;
}

bool Cuenta::ActualizarSaldo(int pSal)
{   bool estado;
    if (Bloqueada = false)
        {   Saldo = pSal;
            estado = true;
        }
    else estado = false;
    return estado;
}




int main()
{

}
