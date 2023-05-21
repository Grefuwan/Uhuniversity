package pcd_examen_1819v2;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 *
 * @author Grefuwan
 */
public class Piscina {

    int capacidadMax = 5, numAletas = 6, numPalas = 5;
    int nadadoresEnPiscina = 0;

    Lock mutex = new ReentrantLock();
    Condition colaPiscina = mutex.newCondition();
    Condition colaAletas = mutex.newCondition();
    Condition colaPalas = mutex.newCondition();

    public synchronized void entraPiscina() throws InterruptedException {
        mutex.lock();
        try {
            while (nadadoresEnPiscina == capacidadMax) {
                colaPiscina.await();
            }
            nadadoresEnPiscina++;
        } finally {
            mutex.unlock();
        }
    }

    public synchronized void salePiscina() {
        mutex.lock();
        try {
            nadadoresEnPiscina--;
            colaPiscina.signal();
        } finally {
            mutex.unlock();
        }
    }

    public synchronized void cogeMaterial() throws InterruptedException {
        mutex.lock();
        try {
            while (numAletas < 2) {
                colaAletas.await();
            }
            numAletas -= 2;

            while (numPalas < 2) {
                colaPalas.await();
            }
            numPalas -= 2;
        } finally {
            mutex.unlock();
        }
    }

    public synchronized void sueltaMaterial() {
        mutex.lock();
        try {
            numAletas += 2;
            colaAletas.signal();
            numPalas += 2;
            colaPalas.signal();
        } finally {
            mutex.unlock();
        }
    }
}

