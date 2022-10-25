/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package AMC_Practica_1;

/**
 *
 * @author Grefuwan
 */
public class Triangulo {

    private Punto a;
    private Punto b;
    private Punto c;

    public Triangulo(Punto a, Punto b, Punto c) {
        super();
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public Punto getA() {
        return a;
    }

    public void setA(Punto a) {
        this.a = a;
    }

    public Punto getB() {
        return b;
    }

    public void setB(Punto b) {
        this.b = b;
    }

    public Punto getC() {
        return c;
    }

    public void setC(Punto c) {
        this.c = c;
    }

    public double perimetro() {
        return Algoritmos.distancia2(a, b) + Algoritmos.distancia2(a, c) + Algoritmos.distancia2(b, c);
    }
    
    public double area(){
        Math.sqrt((this.perimetro()/2 * ))
    }
}
