//Ejercicio Tema 2 (Sin constructores virtuales)


#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include <time.h>

using namespace std;

class Base{
	int a;
	public:
		Base (int a) {Base::a = a;}
		virtual void ver() = 0; //virtual puro clase abstracta
		int get() {return a;}
		void set( int a ) {this->a = a;}
};

class Hijo: public Base{
	int b;
	public:
		Hijo1 (int x, int y): Base(x), b(y) { }
		void ver() {cout << get() "," << b << endl;}
		int calcular() {return get() + b; }
};

class Hijo2: public Base{
	public:
		Hijo2 (int a): Base(a){ }
		Hijo2 operator++();	//++obj
		Hijo2 operator++();	//obj++
		void ver() { cout << get() << endl;}
};

Hijo2 Hijo2::operator++(){
	set(get()+1);
	return *this;
}

Hijo2 Hijo2::operator++(){
	Hijo2 copia(*this); //constructor copia
	set(get()+1);
	return copia;
}

Class Hijo3: public Base{
	public:
		Hijo3( int a ): Base(a){ }
		void saludo() {cout << "Hola\n";}
}