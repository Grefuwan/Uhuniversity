package pcd_ejemplo_wait_notify;

/**
 *
 * @author Grefuwan
 */
public class Ordenador {

    private int turno;

    public Ordenador(int turnoInicial) {
        turno = turnoInicial;
    }

    public synchronized void cogerTurno(int id) {
        while (turno != id) {
            try {
                wait();
            } catch (InterruptedException ex) {
            }
        }
    }

    public synchronized void pasarTurno() {
        turno = (turno + 1) % 5;
        notifyAll();
    }

}

