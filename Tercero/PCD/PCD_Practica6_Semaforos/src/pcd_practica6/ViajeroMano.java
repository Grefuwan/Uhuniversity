package pcd_practica6;

import static java.lang.Thread.sleep;
import java.util.concurrent.Semaphore;

/**
 *
 * @author Grefuwan
 */
public class ViajeroMano implements Runnable {

    private final MiCanvas cv;
    Semaphore rayosMano;
    Semaphore galleta;
    Semaphore perro;
    int id;

    public ViajeroMano(int i, MiCanvas cv, Semaphore rayosMano, Semaphore galleta, Semaphore perro) {
        this.cv = cv;
        this.rayosMano = rayosMano;
        this.galleta = galleta;
        this.perro = perro;
        this.id = i;
    }

    @Override
    public void run() {
        try {
            rayosMano.acquire();    //wait(rayosMano)

            cv.llegaViajeroMano(id);    //Pintar en RayosMaleta
            sleep(2000);
            System.out.println("El ViajeroMano " + id + " pasa a Rayos X Mano");

            cv.insertaManoRayos(id);

            perro.acquire();        //wait(perro)
            rayosMano.release();    //signal

            cv.borraMano();

            System.out.println("El ViajeroMano " + id + " sale de Rayos X Mano y está con el perro");

            cv.pintaPerros(perro.availablePermits());       //Pintar en Perros

            galleta.release();      //signal(galleta)
            
            cv.borraPerros();

        } catch (InterruptedException ex) {
        }

    }

}

