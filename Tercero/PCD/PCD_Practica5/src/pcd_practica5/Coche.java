package pcd_practica5;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Grefuwan
 */
public class Coche extends Thread {

    private Tunel t;
    private MiCanvas cv;

    public Coche(Tunel t, MiCanvas cv) {
        this.t = t;
        this.cv = cv;
    }

    @Override
    public void run() {
        try {
            System.out.println("Entra un Coche con ID: " + this.getId());
            Random r = new Random();
            cv.representaCoche((int) this.getId());

            Thread.sleep((r.nextInt(3) + 1) * 1000);

            char Sitio = t.entraCoche((int) this.getId());

            Thread.sleep((r.nextInt(3) + 1) * 1000);

            t.saleCoche(Sitio);

            cv.borraCoche();

            System.out.println("Sale el Coche con ID: " + this.getId());

        } catch (InterruptedException ex) {
            Logger.getLogger(Coche.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}

