package pcd_practica7;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 *
 * @author Grefuwan
 */
public class Tunel {

    Lock mutex = new ReentrantLock();
    Condition colaCoche = mutex.newCondition();
    Condition colaFurgo = mutex.newCondition();

    int huecosLibres = 3;
    int esperaCoche = 0, esperaFurgo = 0;
    int coches = 0, furgos = 0;

    private MiCanvas cv;

    public Tunel(MiCanvas cv) {
        this.cv = cv;
    }

    public void entraCoche() throws InterruptedException {
        mutex.lock();
        try {
            if (huecosLibres == 0 || coches == 2) {  //Si no puedo entrar, me espero
                esperaCoche++;
                colaCoche.await();
                esperaCoche--;
                huecosLibres--;
                coches++;
            }

        } finally {
            mutex.unlock();
        }
    }

    public void saleCoche() {
        mutex.lock();
        try {
            huecosLibres++;
            coches--;
            if (furgos < 2 && esperaFurgo > 0) {
                colaFurgo.signal();
            }
            else {
                colaCoche.signal();
            }

        } finally {
            mutex.unlock();
        }
    }

    public void entraFurgo() throws InterruptedException {
        mutex.lock();
        try {
            if (huecosLibres == 0 || esperaFurgo == 2) {
                esperaFurgo++;
                colaFurgo.await();
                esperaFurgo--;
                huecosLibres--;
                furgos++;
            }
        } finally {
            mutex.unlock();
        }
    }

    public void saleFurgo() {
        mutex.lock();
        try {
            huecosLibres++;
            furgos--;
            if (esperaCoche == 0 && furgos < 2) {
                colaFurgo.signal();
            }
        } finally {
            mutex.unlock();
        }
    }

}

