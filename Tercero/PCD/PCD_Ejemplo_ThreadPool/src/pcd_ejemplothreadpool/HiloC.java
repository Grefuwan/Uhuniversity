/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pcd_ejemplothreadpool;

import java.util.concurrent.Callable;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 *  Si quiero hacer que un hilo devuelva algo, tiene que hacerse con implements Callable<Object>, siendo Object el tipo de objeto que quiero que devuelva
 *  Luego, en vez de hacer public void run, deberia hacer public Object call()
 */
public class HiloC implements Callable<Integer> {

    private final int id;

    public HiloC(int id) {
        this.id = id;
    }

    @Override
    public Integer call() {

        try {
            for (int i = 0; i < 3; i++) {
                System.out.println("Soy el hilo " + Thread.currentThread().getId() + " ejecutando la tarea " + id);
                Thread.sleep(1000);
            }
        } catch (InterruptedException ex) {
            Logger.getLogger(HiloC.class.getName()).log(Level.SEVERE, null, ex);
        }
        return id * 10;
    }

}

