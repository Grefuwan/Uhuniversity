package AMC_Practica_1;

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

   

    @Override
    public String toString() {
        return " [" + getX() + "," + getY() + "]";
    }
}
