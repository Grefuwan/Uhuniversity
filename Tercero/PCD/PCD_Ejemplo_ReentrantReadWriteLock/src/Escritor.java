
import java.util.Random;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

/**
 *
 * @author Grefuwan
 */
public class Escritor implements Runnable {

    private int id;
    private MiCanvas cv;
    private ReentrantReadWriteLock L;

    public Escritor(int id, MiCanvas cv, ReentrantReadWriteLock L) {
        this.id = id;
        this.cv = cv;
        this.L = L;
    }

    @Override
    public void run() {

        Random rnd = new Random();
        rnd.setSeed(System.currentTimeMillis() + id);

        while (true) {
            try {
                cv.setEscritor(id, 0);    //No Quiero Escribir
                Thread.sleep(1000 * (rnd.nextInt(3) + 1));
                cv.setEscritor(id, 1);    //Quiero Escribir

                //Protocolo de Entrada de Escritor
                L.writeLock().lock();
                try {
                    cv.setEscritor(id, 2);    //Escribiendo
                    Thread.sleep(1000 * (rnd.nextInt(3) + 2));

                    //Protocolo de Salida de Escritor
                } finally {
                    L.writeLock().unlock();
                }
            } catch (InterruptedException ex) {
            }
        }
    }

}

