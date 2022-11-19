package PCD_Practica4;

import java.util.Random;

/**
 *
 * @author Grefuwan
 */
public class Productor extends Thread {

    int id;
    float numRandom;
    ColaLenta lacola;

    public Productor(int id, ColaLenta lacola) {
        this.id = id;
        this.lacola = lacola;
    }

    /**
     * Debe añadir 10 numeros aleatorios.Pondrá un mensaje por pantalla con el
     * ID del hilo y el num introducido
     *
     */
    @Override
    public void run() {

        Random r = new Random();
        r.setSeed(System.nanoTime());

        synchronized (lacola) {
            try {
                for (int i = 0; i < 10; i++) {
                    sleep((r.nextInt(3) + 1) * 1000);
                    numRandom = r.nextInt(25);
                    System.out.println("Soy el hilo Productor " + this.id + " y voy a añadir el numero " + numRandom);
                    lacola.Acola(numRandom);

                    
                }
            } catch (Exception ex) {
                System.out.println("Error: Productor");

            }
        }

    }

}

