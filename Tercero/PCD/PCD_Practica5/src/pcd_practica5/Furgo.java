package pcd_practica5;

import java.util.Random;

/**
 *
 * @author Grefuwan
 */
public class Furgo implements Runnable {

    private Tunel t;
    private MiCanvas cv;

    public Furgo(Tunel t, MiCanvas cv) {
        this.t = t;
        this.cv = cv;
    }

    /**
     *
     */
    @Override
    public void run() {

        try {
            System.out.println("Soy un hilo Furgo con ID: " + Thread.currentThread().getId());
            Random r = new Random();

            cv.representaFurgo((int) Thread.currentThread().getId());

            Thread.sleep((r.nextInt(3) + 1) * 1000);

            char Sitio = t.entraFurgo((int) Thread.currentThread().getId());

            Thread.sleep((r.nextInt(3) + 1) * 1000);

            t.saleFurgo(Sitio);

            cv.borraFurgo();

            System.out.println("Sale la Furgo con ID: " + Thread.currentThread().getId());

        } catch (Exception e) {
        }
    }

}

