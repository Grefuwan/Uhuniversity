package pcd_practica7;

import java.util.Random;

/**
 *
 * @author Grefuwan
 */
public class Coche extends Thread {

    int id;
    Random r = new Random();
    Tunel t;
    MiCanvas cv;

    public Coche(int id, Tunel t, MiCanvas cv) {
        this.id = id;
        this.t = t;
        this.cv = cv;
    }

    @Override
    public void run() {
        try {
            cv.representaCocheEspera(id);
            sleep(1000);
            System.out.println("Llega el coche " + id + " a la cola");
            
            t.entraCoche();
            
            cv.representaCocheLavando(id);
            sleep((r.nextInt(3)+1)*1000);   //Se lava durante 1 y 3 segundos
            
            t.saleCoche();
            cv.borraCoche(id);
            
            System.out.println("Sale el coche con ID " + id);
            
        } catch (InterruptedException ex) {
        }

    }

}

