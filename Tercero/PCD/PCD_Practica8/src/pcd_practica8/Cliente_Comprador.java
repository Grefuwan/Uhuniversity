package pcd_practica8;

import java.util.concurrent.Callable;

/**
 *
 * @author Grefuwan
 */
public class Cliente_Comprador implements Callable<Integer> {

    private CanvasTienda cv;
    private int id;
    private Tienda t;

    public Cliente_Comprador(int id, Tienda t, CanvasTienda cv) {
        this.id = id;
        this.t = t;
        this.cv = cv;
    }

    @Override
    public Integer call() throws Exception {
        try {
            System.out.println("Hilo Comprador: " + Thread.currentThread().getId() + " con ID " + id);
            this.cv.inserta('C', this.id);

            System.out.println("Hilo Comprador: " + Thread.currentThread().getId() + " con ID " + id + " entra en la tienda");
            char tipo = this.t.EntraComprar(this.id);

            Thread.sleep(1000);
            this.t.SaleComprar(tipo, this.id);
            System.out.println("Hilo Comprador: " + Thread.currentThread().getId() + " con ID " + id + " sale de comprar y de la tienda");

        } catch (Exception e) {
        }

        return id;
    }

}

