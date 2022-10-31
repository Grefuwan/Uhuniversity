package pcd_ejemplo_wait_notify;

/**
 *
 * @author Grefuwan
 */
public class Hilo extends Thread {

    private int id;
    private Ordenador o;

    public Hilo(int id, Ordenador o) {
        this.id = id;
        this.o = o;
    }

    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            o.cogerTurno(id);
            System.out.println("Soy el hilo: " + id);
            o.pasarTurno();
        }
    }

}
