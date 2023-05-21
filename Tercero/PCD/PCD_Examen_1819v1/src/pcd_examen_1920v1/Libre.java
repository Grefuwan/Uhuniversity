
package pcd_examen_1920v1;

import java.util.Random;

/**
 *
 * @author Grefuwan
 */
public class Libre extends Thread {

    private final int id;
    private final Piscina p;
    
    Random r = new Random();

    public Libre(Piscina p, int id) {
        this.id = id;
        this.p = p;
    }

    @Override
    public void run() {
        try {
            r.setSeed(System.currentTimeMillis());
            System.out.println("Libre: " + id );
            p.EntraLibre();
            
            sleep((r.nextInt(3)+2)*1000);
            
            System.out.println("Sale Libre: " + id);
            p.SaleLibre();
        } catch (InterruptedException ex) {
        }
    }

}

