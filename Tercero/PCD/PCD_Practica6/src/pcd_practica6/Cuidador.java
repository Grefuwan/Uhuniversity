package pcd_practica6;

import java.util.concurrent.Semaphore;

/**
 *
 * @author Grefuwan
 */
public class Cuidador extends Thread {

    Semaphore galleta;
    Semaphore perro;
    MiCanvas cv;

    public Cuidador(MiCanvas cv, Semaphore galleta, Semaphore perro) {
        this.cv = cv;
        this.galleta = galleta;
        this.perro = perro;
    }

    @Override
    public void run() {
        while (true) {
            try {
                galleta.acquire();  //wait(galleta)
                cv.pintaGalleta();  //Dar la galleta
                perro.release();    //signal(perro)
            } catch (InterruptedException ex) {
            }

        }
    }

}

