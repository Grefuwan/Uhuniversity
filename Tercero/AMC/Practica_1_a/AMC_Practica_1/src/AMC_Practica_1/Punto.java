package AMC_Practica_1;

import java.awt.Color;
import java.awt.Graphics;

public class Punto {

    double x;
    double y;

    public Punto(double cordX, double cordY) {
        this.x = cordX;
        this.y = cordY;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public void dibujaPuntos(Graphics g, Punto p1) {
        g.setColor(Color.black);
        g.fillOval((int) p1.getX(), (int) p1.getY(), 3, 3);
    }

    @Override
    public String toString() {
        return " [" + getX() + "," + getY() + "]";
    }

}

