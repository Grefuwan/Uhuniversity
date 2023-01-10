package AMC_Practica_1;

import Algoritmos.Distancias;
import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

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
        return Distancias.distancia2(a, b) + Distancias.distancia2(a, c) + Distancias.distancia2(b, c);
    }

    public double area() {
        return Math.sqrt((this.perimetro() / 2) * (((this.perimetro() / 2) - Distancias.distancia2(a, b))
                * ((this.perimetro() / 2) - Distancias.distancia2(a, c))
                * ((this.perimetro() / 2) - Distancias.distancia2(b, c))));

    }

    public void dibujaLados(Graphics g, Punto p1, Punto p2, Punto p3) {
        g.setColor(Color.red);
        g.drawLine((int) p1.getX(), (int) p1.getY(), (int) p2.getX(), (int) p2.getY());
        g.drawLine((int) p2.getX(), (int) p2.getY(), (int) p3.getX(), (int) p3.getY());
    }

    /**
     *
     * @return Devuelve la suma de los dos lados menores del triangulo formado
     *         por p1, p2 y p3
     */
    public double sumaLadoMenores() {
        double dist1 = Distancias.distancia2(a, b);
        double dist2 = Distancias.distancia2(b, c);
        double dist3 = Distancias.distancia2(a, c);

        double suma = dist1 + dist2 < dist1 + dist3 ? dist1 + dist2 : dist1 + dist3;
        suma = dist2 + dist3 < suma ? dist2 + dist3 : suma;

        return suma;

    }

    public ArrayList<Punto> trianguloToArrayList() {
        ArrayList arrResult = new ArrayList();
        arrResult.add(a);
        arrResult.add(b);
        arrResult.add(c);
        return arrResult;
    }

}

