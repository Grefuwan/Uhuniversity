package pcd_practica8;

import java.util.concurrent.locks.*;

/**
 *
 * @author Grefuwan
 */
public class Tienda {

    boolean vendedorLibre = true, tecnicoLibre = true;
    private CanvasTienda cv;

    private Lock mutex;
    private Condition compradores;
    private Condition reparadores;

    int nCompradores = 0;

    public Tienda(CanvasTienda cv) {
        this.cv = cv;
        this.mutex = new ReentrantLock();
        this.compradores = this.mutex.newCondition();
        this.reparadores = this.mutex.newCondition();
    }

    public void EntraReparar(int id) throws InterruptedException {
        this.mutex.lock();
        try {
            while (!this.tecnicoLibre || this.nCompradores > 2) {
                this.reparadores.await();
            }

            this.tecnicoLibre = false;
            this.cv.quita('R', id);
            this.cv.repara('R', id);

        } finally {
            this.mutex.unlock();
        }
    }

    public void SaleReparar(int id) {
        this.mutex.lock();

        try {
            this.tecnicoLibre = true;
            this.cv.finalizado('M', id);
            this.reparadores.signal();
        } finally {
            this.mutex.unlock();
        }
    }

    public char EntraComprar(int id) throws InterruptedException {
        this.mutex.lock();
        char Quien = 0;

        try {
            while (!this.vendedorLibre && !this.tecnicoLibre) {
                this.nCompradores++;
                this.compradores.await();
                this.nCompradores--;
            }

            if (this.vendedorLibre) {
                this.vendedorLibre = false;
                Quien = 'C';
                this.cv.quita('C', id);
                this.cv.compra('V', id);
            }

            else if (this.tecnicoLibre) {
                this.tecnicoLibre = false;
                Quien = 'M';
                this.cv.quita('C', id);
                this.cv.compra('M', id);
            }
        } finally {
            this.mutex.unlock();
        }

        return Quien;
    }

    public void SaleComprar(char tipo, int id) {
        this.mutex.lock();
        try {
            if (tipo == 'C') {
                this.vendedorLibre = true;
                this.cv.finalizado('V', id);
            }

            else if (tipo == 'M') {
                this.tecnicoLibre = true;
                this.cv.finalizado('M', id);
            }
        } finally {

            if (this.nCompradores <= 2) {
                this.reparadores.signal();
                this.compradores.signal();
            }

            else {
                this.compradores.signal();
            }
            this.mutex.unlock();
        }
    }

}

