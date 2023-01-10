
import java.util.Random;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author Grefuwan
 */
public class Lector extends Thread {

    private int id;
    private MiCanvas cv;
    private ReentrantReadWriteLock L;

    public Lector(int id, MiCanvas cv, ReentrantReadWriteLock L) {
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
                cv.setLector(id, 0);    //No Quiero Leer
                sleep(1000 * (rnd.nextInt(3) + 1));
                cv.setLector(id, 1);    //Quiero Leer

                //Protocolo Entrada Lector
                L.readLock().lock();
                try {
                    cv.setLector(id, 2);    //Leyendo
                    sleep(1000);
                    if (rnd.nextInt(4) == 0) {
                        L.readLock().unlock();
                        cv.setLector(id, 3);

                        L.writeLock().lock();
                        cv.setLector(id, 4);
                        sleep(2000);
                        //Escribir
                        L.readLock().lock();
                        L.writeLock().unlock();
                        cv.setLector(id, 2);
                    }
                    else {
                        sleep(2000);
                    }
                    sleep(1000);

                    //Protocolo de Salida de Lector
                } finally {
                    L.readLock().unlock();
                }
            } catch (InterruptedException ex) {
            }
        }
    }

}

