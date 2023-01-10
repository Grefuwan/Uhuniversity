package pcd_practica6;

import java.util.concurrent.Semaphore;

/**
 *
 * @author Grefuwan
 */
public class ViajeroMaleta extends Thread {

    private final MiCanvas cv;
    Semaphore rayosMaleta;
    Semaphore galleta;
    Semaphore perro;
    int id;    

    public ViajeroMaleta(int i, MiCanvas cv, Semaphore rayosMaleta, Semaphore galleta, Semaphore perro) throws Exception {
        this.cv = cv;
        this.rayosMaleta = rayosMaleta;
        this.galleta = galleta;
        this.perro = perro;
        this.id = i;

    }

    @Override
    public void run() {
        try {
            rayosMaleta.acquire();  //wait(rayosMaleta)

            cv.llegaViajeroMaleta(id);  //Llega el ViajeroMaleta
            sleep(2000);
            System.out.println("El ViajeroMaleta " + id + " pasa a Rayos X Maleta");
            
            cv.insertaMaletaRayos(id, id%2);

            perro.acquire();        //wait(perro)
            rayosMaleta.release();  //signal(rayosMaleta)

            cv.borraMaleta();

            System.out.println("El ViajeroMaleta " + id + " sale de Rayos X Maleta y está con el perro");

            cv.pintaPerros(perro.availablePermits());       //Pintar en Perros

            galleta.release();      //signal(galleta)
            
            cv.borraPerros();
        } catch (InterruptedException ex) {
        }
    }

}

