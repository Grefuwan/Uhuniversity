package pcd_practica7;

import static java.lang.Thread.sleep;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Grefuwan
 */
public class Furgo implements Runnable {

    int id;
    Tunel t;
    MiCanvas cv;
    Random r = new Random();

    public Furgo(int id, Tunel t, MiCanvas cv) {
        this.id = id;
        this.t = t;
        this.cv = cv;
    }

    @Override
    public void run() {

        try {
            cv.representaFurgoEspera(id);
            sleep(1000);
            System.out.println("Llega la furgo " + id + " a la cola");

            t.entraFurgo();

            cv.representaFurgoLavando(id);
            sleep((r.nextInt(3) + 1) * 1000);

            t.saleFurgo();
            cv.borraFurgo(id);

            System.out.println("Sale la furgo con ID " + id);

        } catch (InterruptedException ex) {
            
        }
    }

}

