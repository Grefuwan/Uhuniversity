package PCD_Practica4;

import static java.lang.Thread.sleep;
import java.util.Random;

/**
 *
 * @author Grefuwan
 */
public class Consumidor implements Runnable {

    private final int id;
    private final int numElemsDesacolar = 15;
    ColaLenta lacola;
    Random r = new Random();

    public Consumidor(int id, ColaLenta lacola) {
        this.id = id;
        this.lacola = lacola;
    }

    /**
     * Esta clase consume elementos de la cola
     *
     */
    @Override
    public void run() {

        synchronized (lacola) {
            try {
                for (int i = 0; i < numElemsDesacolar; i++) {
                    sleep((r.nextInt(3) + 1) * 1000);
                    System.out.println("Soy el hilo Consumidor " + Thread.currentThread().getId()
                            + " y voy a extraer el número " + lacola.Desacola());
                }

                System.out.println("El consumidor ha terminado");
                synchronized (lacola) {
                    notifyAll();
                }

            } catch (Exception ex) {
                System.out.println("Error: Consumidor");
            }
        }

    }

}

