package pcd_examen_1920v1;

import static java.lang.Thread.sleep;
import java.util.Random;

/**
 *
 * @author Grefuwan
 */
public class Generador {

    public static void main(String[] args) throws InterruptedException {

        Random r = new Random();
        r.setSeed(System.currentTimeMillis());
        int prob;

        int numPersonas = 20;

        Thread[] nadadores = new Thread[numPersonas];

        Piscina p = new Piscina();

        for (int i = 0; i < numPersonas; i++) {
            prob = r.nextInt(10);

            if (prob < 2) {
                nadadores[i] = new Libre(p, i);
            }
            else {
                nadadores[i] = new Thread(new Club(p, i));
            }
            nadadores[i].start();
            sleep((r.nextInt(2)+1)*1000);
        }
        
        for (int i = 0; i < numPersonas; i++) {
            nadadores[i].join();
        }
        

    }

}

