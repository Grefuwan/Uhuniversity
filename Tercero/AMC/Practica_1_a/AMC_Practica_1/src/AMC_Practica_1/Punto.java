package AMC_Practica_1;

public class Punto {

    double x;
    double y;

    public Punto(double cordX, double cordY) {
        this.x = cordX;
        this.y = cordY;
    }

    double getPuntoX() {
        return this.x;
    }

    double getPuntoY() {
        return this.y;
    }

    void setPuntoX(double coordX) {
        this.x = coordX;
    }

    void setPuntoY(double coordY) {
        this.y = coordY;
    }

    @Override
    public String toString() {
        return " [" + getPuntoX() + "," + getPuntoY() + "]";
    }
}
