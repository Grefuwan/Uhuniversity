package pcd_examen_1819v2;

public class Generador {

    public static void main(String[] args) {

        int numPersonas = 20;

        Thread[] nadadores = new Thread[numPersonas];
        Piscina p = new Piscina();

        for (int i = 0; i < numPersonas; i++) {
            nadadores[i] = new Thread(new Nadador(i, p));
            nadadores[i].start();
        }

    }

}

