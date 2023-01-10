package pcd_practica8;

import java.util.concurrent.Callable;

/**
 *
 * @author Grefuwan
 */
public class Cliente_Reparador implements Callable<Integer> {

    private CanvasTienda cv;
    private int id;
    private Tienda t;

    public Cliente_Reparador(int id, Tienda t, CanvasTienda cv) {
        this.id = id;
        this.t = t;
        this.cv = cv;
    }

    @Override
    public Integer call() throws Exception {
        int tiempoIni = (int) System.currentTimeMillis();
        try {
            System.out.println("Hilo Reparador: " + Thread.currentThread().getId() + " con ID " + id);
            this.cv.inserta('R', this.id);

            System.out.println("Hilo Reparador: " + Thread.currentThread().getId() + " con ID " + id + " entra en la tienda");
            this.t.EntraReparar(this.id);

            Thread.sleep(2500);

            this.t.SaleReparar(this.id);
            System.out.println("Hilo Reparador: " + Thread.currentThread().getId() + " con ID " + id + " sale de reparar y de la tienda");
        } catch (Exception e) {
        }

        return (int) System.currentTimeMillis() - tiempoIni;
    }

}

