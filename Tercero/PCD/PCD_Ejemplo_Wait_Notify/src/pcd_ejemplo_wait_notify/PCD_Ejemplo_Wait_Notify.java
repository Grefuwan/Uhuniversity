package pcd_ejemplo_wait_notify;

/**
 *
 * @author Grefuwan
 */
public class PCD_Ejemplo_Wait_Notify {

    /**
     * @param args the command line arguments
     *
     * @throws java.lang.InterruptedException
     */
    public static void main(String[] args) throws InterruptedException {
        Thread hilos[] = new Thread[5];

        Ordenador o = new Ordenador(0);
        System.out.println("Comienza la main");

        //Quiero que se ejecuten los hilos en orden: 0 > 1 > 2 > 3 > 4
        for (int i = 0; i < 5; i++) {
            hilos[i] = new Hilo(i, o);
        }

        for (int i = 0; i < 5; i++) {
            hilos[i].start();
        }

        for (int i = 0; i < 5; i++) {
            hilos[i].join();
            if (i == 4) {
                hilos[i].stop();
                System.out.println("Parado");
            }

        }

        System.out.println("Hilos finalizados");
    }

}

