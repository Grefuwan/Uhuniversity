#include <iostream>

using namespace std;

class TicTacToe
{
    char Tablero [3][3];        //Valores posibles: blanco, X, O
public:
    TicTacToe();
    void LimpiarTablero();
    void Pintar();
    bool PonerFicha (char ficha, int fila, int columna);
    bool ComprobarFila (char ficha, int fila);
    bool ComprobarColumna (char ficha, int columna);
    bool ComprobarDiagonal (char ficha, int fila, int columna);
    bool TableroCompleto();
};

TicTacToe::TicTacToe()
{
    LimpiarTablero();
}

void TicTacToe::LimpiarTablero()
{
    int i,j;

    for (i = 0; i<3; i++)
        for (j = 0; j <3; j++)
            Tablero [i][j] = ' ';
}

void TicTacToe::Pintar()
{
    cout << Tablero [0][0] << "|" << Tablero [0][1] << "|" << Tablero[0][2] << endl;
    cout << "-+-+-" << endl;
    cout << Tablero [1][0] << "|" << Tablero [1][1] << "|" << Tablero[1][2] << endl;
    cout << "-+-+-" << endl;
    cout << Tablero [2][0] << "|" << Tablero [2][1] << "|" << Tablero[2][2] << endl;
}
int main()
{
TicTacToe lmao;

lmao.LimpiarTablero();
lmao.Pintar();
    return 0;
}
