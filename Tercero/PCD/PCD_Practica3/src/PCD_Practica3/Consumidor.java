package PCD_Practica3;

/**
 *
 * @author Grefuwan
 */
public class Consumidor implements Runnable {

    int id;
    ColaLenta lacola;

    public Consumidor(int id, ColaLenta lacola) {
        this.id = id;
        this.lacola = lacola;
        Thread.currentThread().setPriority(id);
    }

    /**
     * Esta clase consume elementos de la cola
     *
     */
    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            try {
                System.out.println("Soy el hilo Consumidor " + Thread.currentThread().getId()
                        + " y voy a extraer el número " + lacola.Desacola());
            } catch (Exception ex) {
                System.out.println("Error: Consumidor");
            }
        }

    }

}
