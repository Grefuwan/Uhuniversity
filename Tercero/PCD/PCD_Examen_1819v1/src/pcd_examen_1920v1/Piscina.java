package pcd_examen_1920v1;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/*
 * Dos calles para Club  --  Una calle para Libre
 * Calles Club-> 2 usuarios max -- Calle Libre-> 1 usuario max
 * 
 * Usuarios Libre-> Calle Libre -- Usuarios Club -- Cualquiera si la calle libre está vacía y no hay libres esperando
 */
public class Piscina {

    char callesClub[] = {'N', 'N'}; // N=Nadie -- C=Club
    private boolean calleLibreOcupada = false;

    private int espCClub = 0, espCLibre = 0;

    Lock mutex = new ReentrantLock();
    Condition colaLibre = mutex.newCondition();
    Condition colaClub = mutex.newCondition();

    public synchronized void EntraLibre() throws InterruptedException {
        mutex.lock();
        try {
            espCLibre++;
            while (calleLibreOcupada) {
                colaLibre.await();
            }
            calleLibreOcupada = true;
            espCLibre--;
        } finally {
            mutex.unlock();
        }
    }

    public synchronized void SaleLibre() {
        mutex.lock();
        try {
            calleLibreOcupada = false;
            colaLibre.signalAll();
        } finally {
            mutex.unlock();
        }

    }

    public synchronized void EntraClub() throws InterruptedException {
        mutex.lock();
        try {
            espCClub++;
            if ((calleLibreOcupada || espCLibre > 0) || (callesClub[0] == 'C' && callesClub[1] == 'C')) {
                colaClub.await();
            }

            if (callesClub[0] == 'N') {
                callesClub[0] = 'C';
                System.out.println("Club entra en Calle 0");
            }
            else if (callesClub[1] == 'N') {
                callesClub[0] = 'C';
                System.out.println("Club entra en Calle 1");
            }
            else if (!calleLibreOcupada && espCLibre == 0) {
                calleLibreOcupada = true;
                System.out.println("Club entra en Calle Libre");
            }

            espCClub--;
        } finally {
            mutex.unlock();
        }

    }

    public synchronized void SaleClub() {
        mutex.lock();
        try {
            if (callesClub[0] == 'C') {
                callesClub[0] = 'N';
                System.out.println("Club sale de Calle 0");
            }
            else if (callesClub[1] == 'C') {
                callesClub[1] = 'N';
                System.out.println("Club sale de Calle 1");
            }
            else if (!calleLibreOcupada && espCLibre == 0) {
                calleLibreOcupada = true;
                System.out.println("Club sale de Calle Libre");
            }

            colaClub.signal();
        } finally {
            mutex.unlock();
        }

    }

}

