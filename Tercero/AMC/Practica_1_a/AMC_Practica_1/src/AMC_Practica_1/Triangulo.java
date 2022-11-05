
package AMC_Practica_1;

import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author Grefuwan
 */
public class Triangulo {

    private Punto a;
    private Punto b;
    private Punto c;

    /**
     *
     * @param a
     * @param b
     * @param c
     */
    public Triangulo(Punto a, Punto b, Punto c) {
        super();
        this.a = a;
        this.b = b;
        this.c = c;
    }

    /**
     *
     * @return
     */
    public Punto getA() {
        return a;
    }

    /**
     *
     * @param a
     */
    public void setA(Punto a) {
        this.a = a;
    }

    /**
     *
     * @return
     */
    public Punto getB() {
        return b;
    }

    /**
     *
     * @param b
     */
    public void setB(Punto b) {
        this.b = b;
    }

    /**
     *
     * @return
     */
    public Punto getC() {
        return c;
    }

    /**
     *
     * @param c
     */
    public void setC(Punto c) {
        this.c = c;
    }

    /**
     *
     * @return
     */
    public double perimetro() {
        return Algoritmos.distancia2(a, b) + Algoritmos.distancia2(a, c) + Algoritmos.distancia2(b, c);
    }

    /**
     *
     * @return
     */
    public double area() {
        return Math.sqrt((this.perimetro() / 2) * (((this.perimetro() / 2) - Algoritmos.distancia2(a, b))
                * ((this.perimetro() / 2) - Algoritmos.distancia2(a, c))
                * ((this.perimetro() / 2) - Algoritmos.distancia2(b, c))));

    }
    
    public void dibujaLados(Graphics g, Punto p1, Punto p2, Punto p3){
        g.setColor(Color.red);
        g.drawLine((int) p1.getX(), (int)p1.getY(), (int)p2.getX(), (int)p2.getY());
        g.drawLine((int) p2.getX(), (int)p2.getY(), (int)p3.getX(), (int)p3.getY());
    }
}
