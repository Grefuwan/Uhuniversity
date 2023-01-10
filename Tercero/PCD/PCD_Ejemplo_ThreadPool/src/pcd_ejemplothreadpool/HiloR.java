/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pcd_ejemplothreadpool;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Grefuwan
 */
public class HiloR implements Runnable{

    private int id;
    
    public HiloR (int id){
        this.id = id;
    }
    
    @Override
    public void run() {
        for (int i = 0; i < 3; i++) {
            System.out.println("Soy el hilo " + Thread.currentThread().getId() + " ejecutando la tarea " + id);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(HiloR.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
}

