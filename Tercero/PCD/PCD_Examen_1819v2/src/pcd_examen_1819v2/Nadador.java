package pcd_examen_1819v2;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Grefuwan
 */
public class Nadador implements Runnable {

    private final int id;
    private final Piscina p;

    Random r = new Random();

    public Nadador(int id, Piscina p) {
        this.id = id;
        this.p = p;
    }

    @Override
    public void run() {
        try {
            r.setSeed(System.currentTimeMillis());

            p.entraPiscina();
            System.out.println("Nadador " + id + " entra piscina");

            System.out.println("Nadador " + id + " inicia calentamiento");
            Thread.sleep((r.nextInt(2) + 1) * 1000);

            System.out.println("Nadador " + id + " quiere conseguir equipamiento");
            p.cogeMaterial();
            System.out.println("Nadador " + id + " consigue equipamiento");

            Thread.sleep((r.nextInt(2) + 2) * 1000);

            System.out.println("Nadador " + id + " suelta equipamiento y se va de la piscina");
            p.sueltaMaterial();
            p.salePiscina();

        } catch (InterruptedException ex) {

        }
    }

}

