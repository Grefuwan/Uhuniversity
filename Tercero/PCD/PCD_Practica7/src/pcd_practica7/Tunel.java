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
    int libres = 3;
    Condition colaCoche = mutex.newCondition();

    public void entraCoche() {
        mutex.lock();
        try {
            /*
            if (libres==0 OR coches == 2){  //Si no puedo entrar, me espero
               esperaCoche++;
                colaCoche.await();
                esperaCoche--;
            libres--;
            coches++;
            }
             */
        } finally {
            mutex.unlock();
        };
    }

    public void saleCoche() {
        mutex.lock();
        try {
            /*
            libres++
            coches--
            
            if (furgos < 2 && esperaFurgos > 0
                colaFurgo.signal();
            else
                colaCoche.signal();
            
            
             */
        } finally {
            mutex.unlock();
        }
    }

}

